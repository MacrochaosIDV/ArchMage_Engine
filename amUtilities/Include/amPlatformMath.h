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
#include <cmath>

#include "amPrerequisitesUtilities.h"

namespace amEngineSDK {
  class AM_UTILITIES_EXPORT amPlatformMath {
   public:

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
      return std::sin(theta);
    }

    template<typename T>
    static T cos(T theta) {
      return static_cast<T>(std::cos(theta));
    }

    template<typename T>
    static T tan(T theta) {
      return static_cast<T>(std::tan(theta));
    }

    template<typename T>
    static T aSin(T val) {
      return static_cast<T>(std::asin(val));
    }

    template<typename T>
    static T aCos(T val) {
      return static_cast<T>(std::acos(val));
    }

    template<typename T>
    static T aTan(T val) {
      return static_cast<T>(std::atan(val));
    }

    template<typename T>
    static T fastSin(T theta) {
      return theta - (theta * pow(theta, 2) / 6) + (theta * pow(theta, 4) / 120) - (theta * pow(theta, 6) / 5040) + (theta * pow(theta, 8) / 362880);
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
      return val + ((val * pow(val, 2)) * (2 / (4 * 1 * 3)))
        + ((val * pow(val, 4)) * (24 / (8 * 4 * 5)))
        + ((val * pow(val, 6)) * (720 / (12 * 36 * 7)))
        + ((val * pow(val, 8)) * (40320 / (16 * 576 * 9)));
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
      return static_cast<T>(std::pow(val, exp));
    }

    template<typename T>
    static T sqr(T val) {
      return (val * val);
    }

    template<typename T>
    static T sqrt(T val) {
      return static_cast<T>(std::sqrt(val));
    }

    template<typename T>
    static float invSqrt(T val) {
      return 1.0f / static_cast<float>(sqrt(val));
    }

    template<typename T>
    static T logX(T val, T base) {
      return static_cast<T>(std::log(val) / std::log(base));
    }

    template<typename T>
    static T logN(T val) {
      return static_cast<T>(std::log(val));
    }

    template<typename T>
    static T log2(T val) {
      return static_cast<T>(std::log2(val));
    }

    template<typename T>
    static T log10(T val) {
      return static_cast<T>(std::log10(val));
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
      return static_cast<int32>(val + 0.5f * (abs(val) / val));
    }

    template<typename T>
    static T floor(T val) {
      return static_cast<int32>(val);
    }

    template<typename T>
    static T ceil(T val) {
      return static_cast<int32>(val + 9.99999999);
    }

    template<typename T>
    static T fractional(T frac, T* ptr_intpart) {
      return std::modf(frac, ptr_intpart);
    }

    template<typename T>
    static T exp(T val) {
      return std::exp(val);
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

    /**
     *  Collisions
     */

    /**
     *  Vector3 collisions
     */

    static bool
    intersects(const amVector3& vec, const amFrustrum &f);

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
