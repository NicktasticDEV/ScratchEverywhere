#include "renderer_gx.hpp"
#include "window.hpp"

Renderer_GX::Renderer_GX() {
    window = createWindow(0, 0, "", WindowingBackends::Headless);
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
    hasFrameBegan = true;
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