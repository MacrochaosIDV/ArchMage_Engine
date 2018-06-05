/*doxygen comment here*/
#pragma once
#include "amPrerequisitesUtilities.h"

#include "AABB.h"
#include "Capsule.h"
#include "Frustrum.h"
#include "Matix3x3.h"
#include "OOBB.h"
#include "Plane.h"
#include "Quaternion.h"
#include "Ray.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Vector3.h"

namespace amEngineSDK {
  namespace amMath {
    /*Trigonometric functions*/
    template <typename T>
    const & Sin(const T&);
    template <typename T>
    const & Cos(const T&);
    template <typename T>
    const & Tan(const T&);
    template <typename T>
    const & aSin(const T&);
    template <typename T>
    const & aCos(const T&);
    template <typename T>
    const & aTan(const T&);

    /*Fast Trigonometric functions*/
    template <typename T>
    const & FastSin(const T&);
    template <typename T>
    const & FastCos(const T&);
    template <typename T>
    const & FastTan(const T&);
    template <typename T>
    const & FastaSin(const T&);
    template <typename T>
    const & FastaCos(const T&);
    template <typename T>
    const & FastaTan(const T&);
    template <typename T>

    /*Other Math Functions*/
    const & Sqr(const T&);
    template <typename T>
    const & Sqrt(const T&);
    template <typename T>
    const & Invsqrt(const T&);
    template <typename T>

    template <typename T>
    const & LogN(const T&);
    template <typename T>
    const & Log2(const T&);
    template <typename T>
    const & Log10(const T&);

    template <typename T>
    const float& Lerp(const float& n, const float& n2);
    template <typename T>
    const float& sLerp(const float& n, const float& n2); // Spherical interpolation

    template <typename T>
    const & Abs(const T&); // Absolute
    template <typename T>
    const & Round(const T&);
    template <typename T>
    const & Floor(const T&);
    template <typename T>
    const & Ceil(const T&);
    template <typename T>
    const & Fractional(const T&);
    template <typename T>
    const & Exp(const T&);


    /*Minimums, Maxes & Clamps Functions*/ 
    const float& Min(const float& n1, const float& n2);
    const float& Max(const float& n1, const float& n2);
    const float& Clamp(const float& n1, const float& n2);

    const float& Min3(const float& n1, const float& n2, const float& n3);
    const float& Max3(const float& n1, const float& n2, const float& n3);
    const float& Clamp3(const float& n1, const float& n2, const float& n3);

    /*Collision Functions*/

    template<typename T>
    const & Sin(const T &) {
      return T - T * T*T / 6 + T * T*T*T*T / 120 - T * T*T*T*T*T*T / 5040 + T * T*T*T*T*T*T*T*T / 362880
        - T * T*T*T*T*T*T*T*T*T*T / 39916800 + T * T*T*T*T*T*T*T*T*T*T*T*T / 6227020800;
    }

    template<typename T>
    const & Cos(const T &) {
      return 1 - T * T / 2 + T * T*T*T / 24 - T * T*T*T*T*T / 720 + T * T*T*T*T*T*T*T / 40320 - T * T*T*T*T*T*T*T*T*T / 3628800
        + T * T*T*T*T*T*T*T*T*T*T*T / 479001600;
    }

    template<typename T>
    const & Tan(const T &) {
      return T + T * T*T * 2 / 6 + T * T*T*T*T * 16 / 120 + T * T*T*T*T*T*T * 272 / 5040 + +T * T*T*T*T*T*T*T*T * 7936 / 362880;
    }

    template<typename T>
    const & aSin(const T &) {
      // sigma: 0-> inf : ((2n)!/ 4n * (n!)^2 * (2n + 1)) * x^(2n + 1)
      return T + T * T*T*(2 / (8 * 4 * 3)) + T * T*T*T*T * 720 / (12 * 36 * 5) + T * T*T*T*T*T*T * 40320 / (16 * 576 * 7);
    }

    template<typename T>
    const & aCos(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & aTan(const T &) {
      //sigma: 0-> inf : ((-1)^n / 2n + 1) * x ^(2n+1)
      return T - T * T*T / 3 + T * T*T*T*T / 5 - T * T*T*T*T*T*T / 7 + T * T*T*T*T*T*T*T*T / 9 - T * T*T*T*T*T*T*T*T*T*T / 11
        + T * T*T*T*T*T*T*T*T*T*T*T*T / 13 - T * T*T*T*T*T*T*T*T*T*T*T*T*T*T / 15;
    }

    template<typename T>
    const & FastSin(const T &) {
      return T - T * T*T / 6 + T * T*T*T*T / 120 - T * T*T*T*T*T*T / 5040 + T * T*T*T*T*T*T*T*T / 362880;
    }

    template<typename T>
    const & FastCos(const T &) {
      return 1 - T * T / 2 + T * T*T*T / 34 - T * T*T*T*T*T / 720 + T * T*T*T*T*T*T*T / 40320
    }

    template<typename T>
    const & FastTan(const T &) {
      return T + T * T*T * 2 / 6 + T * T*T*T*T * 16 / 120 + T * T*T*T*T*T*T * 272 / 5040 + +T * T*T*T*T*T*T*T*T*7936 / 362880;
    }

    template<typename T>
    const & FastaSin(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & FastaCos(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & FastaTan(const T &) {
      return T - T * T*T / 3 + T * T*T*T*T / 5 - T * T*T*T*T*T*T / 7 + T * T*T*T*T*T*T*T*T / 9 - T * T*T*T*T*T*T*T*T*T*T / 11;
    }

    template<typename T>
    const & Sqr(const T &) {
      return T * T;
    }

    template<typename T>
    const & Sqrt(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & Invsqrt(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & LogN(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & Log2(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & Log10(const T &) {
      // TODO: insert return statement here
    }
  
    template<typename T>
    const & Abs(const T &) {
      (T >= 0) ? return T : return -T;
    }

    template<typename T>
    const & Round(const T &) {
      return static_cast(int)T + 0.5f;
    }

    template<typename T>
    const & Floor(const T &) {
      return static_cast(int)T;
    }

    template<typename T>
    const & Ceil(const T &) {
      return static_cast(int)T + 9.9999f;
    }

    template<typename T>
    const & Fractional(const T &) {
      // TODO: insert return statement here
    }

    template<typename T>
    const & Exp(const T &) {
      // TODO: insert return statement here
    }

  }
}

