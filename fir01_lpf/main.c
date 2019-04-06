#include <ifx-49.h>

int main(void) {
    ifx49_init();
    adau1361_enable();
    while (1) {
        idle();
        adau1361_data_check();
    }
}

#define NUM_COEFF 55

static const int32_t fir_coeff[NUM_COEFF] = {
        5083,
        6269,
        8621,
        9871,
        8810,
        4110,
        -5434,
        -20591,
        -41350,
        -66600,
        -93908,
        -119443,
        -138100,
        -143851,
        -130315,
        -91498,
        -22624,
        79034,
        213473,
        377499,
        564615,
        765297,
        967642,
        1158371,
        1324058,
        1452451,
        1533733,
        1561558,
        1533733,
        1452451,
        1324058,
        1158371,
        967642,
        765297,
        564615,
        377499,
        213473,
        79034,
        -22624,
        -91498,
        -130315,
        -143851,
        -138100,
        -119443,
        -93908,
        -66600,
        -41350,
        -20591,
        -5434,
        4110,
        8810,
        9871,
        8621,
        6269,
        5083,
};

static int32_t buf_l[NUM_COEFF];
static int32_t buf_r[NUM_COEFF];
static int32_t idx = 0;

void codec_audio_process(const int32_t *buf_in[2], int32_t *buf_out[2]) {
    int i;
    int j;
    int k;

    for (i = 0; i < NUM_SAMPLES; i++) {
        buf_l[idx] = buf_in[0][i];
        buf_r[idx] = buf_in[1][i];

        buf_out[0][i] = 0;
        buf_out[1][i] = 0;

        for (j = 0, k = idx; j < NUM_COEFF; j++) {
            buf_out[0][i] += mult_fr32(fir_coeff[j], buf_l[k]);
            buf_out[1][i] += mult_fr32(fir_coeff[j], buf_r[k]);
            k = (k + 1) % NUM_COEFF;
        }
        idx = (idx + 1) % NUM_COEFF;
    }
}