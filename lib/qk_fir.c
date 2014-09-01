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

void qk_fir_setup(qk_fir *f, int N, const int16_t *b, int16_t *x)
{
  f->N = N;
  f->b = b;
  f->x = x;
  f->_head = N-1;
  memset(x, 0, N*sizeof(int16_t));
}
void qk_fir_init(qk_fir *f, int16_t initial)
{
  memset(f->x, initial, f->N*sizeof(int16_t));
}
int16_t qk_fir_filter(qk_fir *f, int16_t new_sample)
{
  uint16_t i,j;
  int32_t tmp;
  int16_t yn = 0;

  tmp = (int32_t)QK_DSP_MULSS(f->b[0], new_sample);
  for(i=1, j=(f->_head+1)%(f->N); i <= f->N; i++, j=(j+1)%(f->N))
  {
    tmp += (int32_t)QK_DSP_MULSS(f->b[i],f->x[j]);
  }
  yn += (int16_t)((tmp + (1<<14)) >> 15);

  f->x[f->_head] = new_sample;
  if(f->_head == 0)
    f->_head = f->N-1;
  else
    f->_head--;
  return yn;
}
