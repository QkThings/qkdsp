/*
 * QkThings LICENSE
 * The open source framework and modular platform for smart devices.
 * Copyright (C) 2014 <http://qkthings.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

void qk_iir_setup(qk_iir *f, const int16_t *b, const int16_t *a, int16_t *x, int16_t *y)
{
  f->N = 2; // Biquad section
  f->b = b;
  f->a = a;
  f->x = x;
  f->y = y;
  f->gain = 1;
  f->_head = 0;
  memset(x, 0, f->N*sizeof(int16_t));
  memset(y, 0, f->N*sizeof(int16_t));
}

void iir_init(qk_iir *f, int16_t initial)
{
  uint16_t i;
  for(i=0; i < (f->N); i++)
    f->x[i] = initial;
  for(i=0; i < (f->N); i++)
    f->y[i] = 0;
}

void iir_setGain(qk_iir *f, int16_t gain)
{
  f->gain = gain;
}

void iir_setQFormat(qk_iir *f, uint8_t format)
{
  f->format = format;
}

int16_t iir_filter(qk_iir *f, int16_t new_sample)
{
  uint16_t i,j;
  int16_t yn = 0;
  int32_t tmp = 0;

  tmp = (int32_t)QK_DSP_MULSS(f->b[0],new_sample);

  for(i = f->_head, j=1; j <= f->N; j++)
  {
    if(i==0)
      i = f->N-1;
    else
      i--;
    tmp += (int32_t)QK_DSP_MULSS(f->b[j],f->x[i]);
    tmp -= (int32_t)QK_DSP_MULSS(f->a[j],f->y[i]);
  }
  tmp = (tmp + (1<<f->format-1)) >> f->format;

  yn = (int16_t)tmp;

  f->x[f->_head] = new_sample;
  f->y[f->_head] = yn;
  f->_head = (f->_head + 1) % f->N;

  return yn;
}
