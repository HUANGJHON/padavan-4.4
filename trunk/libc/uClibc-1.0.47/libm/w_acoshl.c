/* Copyright (C) 2011-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@gmail.com>, 2011.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <math.h>
#include "math_private.h"

#if !defined __NO_LONG_DOUBLE_MATH
/* wrapper acosl */
long double
acoshl (long double x)
{
#if defined(__UCLIBC_HAS_FENV__)
  if (__builtin_expect (isless (x, 1.0L), 0) && _LIB_VERSION != _IEEE_)
    /* acosh(x<1) */
    return __kernel_standard_l (x, x, 229);
#endif
  return (long double) __ieee754_acosh ((double) x);
}
#endif
