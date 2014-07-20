#include "qk_dsp.h"
#include <string.h>

void qk_avg_ma_setup(qk_avg_ma *f, int16_t *w, int16_t N)
{
  f->w = w;
  f->N = N;
  f->_yn = 0;
  f->_head = 0;
  f->_mode = QK_AVG_MA_MODE_NONRECURSIVE;
  memset(w, 0, N*sizeof(int16_t));
}
void qk_avg_ma_init(ma_t *f, int16_t initial)
{
  uint16_t i;
  f->_yn = initial;
  for(i=0; i<f->N; i++)
    f->w[i] = initial;
}
void qk_avg_ma_set_mode(qk_avg_ma* f, ma_mode_t mode)
{
  f->_mode = mode;
}
int16_t ma_filter(qk_avg_ma *f, int16_t new_sample)
{
  if(f->_mode == QK_AVG_MA_MODE_RECURSIVE)
  {
    f->_yn = new_sample/f->N - f->w[f->_head]/f->N + f->_yn;
    f->w[f->_head] = new_sample;
  }
  else
  {
    uint8_t i,cnt;
    uint32_t buf;
    f->w[f->_head] = new_sample;
    for(buf=0,cnt=0,i=f->_head; cnt < f->N; i = (i+1) % f->N, cnt++)
      buf += f->w[i];
    buf /= f->N;
    f->_yn = buf;
  }

  f->_head = (f->_head+1) % f->N;
}

void qk_avg_ema_setup(qk_avg_ema *f, int16_t alpha)
{
  f->alpha = alpha;
  f->yn = 0;
}

void qk_avg_ema_init(qk_avg_ema *f, int16_t init)
{
  f->yn = init;
}

int16_t qk_avg_ema_filter(qk_avg_ema *f, int16_t new_sample)
{
  int32_t tmp;
  if(new_sample != f->yn)
  {
    tmp = (int32_t)QK_DSP_MULSS(new_sample,(f->alpha));
    tmp += (int32_t)QK_DSP_MULSS(f->yn,((1<<15)-f->alpha));
    f->yn = (int16_t)((tmp + (1<<14)) >> 15);
  }
  return f->yn;
}
