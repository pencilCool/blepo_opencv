/* err/gsl_test.h
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman, Brian Gough
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __GSL_TEST_H__
#define __GSL_TEST_H__

#include "..\\WinGslDll.inl"

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

WINGSLDLL_API void
  gsl_test (int status, const char *test_description, ...);

WINGSLDLL_API void
gsl_test_rel (double result, double expected, double relative_error,
              const char *test_description, ...) ;

WINGSLDLL_API void
gsl_test_abs (double result, double expected, double absolute_error,
              const char *test_description, ...) ;

WINGSLDLL_API void
gsl_test_factor (double result, double expected, double factor,
                 const char *test_description, ...) ;

WINGSLDLL_API void
gsl_test_int (int result, int expected, const char *test_description, ...) ;

WINGSLDLL_API void
gsl_test_str (const char * result, const char * expected, 
              const char *test_description, ...) ;

WINGSLDLL_API void
  gsl_test_verbose (int verbose) ;

WINGSLDLL_API int
  gsl_test_summary (void) ;


__END_DECLS

#endif /* __GSL_TEST_H__ */