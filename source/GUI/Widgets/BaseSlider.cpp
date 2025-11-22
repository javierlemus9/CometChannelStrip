//
// Created by Landon Viator on 11/21/25.
//

#include "BaseSlider.h"

namespace viator::gui::widgets
{
    BaseSlider::BaseSlider()
    {

    }

    BaseSlider::~BaseSlider()
    {

    }

    void BaseSlider::paint(juce::Graphics &g)
    {
        juce::Slider::paint(g);
    }

    void BaseSlider::mouseDown(const juce::MouseEvent &event)
    {
        if (event.mods.isRightButtonDown())
        {
            sendSynchronousChangeMessage();
        }
    }
}