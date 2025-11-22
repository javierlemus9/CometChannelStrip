//
// Created by Landon Viator on 11/14/25.
//

#include "ClipperEditor.h"

namespace viator::gui::editors
{
    ClipperEditor::ClipperEditor(viator::dsp::processors::ClipperProcessor &p)
            : viator::gui::editors::BaseEditor(p), processorRef(p)
    {
        juce::ignoreUnused(processorRef);

        m_drive_slider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
        m_drive_slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 32, 64);
        m_drive_slider.addMouseListener(this, true);
        m_drive_slider.setComponentID(ClipperParameters::driveID + juce::String(processorRef.getProcessorID()));
        getSliders().push_back(&m_drive_slider);
        addAndMakeVisible(m_drive_slider);

        m_drive_attach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processorRef
                .getTreeState(), ClipperParameters::driveID + juce::String(processorRef.getProcessorID()),
                m_drive_slider);

        setSize(1000, 600);
    }

    ClipperEditor::~ClipperEditor()
    {
    }

//==============================================================================
    void ClipperEditor::paint(juce::Graphics &g)
    {
        g.fillAll(juce::Colours::black.brighter(0.15f));

        g.setColour(juce::Colours::white);
        g.drawText("Clipper", 0, 0, getWidth(), getHeight(), juce::Justification::centredTop);
    }

    void ClipperEditor::resized()
    {
        m_drive_slider.setBounds(getLocalBounds().withSizeKeepingCentre(getWidth() / 1, getWidth() / 1));
    }
}