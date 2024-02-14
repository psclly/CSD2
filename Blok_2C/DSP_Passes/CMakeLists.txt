project(DSPPASSES VERSION 0.0.1)
juce_add_console_app(DSPPASSES PRODUCT_NAME "DSPPASSES")
target_sources(DSPPASSES PRIVATE main.cpp writeToFile.cpp)
target_compile_definitions(DSPPASSES PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(DSPPASSES
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(DSPPASSES PRIVATE cxx_std_20)
