/*doxygen comment here*/
#pragma once
#include "amPrerequisitesUtilities.h"

#include <math.h>
#include <cmath>

#include "amAABB.h"
#include "amBox.h"
#include "amCapsule.h"
#include "amFrustrum.h"
#include "amMatix4x4.h"
#include "amOOBB.h"
#include "amPlane.h"
#include "amQuaternion.h"
#include "amRay.h"
#include "amSphere.h"
#include "amTriangle.h"



namespace amEngineSDK {
  namespace amMath {
    static const float PI = std::tan(1) * 4;
    static const float HALFPI = std::tan(1) * 2;
    static const float TWOPI = 6.28318530;
    static const float RAD2DEG = 57.29577951;
    static const float DEG2RAD = 0.017453292519;

    ////* Trigonometric functions */
    //template<typename T>
    //float
    //sin(T theta);

    //template<typename T>
    //float
    //cos(T theta);

    //template<typename T>
    //float
    //tan(T theta);

    //template <typename T>
    //T aSin(T val);

    //template <typename T>
    //T aCos(T val);

    //template <typename T>
    //T aTan(T val);

    ////* Fast Trigonometric functions */
    //template <typename T>
    //T fastSin(T theta);

    //template <typename T>
    //T fastCos(T theta);

    //template <typename T>
    //T fastTan(T theta);

    //template <typename T>
    //T fastASin(T val);

    //template <typename T>
    //T fastACos(T val);

    //template <typename T>
    //T fastATan(T val);

    ////* Other Math Functions */
    //template <typename T>
    //T sqr(T val);

    //template <typename T>
    //T sqrt(T val);

    //template <typename T>
    //T invSqrt(T val);
    //
    //template <typename T>
    //T logX(T val, T base);

    //template<typename T>
    //T logN(T val);

    //template <typename T>
    //T log2(T val);

    //template <typename T>
    //T log10(T val);

    //template <typename T>
    //T lerp(T valIni, T valFin, float t);

    //template <typename T>
    //T sLerp(T valIni, T valFin, float t); // Spherical interpolation

    //template<typename T>
    //T abs(T value); // Absolute
    //
    //template <typename T>
    //int32 roundToInt(T val);

    //template <typename T>
    //T floor(T val);

    //template <typename T>
    //T ceil(T val);

    //template <typename T>
    //float fractional(T val); // Returns the fractional part of a float

    //template <typename T>
    //float exp(T val);

    ////* Minimums, Maxes & Clamps Functions */
    //template <typename T>
    //T min(T n1, T n2);
    //template <typename T>
    //T max(T n1, T n2);
    //template <typename T>
    //T clamp(T minVal, T maxVal, T val);

    //template <typename T>
    //T min3(T n1, T n2, T n3);
    //template <typename T>
    //T max3(T n1, T n2, T n3);

    //

   ////* Implementations */

    template<typename T>
    T sin(T theta) {
      /*return theta - (theta * pow(theta, 2) / 6) + (theta * pow(theta, 4) / 120) - (theta * pow(theta, 6) / 5040) 
        + (theta * pow(theta, 8) / 362880) - (theta * pow(theta, 10) / 39916800) + (theta * pow(theta, 12) / 6227020800);*/
      return std::sin(theta);
    }

    template<typename T>
    T cos(T theta) {
      /*return 1 - (theta * theta / 2) + (theta * pow(theta, 3) / 24) - (theta * pow(theta, 5) / 720) 
        + (theta * pow(theta, 7) / 40320) - (theta * pow(theta, 9) / 3628800) + (theta * pow(theta, 11) / 479001600);*/
      return std::cos(theta);
    }

    template<typename T>
    T tan(T theta) {
      //return theta + (theta * pow(theta, 2) * 2 / 6) + (theta * pow(theta, 4) * 16 / 120)
      //  + (theta * pow(theta, 6) * 272 / 5040) + (theta * pow(theta, 8) * 7936 / 362880)
      //  + (theta * pow(theta, 8) * 7936 / 362880)// 2 more iterations

      return std::tan(theta);
    }

    template<typename T>
    T aSin(T val) {
      // sigma: 0-> inf : x^(2n + 1) * ((2n)!    /    4n * (n!)^2 * (2n + 1))  
      //return val/* iter 0*/ + ((val * pow(val, 2)) * (2 / (4 * 1 * 3)))/* iter 1*/
      //  + ((val * pow(val, 4)) * (24 / (8 * 4 * 5)))/* iter 2*/
      //  + ((val * pow(val, 6)) * (720 / (12 * 36 * 7)))/* iter 3*/
      //  + ((val * pow(val, 8)) * (40320 / (16 * 576 * 9)))/* iter 4*/
      //  + ((val * pow(val, 10)) * (3628800 / (20 * 14400 * 11)))/* iter 5*/
      //  + ((val * pow(val, 12)) * (479001600 / (24 * 518400 * 13)));/* iter 6*/
      return std::asin(val);
    }

    template<typename T>
    T aCos(T val) {
      return std::acos(val);
    }

    template<typename T>
    T aTan(T val) {
      //sigma: 0-> inf : ((-1)^n / 2n + 1) * x ^(2n+1)
      /*return val - ((val * pow(theta, 2)) / 3) + ((val * pow(val, 4)) / 5) - ((val * pow(val, 6)) / 7)
        + ((val * pow(val, 8)) / 9) - ((val * pow(val, 10)) / 11)
        + ((val * pow(val, 12)) / 13) - ((val * pow(val, 14)) / 15);*/
      return std::atan(val);
    }

    template<typename T>
    T fastSin(T theta) {
      return theta - (theta * pow(theta, 2) / 6) + (theta * pow(theta, 4) / 120) - (theta * pow(theta, 6) / 5040)
        + (theta * pow(theta, 8) / 362880);
    }

    template<typename T>
    T fastCos(T theta) {
      return 1 - (theta * theta / 2) + (theta * pow(theta, 3) / 24) - (theta * pow(theta, 5) / 720)
        + (theta * pow(theta, 7) / 40320);
    }

    template<typename T>
    T fastTan(T theta) {
      return theta + (theta * pow(theta, 2) * 2 / 6) + (theta * pow(theta, 4) * 16 / 120)
        + (theta * pow(theta, 6) * 272 / 5040) + (theta * pow(theta, 8) * 7936 / 362880);
    }

    template<typename T>
    T fastASin(T val) {
      // sigma: 0-> inf : x^(2n + 1) * ((2n)!    /    4n * (n!)^2 * (2n + 1))  
      return val/* iter 0*/ + ((val * pow(val, 2)) * (2 / (4 * 1 * 3)))/* iter 1*/
        + ((val * pow(val, 4)) * (24 / (8 * 4 * 5)))/* iter 2*/
        + ((val * pow(val, 6)) * (720 / (12 * 36 * 7)))/* iter 3*/
        + ((val * pow(val, 8)) * (40320 / (16 * 576 * 9)))/* iter 4*/;
    }

    template<typename T>
    T fastACos(T val) {
      float root = sqrt(abs(1.0f - val));
      float res = -0.0187295f;
      res *= val;
      res += 0.0742610f;
      res *= val;
      res -= 0.2121144f;
      res += 1.5706288f;
      return res * root;
    }

    template<typename T>
    T fastATan(T val) {
      return val - ((val * pow(val, 2)) / 3) + ((val * pow(val, 4)) / 5) - ((val * pow(val, 6)) / 7)
        + ((val * pow(val, 8)) / 9);
    }

    template<typename T>
    T pow(T val, T exp) {
      return std::pow(val, exp);
    }

    template<typename T>
    T sqr(T val) {
      return (val * val);
    }

    template<typename T>
    T sqrt(T val) {
      return std::sqrt(val);
    }
    
    template<typename T>
    T invSqrt(T val) {
      return 1 / sqrt(val);
    }

    template<typename T>
    T logX(T val, T base) {
      return (std::log(val) / std::log(base));
    }

    template<typename T>
    T logN(T val) {
      return std::log(val);
    }

    template<typename T>
    T log2(T val) {
      return std::log2(val);
    }

    template<typename T>
    T log10(T val) {
      return std::log10(val);
    }

    template<typename T>
    T lerp(T valIni, T valFin, float t) {
      return(valIni + ((valFin - valIni) * t));
    }

    template<typename T>
    T sLerp(T valIni, T valFin, float t) {
      return std::pow(valIni*(valFin / valIni), t);
    }
  
    template<typename T>
    T abs(T value) {
      (value <= 0) ? return -value : return value;
    }

    template<typename T>
    int32 roundToInt(T val) {
      return static_cast(int32)val + 0.5f;
    }

    template<typename T>
    T floor(T val) {
      return static_cast(int32)val;
    }

    template<typename T>
    T ceil(T val) {
      return static_cast(int32)val + 9.99999999;
    }

    template<typename T>
    T fractional(T val) {
      return val % 1;
    }

    template<typename T>
    T exp(T val) { 
      // Euler
      //return std::powf(2.7182818, val);
      std::exp(val);
    }

    template<typename T>
    T min(T n1, T n2) {
      (n1 < n2) ? return n1 : return n2;
    }

    template<typename T>
    T max(T n1, T n2) {
      (n1 > n2) ? return n1 : return n2;
    }

    template<typename T>
    T clamp(T minVal, T maxVal, T val) {
      if (val <= minVal)
        return minVal;
      else if (val >= maxVal)
        return maxVal;
      else
        return val;
    }

    template<typename T>
    T min3(T n1, T n2, T n3) {
      if (n1 < n2) {
        if (n1 < n3)
          return n1;
        else
          return n3;
      }
      else {
        if (n2 < n3)
          return n2;
        else
          return n3;
      }
    }

    template<typename T>
    T max3(T n1, T n2, T n3) {
      if (n1 > n2) {
        if (n1 > n3)
          return n1;
        else
          return n3;
      }
      else {
        if (n2 > n3)
          return n2;
        else
          return n3;
      }
    }

    /***********************
    *  @brief Collisions
    ***********************/

  }
}

