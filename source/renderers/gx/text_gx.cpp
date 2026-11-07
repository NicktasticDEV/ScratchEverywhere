#include "text_gx.hpp"

TextObjectGX::TextObjectGX(std::string txt, double posX, double posY, std::string fontPath)
    : TextObjectBase(txt, posX, posY, fontPath, 30.0f) {
}

TextObjectGX::~TextObjectGX() = default;

void TextObjectGX::uploadAtlas(FontGeneration &gen) {
}

void TextObjectGX::render(int xPos, int yPos) {
}
