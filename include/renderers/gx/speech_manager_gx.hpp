#pragma once
#include <se_export.hpp>

#include "speech_manager.hpp"

class SE_EXPORT SpeechManagerGX : public SpeechManager {
  public:
    SpeechManagerGX();
    ~SpeechManagerGX() override;
};
