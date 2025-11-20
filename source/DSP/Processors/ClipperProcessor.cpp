#include "ClipperProcessor.h"
#include "../../GUI/Editors/ClipperEditor.h"

namespace viator::dsp::processors
{

//==============================================================================
    ClipperProcessor::ClipperProcessor(int id)
            : viator::dsp::processors::BaseProcessor(id)
    {
    }

    ClipperProcessor::~ClipperProcessor()
    {
    }

//==============================================================================
    const juce::String ClipperProcessor::getName() const
    {
        return "Reduction";
    }

    bool ClipperProcessor::acceptsMidi() const
    {
#if JucePlugin_WantsMidiInput
        return true;
#else
        return false;
#endif
    }

    bool ClipperProcessor::producesMidi() const
    {
#if JucePlugin_ProducesMidiOutput
        return true;
#else
        return false;
#endif
    }

    bool ClipperProcessor::isMidiEffect() const
    {
#if JucePlugin_IsMidiEffect
        return true;
#else
        return false;
#endif
    }

    double ClipperProcessor::getTailLengthSeconds() const
    {
        return 0.0;
    }

    int ClipperProcessor::getNumPrograms()
    {
        return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
        // so this should be at least 1, even if you're not really implementing programs.
    }

    int ClipperProcessor::getCurrentProgram()
    {
        return 0;
    }

    void ClipperProcessor::setCurrentProgram(int index)
    {
        juce::ignoreUnused(index);
    }

    const juce::String ClipperProcessor::getProgramName(int index)
    {
        juce::ignoreUnused(index);
        return {};
    }

    void ClipperProcessor::changeProgramName(int index, const juce::String &newName)
    {
        juce::ignoreUnused(index, newName);
    }


//==============================================================================
    void ClipperProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
    {
        // Use this method as the place to do any pre-playback
        // initialisation that you need..
        juce::ignoreUnused(sampleRate, samplesPerBlock);

    }

    void ClipperProcessor::releaseResources()
    {
        // When playback stops, you can use this as an opportunity to free up any
        // spare memory, etc.
    }

    bool ClipperProcessor::isBusesLayoutSupported(const BusesLayout &layouts) const
    {
#if JucePlugin_IsMidiEffect
        juce::ignoreUnused (layouts);
        return true;
#else
        // This is the place where you check if the layout is supported.
        // In this template code we only support mono or stereo.
        // Some plugin hosts, such as certain GarageBand versions, will only
        // load plugins that support stereo bus layouts.
        if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
            && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
            return false;

        // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
        if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
            return false;
#endif

        return true;
#endif
    }

    void ClipperProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                        juce::MidiBuffer &midiMessages)
    {
        juce::ignoreUnused(midiMessages);

        for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
        {
            auto *data = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
            {
                const auto xn = data[sample];
                const auto yn = std::tanh(xn * 5.0f);
                data[sample] = yn;
            }
        }
    }

//==============================================================================
    bool ClipperProcessor::hasEditor() const
    {
        return true; // (change this to false if you choose to not supply an editor)
    }

    juce::AudioProcessorEditor *ClipperProcessor::createEditor()
    {
        return new viator::gui::editors::ClipperEditor (*this);
    }

//==============================================================================
    void ClipperProcessor::getStateInformation(juce::MemoryBlock &destData)
    {
        // You should use this method to store your parameters in the memory block.
        // You could do that either as raw data, or use the XML or ValueTree classes
        // as intermediaries to make it easy to save and load complex data.
        juce::ignoreUnused(destData);
    }

    void ClipperProcessor::setStateInformation(const void *data, int sizeInBytes)
    {
        // You should use this method to restore your parameters from this memory block,
        // whose contents will have been created by the getStateInformation() call.
        juce::ignoreUnused(data, sizeInBytes);
    }
}