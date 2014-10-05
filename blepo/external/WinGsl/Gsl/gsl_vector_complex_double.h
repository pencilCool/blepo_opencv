/* vector/gsl_vector_complex_double.h
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

#ifndef __GSL_VECTOR_COMPLEX_DOUBLE_H__
#define __GSL_VECTOR_COMPLEX_DOUBLE_H__

#include <stdlib.h>
#include <gsl/gsl_types.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_check_range.h>
#include <gsl/gsl_vector_double.h>
#include <gsl/gsl_vector_complex.h>
#include <gsl/gsl_block_complex_double.h>

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

typedef struct 
{
  size_t size;
  size_t stride;
  double *data;
  gsl_block_complex *block;
  int owner;
} gsl_vector_complex;

typedef struct
{
  gsl_vector_complex vector;
} _gsl_vector_complex_view;

typedef _gsl_vector_complex_view gsl_vector_complex_view;

typedef struct
{
  gsl_vector_complex vector;
} _gsl_vector_complex_const_view;

typedef const _gsl_vector_complex_const_view gsl_vector_complex_const_view;

/* Allocation */

WINGSLDLL_API gsl_vector_complex *gsl_vector_complex_alloc (const size_t n);
WINGSLDLL_API gsl_vector_complex *gsl_vector_complex_calloc (const size_t n);

WINGSLDLL_API gsl_vector_complex *
gsl_vector_complex_alloc_from_block (gsl_block_complex * b, 
                                           const size_t offset, 
                                           const size_t n, 
                                           const size_t stride);

WINGSLDLL_API gsl_vector_complex *
gsl_vector_complex_alloc_from_vector (gsl_vector_complex * v, 
                                             const size_t offset, 
                                             const size_t n, 
                                             const size_t stride);

WINGSLDLL_API void gsl_vector_complex_free (gsl_vector_complex * v);

/* Views */

WINGSLDLL_API _gsl_vector_complex_view
gsl_vector_complex_view_array (double *base,
                                     size_t n);

WINGSLDLL_API _gsl_vector_complex_view
gsl_vector_complex_view_array_with_stride (double *base,
                                                 size_t stride,
                                                 size_t n);

WINGSLDLL_API _gsl_vector_complex_const_view
gsl_vector_complex_const_view_array (const double *base,
                                           size_t n);

WINGSLDLL_API _gsl_vector_complex_const_view
gsl_vector_complex_const_view_array_with_stride (const double *base,
                                                       size_t stride,
                                                       size_t n);

WINGSLDLL_API _gsl_vector_complex_view
gsl_vector_complex_subvector (gsl_vector_complex *base,
                                         size_t i, 
                                         size_t n);


WINGSLDLL_API _gsl_vector_complex_view 
gsl_vector_complex_subvector_with_stride (gsl_vector_complex *v, 
                                                size_t i, 
                                                size_t stride, 
                                                size_t n);

WINGSLDLL_API _gsl_vector_complex_const_view
gsl_vector_complex_const_subvector (const gsl_vector_complex *base,
                                               size_t i, 
                                               size_t n);


WINGSLDLL_API _gsl_vector_complex_const_view 
gsl_vector_complex_const_subvector_with_stride (const gsl_vector_complex *v, 
                                                      size_t i, 
                                                      size_t stride, 
                                                      size_t n);

WINGSLDLL_API _gsl_vector_view
gsl_vector_complex_real (gsl_vector_complex *v);

WINGSLDLL_API _gsl_vector_view 
gsl_vector_complex_imag (gsl_vector_complex *v);

WINGSLDLL_API _gsl_vector_const_view
gsl_vector_complex_const_real (const gsl_vector_complex *v);

WINGSLDLL_API _gsl_vector_const_view 
gsl_vector_complex_const_imag (const gsl_vector_complex *v);


/* Operations */

WINGSLDLL_API gsl_complex 
gsl_vector_complex_get (const gsl_vector_complex * v, const size_t i);

WINGSLDLL_API void gsl_vector_complex_set (gsl_vector_complex * v, const size_t i,
                                   gsl_complex z);

WINGSLDLL_API gsl_complex 
*gsl_vector_complex_ptr (gsl_vector_complex * v, const size_t i);

WINGSLDLL_API const gsl_complex 
*gsl_vector_complex_const_ptr (const gsl_vector_complex * v, const size_t i);

WINGSLDLL_API void gsl_vector_complex_set_zero (gsl_vector_complex * v);
WINGSLDLL_API void gsl_vector_complex_set_all (gsl_vector_complex * v,
                                       gsl_complex z);
WINGSLDLL_API int gsl_vector_complex_set_basis (gsl_vector_complex * v, size_t i);

WINGSLDLL_API int gsl_vector_complex_fread (FILE * stream,
                                    gsl_vector_complex * v);
WINGSLDLL_API int gsl_vector_complex_fwrite (FILE * stream,
                                     const gsl_vector_complex * v);
WINGSLDLL_API int gsl_vector_complex_fscanf (FILE * stream,
                                     gsl_vector_complex * v);
WINGSLDLL_API int gsl_vector_complex_fprintf (FILE * stream,
                                      const gsl_vector_complex * v,
                                      const char *format);

WINGSLDLL_API int gsl_vector_complex_memcpy (gsl_vector_complex * dest, const gsl_vector_complex * src);

WINGSLDLL_API int gsl_vector_complex_reverse (gsl_vector_complex * v);

WINGSLDLL_API int gsl_vector_complex_swap (gsl_vector_complex * v, gsl_vector_complex * w);
WINGSLDLL_API int gsl_vector_complex_swap_elements (gsl_vector_complex * v, const size_t i, const size_t j);

WINGSLDLL_API int gsl_vector_complex_isnull (const gsl_vector_complex * v);

#if HAVE_INLINE

extern inline
gsl_complex
gsl_vector_complex_get (const gsl_vector_complex * v,
                              const size_t i)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      gsl_complex zero = {{0, 0}};
      GSL_ERROR_VAL ("index out of range", GSL_EINVAL, zero);
    }
#endif
  return *GSL_COMPLEX_AT (v, i);
}

extern inline
void
gsl_vector_complex_set (gsl_vector_complex * v,
                              const size_t i, gsl_complex z)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      GSL_ERROR_VOID ("index out of range", GSL_EINVAL);
    }
#endif
  *GSL_COMPLEX_AT (v, i) = z;
}

extern inline
gsl_complex *
gsl_vector_complex_ptr (gsl_vector_complex * v,
                              const size_t i)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      GSL_ERROR_NULL ("index out of range", GSL_EINVAL);
    }
#endif
  return GSL_COMPLEX_AT (v, i);
}

extern inline
const gsl_complex *
gsl_vector_complex_const_ptr (const gsl_vector_complex * v,
                                    const size_t i)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      GSL_ERROR_NULL ("index out of range", GSL_EINVAL);
    }
#endif
  return GSL_COMPLEX_AT (v, i);
}


#endif /* HAVE_INLINE */

__END_DECLS

#endif /* __GSL_VECTOR_COMPLEX_DOUBLE_H__ */