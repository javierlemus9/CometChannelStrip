//
// Created by Landon Viator on 11/1/25.
//

#pragma once

namespace viator::parameters
{
    inline const juce::String oversamplingChoiceID = "oversamplingChoiceID";
    inline const juce::String oversamplingChoiceName = "oversamplingChoiceName";

    struct parameters
    {
        explicit parameters(const juce::AudioProcessorValueTreeState& state)
        {
            oversamplingParam = dynamic_cast<juce::AudioParameterChoice*>(state.getParameter(viator::parameters::oversamplingChoiceID));
        }

        juce::AudioParameterChoice *oversamplingParam { nullptr };
    };
}
