#ifndef QK_AVG_H
#define QK_AVG_H

/** \addtogroup QkAvg
 * @brief Averagers
 *  @{
 */

/*******************************************************************************
  Moving Average (MA)
 ******************************************************************************/
/**
 * Moving average filter mode
 */
typedef enum
{
  QK_AVG_MA_MODE_NONRECURSIVE = 0,
  QK_AVG_MA_MODE_RECURSIVE
} qk_avg_ma_mode;

/**
 * Moving average filter
 */
typedef struct
{
  int16_t *w; // Window (N)
  uint16_t N;
  int16_t _yn;
  uint16_t _head;
  uint8_t _mode;
} qk_avg_ma;

/**
 * @brief .
 */
void qk_avg_ma_setup(qk_avg_ma *f, int16_t *w, int16_t N);

/**
 * @brief .
 */
void qk_avg_ma_init(qk_avg_ma *f, int16_t initial);

/**
 * @brief .
 */
void qk_avg_ma_setMode(qk_avg_ma *f, qk_avg_ma_mode mode);

/**
 * @brief .
 */
int16_t qk_avg_ma_filter(qk_avg_ma *f, int16_t new_sample);

/*******************************************************************************
  Exponential Moving Average (EMA)
 ******************************************************************************/

/**
 * Exponential Moving Average
 */
typedef struct
{
  int16_t alpha;  // alpha=2/(N+1)
  int16_t yn;    // Last ouput
} qk_avg_ema;

/**
 * @brief .
 */
void qk_avg_ema_setup(qk_avg_ema *f, int16_t alfa);

/**
 * @brief .
 */
void qk_avg_ema_init(qk_avg_ema *f, int16_t init);

/**
 * @brief .
 */
int16_t qk_avg_ema_filter(qk_avg_ema *f, int16_t new_sample);

/** @}*/

#endif
