/******************************************
 * @file amPlatformMath.h
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief Template functions of the math library
 *
 * @note
******************************************/
#pragma once
/***********************
*
*  Includes
*
***********************/
#include "amPrerequisitesUtilities.h"

#include <math.h>
#include <cmath>



namespace amEngineSDK {
  struct AM_UTILITIES_EXPORT amPLatformMath {
    static const float PI;      // = std::tan(1) * 4;
    static const float HALFPI;  // = std::tan(1) * 2;
    static const float TWOPI;   // = std::tan(1) * 8;
    static const float RAD2DEG; // = 57.29577951;
    static const float DEG2RAD; // = 0.017453292519;

    

    ////* Implementations *////

    /***********************
    *  @brief Calculates the sine of the angle
    *
    *  @param the angle to cal the sine of
    *
    *  @return the sine
    ***********************/
    template<typename T>
    static T sin(T theta) {
      /*return theta - (theta * pow(theta, 2) / 6) + (theta * pow(theta, 4) / 120) - (theta * pow(theta, 6) / 5040)
      + (theta * pow(theta, 8) / 362880) - (theta * pow(theta, 10) / 39916800) + (theta * pow(theta, 12) / 6227020800);*/
      return std::sin(theta);
    }

    template<typename T>
    static T cos(T theta) {
      /*return 1 - (theta * theta / 2) + (theta * pow(theta, 3) / 24) - (theta * pow(theta, 5) / 720)
      + (theta * pow(theta, 7) / 40320) - (theta * pow(theta, 9) / 3628800) + (theta * pow(theta, 11) / 479001600);*/
      return std::cos(theta);
    }

    template<typename T>
    static T tan(T theta) {
      //return theta + (theta * pow(theta, 2) * 2 / 6) + (theta * pow(theta, 4) * 16 / 120)
      //  + (theta * pow(theta, 6) * 272 / 5040) + (theta * pow(theta, 8) * 7936 / 362880)
      //  + (theta * pow(theta, 8) * 7936 / 362880)// 2 more iterations

      return std::tan(theta);
    }

    template<typename T>
    static T aSin(T val) {
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
    static T aCos(T val) {
      return std::acos(val);
    }

    template<typename T>
    static T aTan(T val) {
      /*sigma: 0-> inf : ((-1)^n / 2n + 1) * x ^(2n+1)
      return val - ((val * pow(theta, 2)) / 3) + ((val * pow(val, 4)) / 5) - ((val * pow(val, 6)) / 7)
      + ((val * pow(val, 8)) / 9) - ((val * pow(val, 10)) / 11)
      + ((val * pow(val, 12)) / 13) - ((val * pow(val, 14)) / 15);*/
      return std::atan(val);
    }

    template<typename T>
    static T fastSin(T theta) {
      return theta - (theta * pow(theta, 2) / 6) + (theta * pow(theta, 4) / 120) - (theta * pow(theta, 6) / 5040)
        + (theta * pow(theta, 8) / 362880);
    }

    template<typename T>
    static T fastCos(T theta) {
      return 1 - (theta * theta / 2) + (theta * pow(theta, 3) / 24) - (theta * pow(theta, 5) / 720)
        + (theta * pow(theta, 7) / 40320);
    }

    template<typename T>
    static T fastTan(T theta) {
      return theta + (theta * pow(theta, 2) * (2 / 6)) + (theta * pow(theta, 4) * (16 / 120))
        + (theta * pow(theta, 6) * (272 / 5040)) + (theta * pow(theta, 8) * (7936 / 362880));
    }

    template<typename T>
    static T fastASin(T val) {
      // sigma: 0-> inf : x^(2n + 1) * ((2n)!    /    4n * (n!)^2 * (2n + 1))  
      return val/* iter 0*/ + ((val * pow(val, 2)) * (2 / (4 * 1 * 3)))/* iter 1*/
        + ((val * pow(val, 4)) * (24 / (8 * 4 * 5)))/* iter 2*/
        + ((val * pow(val, 6)) * (720 / (12 * 36 * 7)))/* iter 3*/
        + ((val * pow(val, 8)) * (40320 / (16 * 576 * 9)))/* iter 4*/;
    }

    template<typename T>
    static T fastACos(T val) {
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
    static T fastATan(T val) {
      return val - ((val * pow(val, 2)) / 3) + ((val * pow(val, 4)) / 5) - ((val * pow(val, 6)) / 7)
        + ((val * pow(val, 8)) / 9);
    }

    template<typename T>
    static T pow(T val, T exp) {
      return std::pow(val, exp);
    }

    template<typename T>
    static T sqr(T val) {
      return (val * val);
    }

    template<typename T>
    static T sqrt(T val) {
      return std::sqrt(val);
    }

    template<typename T>
    static T invSqrt(T val) {
      return 1 / sqrt(val);
    }

    template<typename T>
    static T logX(T val, T base) {
      return (std::log(val) / std::log(base));
    }

    template<typename T>
    static T logN(T val) {
      return std::log(val);
    }

    template<typename T>
    static T log2(T val) {
      return std::log2(val);
    }

    template<typename T>
    static T log10(T val) {
      return std::log10(val);
    }

    template<typename T>
    static T lerp(T valIni, T valFin, float t) {
      return(valIni + ((valFin - valIni) * t));
    }

    template<typename T>
    static T sLerp(T valIni, T valFin, float t) {
      return std::pow(valIni * (valFin / valIni), t);
    }

    template<typename T>
    static T abs(T value) {
      return (value <= 0) ?  -value : value;
    }

    template<typename T>
    static int32 roundToInt(T val) {
      return static_cast<int32>(val) + 0.5f * (abs(val) / val);
    }

    template<typename T>
    static T floor(T val) {
      return static_cast<int32>(val);
    }

    template<typename T>
    static T ceil(T val) {
      return static_cast<int32>(val) + 9.99999999;
    }

    template<typename T>
    static T fractional(T frac, T* ptr_intpart) {
      return std::modf(frac, ptr_intpart);
    }

    template<typename T>
    static T exp(T val) {
      // Euler
      //return std::powf(2.7182818, val);
      std::exp(val);
    }

    template<typename T>
    static T min(T n1, T n2) {
      return(n1 < n2) ?  n1 : n2;
    }

    template<typename T>
    static T max(T n1, T n2) {
      return(n1 > n2) ? n1 : n2;
    }

    template<typename T>
    static T clamp(T minVal, T maxVal, T val) {
      if (val <= minVal)
        return minVal;
      else if (val >= maxVal)
        return maxVal;
      else
        return val;
    }

    template<typename T>
    static T min3(T n1, T n2, T n3) {
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
    static T max3(T n1, T n2, T n3) {
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

    template<typename T>
    static T factorial(T n) {
      return (n == 0) ? return 1 : return n * factorial(n - 1);
    }

    /***********************
    *
    *  Collisions
    *
    ***********************/

    /***********************
    *
    *  Vector3 collisions
    *
    ***********************/

    static bool
    intersects(const amVector3 &vec, const amFrustrum &f);

    static bool
    intersects(const amVector3 &vec, const amCapsule &c);

    static bool
    intersects(const amVector3 &vec, const amTriangle &t);

    static bool
    intersects(const amVector3 &vec, const amSphere &s);

    static bool
    intersects(const amVector3 &vec, const amOOBB &o);

    static bool
    intersects(const amVector3 & vec, const amAABB &a);

    static bool
    intersects(const amVector3 &vec, const amPlane &p);

    static bool
    intersects(const amVector3 &vec, const amRay &r);

    /***********************
    *
    *  Frustrum collisions
    *
    ***********************/

    static bool
    intersects(const amFrustrum &f, const amCapsule &c);

    static bool
    intersects(const amFrustrum &f, const amTriangle &t);

    static bool
    intersects(const amFrustrum &f, const amSphere &s);

    static bool
    intersects(const amFrustrum &f, const amOOBB &o);

    static bool
    intersects(const amFrustrum &f, const amAABB &a);

    static bool
    intersects(const amFrustrum &f, const amPlane &p);

    static bool
    intersects(const amFrustrum &f, const amRay &r);

    /***********************
    *
    *  Capsule collisions
    *
    ***********************/
    static bool
    intersects(const amCapsule &c, const amTriangle &t);

    static bool
    intersects(const amCapsule &c, const amSphere &s);

    static bool
    intersects(const amCapsule &c, const amOOBB &o);

    static bool
    intersects(const amCapsule &c, const amAABB &a);

    static bool
    intersects(const amCapsule &c, const amPlane &p);

    static bool
    intersects(const amCapsule &c, const amRay &r);

    /***********************
    *
    *  Triangle collisions
    *
    ***********************/

    static bool
    intersects(const amTriangle &t, const amSphere &s);

    static bool
    intersects(const amTriangle &t, const amOOBB &o);

    static bool
    intersects(const amTriangle &t, const amAABB &a);

    static bool
    intersects(const amTriangle &t, const amPlane &p);

    static bool
    intersects(const amTriangle &t, const amRay &r);

    /***********************
    *
    *  Sphere collisions
    *
    ***********************/

    static bool
    intersects(const amSphere &s, const amOOBB &o);

    static bool
    intersects(const amSphere &s, const amAABB &a);

    static bool
    intersects(const amSphere &s, const amPlane &p);

    static bool
    intersects(const amSphere &s, const amRay &r);

    /***********************
    *
    *  OOBB collisions
    *
    ***********************/

    static bool
    intersects(const amOOBB &o, const amAABB &a);

    static bool
    intersects(const amOOBB &o, const amPlane &p);

    static bool
    intersects(const amOOBB &o, const amRay &r);

    /***********************
    *
    *  AABB collisions
    *
    ***********************/

    static bool
    intersects(const amAABB &a, const amPlane &p);

    static bool
    intersects(const amAABB &a, const amRay &r);

    /***********************
    *
    *  Plane <---> Ray collision
    *
    ***********************/

    static bool
    intersects(const amPlane &p, const amRay &r, float dist);

    static bool
    intersects(const amPlane &p, const amRay &r);
  };
}