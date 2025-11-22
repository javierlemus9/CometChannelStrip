//
// Created by Landon Viator on 11/1/25.
//

#pragma once
#include <juce_dsp/juce_dsp.h>
#include "DSP/Units/ConsoleModule.h"
#include "DSP/Units/MasterBus.h"
#include "DSP/Modules/Tube.h"
#include "DSP/Modules/GraphicEq.h"

namespace viator::dsp
{
    class ProcessBlock
    {
    public:
        ProcessBlock() = default;
        ~ProcessBlock() = default;

        void prepare(double sample_rate, int samples_per_block, int num_channels, int factor)
        {
            juce::dsp::ProcessSpec spec{};
            spec.sampleRate = sample_rate;
            spec.maximumBlockSize = samples_per_block;
            spec.numChannels= num_channels;

            m_oversampler = std::make_unique<juce::dsp::Oversampling<float>>(spec.numChannels,
                    factor,
                    juce::dsp::Oversampling<float>::FilterType::filterHalfBandPolyphaseIIR,
                    true);
            m_oversampler->initProcessing(spec.maximumBlockSize);
        }

        void process(juce::AudioBuffer<float>& buffer, const int num_samples)
        {
            const int num_oversampled_samples = num_samples * static_cast<int>(m_oversampler->getOversamplingFactor());
            juce::dsp::AudioBlock<float> block (buffer);
            auto up_sampled_block = m_oversampler->processSamplesUp(block);
            m_oversampler->processSamplesDown(block);
        }

        void updateParameters(viator::parameters::parameters& parameters)
        {
        }

    private:
        std::unique_ptr<juce::dsp::Oversampling<float>> m_oversampler;
    };
}
