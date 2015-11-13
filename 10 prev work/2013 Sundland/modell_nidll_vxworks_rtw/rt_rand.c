/*
 * rt_rand.c
 *
 * Real-Time Workshop code generation for Simulink model "modell.mdl".
 *
 * Model Version              : 1.149
 * Real-Time Workshop version : 7.3  (R2009a)  15-Jan-2009
 * C source code generated on : Tue Mar 12 15:06:47 2013
 *
 * Target selection: nidll_vxworks.tlc
 *   Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 */

#include "rt_rand.h"

/* Function: rt_Urand =======================================================
 * Abstract:
 *   Uniform random number generator (random number between 0 and 1)
 *
 *   #define IA      16807                      magic multiplier = 7^5
 *   #define IM      2147483647                 modulus = 2^31-1
 *   #define IQ      127773                     IM div IA
 *   #define IR      2836                       IM modulo IA
 *   #define S       4.656612875245797e-10      reciprocal of 2^31-1
 *
 *   test = IA * (seed % IQ) - IR * (seed/IQ)
 *   seed = test < 0 ? (test + IM) : test
 *   return (seed*S)
 *
 */
real_T rt_Urand(uint32_T *seed)        /* pointer to a running seed */
{
  uint32_T hi = *seed / 127773U;
  uint32_T lo = *seed % 127773U;
  int32_T test = (16807 * lo) - (2836 * hi);/* never overflows      */
  *seed = ((test < 0) ? (uint32_T)(test + 2147483647) : (uint32_T)test);
  return ((real_T) (*seed * 4.656612875245797e-10));
}                                      /* end rt_Urand */

/* Function: rt_NormalRand ====================================================
 * Abstract:
 *      Normal (Gaussian) random number generator also known as mlUrandn in
 *      MATLAB V4.
 */
real_T rt_NormalRand(uint32_T *seed)
{
  real_T sr, si, t;
  do {
    sr = (2.0 * rt_Urand(seed)) - 1.0;
    si = (2.0 * rt_Urand(seed)) - 1.0;
    t = (sr * sr) + (si * si);
  } while (t > 1.0);

  return(sr * sqrt((-2.0 * log(t)) / t));
}                                      /* end rt_NormalRand */
