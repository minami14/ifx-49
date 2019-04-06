#include <ifx-49.h>

int main(void) {
    ifx49_init();
    adau1361_enable();
    while (1) {
        idle();
        adau1361_data_check();
    }
}

#define NUM_SMA_SAMPLES 64

static int32_t buf_l[NUM_SMA_SAMPLES];
static int32_t buf_r[NUM_SMA_SAMPLES];
static int32_t tail = 0;
static int32_t head = 1;
static int32_t sum_l = 0;
static int32_t sum_r = 0;

void codec_audio_process(const int32_t *buf_in[2], int32_t *buf_out[2]) {
    int i;
    int j;
    for (i = 0; i < NUM_SAMPLES; i++) {
        buf_l[tail] = buf_in[0][i];
        buf_r[tail] = buf_in[1][i];
        sum_l = sum_l + buf_l[tail] - buf_l[head];
        sum_r = sum_r + buf_r[tail] - buf_r[head];
        if (++tail == NUM_SMA_SAMPLES) {
            tail = 0;
        }
        if (++head == NUM_SMA_SAMPLES) {
            head = 0;
        }
        // TODO: Check over flow
        buf_out[0][i] = sum_l / NUM_SMA_SAMPLES + buf_in[0][i];
        buf_out[1][i] = sum_r / NUM_SMA_SAMPLES + buf_in[1][i];
    }

}