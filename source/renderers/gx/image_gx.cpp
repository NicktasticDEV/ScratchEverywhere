#include "image_gx.hpp"
#include "nonstd/expected.hpp"

Image_GX::Image_GX(std::string filePath, bool fromScratchProject, bool bitmapHalfQuality, float scale) : Image(filePath, fromScratchProject, bitmapHalfQuality, scale) {
    if (imgData.pixels) {
        free(imgData.pixels);
        imgData.pixels = nullptr;
    }
}

Image_GX::Image_GX(std::string filePath, ZipArchive *zip, bool bitmapHalfQuality, float scale) : Image(filePath, zip, bitmapHalfQuality, scale) {
    if (imgData.pixels) {
        free(imgData.pixels);
        imgData.pixels = nullptr;
    }
}

Image_GX::~Image_GX() {
}

void Image_GX::render(ImageRenderParams &params) {
}

void Image_GX::renderNineslice(double xPos, double yPos, double width, double height, double padding, bool centered) {
}

void *Image_GX::getNativeTexture() {
    return nullptr;
}

nonstd::expected<void, std::string> Image_GX::refreshTexture() {
    return {};
}
