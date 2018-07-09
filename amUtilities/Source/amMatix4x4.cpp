#include "amMatix4x4.h"

namespace amEngineSDK {
  amMatix4x4::amMatix4x4() {}


  amMatix4x4::~amMatix4x4() {}

  amMatix4x4::amMatix4x4(amMatix4x4 & other) {
    _m = other._m;
  }

  void amMatix4x4::init() {
    /*for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 4; i++) {
        m[j][i] = 0;
      }
    }*/
    memset(&_m, 0, sizeof(_m));
  }

  void amMatix4x4::initIdentity() {
    init();
    _m.m00 = _m.m11 = _m.m22 = _m.m33 = 1;
    /*for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        m[j][i] = (j == i) ? 1.0f : 0.0f;*/
  }

  amMatix4x4 amMatix4x4::operator*(const float & f) {
    for (int i = 0; i < 16; ++i)
      fvec[i] *= f;
  }

  amMatix4x4& amMatix4x4::operator=(const amMatix4x4 & other) {
    _m = other._m;
    return *this;
  }

  /*amMatix4x4 operator*(amMatix4x4& A, amMatix4x4& B) {
    amMatix4x4 R;
    memset(&R, 0, sizeof(R));
    for (int j = 0; j < 4; j++)
      for (int i = 0; i < 4; i++)
        for (int k = 0; k < 4; k++)
          R.m[j][i] += A.m[j][k] * B.m[k][i];
    return R;
  }*/
  amMatix4x4 amMatix4x4::operator*(const amMatix4x4& other) {
    amMatix4x4 res = *this;
    res.init();
    for (int j = 0; j < 4; j++)
      for (int i = 0; i < 4; i++)
        for (int k = 0; k < 4; k++)
          res.m[j][i] += other.m[j][k] * other.m[k][i];
    return res;
  }

  /*
  amVector4 amMatix4x4::operator*(amVector4& V) {
    amVector4 res;
    res.init();
      for (int j = 0; j < 4; j++)
        for (int i = 0; i < 4; i++)
          for (int k = 0; k < 4; k++)
            res.v[j] += m[i][j] * V.v[i];
      return res;
  }
  */

  amVector4 amMatix4x4::operator*(amVector4& V) {
      amVector4 res;
      res.init();
      res.x = (_m.m00 * V.x) + (_m.m01 * V.y) + (_m.m02 * V.z) + (_m.m03 * V.w);
      res.y = (_m.m10 * V.x) + (_m.m11 * V.y) + (_m.m12 * V.z) + (_m.m13 * V.w);
      res.z = (_m.m20 * V.x) + (_m.m21 * V.y) + (_m.m22 * V.z) + (_m.m23 * V.w);
      res.w = (_m.m30 * V.x) + (_m.m31 * V.y) + (_m.m32 * V.z) + (_m.m33 * V.w);
      return res;
  }
  /*
    amVector4 operator*(amVector4 & A, amVector4 & B) {
        amVector4 aux = { A.x*B.x,A.y*B.y, A.z*B.z, 1 };
        return aux;
    }
  */

  amMatix4x4 amMatix4x4::RotationY_RH(const float& theta) {
      //theta = theta * 0.01745;
      amMatix4x4 res;
      res.initIdentity();

      res._m.m00 = res._m.m22 = cos(theta);
      res._m.m20 = sin(theta);
      res._m.m02 = -res._m.m20;
      return res;
  }

  amMatix4x4 amMatix4x4::RotationX_RH(const float& theta) {
      //theta = theta * 0.01745;
    amMatix4x4 res;
    res.initIdentity();
    res._m.m11 = res._m.m22 = cos(theta);
    res._m.m21 = sin(theta);
    res._m.m12 = -res._m.m21;
      return res;
  }

  amMatix4x4 amMatix4x4::RotationZ_RH(const float& theta) {
      //theta = theta * 0.01745;
      amMatix4x4 res;
      res.initIdentity();
      res._m.m00 = res._m.m11 = cos(theta);
      res._m.m10 = sin(theta);
      res._m.m01 = -res._m.m10;
      return res;
  }

  amMatix4x4 amMatix4x4::RotationX_LH(const float& theta) {
      //theta = theta * 0.01745;
      amMatix4x4 res;
      res.initIdentity();
      res._m.m11 = res._m.m22 = cos(theta);
      res._m.m21 = -sin(theta);
      res._m.m12 = -res._m.m21;
      return res;
  }

  amMatix4x4 amMatix4x4::RotationY_LH(const float& theta) {
      //theta = theta * 0.01745;
    amMatix4x4 res;
    res.initIdentity();
    res._m.m00 = res._m.m22 = cos(theta);
    res._m.m20 = -sin(theta);
    res._m.m02 = -res._m.m20;
      return res;
  }

  amMatix4x4 amMatix4x4::RotationZ_LH(const float& theta) {
      //theta = theta * 0.01745;
      amMatix4x4 res;
      res.initIdentity();
      res._m.m00 = res._m.m11 = cos(theta);
      res._m.m10 = -sin(theta);
      res._m.m01 = -res._m.m10;
      return res;
  }

  amMatix4x4 amMatix4x4::Transposed() {
    amMatix4x4 T;
    for (int j = 0; j < 4; j++) {
      for (int i = 0; i < 4; i++) {
        T.m[j][i] = m[i][j];
      }
    }
    return T;
  }

  amMatix4x4 amMatix4x4::Fast_Inverse(amMatix4x4 & M) {
      amMatix4x4 res;
      amVector4 InvPos;
      res = res.Transposed();
      InvPos = res.vec[3];
      res._m.m03 = -res.vec[0].DotNormalized(InvPos);
      res._m.m13 = -res.vec[1].DotNormalized(InvPos);
      res._m.m23 = -res.vec[2].DotNormalized(InvPos);
      res.vec[3].x = 0;
      res.vec[3].y = 0;
      res.vec[3].z = 0;
      return res;
  }

  //float amMatix4x4::Inverse(amMatix4x4 & M, amMatix4x4 & R) {
  //    amMatix4x4 I;
  //    double inv[16], det;
  //    int i;

  //    inv[0] = M.v[5] * M.v[10] * M.v[15] -
  //      M.v[5] * M.v[11] * M.v[14] -
  //      M.v[9] * M.v[6] * M.v[15] +
  //      M.v[9] * M.v[7] * M.v[14] +
  //      M.v[13] * M.v[6] * M.v[11] -
  //      M.v[13] * M.v[7] * M.v[10];

  //    inv[4] = -M.v[4] * M.v[10] * M.v[15] +
  //      M.v[4] * M.v[11] * M.v[14] +
  //      M.v[8] * M.v[6] * M.v[15] -
  //      M.v[8] * M.v[7] * M.v[14] -
  //      M.v[12] * M.v[6] * M.v[11] +
  //      M.v[12] * M.v[7] * M.v[10];

  //    inv[8] = M.v[4] * M.v[9] * M.v[15] -
  //      M.v[4] * M.v[11] * M.v[13] -
  //      M.v[8] * M.v[5] * M.v[15] +
  //      M.v[8] * M.v[7] * M.v[13] +
  //      M.v[12] * M.v[5] * M.v[11] -
  //      M.v[12] * M.v[7] * M.v[9];

  //    inv[12] = -M.v[4] * M.v[9] * M.v[14] +
  //      M.v[4] * M.v[10] * M.v[13] +
  //      M.v[8] * M.v[5] * M.v[14] -
  //      M.v[8] * M.v[6] * M.v[13] -
  //      M.v[12] * M.v[5] * M.v[10] +
  //      M.v[12] * M.v[6] * M.v[9];

  //    inv[1] = -M.v[1] * M.v[10] * M.v[15] +
  //      M.v[1] * M.v[11] * M.v[14] +
  //      M.v[9] * M.v[2] * M.v[15] -
  //      M.v[9] * M.v[3] * M.v[14] -
  //      M.v[13] * M.v[2] * M.v[11] +
  //      M.v[13] * M.v[3] * M.v[10];

  //    inv[5] = M.v[0] * M.v[10] * M.v[15] -
  //      M.v[0] * M.v[11] * M.v[14] -
  //      M.v[8] * M.v[2] * M.v[15] +
  //      M.v[8] * M.v[3] * M.v[14] +
  //      M.v[12] * M.v[2] * M.v[11] -
  //      M.v[12] * M.v[3] * M.v[10];

  //    inv[9] = -M.v[0] * M.v[9] * M.v[15] +
  //      M.v[0] * M.v[11] * M.v[13] +
  //      M.v[8] * M.v[1] * M.v[15] -
  //      M.v[8] * M.v[3] * M.v[13] -
  //      M.v[12] * M.v[1] * M.v[11] +
  //      M.v[12] * M.v[3] * M.v[9];

  //    inv[13] = M.v[0] * M.v[9] * M.v[14] -
  //      M.v[0] * M.v[10] * M.v[13] -
  //      M.v[8] * M.v[1] * M.v[14] +
  //      M.v[8] * M.v[2] * M.v[13] +
  //      M.v[12] * M.v[1] * M.v[10] -
  //      M.v[12] * M.v[2] * M.v[9];

  //    inv[2] = M.v[1] * M.v[6] * M.v[15] -
  //      M.v[1] * M.v[7] * M.v[14] -
  //      M.v[5] * M.v[2] * M.v[15] +
  //      M.v[5] * M.v[3] * M.v[14] +
  //      M.v[13] * M.v[2] * M.v[7] -
  //      M.v[13] * M.v[3] * M.v[6];

  //    inv[6] = -M.v[0] * M.v[6] * M.v[15] +
  //      M.v[0] * M.v[7] * M.v[14] +
  //      M.v[4] * M.v[2] * M.v[15] -
  //      M.v[4] * M.v[3] * M.v[14] -
  //      M.v[12] * M.v[2] * M.v[7] +
  //      M.v[12] * M.v[3] * M.v[6];

  //    inv[10] = M.v[0] * M.v[5] * M.v[15] -
  //      M.v[0] * M.v[7] * M.v[13] -
  //      M.v[4] * M.v[1] * M.v[15] +
  //      M.v[4] * M.v[3] * M.v[13] +
  //      M.v[12] * M.v[1] * M.v[7] -
  //      M.v[12] * M.v[3] * M.v[5];

  //    inv[14] = -M.v[0] * M.v[5] * M.v[14] +
  //      M.v[0] * M.v[6] * M.v[13] +
  //      M.v[4] * M.v[1] * M.v[14] -
  //      M.v[4] * M.v[2] * M.v[13] -
  //      M.v[12] * M.v[1] * M.v[6] +
  //      M.v[12] * M.v[2] * M.v[5];

  //    inv[3] = -M.v[1] * M.v[6] * M.v[11] +
  //      M.v[1] * M.v[7] * M.v[10] +
  //      M.v[5] * M.v[2] * M.v[11] -
  //      M.v[5] * M.v[3] * M.v[10] -
  //      M.v[9] * M.v[2] * M.v[7] +
  //      M.v[9] * M.v[3] * M.v[6];

  //    inv[7] = M.v[0] * M.v[6] * M.v[11] -
  //      M.v[0] * M.v[7] * M.v[10] -
  //      M.v[4] * M.v[2] * M.v[11] +
  //      M.v[4] * M.v[3] * M.v[10] +
  //      M.v[8] * M.v[2] * M.v[7] -
  //      M.v[8] * M.v[3] * M.v[6];

  //    inv[11] = -M.v[0] * M.v[5] * M.v[11] +
  //      M.v[0] * M.v[7] * M.v[9] +
  //      M.v[4] * M.v[1] * M.v[11] -
  //      M.v[4] * M.v[3] * M.v[9] -
  //      M.v[8] * M.v[1] * M.v[7] +
  //      M.v[8] * M.v[3] * M.v[5];

  //    inv[15] = M.v[0] * M.v[5] * M.v[10] -
  //      M.v[0] * M.v[6] * M.v[9] -
  //      M.v[4] * M.v[1] * M.v[10] +
  //      M.v[4] * M.v[2] * M.v[9] +
  //      M.v[8] * M.v[1] * M.v[6] -
  //      M.v[8] * M.v[2] * M.v[5];

  //    det = M.v[0] * inv[0] + M.v[1] * inv[4] + M.v[2] * inv[8] + M.v[3] * inv[12];

  //    if (fabs(det) < 0.0001)
  //      return 0.0f;

  //    double invdet = 1.0 / det;

  //    for (i = 0; i < 16; i++) {
  //      R.v[i] = (float)(inv[i] * invdet);
  //    }
  //    return (float)det;
  //}

  amMatix4x4 amMatix4x4::Scaling(float sx, float sy, float sz) {
    amMatix4x4 res;
    res.initIdentity();
    res._m.m00 = sx; res._m.m11 = sy; res._m.m22 = sz;
      return res;
  }

  amMatix4x4 amMatix4x4::Translation_RH(float dx, float dy, float dz) {
    amMatix4x4 res;
    res.initIdentity();
      res._m.m03 = dx; res._m.m13 = dy; res._m.m23 = dz;
      return res;
  }

  amMatix4x4 amMatix4x4::Translation_LH(float dx, float dy, float dz) {
    amMatix4x4 res; 
    res.initIdentity();
    res._m.m30 = dx;
    res._m.m31 = dy;
    res._m.m32 = dz;
    return res;
  }

  amMatix4x4 amMatix4x4::lookAt_RH(amVector4 & EyePos, amVector4 & Target, amVector4 & Up) {
      amVector4 xDir, yDir, zDir;
      zDir = (EyePos - Target).getNormalized();
      //xDir = Normalize(Cross3(Up, zDir));
      xDir = Up.cross3(zDir).getNormalized();
      //yDir = Cross3(zDir, xDir);
      yDir = zDir.cross3(xDir);
      amMatix4x4 View;
      View.init();
      /*
      Cmatrix4D View = ( 
      xDir.x,				      yDir.x,				      zDir.x,		         0,
      xDir.y,				      yDir.y,				      zDir.y,		         0,
      xDir.z,				      yDir.z,				      zDir.z,		         0,
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

  amMatix4x4 amMatix4x4::lookAt_LH(amVector4 & EyePos, amVector4 & Target, amVector4 & Up) {
      amVector4 xDir, yDir, zDir;
      zDir = (Target - EyePos).getNormalized();
      //xDir = Normalize(Cross3(Up, zDir));
      xDir = Up.cross3(zDir).getNormalized();
      //yDir = Cross3(zDir, xDir);
      yDir = zDir.cross3(xDir);
      amMatix4x4 View;
      View.init();
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

  amMatix4x4 amMatix4x4::perspectiveFOVRH(const float& FOVY, const float& ratio, const float& zNear, const float& zFar) {
      float ang = FOVY / 2;

      //float h = 1 / tan(ang);
      //float w = h*ratio;

      float h = cos(ang) / sin(ang);
      float w = h / ratio;

      amMatix4x4 Persp;
      Persp.init();

      /*
      Cmatrix4D P = { 
      w,	0,	              0,	           0,
      0,	h,	              0,	           0,
      0,	0,  zFar / (zNear - zFar),      -1,
      0,	0,	zNear*zFar / (zNear - zFar), 0 };
      */

      Persp._m.m00 = w;
      Persp._m.m11 = h;
      Persp._m.m22 = zFar / (zNear - zFar);
      Persp._m.m23 = -1;
      Persp._m.m32 = zNear * zFar / (zNear - zFar);

      return Persp;
  }

  amMatix4x4 amMatix4x4::perspectiveFOVLH(const float& FOVY, const float& ratio, const float& zNear, const float& zFar) {
      float ang = FOVY / 2;
      //float h = 1 / tan(ang);
      //float w = h*ratio;

      float h = cos(ang) / sin(ang);
      float w = h / ratio;

      amMatix4x4 Persp;
      Persp.init();
      /*
      Cmatrix4D P = {
      w,	0,	           0,	                0,
      0,	h,	           0,                 0,
      0,	0,		zFar / (zFar - zNear),	  	1,
      0,	0,	-zNear*zFar / (zFar - zNear),	0 };
      */
      
      Persp._m.m00 = w;
      Persp._m.m11 = h;
      Persp._m.m22 = zFar / (zFar - zNear);
      Persp._m.m23 = 1;
      Persp._m.m32 = -zNear * zFar / (zFar - zNear);
      return Persp;
  }

  amVector4 amMatix4x4::buildPlane(amVector4& vertex0, amVector4& vertex1) {
      amVector4 A, B, C, result;
      A = vertex0 + vertex1;
      A.x = (float)A.x / 2.0f;
      A.y = (float)A.y / 2.0f;
      A.z = 1; A.w = 1;
      B = A - vertex0;
      C = vertex1 - vertex0;
      //A = cross3(C, B);
      A = C.cross3(B);
      result = A;
      result.w = -A.DotNormalized(vertex0);
      return result;
  }
}


