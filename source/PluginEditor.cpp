#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), m_rack(processorRef)
{
    juce::ignoreUnused (processorRef);

    const auto items = viator::globals::Oversampling::items;
    setComboBoxProps(m_oversampling_menu, items);
    m_oversampling_Attach = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(processorRef.getTreeState(),
                                                                                                     viator::parameters::oversamplingChoiceID,
                                                                                                     m_oversampling_menu);

    addAndMakeVisible(m_rack);
    setSize (1200, 720);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black.brighter(0.12f));

    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 3);
}

void AudioPluginAudioProcessorEditor::resized()
{
    const auto padding = juce::roundToInt(getWidth() * 0.03);
    auto width = juce::roundToInt(getWidth() * 0.1);
    auto height = juce::roundToInt(getHeight() * 0.05);
    auto x = getWidth() - width - padding;
    auto y = padding;
    m_oversampling_menu.setBounds(x, y, width, height);

    width = getWidth();
    height = juce::roundToInt(getHeight() * 0.8);
    x = 0;
    y = getHeight() / 10;
    m_rack.setBounds(x, y, width, height);
}

void AudioPluginAudioProcessorEditor::setComboBoxProps(juce::ComboBox &box, const juce::StringArray &items)
{
    box.addItemList(items, 1);
    box.setSelectedId(1, juce::dontSendNotification);
    addAndMakeVisible(box);
}