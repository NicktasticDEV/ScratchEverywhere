#pragma once
#include <se_export.hpp>
#include <text.hpp>

class SE_EXPORT TextObjectGX : public TextObjectBase {
  protected:
    void uploadAtlas(FontGeneration &gen) override;

  public:
    TextObjectGX(std::string txt, double posX, double posY, std::string fontPath = "");
    ~TextObjectGX() override;

    void render(int xPos, int yPos) override;
};
