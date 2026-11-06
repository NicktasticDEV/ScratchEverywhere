#include "speech_manager_gx.hpp"

SpeechManagerGX::SpeechManagerGX() = default;

SpeechManagerGX::~SpeechManagerGX() {
    cleanup();
}
