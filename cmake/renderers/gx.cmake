# VI code could probably be in windowing instead.
list(APPEND SE_WINDOWING_VALID_OPTIONS "headless")

if(NOT DEFINED SE_AUDIO_ENGINE_DEFAULT)
	set(SE_AUDIO_ENGINE_DEFAULT "sdl2")
endif()
