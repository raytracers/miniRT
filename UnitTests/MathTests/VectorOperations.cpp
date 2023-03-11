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
