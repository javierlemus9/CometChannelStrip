//
// Created by Landon Viator on 11/14/25.
//

#pragma once

#include "../../DSP/Processors/BaseProcessor.h"
#include "../Widgets/BaseSlider.h"

namespace viator::gui::editors
{
class BaseEditor : public juce::AudioProcessorEditor
    {
    public:
        explicit BaseEditor(viator::dsp::processors::BaseProcessor &);

        ~BaseEditor() override;

        //==============================================================================
        void paint(juce::Graphics &) override;

        void resized() override;

        std::vector<viator::gui::widgets::BaseSlider*>& getSliders() { return m_sliders; }
    private:
        viator::dsp::processors::BaseProcessor &processorRef;

        std::vector<viator::gui::widgets::BaseSlider*> m_sliders;
    };
}