#include <RosAudioSource.h>
#include <ros/ros.h>

using namespace opentera;


RosAudioSource::RosAudioSource(unsigned int soundCardTotalDelayMs,
            bool echoCancellation,
            bool autoGainControl,
            bool noiseSuppression,
            bool highPassFilter,
            bool stereoSwapping,
            bool typingDetection,
            bool residualEchoDetector,
            bool transientSuppression)
    //Creating a default configuration for now, int bitsPerSample, int sampleRate, size_t numberOfChannels);
    : AudioSource(AudioSourceConfiguration::create(soundCardTotalDelayMs,
        echoCancellation, autoGainControl, noiseSuppression, highPassFilter,
        stereoSwapping, typingDetection, residualEchoDetector, transientSuppression), 16, 48000, 1)
{
}

 void RosAudioSource::sendFrame(const audio_utils::AudioFrameConstPtr& msg)
 {
     //Checking if frame fits default configuration and send frame
     if(msg->channel_count == 1 &&
           msg->sampling_frequency == 48000 &&
           msg->format == "signed_16")
    {
        //ROS_INFO("Frame size %i", msg->frame_sample_count);
        AudioSource::sendFrame(msg->data.data(), msg->frame_sample_count);
    }
    else
    {
        ROS_ERROR("Invalid audio frame (channel_count=%i, sampling_frequency=%i, format=%s)",
                msg->channel_count, msg->sampling_frequency, msg->format.c_str());
    }
 }