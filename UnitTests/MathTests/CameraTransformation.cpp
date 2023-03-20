#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

void	test_rotation(const char *str)
{
	t_camera	*c;
	double		**vtm;
	double		**rtm;
	char		**attr;

	attr = ft_split(str, ' ');
	init_camera(attr, &c);
	ASSERT_NE(c, nullptr);
	rtm = get_rtm(c);
	ASSERT_NE(rtm, nullptr);
	vtm = get_vtm(rtm, c);
	ASSERT_NE(vtm, nullptr);
	transform_camera(c, vtm, rtm);

	EXPECT_DOUBLE_EQ(c->origin.x, 0);
	EXPECT_DOUBLE_EQ(c->origin.y, 0);
	EXPECT_DOUBLE_EQ(c->origin.z, 0);
	EXPECT_TRUE(c->orientation.x > -0.001 && c->orientation.x < 0.001);
	EXPECT_TRUE(c->orientation.y > -0.001 && c->orientation.y < 0.001);
	EXPECT_DOUBLE_EQ(c->orientation.z, -1);
}

TEST(CameraTransformation, CameraAtRandompos)
{
	test_rotation("-50.0,0,20 0.424,0.566,0.707 70");
	test_rotation("42,21,84 0,0.707,0.707 70");
	test_rotation("-50,-50,-50 0,-0.707,0.707 70");
}

TEST(CameraTransformation, CameraAlignedWithZ)
{
	test_rotation("0,0,0 0,0,1 70");
	test_rotation("42,42,42 0,0,-1 70");
}
