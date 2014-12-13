/* -----------------------------------------------------------------------
   closures_va.c

   Code to access variadic arguments inside of closures.

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   ``Software''), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED ``AS IS'', WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
   ----------------------------------------------------------------------- */

#include <ffi.h>
#include <ffi_common.h>

#if FFI_CLOSURES
#  if __STDC_VERSION__ >= 199901L

/* Note: int8_t, uint8_t, int16_t and uint16_t are promoted to int in '...'
 */
int8_t
ffi_closure_va_sint8(ffi_cif *cif) {
  return ffi_closure_va_sint32(cif);
}

uint8_t
ffi_closure_va_uint8(ffi_cif *cif) {
  return ffi_closure_va_uint32(cif);
}

int16_t
ffi_closure_va_sint16(ffi_cif *cif) {
  return ffi_closure_va_sint32(cif);
}

uint16_t
ffi_closure_va_uint16(ffi_cif *cif) {
  return ffi_closure_va_uint32(cif);
}

int32_t
ffi_closure_va_sint32(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_sint32, &val));
  return *(int32_t *)val;
}

uint32_t
ffi_closure_va_uint32(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_uint32, &val));
  return *(uint32_t *)val;
}

int64_t
ffi_closure_va_sint64(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_sint64, &val));
  return *(int64_t *)val;
}

uint64_t
ffi_closure_va_uint64(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_uint64, &val));
  return *(uint64_t *)val;
}
#  endif /* __STDC_VERSION__ >= 199901L */

#  if !defined (LIBFFI_HIDE_BASIC_TYPES)

/* Note: char, uchar, short and ushort are promoted to int in '...'
 */
signed char
ffi_closure_va_schar(ffi_cif *cif) {
  return ffi_closure_va_sint(cif);
}

unsigned char
ffi_closure_va_uchar(ffi_cif *cif) {
  return ffi_closure_va_uint(cif);
}

short
ffi_closure_va_sshort(ffi_cif *cif) {
  return ffi_closure_va_sint(cif);
}

unsigned short
ffi_closure_va_ushort(ffi_cif *cif) {
  return ffi_closure_va_uint(cif);
}

int
ffi_closure_va_sint(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_sint, &val));
  return *(int *)val;
}

unsigned int
ffi_closure_va_uint(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_uint, &val));
  return *(unsigned int *)val;
}

long
ffi_closure_va_slong(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_slong, &val));
  return *(long *)val;
}

unsigned long
ffi_closure_va_ulong(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_ulong, &val));
  return *(unsigned long *)val;
}

#  endif /* ! LIBFFI_HIDE_BASIC_TYPES */

/* Note: float is promoted to double when passed through '...'
 */

float
ffi_closure_va_float(ffi_cif *cif) {
  return ffi_closure_va_double(cif);
}

double
ffi_closure_va_double(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_double, &val));
  return *(double *)val;
}

void *
ffi_closure_va_pointer(ffi_cif *cif) {
  void **val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_pointer, (void **)&val));
  return *val;
}

#  if HAVE_LONG_DOUBLE
long double
ffi_closure_va_longdouble(ffi_cif *cif) {
  void *val;
  FFI_RUN_OK(ffi_closure_va_arg(cif, &ffi_type_longdouble, &val));
  return *(long double *)val;
}
#  endif /* HAVE_LONG_DOUBLE */
#endif /* FFI_CLOSURES */
