#ifndef QK_AVG_H
#define QK_AVG_H

/*******************************************************************************
  Moving Average (MA)
 ******************************************************************************/
typedef enum qk_avg_ma_mode
{
  QK_AVG_MA_MODE_NONRECURSIVE = 0,
  QK_AVG_MA_MODE_RECURSIVE
} ma_mode_t;

typedef struct qk_avg_ma {
  int16_t *w; // Window (N)
  uint16_t N;
  int16_t _yn;
  uint16_t _head;
  uint8_t _mode;
} qk_avg_ma;
void qk_avg_ma_setup(qk_avg_ma *f, int16_t *w, int16_t N);
void qk_avg_ma_init(qk_avg_ma *f, int16_t initial);
void qk_avg_ma_setMode(qk_avg_ma *f, ma_mode_t mode);
int16_t qk_avg_ma_filter(qk_avg_ma *f, int16_t new_sample);

/*******************************************************************************
  Exponential Moving Average (EMA)
 ******************************************************************************/
typedef struct qk_avg_ema {
  int16_t alpha;  // alpha=2/(N+1)
  int16_t yn;    // Last ouput
} qk_avg_ema;

void qk_avg_ema_setup(qk_avg_ema *f, int16_t alfa);
void qk_avg_ema_init(qk_avg_ema *f, int16_t init);
int16_t qk_avg_ema_filter(qk_avg_ema *f, int16_t new_sample);

#endif
