//
// Created by Landon Viator on 11/14/25.
//

#pragma once

#include "../../DSP/Processors/ClipperProcessor.h"

namespace viator::gui::editors
{
    class ClipperEditor : public juce::AudioProcessorEditor
    {
    public:
        explicit ClipperEditor(viator::dsp::processors::ClipperProcessor &);

        ~ClipperEditor() override;

        //==============================================================================
        void paint(juce::Graphics &) override;

        void resized() override;

    private:
        viator::dsp::processors::ClipperProcessor &processorRef;
    };
}