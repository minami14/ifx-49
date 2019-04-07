#include <ifx-49.h>

int main(void) {
    ifx49_init();
    adau1361_enable();
    while (1) {
        idle();
        adau1361_data_check();
    }
}

void codec_audio_process(const int32_t *buf_in[2], int32_t *buf_out[2]) {
    int i;
    for (i = 0; i < NUM_SAMPLES; i++) {
        buf_out[0][i] = buf_in[0][i] - buf_in[1][i];
        buf_out[1][i] = buf_in[0][i] - buf_in[1][i];
    }
}