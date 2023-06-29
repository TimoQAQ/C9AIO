/*
 * 定义一个数据结构存放所有音频数据
 * 定义一个混音器对象
 * 定义一个采集器
 * 定义一个播放器
 * 创建线程
 *
 */

#include "mixer.h"
#include "capture.h"
#include "player.h"
#include "config.h"

class AudioIO
{
private:
    Mixer m_mixer;
    Player m_player;
    Capture m_capture;
    Config m_config;

public:
    AudioIO(/* args */);
    ~AudioIO();
    void loop_thread(void);
};
