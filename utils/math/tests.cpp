/*
 * tests.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: blroot
 */

#include <gtest/gtest.h>
#include "vec3.h"

using namespace math;

TEST(Vec3Test, NullVec) {
	vec3 v = vec3();

    ASSERT_EQ(v.x, 0.0f);
    ASSERT_EQ(v.y, 0.0f);
    ASSERT_EQ(v.z, 0.0f);
}

TEST(Vec3Test, UnitVecCreation) {
	vec3 v = vec3(1.0f, 1.0f, 1.0f);

    ASSERT_EQ(v.x, 1.0f);
    ASSERT_EQ(v.y, 1.0f);
    ASSERT_EQ(v.z, 1.0f);
}

TEST(Vec3Test, Add) {
	vec3 v = vec3(1.0f, 6.0f, 1.0f);
	vec3 w = vec3(5.0f, 1.0f, 0.0f);

	vec3 u = v + w;

	ASSERT_EQ(u.x, 6.0f);
	ASSERT_EQ(u.y, 7.0f);
	ASSERT_EQ(u.z, 1.0f);
}

TEST(Vec3Test, Substract) {
	vec3 v = vec3(1.0f, 6.0f, 1.0f);
	vec3 w = vec3(5.0f, 1.0f, 0.0f);

	vec3 u = v - w;

	ASSERT_EQ(u.x, -4.0f);
	ASSERT_EQ(u.y, 5.0f);
	ASSERT_EQ(u.z, 1.0f);
}

TEST(Vec3Test, ByScalarProduct) {
	vec3 v = vec3(1.0f, 6.0f, 2.0f);

	vec3 u = 5*v;

	ASSERT_EQ(u.x, 5.0f);
	ASSERT_EQ(u.y, 30.0f);
	ASSERT_EQ(u.z, 10.0f);
}

TEST(Vec3Test, Normalize) {
	vec3 v = vec3(5.0f, 3.0f, 2.0f);
	vec3 versor_v = v.normalize();

    ASSERT_FLOAT_EQ(versor_v.x, 0.8111071);
    ASSERT_FLOAT_EQ(versor_v.y, 0.48666427);
    ASSERT_FLOAT_EQ(versor_v.z, 0.32444283);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
