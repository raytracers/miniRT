#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(VectorOperations, VectorDifference)
{
	t_point	result;
	{
		t_point	a = { 0, 0, 0 };
		t_point	b = { 1, 2, 3 };
		result = vector_dif(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, -1.0);
	EXPECT_DOUBLE_EQ(result.y, -2.0);
	EXPECT_DOUBLE_EQ(result.z, -3.0);
	{
		t_point	a = { 1, 2, 3 };
		t_point	b = { 0, 0, 0 };
		result = vector_dif(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, 1.0);
	EXPECT_DOUBLE_EQ(result.y, 2.0);
	EXPECT_DOUBLE_EQ(result.z, 3.0);
	{
		t_point	a = { 1, 2, 3 };
		t_point	b = { -10, 4, 3 };
		result = vector_dif(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, 11.0);
	EXPECT_DOUBLE_EQ(result.y, -2.0);
	EXPECT_DOUBLE_EQ(result.z, 0.0);
}

TEST(VectorOperations, VectorSum)
{
	t_point	result;
	{
		t_point	a = { 0, 0, 0 };
		t_point	b = { 1, 2, 3 };
		result = vector_sum(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, 1.0);
	EXPECT_DOUBLE_EQ(result.y, 2.0);
	EXPECT_DOUBLE_EQ(result.z, 3.0);
	{
		t_point	a = { 1, 2, 3 };
		t_point	b = { 0, 0, 0 };
		result = vector_sum(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, 1.0);
	EXPECT_DOUBLE_EQ(result.y, 2.0);
	EXPECT_DOUBLE_EQ(result.z, 3.0);
	{
		t_point	a = { 1, 2, 3 };
		t_point	b = { -10, 4, 3 };
		result = vector_sum(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, -9.0);
	EXPECT_DOUBLE_EQ(result.y, 6.0);
	EXPECT_DOUBLE_EQ(result.z, 6.0);
}

TEST(VectorOperations, VectorScalarProduct)
{
	t_point	result;
	{
		t_point	v = { 0, 0, 0 };
		double	s = 42;
		result = vector_scalar_product(v, s);
	}
	EXPECT_DOUBLE_EQ(result.x, 0.0);
	EXPECT_DOUBLE_EQ(result.y, 0.0);
	EXPECT_DOUBLE_EQ(result.z, 0.0);
	{
		t_point	v = { 42, 42, 42 };
		double	s = 0;
		result = vector_scalar_product(v, s);
	}
	EXPECT_DOUBLE_EQ(result.x, 0.0);
	EXPECT_DOUBLE_EQ(result.y, 0.0);
	EXPECT_DOUBLE_EQ(result.z, 0.0);
	{
		t_point	v = { 2, 4, 8};
		double	s = 2;
		result = vector_scalar_product(v, s);
	}
	EXPECT_DOUBLE_EQ(result.x, 4.0);
	EXPECT_DOUBLE_EQ(result.y, 8.0);
	EXPECT_DOUBLE_EQ(result.z, 16.0);
}

TEST(VectorOperations, DotProduct)
{
	{
		t_point	a = { 0, 0, 0 };
		t_point	b = { 1, 2, 3 };
		EXPECT_DOUBLE_EQ(dot_product(a, b), 0.0);
	}
	{
		t_point	a = { 1, 2, 3 };
		t_point	b = { 0, 0, 0 };
		EXPECT_DOUBLE_EQ(dot_product(a, b), 0.0);
	}
	{
		t_point	a = { 1, 2, 3 };
		t_point	b = { -2, 6, 10 };
		EXPECT_DOUBLE_EQ(dot_product(a, b), 40.0);
	}
}
