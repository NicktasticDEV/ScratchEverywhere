#include "renderer_gx.hpp"
#include "window.hpp"

#include <gccore.h>
#include <ogc/conf.h>
#include <wiiuse/wpad.h>

#include <malloc.h>

static GXRModeObj* renderMode = nullptr;
static bool widescreen = false;
static void* framebuffer = nullptr;
static uint32_t fifoSize = 256 * 1024;
static void* fifo = nullptr;
static GXColor backgroundColor = {0, 0, 0, 255};

static bool widescreenMode(GXRModeObj* mode) {
    if (CONF_GetAspectRatio() != CONF_ASPECT_16_9) {
        return false;
    }

    u16 widescreenViWidth = 678;
    u16 maxViWidth = VI_MAX_WIDTH_NTSC;

    mode->viWidth = widescreenViWidth;
    mode->viXOrigin = (VI_MAX_WIDTH_NTSC - widescreenViWidth) / 2;
    return true;
}

static bool allocateFramebuffer() {
    const u32 size = VIDEO_GetFrameBufferSize(renderMode);

    void* cached = memalign(32, size);
    framebuffer = MEM_K0_TO_K1(cached);
    VIDEO_ClearFrameBuffer(renderMode, framebuffer, COLOR_BLACK);
    
    return true;
}

Renderer_GX::Renderer_GX() {
    // VI is initialized through renderer instead of windowing
    window = createWindow(0, 0, "", WindowingBackends::Headless);

    // === VI initialization ===
    VIDEO_Init();
    CONF_Init();

    renderMode = VIDEO_GetPreferredMode(nullptr);
    widescreen = widescreenMode(renderMode);

    VIDEO_Configure(renderMode);
    allocateFramebuffer();

    VIDEO_Configure(renderMode);
    VIDEO_SetNextFramebuffer(framebuffer);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();

    VIDEO_WaitVSync();
    if ((renderMode->viTVMode & VI_NON_INTERLACE) != 0) {
        VIDEO_WaitVSync();
    } else {
        while (VIDEO_GetNextField() != 0) {
            VIDEO_WaitVSync();
        }
    }

    //CON_Init(framebuffer, 20, 20, renderMode->fbWidth,
    //             renderMode->xfbHeight, renderMode->fbWidth * VI_DISPLAY_PIX_SZ);

    // === GX initialization ===
    fifo = memalign(32, fifoSize);
    memset(fifo, 0, fifoSize);

    GX_Init(fifo, fifoSize);

    GX_SetCopyClear(backgroundColor, GX_MAX_Z24);

    GX_SetViewport(0.0f, 0.0f, static_cast<f32>(renderMode->fbWidth),
                   static_cast<f32>(renderMode->efbHeight), 0.0f, 1.0f);
    GX_SetScissor(0, 0, renderMode->fbWidth, renderMode->efbHeight);

    const u32 xfb_height =
        GX_SetDispCopyYScale(static_cast<f32>(renderMode->xfbHeight) /
                             static_cast<f32>(renderMode->efbHeight));

    GX_SetDispCopySrc(0, 0, renderMode->fbWidth, renderMode->efbHeight);
    GX_SetDispCopyDst(renderMode->fbWidth, static_cast<u16>(xfb_height));
    GX_SetCopyFilter(renderMode->aa, renderMode->sample_pattern, GX_TRUE, renderMode->vfilter);
    GX_SetFieldMode(renderMode->field_rendering,
                    renderMode->viHeight == 2 * renderMode->xfbHeight ? GX_ENABLE : GX_DISABLE);
    GX_SetDispCopyGamma(GX_GM_1_0);

    GX_SetPixelFmt(renderMode->aa ? GX_PF_RGB565_Z16 : GX_PF_RGB8_Z24, GX_ZC_LINEAR);

    GX_SetZMode(GX_DISABLE, GX_ALWAYS, GX_DISABLE);
    GX_SetCullMode(GX_CULL_NONE);
    GX_SetColorUpdate(GX_TRUE);
    GX_SetAlphaUpdate(GX_TRUE);
    GX_SetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
}

Renderer_GX::~Renderer_GX() = default;

bool Renderer_GX::initPen() {
    return true;
}

void Renderer_GX::setRenderTarget(void *renderTarget, int width, int height) {
}

void Renderer_GX::clearRenderTarget() {
}

bool Renderer_GX::createSpeechManager() {
    return true;
}

SpeechManager *Renderer_GX::getSpeechManager() {
    return nullptr;
}

void Renderer_GX::destroySpeechManager() {
}

void Renderer_GX::beginFrame(int screen, int colorR, int colorG, int colorB) {
    if (!hasFrameBegan) {
        GX_SetViewport(0, 0, getWidth(), getHeight(), 0.0f, 300.0f);
        hasFrameBegan = true;
    }
}

void Renderer_GX::endFrame(bool shouldFlush) {
    hasFrameBegan = false;
}

int Renderer_GX::getWidth() {
    return 0;
}

int Renderer_GX::getHeight() {
    return 0;
}

float Renderer_GX::getPixelDensity() {
    return 1.0f;
}

void Renderer_GX::renderSprites() {
}

void Renderer_GX::renderPenLayer() {
}

void Renderer_GX::drawBox(int w, int h, int x, int y, uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA) {
}

void Renderer_GX::drawRoundedBox(int w, int h, int x, int y, int radius, uint8_t colorR, uint8_t colorG, uint8_t colorB, uint8_t colorA) {
}

bool Renderer_GX::appShouldRun() {
    return true;
}

void Renderer_GX::penMoveFast(double x1, double y1, double x2, double y2, Sprite *sprite) {
}

void Renderer_GX::penMoveAccurate(double x1, double y1, double x2, double y2, Sprite *sprite) {
}

void Renderer_GX::penDotFast(Sprite *sprite) {
}

void Renderer_GX::penDotAccurate(Sprite *sprite) {
}

void Renderer_GX::penStamp(Sprite *sprite) {
}

void Renderer_GX::penClear() {
}

void Renderer_GX::cleanupPen() {
}

void Renderer_GX::preparePenColorQuery(float minX, float minY, float maxX, float maxY) {
}

bool Renderer_GX::samplePenColor(float x, float y, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) {
    return false;
}