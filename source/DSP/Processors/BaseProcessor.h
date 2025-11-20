//
// Created by Landon Viator on 11/14/25.
//

#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>

namespace viator::dsp::processors
{
class BaseProcessor : public juce::AudioProcessor
    {
    public:
    explicit BaseProcessor(const BusesProperties& ioConfig) : juce::AudioProcessor(ioConfig) {}
    ~BaseProcessor() override = default;

    juce::AudioProcessorValueTreeState& getTreeState() const { return *m_tree_state; }

    void initTreeState(BaseProcessor* owner, juce::AudioProcessorValueTreeState::ParameterLayout layout)
    {
        m_tree_state = std::make_unique<juce::AudioProcessorValueTreeState>(*owner, nullptr, "PARAMETERS", std::move(layout));
    }

    int getProcessorID() { return m_processor_id; }

    void setProcessorID(const int id) { m_processor_id = id; }
private:

    std::unique_ptr<juce::AudioProcessorValueTreeState> m_tree_state;

    int m_processor_id { -1 };
    //==============================================================================
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseProcessor)
    };
}



