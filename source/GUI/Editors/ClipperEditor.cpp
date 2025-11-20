//
// Created by Landon Viator on 11/14/25.
//

#include "ClipperEditor.h"

namespace viator::gui::editors
{
    ClipperEditor::ClipperEditor(viator::dsp::processors::ClipperProcessor &p)
            : AudioProcessorEditor(&p), processorRef(p)
    {
        juce::ignoreUnused(processorRef);

        setSize(1000, 600);
    }

    ClipperEditor::~ClipperEditor()
    {
    }

//==============================================================================
    void ClipperEditor::paint(juce::Graphics &g)
    {
        g.fillAll(juce::Colours::blue);

        g.setColour(juce::Colours::black);
        g.drawText("Clipper", 0, 0, getWidth(), getHeight(), juce::Justification::centred);
    }

    void ClipperEditor::resized()
    {
    }
}