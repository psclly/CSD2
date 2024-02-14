project(CIRCBUFFER VERSION 0.0.1)
juce_add_console_app(CIRCBUFFER PRODUCT_NAME "CIRCBUFFER")
target_sources(CIRCBUFFER PRIVATE main.cpp sine.cpp circBuffer.cpp effect.cpp tremolo.cpp writeToFile.cpp delay.cpp)
target_compile_definitions(CIRCBUFFER PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(CIRCBUFFER
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(CIRCBUFFER PRIVATE cxx_std_20)
