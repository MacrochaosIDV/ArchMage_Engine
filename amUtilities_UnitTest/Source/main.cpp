#include <amPrerequisitesUtilities.h>
#include <amMath.h>

#include <gtest\gtest.h>
//using namespace amEngineSDK;
//using amMath;



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(amMath_funcs, tesst) {
  
  float a = amEngineSDK::amMath::cos(1);

  EXPECT_EQ(amMath::pow(2, 3), 8);
  EXPECT_NE(amMath::pow(2, 3), 16);

  EXPECT_EQ(amMath::logX(2, 3), 8);// needs values set for testing
  EXPECT_NE(amMath::logX(2, 3), 16);// needs values set for testing

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

  EXPECT_EQ(amMath::fractional(1.4), 0.4);
  EXPECT_EQ(amMath::fractional(2.6), 0.6);
  EXPECT_NE(amMath::fractional(-1.4), -2);
  EXPECT_NE(amMath::fractional(-2.6), -3);

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

  
}

TEST(Shapes_3D, tesst) {

  amSphere sph1;
  amSphere sph2;
  EXPECT_EQ(sph1, sph2);

  
}



