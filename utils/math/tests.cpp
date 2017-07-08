/*
 * tests.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: blroot
 */

#include <gtest/gtest.h>
#include "vec3.h"
#include "mat3.h"

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

TEST(Vec3Test, ScalarMultiplication) {
	vec3 v = vec3(1.0f, 6.0f, 2.0f);

	vec3 u = 5*v;

	ASSERT_EQ(u.x, 5.0f);
	ASSERT_EQ(u.y, 30.0f);
	ASSERT_EQ(u.z, 10.0f);
}

TEST(Vec3Test, DotProduct) {
	vec3 v = vec3(1.0f, 6.0f, 2.0f);
	vec3 w = vec3(5.0f, 1.0f, 0.0f);

	float u = v.dot(w);

	ASSERT_EQ(u, 11.0f);
}

TEST(Vec3Test, Normalize) {
	vec3 v = vec3(5.0f, 3.0f, 2.0f);
	vec3 versor_v = v.normalize();

    ASSERT_FLOAT_EQ(versor_v.x, 0.8111071);
    ASSERT_FLOAT_EQ(versor_v.y, 0.48666427);
    ASSERT_FLOAT_EQ(versor_v.z, 0.32444283);
}

TEST(Vec3Test, Cross) {
	vec3 v = vec3(1.0f, 0.0f, 0.0f);
	vec3 w = vec3(0.0f, 1.0f, 0.0f);

	vec3 u = v.cross(w);

	ASSERT_EQ(u.x, 0.0f);
	ASSERT_EQ(u.y, 0.0f);
	ASSERT_EQ(u.z, 1.0f);
}

TEST(Mat3Test, NullMat) {
	mat3 M = mat3();

	ASSERT_FLOAT_EQ(M.elements[0], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[1], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[2], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[3], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[4], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[5], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[6], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[7], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[8], 0.0f);
}

TEST(Mat3Test, DiagonalMat) {
	mat3 M = mat3(1.0f);

	ASSERT_FLOAT_EQ(M.elements[0], 1.0f);
	ASSERT_FLOAT_EQ(M.elements[1], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[2], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[3], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[4], 1.0f);
	ASSERT_FLOAT_EQ(M.elements[5], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[6], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[7], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[8], 1.0f);
}

TEST(Mat3Test, DiagonalDeterminant) {
	mat3 M = mat3(1.0f);

	ASSERT_FLOAT_EQ(M.determinant(), 1.0f);
}

TEST(Mat3Test, Determinant) {
	mat3 M = mat3(1.0f, 2.0f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f);

	ASSERT_FLOAT_EQ(M.determinant(), -1.0f);
}

TEST(Mat3Test, Transpose) {
	mat3 M = mat3(1.0f, 2.0f, 3.0f, 5.0f, 2.0f, 3.0f, 6.0f, 2.0f, 3.0f).transpose();

	ASSERT_FLOAT_EQ(M.elements[0], 1.0f);
	ASSERT_FLOAT_EQ(M.elements[1], 2.0f);
	ASSERT_FLOAT_EQ(M.elements[2], 3.0f);
	ASSERT_FLOAT_EQ(M.elements[3], 5.0f);
	ASSERT_FLOAT_EQ(M.elements[4], 2.0f);
	ASSERT_FLOAT_EQ(M.elements[5], 3.0f);
	ASSERT_FLOAT_EQ(M.elements[6], 6.0f);
	ASSERT_FLOAT_EQ(M.elements[7], 2.0f);
	ASSERT_FLOAT_EQ(M.elements[8], 3.0f);
}

TEST(Mat3Test, Inverse) {
	mat3 M = mat3(1.0f, 2.0f, 3.0f, 2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f).inverse();

	ASSERT_FLOAT_EQ(M.elements[0], -1.0f);
	ASSERT_FLOAT_EQ(M.elements[1], 1.0f);
	ASSERT_FLOAT_EQ(M.elements[2], 0.0f);
	ASSERT_FLOAT_EQ(M.elements[3], -1.0f);
	ASSERT_FLOAT_EQ(M.elements[4], 2.0f);
	ASSERT_FLOAT_EQ(M.elements[5], -1.0f);
	ASSERT_FLOAT_EQ(M.elements[6], 4.0f);
	ASSERT_FLOAT_EQ(M.elements[7], -5.0f);
	ASSERT_FLOAT_EQ(M.elements[8], 2.0f);
}

TEST(Mat3Test, ScalarMultiplication) {
	mat3 M = mat3(1.0f, 2.0f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f);
	M = 3*M;

	ASSERT_FLOAT_EQ(M.elements[0], 3.0f);
	ASSERT_FLOAT_EQ(M.elements[1], 6.0f);
	ASSERT_FLOAT_EQ(M.elements[2], 3.0f);
	ASSERT_FLOAT_EQ(M.elements[3], 6.0f);
	ASSERT_FLOAT_EQ(M.elements[4], 6.0f);
	ASSERT_FLOAT_EQ(M.elements[5], 3.0f);
	ASSERT_FLOAT_EQ(M.elements[6], 3.0f);
	ASSERT_FLOAT_EQ(M.elements[7], 3.0f);
	ASSERT_FLOAT_EQ(M.elements[8], 3.0f);
}

int main(int argc, char **argv) {
    mat3 M = mat3(1.0f, 2.0f, 1.0f, 2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f).inverse();
    printf("%.2f \n", M.elements[0]);
    printf("%.2f\n", M.elements[1]);
    printf("%.2f\n", M.elements[2]);
    printf("%.2f\n", M.elements[3]);
    printf("%.2f\n", M.elements[4]);
    printf("%.2f\n", M.elements[5]);
    printf("%.2f\n", M.elements[6]);
    printf("%.2f\n", M.elements[7]);
    printf("%.2f\n", M.elements[8]);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
