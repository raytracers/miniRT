#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(IsNormalized, NormalVectors)
{
{
	t_point	v = { 0, 0, 1 };
	EXPECT_TRUE(is_normalized(v));
}
{
	t_point	v = { 0, 1, 0 };
	EXPECT_TRUE(is_normalized(v));
}
{
	t_point	v = { 1, 0, 0 };
	EXPECT_TRUE(is_normalized(v));
}
{
	t_point	v = { 0.707, 0.707, 0 };
	EXPECT_TRUE(is_normalized(v));
}
{
	t_point	v = { 0.577, 0.577, 0.577 };
	EXPECT_TRUE(is_normalized(v));
}
{
	t_point	v = { -0.061, 0.511, -0.858 };
	EXPECT_TRUE(is_normalized(v));
}
{
	t_point	v = { 0.267, 0.535, 0.802 };
	EXPECT_TRUE(is_normalized(v));
}
}

TEST(IsNormalized, UnnormalizedVectors)
{
{
	t_point	v = { 1, 1, 1 };
	EXPECT_FALSE(is_normalized(v));
}
{
	t_point	v = { 0, 0, 2 };
	EXPECT_FALSE(is_normalized(v));
}
{
	t_point	v = { 0, 2, 0 };
	EXPECT_FALSE(is_normalized(v));
}
{
	t_point	v = { 2, 0, 0 };
	EXPECT_FALSE(is_normalized(v));
}
{
	t_point	v = { 0.707, 0.707, 0.707 };
	EXPECT_FALSE(is_normalized(v));
}
{
	t_point	v = { 0.42, 0.42, 0.42 };
	EXPECT_FALSE(is_normalized(v));
}
{
	t_point	v = { -0.577, 0, 0.577 };
	EXPECT_FALSE(is_normalized(v));
}
{
	t_point	v = { -1, 0, 1 };
	EXPECT_FALSE(is_normalized(v));
}
}
