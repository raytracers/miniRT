#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(GetPoint, ValidPoints)
{
	t_point	point;

	EXPECT_FALSE(get_point((char *)"42.42,-535.42,0.002", &point));
	EXPECT_DOUBLE_EQ(point.x, 42.42);
	EXPECT_DOUBLE_EQ(point.y, -535.42);
	EXPECT_DOUBLE_EQ(point.z, 0.002);
	EXPECT_FALSE(get_point((char *)"-0,-1,-2", &point));
	EXPECT_FALSE(get_point((char *)"+0,+1,+2", &point));
}

TEST(GetPoint, InvalidPoints)
{
	t_point	point;

	EXPECT_TRUE(get_point((char *)",,", &point));
	EXPECT_TRUE(get_point((char *)"+,+,+", &point));
	EXPECT_TRUE(get_point((char *)"++32,+2,+1", &point));
	EXPECT_TRUE(get_point((char *)"--32,-2,-1", &point));
	EXPECT_TRUE(get_point((char *)"F32,2,1", &point));
	EXPECT_TRUE(get_point((char *)"32f,2,1", &point));
	EXPECT_TRUE(get_point((char *)"32+,2+,1+", &point));
	EXPECT_TRUE(get_point((char *)"32-,2-,1-", &point));
	EXPECT_TRUE(get_point((char *)"32-,2-,1-", &point));
	EXPECT_TRUE(get_point((char *)"+32+2+1", &point));
	EXPECT_TRUE(get_point((char *)"3221", &point));
	EXPECT_TRUE(get_point((char *)"+3221", &point));
	EXPECT_TRUE(get_point((char *)"-0;-1;-2", &point));
}
