/******************************************
 * @file amMatrix4x4.cpp
 * @date 2018/09/27
 *
 * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp of the 4x4 matrix in COL Mayor
 *
 *
 * @note
******************************************/
#include "amMatrix4x4.h"
#include "amVector3.h"

namespace amEngineSDK {
  
  amMatrix4x4::amMatrix4x4() {}


  amMatrix4x4::~amMatrix4x4() {}

  const amMatrix4x4 amMatrix4x4::IDENTITY = amMatrix4x4(FORCE_INIT::kONE);
  const amMatrix4x4 amMatrix4x4::ZERO = amMatrix4x4(FORCE_INIT::kZERO);

  amMatrix4x4::amMatrix4x4(const amMatrix4x4& other) {
    //_m = other._m;
    for (int i = 0; i < 16; ++i)
      fvec[i] = other.fvec[i];
  }

  void amMatrix4x4::initIdentity() {
    *this = IDENTITY;
  }

  amMatrix4x4::amMatrix4x4(int32 val) {
    memset(this, 0, sizeof(amMatrix4x4));
    if (val == FORCE_INIT::kONE)
      _m.m00 = _m.m11 = _m.m22 = _m.m33 = 1.0f;
  }

  amMatrix4x4::amMatrix4x4(const float _m00, const float _m01, const float _m02, const float _m03,
                           const float _m10, const float _m11, const float _m12, const float _m13,
                           const float _m20, const float _m21, const float _m22, const float _m23,
                           const float _m30, const float _m31, const float _m32, const float _m33) {
    _m.m00 = _m00; _m.m01 = _m01; _m.m02 = _m02; _m.m03 = _m03;
    _m.m10 = _m10; _m.m11 = _m11; _m.m12 = _m12; _m.m13 = _m13;
    _m.m20 = _m20; _m.m21 = _m21; _m.m22 = _m22; _m.m23 = _m23;
    _m.m30 = _m30; _m.m31 = _m31; _m.m32 = _m32; _m.m33 = _m33;
  }

  amMatrix4x4 amMatrix4x4::operator*(const float & f) {
    amMatrix4x4 res = *this;
    for (int i = 0; i < 16; ++i)
      res.fvec[i] *= f;
    return res;
  }

  amMatrix4x4& amMatrix4x4::operator=(const amMatrix4x4 & other) {
    //_m = other._m;
    for (int i = 0; i < 16; ++i)
      fvec[i] = other.fvec[i];
    return *this;
  }

  amMatrix4x4& amMatrix4x4::operator*=(const amMatrix4x4 & other) {
    *this = *this * other;
    return *this;
  }

  amMatrix4x4 amMatrix4x4::operator*(const amMatrix4x4& other) {
    amMatrix4x4 res = *this;
    for (int j = 0; j < 4; j++)
      for (int i = 0; i < 4; i++)
        for (int k = 0; k < 4; k++)
          res.m[j][i] += other.m[j][k] * other.m[k][i];
    return res;
  }

  amVector4 amMatrix4x4::operator*(amVector4& V) {
    /**
    ************************
    *
    *  @TODO convert to Col major 
    *
    ************************
    */
      amVector4 res;
      res.x = (_m.m00 * V.x) + (_m.m10 * V.y) + (_m.m20 * V.z) + (_m.m30 * V.w);
      res.y = (_m.m01 * V.x) + (_m.m11 * V.y) + (_m.m21 * V.z) + (_m.m31 * V.w);
      res.z = (_m.m02 * V.x) + (_m.m12 * V.y) + (_m.m22 * V.z) + (_m.m32 * V.w);
      res.w = (_m.m03 * V.x) + (_m.m13 * V.y) + (_m.m23 * V.z) + (_m.m33 * V.w);
      return res;
  }

  /*amMatrix4x4 amMatrix4x4::RotationY_RH(const float& theta) {
      amMatrix4x4 res(IDENTITY);

      res._m.m00 = res._m.m22 = amMath::cos(theta);
      res._m.m20 = amMath::sin(theta);
      res._m.m02 = -res._m.m20;
      return res;
  }

  amMatrix4x4 amMatrix4x4::RotationX_RH(const float& theta) {
      //theta = theta * 0.01745;
    amMatrix4x4 res(IDENTITY);
    res._m.m11 = res._m.m22 = amMath::cos(theta);
    res._m.m21 = amMath::sin(theta);
    res._m.m12 = -res._m.m21;
      return res;
  }

  amMatrix4x4 amMatrix4x4::RotationZ_RH(const float& theta) {
      //theta = theta * 0.01745;
      amMatrix4x4 res(IDENTITY);
      res._m.m00 = res._m.m11 = amMath::cos(theta);
      res._m.m10 = amMath::sin(theta);
      res._m.m01 = -res._m.m10;
      return res;
  }*/

  amMatrix4x4& amMatrix4x4::rotateX(const float& theta) {
      //theta = theta * 0.01745;
      //amMatrix4x4 res(IDENTITY);
      _m.m11 = _m.m22 = amMath::cos(theta);
      _m.m21 = -amMath::sin(theta);
      _m.m12 = -_m.m21;
      return *this;
  }

  amMatrix4x4& amMatrix4x4::rotateY(const float& theta) {
      //theta = theta * 0.01745;
    //amMatrix4x4 res(IDENTITY);
    _m.m00 = _m.m22 = amMath::cos(theta);
    _m.m20 = -amMath::sin(theta);
    _m.m02 = -_m.m20;
      return *this;
  }

  amMatrix4x4& amMatrix4x4::rotateZ(const float& theta) {
      //theta = theta * 0.01745;
      //amMatrix4x4 res(IDENTITY);
      _m.m00 = _m.m11 = amMath::cos(theta);
      _m.m10 = -amMath::sin(theta);
      _m.m01 = -_m.m10;
      return *this;
  }

  amMatrix4x4& amMatrix4x4::rotateAxis(const amVector3 & axis, float ang) {
    float cosAng = amMath::cos(ang);
    float sinAng = amMath::sin(ang);
    _m.m00 = cosAng + amMath::pow(axis.x, 2.0f) * (1 - cosAng); 
    _m.m01 = ((axis.x * axis.y) * (1 - cosAng)) - axis.z * sinAng;
    _m.m02 = ((axis.x * axis.z) * (1 - cosAng)) + axis.y * sinAng;

    _m.m10 = ((axis.x * axis.y) * (1 - cosAng)) + axis.z * sinAng;
    _m.m11 = cosAng + amMath::pow(axis.y, 2.0f) * (1 - cosAng);
    _m.m12 = ((axis.z * axis.y) * (1 - cosAng)) - axis.x * sinAng;

    _m.m20 = ((axis.x * axis.z) * (1 - cosAng)) - axis.y * sinAng;
    _m.m21 = ((axis.z * axis.y) * (1 - cosAng)) + axis.x * sinAng;
    _m.m22 = cosAng + amMath::pow(axis.z, 2.0f) * (1 - cosAng);
    return *this;
  }

  amMatrix4x4& amMatrix4x4::transpose() {
    amMatrix4x4 T;
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 4; i++) {
        T.m[j][i] = m[i][j];
      }
    }
    *this = T;
    return *this;
  }

  amMatrix4x4 amMatrix4x4::transposed() {
    amMatrix4x4 __m = *this;
    return __m.transpose();
  }

  /*amMatrix4x4 amMatrix4x4::Fast_Inverse(amMatrix4x4 & M) {
    M;
      amMatrix4x4 res;
      amVector4 InvPos;
      res = res.transposed();
      InvPos = res.vec[3];
      res._m.m03 = -res.vec[0].DotNormalized(InvPos);
      res._m.m13 = -res.vec[1].DotNormalized(InvPos);
      res._m.m23 = -res.vec[2].DotNormalized(InvPos);
      res.vec[3].x = 0;
      res.vec[3].y = 0;
      res.vec[3].z = 0;
      return res;
  }*/

  amMatrix4x4 amMatrix4x4::inverse() {
    amMatrix4x4 inv;

      inv.fvec[0] = fvec[5] * fvec[10] * fvec[15] -
        fvec[5] * fvec[11] * fvec[14] -
        fvec[9] * fvec[6] * fvec[15] +
        fvec[9] * fvec[7] * fvec[14] +
        fvec[13] * fvec[6] * fvec[11] -
        fvec[13] * fvec[7] * fvec[10];

      inv.fvec[4] = -fvec[4] * fvec[10] * fvec[15] +
        fvec[4] * fvec[11] * fvec[14] +
        fvec[8] * fvec[6] * fvec[15] -
        fvec[8] * fvec[7] * fvec[14] -
        fvec[12] * fvec[6] * fvec[11] +
        fvec[12] * fvec[7] * fvec[10];

      inv.fvec[8] = fvec[4] * fvec[9] * fvec[15] -
        fvec[4] * fvec[11] * fvec[13] -
        fvec[8] * fvec[5] * fvec[15] +
        fvec[8] * fvec[7] * fvec[13] +
        fvec[12] * fvec[5] * fvec[11] -
        fvec[12] * fvec[7] * fvec[9];

      inv.fvec[12] = -fvec[4] * fvec[9] * fvec[14] +
        fvec[4] * fvec[10] * fvec[13] +
        fvec[8] * fvec[5] * fvec[14] -
        fvec[8] * fvec[6] * fvec[13] -
        fvec[12] * fvec[5] * fvec[10] +
        fvec[12] * fvec[6] * fvec[9];

      inv.fvec[1] = -fvec[1] * fvec[10] * fvec[15] +
        fvec[1] * fvec[11] * fvec[14] +
        fvec[9] * fvec[2] * fvec[15] -
        fvec[9] * fvec[3] * fvec[14] -
        fvec[13] * fvec[2] * fvec[11] +
        fvec[13] * fvec[3] * fvec[10];

      inv.fvec[5] = fvec[0] * fvec[10] * fvec[15] -
        fvec[0] * fvec[11] * fvec[14] -
        fvec[8] * fvec[2] * fvec[15] +
        fvec[8] * fvec[3] * fvec[14] +
        fvec[12] * fvec[2] * fvec[11] -
        fvec[12] * fvec[3] * fvec[10];

      inv.fvec[9] = -fvec[0] * fvec[9] * fvec[15] +
        fvec[0] * fvec[11] * fvec[13] +
        fvec[8] * fvec[1] * fvec[15] -
        fvec[8] * fvec[3] * fvec[13] -
        fvec[12] * fvec[1] * fvec[11] +
        fvec[12] * fvec[3] * fvec[9];

      inv.fvec[13] = fvec[0] * fvec[9] * fvec[14] -
        fvec[0] * fvec[10] * fvec[13] -
        fvec[8] * fvec[1] * fvec[14] +
        fvec[8] * fvec[2] * fvec[13] +
        fvec[12] * fvec[1] * fvec[10] -
        fvec[12] * fvec[2] * fvec[9];

      inv.fvec[2] = fvec[1] * fvec[6] * fvec[15] -
        fvec[1] * fvec[7] * fvec[14] -
        fvec[5] * fvec[2] * fvec[15] +
        fvec[5] * fvec[3] * fvec[14] +
        fvec[13] * fvec[2] * fvec[7] -
        fvec[13] * fvec[3] * fvec[6];

      inv.fvec[6] = -fvec[0] * fvec[6] * fvec[15] +
        fvec[0] * fvec[7] * fvec[14] +
        fvec[4] * fvec[2] * fvec[15] -
        fvec[4] * fvec[3] * fvec[14] -
        fvec[12] * fvec[2] * fvec[7] +
        fvec[12] * fvec[3] * fvec[6];

      inv.fvec[10] = fvec[0] * fvec[5] * fvec[15] -
        fvec[0] * fvec[7] * fvec[13] -
        fvec[4] * fvec[1] * fvec[15] +
        fvec[4] * fvec[3] * fvec[13] +
        fvec[12] * fvec[1] * fvec[7] -
        fvec[12] * fvec[3] * fvec[5];

      inv.fvec[14] = -fvec[0] * fvec[5] * fvec[14] +
        fvec[0] * fvec[6] * fvec[13] +
        fvec[4] * fvec[1] * fvec[14] -
        fvec[4] * fvec[2] * fvec[13] -
        fvec[12] * fvec[1] * fvec[6] +
        fvec[12] * fvec[2] * fvec[5];

      inv.fvec[3] = -fvec[1] * fvec[6] * fvec[11] +
        fvec[1] * fvec[7] * fvec[10] +
        fvec[5] * fvec[2] * fvec[11] -
        fvec[5] * fvec[3] * fvec[10] -
        fvec[9] * fvec[2] * fvec[7] +
        fvec[9] * fvec[3] * fvec[6];

      inv.fvec[7] = fvec[0] * fvec[6] * fvec[11] -
        fvec[0] * fvec[7] * fvec[10] -
        fvec[4] * fvec[2] * fvec[11] +
        fvec[4] * fvec[3] * fvec[10] +
        fvec[8] * fvec[2] * fvec[7] -
        fvec[8] * fvec[3] * fvec[6];

      inv.fvec[11] = -fvec[0] * fvec[5] * fvec[11] +
        fvec[0] * fvec[7] * fvec[9] +
        fvec[4] * fvec[1] * fvec[11] -
        fvec[4] * fvec[3] * fvec[9] -
        fvec[8] * fvec[1] * fvec[7] +
        fvec[8] * fvec[3] * fvec[5];

      inv.fvec[15] = fvec[0] * fvec[5] * fvec[10] -
        fvec[0] * fvec[6] * fvec[9] -
        fvec[4] * fvec[1] * fvec[10] +
        fvec[4] * fvec[2] * fvec[9] +
        fvec[8] * fvec[1] * fvec[6] -
        fvec[8] * fvec[2] * fvec[5];

      float det = fvec[0] * inv.fvec[0] + fvec[1] * inv.fvec[4] + fvec[2] * inv.fvec[8] + fvec[3] * inv.fvec[12];

      if (amMath::abs(det) < 0.0001)
        return *this;
      return inv * (1.0f / det);
      //float invdet = 1.0 / det;
  }

  amMatrix4x4 & amMatrix4x4::fastInverse() {

    return *this;
  }

  amMatrix4x4& amMatrix4x4::invert() {
    this->inverse();
    return *this;
  }

  amVector3
  amMatrix4x4::getPosition() {
    return amVector3(_m.m30, _m.m31, _m.m32);
  }

  amMatrix4x4
  amMatrix4x4::scale(const float sx, const float sy, const float sz) {
    amMatrix4x4 res(IDENTITY);
    res._m.m00 = sx; res._m.m11 = sy; res._m.m22 = sz;
    return res;
  }

  /*amMatrix4x4 amMatrix4x4::Translation_LH(float dx, float dy, float dz) {
    amMatrix4x4 res(IDENTITY);
      res._m.m03 = dx; 
      res._m.m13 = dy; 
      res._m.m23 = dz;
      return res;
  }

  amMatrix4x4 amMatrix4x4::Translation_RH(float dx, float dy, float dz) {
    amMatrix4x4 res(IDENTITY);
    res._m.m30 = dx; 
    res._m.m31 = dy; 
    res._m.m32 = dz;
    return res;
  }*/

  /*amMatrix4x4 amMatrix4x4::lookAt_RH(amVector4 & EyePos, amVector4 & Target, amVector4 & Up) {
      amVector4 xDir, yDir, zDir;
      zDir = (EyePos - Target).getNormalized();
      //xDir = Normalize(Cross3(Up, zDir));
      xDir = Up.cross3(zDir).getNormalized();
      //yDir = Cross3(zDir, xDir);
      yDir = zDir.cross3(xDir);
      amMatrix4x4 View;
      / *
      Cmatrix4D View = ( 
      xDir.x,				      yDir.x,				      zDir.x,		         0,
      xDir.y,				      yDir.y,				      zDir.y,		         0,
      xDir.z,				      yDir.z,				      zDir.z,		         0,
      -Dot(xDir,EyePos), -Dot(yDir, EyePos), -Dot(zDir, EyePos), 1 );
      * /
      View._m.m00 = xDir.x;
      View._m.m01 = yDir.x;
      View._m.m02 = zDir.x;

      View._m.m10 = xDir.y;
      View._m.m11 = yDir.y;
      View._m.m12 = zDir.y;

      View._m.m20 = xDir.z;
      View._m.m21 = yDir.z;
      View._m.m22 = zDir.z;

      View._m.m30 = -xDir.DotNormalized(EyePos);
      View._m.m31 = -yDir.DotNormalized(EyePos);
      View._m.m32 = -zDir.DotNormalized(EyePos);
      View._m.m33 = 1;
      return View;
  }*/

  amMatrix4x4
  amMatrix4x4::lookAt(const amVector3 & EyePos, const amVector3 & Target, const amVector3 & Up) {
      amVector3 xDir, yDir, zDir;
      zDir = (Target - EyePos).getNormalized();
      xDir = Up.cross3(zDir).getNormalized();
      yDir = zDir.cross3(xDir);
      amMatrix4x4 View;
      /*Cmatrix4D View = ( xDir.x,			yDir.x,				zDir.x,		   0,
      xDir.y,			yDir.y,				zDir.y,		   0,
      xDir.z,			yDir.z,				zDir.z,		   0,
      -Dot(xDir,EyePos), -Dot(yDir, EyePos), -Dot(zDir, EyePos), 1 );
      */
      View._m.m00 = xDir.x;
      View._m.m01 = yDir.x;
      View._m.m02 = zDir.x;

      View._m.m10 = xDir.y;
      View._m.m11 = yDir.y;
      View._m.m12 = zDir.y;

      View._m.m20 = xDir.z;
      View._m.m21 = yDir.z;
      View._m.m22 = zDir.z;

      View._m.m30 = -xDir.DotNormalized(EyePos);
      View._m.m31 = -yDir.DotNormalized(EyePos);
      View._m.m32 = -zDir.DotNormalized(EyePos);
      View._m.m33 = 1;

      return View;
  }

  /*amMatrix4x4 amMatrix4x4::perspectiveFOVRH(const float& FOVY, const float& ratio, const float& zNear, const float& zFar) {
      float ang = FOVY / 2;
      float h = amMath::tan(ang);
      float w = h / ratio;
      amMatrix4x4 Persp;

      / *
      Cmatrix4D P = { 
      w,	0,	              0,	           0,
      0,	h,	              0,	           0,
      0,	0,  zFar / (zNear - zFar),      -1,
      0,	0,	zNear*zFar / (zNear - zFar), 0 };
      * /

      Persp._m.m00 = w;
      Persp._m.m11 = h;
      Persp._m.m22 = zFar / (zNear - zFar);
      Persp._m.m23 = -1;
      Persp._m.m32 = zNear * zFar / (zNear - zFar);

      return Persp;
  }*/

  amMatrix4x4& amMatrix4x4::setViewProjection(const float& FOV, const float& ratio, const float& zNear, const float& zFar) {
      float ang = FOV / 2;
      float h = amMath::tan(ang);
      float w = h / ratio;
      //amMatrix4x4 Persp;
      /*
      Cmatrix4D P = {
      w,	0,	           0,	                0,
      0,	h,	           0,                 0,
      0,	0,		zFar / (zFar - zNear),	  	1,
      0,	0,	-zNear*zFar / (zFar - zNear),	0 };
      */
      
      _m.m00 = w;
      _m.m11 = h;
      _m.m22 = zFar / (zFar - zNear);
      _m.m23 = 1;
      _m.m32 = -zNear * zFar / (zFar - zNear);
      
      return *this;
  }
}


