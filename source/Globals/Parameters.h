//
// Created by Landon Viator on 11/1/25.
//

#pragma once

namespace viator::parameters
{
    inline const juce::String oversamplingChoiceID = "oversamplingChoiceID";
    inline const juce::String oversamplingChoiceName = "oversamplingChoiceName";

    inline const juce::String consoleDriveID = "consoleDriveID";
    inline const juce::String consoleDriveName = "Console Drive";

    struct parameters
    {
        explicit parameters(const juce::AudioProcessorValueTreeState& state)
        {
            oversamplingParam = dynamic_cast<juce::AudioParameterChoice*>(state.getParameter(viator::parameters::oversamplingChoiceID));
            consoleDriveParam = dynamic_cast<juce::AudioParameterFloat*>(state.getParameter(viator::parameters::consoleDriveID));
        }

        juce::AudioParameterChoice *oversamplingParam { nullptr };
        juce::AudioParameterFloat *consoleDriveParam { nullptr };
    };
}
