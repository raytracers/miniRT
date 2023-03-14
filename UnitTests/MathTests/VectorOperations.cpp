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
		result = vector_scalar(v, s);
	}
	EXPECT_DOUBLE_EQ(result.x, 0.0);
	EXPECT_DOUBLE_EQ(result.y, 0.0);
	EXPECT_DOUBLE_EQ(result.z, 0.0);
	{
		t_point	v = { 42, 42, 42 };
		double	s = 0;
		result = vector_scalar(v, s);
	}
	EXPECT_DOUBLE_EQ(result.x, 0.0);
	EXPECT_DOUBLE_EQ(result.y, 0.0);
	EXPECT_DOUBLE_EQ(result.z, 0.0);
	{
		t_point	v = { 2, 4, 8};
		double	s = 2;
		result = vector_scalar(v, s);
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

TEST(VectorOperations, CrossProduct)
{
	t_point	result;
	{
		t_point	a = { 0, 0, 0 };
		t_point	b = { 1, 2, 3 };
		result = cross_product(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, 0.0);
	EXPECT_DOUBLE_EQ(result.y, 0.0);
	EXPECT_DOUBLE_EQ(result.z, 0.0);
	{
		t_point	a = { 1, 0, 0 };
		t_point	b = { 1, 0, 0 };
		result = cross_product(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, 0.0);
	EXPECT_DOUBLE_EQ(result.y, 0.0);
	EXPECT_DOUBLE_EQ(result.z, 0.0);
	{
		t_point	a = { 1, 5, 2 };
		t_point	b = { 3, 4, 6 };
		result = cross_product(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, 22.0);
	EXPECT_DOUBLE_EQ(result.y, 0.0);
	EXPECT_DOUBLE_EQ(result.z, -11.0);
	{
		t_point	a = { 0, -1, -3 };
		t_point	b = { -5, -4, 6 };
		result = cross_product(a, b); 
	}
	EXPECT_DOUBLE_EQ(result.x, -18.0);
	EXPECT_DOUBLE_EQ(result.y, 15.0);
	EXPECT_DOUBLE_EQ(result.z, -5.0);
}

TEST(VectorOperations, VectorTransformation)
{
	t_point	v;
	t_point	r;
	double	*m[4];
	double	last[4] = { 0, 0, 0, 1 };
	m[3] = last;

	{
		double	first[4] =	{1, 0, 0, 3};
		double	second[4] =	{2, 1, 0, -2};
		double	third[4] =	{3, 3, 3, 6};
		m[0] = first;
		m[1] = second;
		m[2] = third;
	}
	v.x = 1; v.y = 2; v.z = 3;
	r = transform_vector(v, m);
	EXPECT_DOUBLE_EQ(r.x, 1.0);
	EXPECT_DOUBLE_EQ(r.y, 4.0);
	EXPECT_DOUBLE_EQ(r.z, 18.0);

	{
		double	first[4] =	{0, 1, 3, -4};
		double	second[4] =	{0, 1, 2, 1};
		double	third[4] =	{3, 2, 1, 7};
		m[0] = first;
		m[1] = second;
		m[2] = third;
	}
	v.x = 7; v.y = -4; v.z = 1;
	r = transform_vector(v, m);
	EXPECT_DOUBLE_EQ(r.x, -1.0);
	EXPECT_DOUBLE_EQ(r.y, -2.0);
	EXPECT_DOUBLE_EQ(r.z, 14.0);
}
