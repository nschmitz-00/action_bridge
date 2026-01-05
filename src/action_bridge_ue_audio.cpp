#include <action_bridge/action_bridge.hpp>

#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunused-parameter"
#endif
#include <clf_ue_audio_one_msgs/AudioStreamingAction.h>
#ifdef __clang__
# pragma clang diagnostic pop
#endif

#include <clf_ue_audio_msgs/action/audio_streaming.hpp>

using AudioActionBridge = ActionBridge_1_2<clf_ue_audio_one_msgs::AudioStreamingAction, 
    clf_ue_audio_msgs::action::AudioStreaming>;

template<>
void AudioActionBridge::translate_goal_1_to_2(const ROS1Goal & goal1, ROS2Goal & goal2)
{
    goal2.data.data = goal1.data.data;
    goal2.info.bitrate = goal1.info.bitrate;
    goal2.info.channels = goal1.info.channels;
    goal2.info.coding_format = goal1.info.coding_format;
    goal2.info.sample_format = goal1.info.sample_format;
    goal2.info.sample_rate = goal1.info.sample_rate;
}

template<>
void AudioActionBridge::translate_result_2_to_1(ROS1Result & result1, const ROS2Result & result2) 
{
    result1.return_code.code = result2.return_code.code;
}

template<>
void AudioActionBridge::translate_feedback_2_to_1(ROS1Feedback & feedback1, const ROS2Feedback & feedback2) 
{
    feedback1.status.code = feedback2.status.code;
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3) {
        std::cerr << "Usage: action_bridge_ue_audio_node <ros1_action_name> <ros2_action_name>" << std::endl;
        return 1;
    }
    std::cout << "Starting action_bridge_ue_audio_node bridging ROS1 action '" << argv[1]
              << "' and ROS2 action '" << argv[2] << "'" << std::endl;
    return AudioActionBridge::main(std::string(argv[1]), std::string(argv[2]), argc, argv);
}