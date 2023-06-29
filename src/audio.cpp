#include "audio.h"

AudioIO::AudioIO(/* args */)
{
    m_config = Config("/opt/audio_config.json", "/data/userdata/config/audio_config.json"); // 读取配置文件

    // 配置各个音频对象
    m_player = Player(m_config);
    m_capture = Capture(m_config);
    m_mixer = Mixer(m_config);
}

AudioIO::~AudioIO()
{
}

void AudioIO::loop_thread()
{

    while (true)
    {
        // 传递指向数据存放结构的指针
        // 包含各个通道，一个粒度的音频数据+时间戳
        data_type &proc_data;
        m_capture.cap(proc_data);
        m_mixer.mix(proc_data);
        m_player.play(proc_data);
        /* code */
    }
}