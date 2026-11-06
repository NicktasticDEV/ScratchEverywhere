#include "text_headless.hpp"

TextObjectGX::TextObjectGX(std::string txt, double posX, double posY, std::string fontPath)
    : TextObject(txt, posX, posY, fontPath) {
}

TextObjectGX::~TextObjectGX() {
}

void TextObjectGX::setText(std::string txt) {
    text = txt;
}

void TextObjectGX::render(int xPos, int yPos) {
}

std::vector<float> TextObjectGX::getSize() {
    return {0.0f, 0.0f};
}

std::vector<float> TextObjectGX::getStringSize(const std::string &txt) {
    return {0.0f, 0.0f};
}
