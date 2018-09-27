/******************************************
 * @file main.cpp
 * @date 2018/09/27
 *
  * @author Andrés Sumano
 * Contact: andressumano@hotmail.com
 *
 * @brief cpp for google testing all the everything from the math library
 *
 * @note
******************************************/
#include <amPrerequisitesUtilities.h>
#include <amMath.h>
#include <conio.h>
#include <gtest\gtest.h>
using namespace amEngineSDK;
//using amMath;



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  getch();
  return 0;
}

TEST(Basic_Types, Types) {
  EXPECT_EQ(sizeof(uint8), 1);
  EXPECT_EQ(sizeof(uint16), 2);
  EXPECT_EQ(sizeof(uint32), 4);
  EXPECT_EQ(sizeof(uint64), 8);
  EXPECT_EQ(sizeof(uint128), 16);
}

TEST(amMath_funcs, Funcs) {
  
  float a = amEngineSDK::amMath::cos(1);

  EXPECT_EQ(amMath::pow(2, 3), 8);
  EXPECT_NE(amMath::pow(2, 3), 16);

  EXPECT_EQ(amMath::logX(9, 3), 2);
  EXPECT_NE(amMath::logX(27, 3), 2);

  EXPECT_EQ(amMath::logN(2), 8);// needs values set for testing
  EXPECT_NE(amMath::logN(2), 16);// needs values set for testing

  EXPECT_EQ(amMath::log2(8), 3);// needs values set for testing
  EXPECT_NE(amMath::log2(2), 16);// needs values set for testing

  EXPECT_EQ(amMath::log10(2), 8);// needs values set for testing
  EXPECT_NE(amMath::log10(2), 16);// needs values set for testing

  EXPECT_EQ(amMath::abs(-2), 2);
  EXPECT_NE(amMath::abs(-2), -2);

  EXPECT_EQ(amMath::roundToInt(1.4), 1);
  EXPECT_EQ(amMath::roundToInt(2.6), 3);
  EXPECT_EQ(amMath::roundToInt(-1.4), -1);
  EXPECT_EQ(amMath::roundToInt(-2.6), -3);
  EXPECT_NE(amMath::roundToInt(1.4), 2);
  EXPECT_NE(amMath::roundToInt(2.6), 2);
  EXPECT_NE(amMath::roundToInt(-2.6), -2);
  EXPECT_NE(amMath::roundToInt(2.4), -3);

  EXPECT_EQ(amMath::floor(1.4), 1);
  EXPECT_EQ(amMath::floor(2.6), 2);
  EXPECT_NE(amMath::floor(-1.4), -1);
  EXPECT_NE(amMath::floor(-2.6), -2);

  EXPECT_EQ(amMath::ceil(1.4), 2);
  EXPECT_EQ(amMath::ceil(2.6), 3);
  EXPECT_NE(amMath::ceil(-1.4), -2);
  EXPECT_NE(amMath::ceil(-2.6), -3);

  float f = 0;
  EXPECT_EQ(amMath::fractional(1.4f, &f), 0.4);
  EXPECT_EQ(amMath::fractional(2.6f, &f), 0.6);
  EXPECT_NE(amMath::fractional(-1.4f, &f), -2);
  EXPECT_NE(amMath::fractional(-2.6f, &f), -3);

  EXPECT_EQ(amMath::min(1, 2), 1);
  EXPECT_EQ(amMath::min(-2 ,-1), -2);
  EXPECT_NE(amMath::min(1, 2), 2);
  EXPECT_NE(amMath::min(-2, -1), -1);

  EXPECT_EQ(amMath::max(1, 2), 2);
  EXPECT_EQ(amMath::max(-2, -1), -1);
  EXPECT_NE(amMath::max(1, 2), 1);
  EXPECT_NE(amMath::max(-2, -1), -2);

  EXPECT_EQ(amMath::clamp(1, 2, 3), 2);
  EXPECT_EQ(amMath::clamp(1, 2, 0), 1);
  EXPECT_EQ(amMath::clamp(1.0f, 2.0f, 1.5f), 1.5f);
  EXPECT_NE(amMath::clamp(1, 2, 3), 3);
  EXPECT_NE(amMath::clamp(1, 2, 0), 0);

  EXPECT_FLOAT_EQ(amMath::HALFPI, amMath::tan(1) * 2);
  EXPECT_FLOAT_EQ(amMath::PI, amMath::tan(1) * 4);
  EXPECT_FLOAT_EQ(amMath::TWOPI, amMath::tan(1) * 8);
  EXPECT_FLOAT_EQ(amMath::DEG2RAD, amMath::PI / 180.0f);
  EXPECT_FLOAT_EQ(amMath::RAD2DEG, 180.0f / amMath::PI);
}

//TEST(Shapes_3D, tesst) {
//  amMath::amSphere sph1;
//  amMath::amSphere sph2;
//  EXPECT_EQ(sph1, sph2);
//}



