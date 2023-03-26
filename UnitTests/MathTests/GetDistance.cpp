#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(GetDistance, TwoRandomPoints)
{
	double	dist;

	dist = get_distance(new_point(1, 4, 3), new_point(3, 4, 5));
	EXPECT_TRUE(dist > 2.82 && dist < 2.84);
}

TEST(GetDistance, PointAtOrigin)
{
	double	dist;

	dist = get_distance(new_point(0, 0, 0), new_point(3, 4, 5));
	EXPECT_TRUE(dist > 7.06 && dist < 7.08);
}

TEST(GetDistance, PointsAtSamePosition)
{
	double	dist;

	dist = get_distance(new_point(3, 3, 3), new_point(3, 3, 3));
	EXPECT_DOUBLE_EQ(dist, 0);
}
