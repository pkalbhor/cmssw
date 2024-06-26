#ifndef DataFormat_Math_SIMDVec_H
#define DataFormat_Math_SIMDVec_H
//
//  For sustenaibility prefer the use of hte implementation based on the extended vector syntax
//  supported by gcc and clang on all architectures
//
//
#if (defined(__CLING__) || defined(__MIC__) || defined(__NVCC__)) || (__BIGGEST_ALIGNMENT__ < 16)
#elif defined(__INTEL_COMPILER)
// intel compiler does not support the extended vector syntax
#define USE_SSEVECT
#elif defined(__GNUC__) || defined(__clang__)
#if defined(__x86_64__) && defined(__SSE__) && defined(CMS_PREFER_SSEVECT)
#define USE_SSEVECT
#else
#define USE_EXTVECT
#endif
#endif

// to be moved elsewhere
namespace mathSSE {
  //
  template <typename T>
  inline bool samesign(T rh, T lh);

  template <>
  inline bool __attribute__((always_inline)) __attribute__((pure)) samesign<int>(int rh, int lh) {
    int const mask = 0x80000000;
    return ((rh ^ lh) & mask) == 0;
  }

  template <>
  inline bool __attribute__((always_inline)) __attribute__((pure)) samesign<long long>(long long rh, long long lh) {
    long long const mask = 0x8000000000000000LL;
    return ((rh ^ lh) & mask) == 0;
  }

  template <>
  inline bool __attribute__((always_inline)) __attribute__((pure)) samesign<float>(float rh, float lh) {
    union {
      int i;
      float f;
    } a, b;
    a.f = rh;
    b.f = lh;
    return samesign<int>(a.i, b.i);
  }

  template <>
  inline bool __attribute__((always_inline)) __attribute__((pure)) samesign<double>(double rh, double lh) {
    union {
      long long i;
      double f;
    } a, b;
    a.f = rh;
    b.f = lh;
    return samesign<long long>(a.i, b.i);
  }
}  // namespace mathSSE

#if defined(USE_EXTVECT)
#include "DataFormats/Math/interface/ExtVec.h"
#elif defined(USE_SSEVECT)
#if !defined(CMS_PREFER_SSEVECT) || !defined(__INTEL_COMPILER)
#warning "using SSEVECT even if not requirested?????"
#endif
#include "DataFormats/Math/interface/SSEVec.h"
#include "DataFormats/Math/interface/SSERot.h"
#endif

#endif  //
