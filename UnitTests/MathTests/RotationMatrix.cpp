#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

void	test_rotation(const char *str)
{
	t_camera	*c;
	double		**rtm;
	char		**attr;

	attr = ft_split(str, ' ');
	init_camera(attr, &c);
	ASSERT_NE(c, nullptr);
	rtm = get_rtm(c);
	ASSERT_NE(rtm, nullptr);
	c->orientation = transform_vector(c->orientation, rtm);

	EXPECT_TRUE(c->orientation.x > -0.001 && c->orientation.x < 0.001);
	EXPECT_TRUE(c->orientation.y > -0.001 && c->orientation.y < 0.001);
	EXPECT_DOUBLE_EQ(c->orientation.z, -1);
	ft_free_array(attr);
	free_matrix(rtm);
	free(c);
}

TEST(RotationMatrix, VectorAtRandomOrientation)
{
	test_rotation("-50.0,0,20 0.424,0.566,0.707 70");
	test_rotation("42,21,84 0,0.707,0.707 70");
	test_rotation("-50,-50,-50 0,-0.707,0.707 70");
	test_rotation("-50,-50,-50 0,1,0 70");
	test_rotation("-50,-50,-50 1,0,0 70");
}

TEST(RotationMatrix, VectorAlignedWithZaxis)
{
	test_rotation("0,0,0 0,0,1 70");
	test_rotation("42,42,42 0,0,-1 70");
}
