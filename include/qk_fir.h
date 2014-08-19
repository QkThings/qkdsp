#ifndef QK_FIR_H
#define QK_FIR_H

/** \addtogroup QkFIR
 * @brief Finite Impulse Response
 *  @{
 */

/**
 * Finite Impulse Response (FIR) filter
 */
typedef struct qk_fir
{
  uint16_t N;
  const int16_t *b; // Coefficients (N+1)
  int16_t *x;       // Input sampels buffer (N)
  uint16_t _head;
} qk_fir;

/**
 * @brief .
 */
void qk_fir_setup(qk_fir *f, int N, const int16_t *b, int16_t *x);

/**
 * @brief .
 */
void qk_fir_init(qk_fir *f, int16_t initial);

/**
 * @brief .
 */
int16_t qk_fir_filter(qk_fir *f, int16_t new_sample);

/** @}*/

#endif
