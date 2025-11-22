//
// Created by Landon Viator on 11/21/25.
//

#pragma once
#include <juce_gui_basics/juce_gui_basics.h>

namespace viator::gui::widgets
{
class BaseSlider : public juce::Slider, public juce::ChangeBroadcaster
    {
    public:
        BaseSlider();

        ~BaseSlider() override;

        void paint(juce::Graphics &g) override;

    private:
    void mouseDown(const juce::MouseEvent &event);
    };
}

