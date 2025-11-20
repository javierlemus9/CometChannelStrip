//
// Created by Landon Viator on 11/14/25.
//

#include "50AEditor.h"

namespace viator::gui::editors
{
    AmplificationEditor::AmplificationEditor(viator::dsp::processors::AmplificationProcessor &p)
            : AudioProcessorEditor(&p), processorRef(p)
    {
        juce::ignoreUnused(processorRef);

        setSize(1000, 600);
    }

    AmplificationEditor::~AmplificationEditor()
    {
    }

//==============================================================================
    void AmplificationEditor::paint(juce::Graphics &g)
    {
        g.fillAll(juce::Colours::red);
        g.drawText("50A", 0, 0, getWidth(), getHeight(), juce::Justification::centred);
    }

    void AmplificationEditor::resized()
    {
    }
}