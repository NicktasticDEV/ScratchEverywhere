#pragma once
#include "nonstd/expected.hpp"
#include <image.hpp>
#include <se_export.hpp>

class SE_EXPORT Image_GX : public Image {
  public:
    Image_GX(std::string filePath, bool fromScratchProject = true, bool bitmapHalfQuality = false, float scale = 1);

    Image_GX(std::string filePath, ZipArchive *zip, bool bitmapHalfQuality = false, float scale = 1);

    ~Image_GX() override;

    void render(ImageRenderParams &params) override;
    void renderNineslice(double xPos, double yPos, double width, double height, double padding, bool centered = false) override;

    void *getNativeTexture() override;

    nonstd::expected<void, std::string> refreshTexture() override;
};
