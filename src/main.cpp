// https://github.com/TimoQAQ/C9AIO.git
#include <stdio.h>
#include <alsa/asoundlib.h>

// commit 1
int main()
{
    snd_pcm_hw_params_t *hwparams;
	snd_pcm_sw_params_t *swparams;

	snd_pcm_hw_params_alloca(&hwparams);
	snd_pcm_sw_params_alloca(&swparams);

    printf("TIMO!");
    return 0;
}