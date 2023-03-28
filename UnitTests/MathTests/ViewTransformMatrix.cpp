#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

double	**view_transform_matrix(const char *str)
{
	t_camera	*c;
	double		**vtm;
	double		**rtm;
	char		**attr;

	attr = ft_split(str, ' ');
	init_camera(attr, &c);
	rtm = get_rtm(c);
	vtm = get_vtm(rtm, c);
	free_matrix(rtm);
	free(c);
	ft_free_array(attr);
	return (vtm);
}

TEST(ViewTransformMatrix, PointAtRandomPosition)
{
	double	**vtm;
	t_point	p;

	vtm = view_transform_matrix("0,0,0 0,1,0 70");
	p = new_point(20, 30, 50);
	p = transform_vector(p, vtm);
	EXPECT_DOUBLE_EQ(p.x, 20);
	EXPECT_DOUBLE_EQ(p.y, 50);
	EXPECT_DOUBLE_EQ(p.z, -30);
	p = transform_vector(new_point(0, 0, 50), vtm);
	EXPECT_DOUBLE_EQ(p.x, 0);
	EXPECT_DOUBLE_EQ(p.y, 50);
	EXPECT_DOUBLE_EQ(p.z, 0);
	p = transform_vector(new_point(0, 0, 0), vtm);
	EXPECT_DOUBLE_EQ(p.x, 0);
	EXPECT_DOUBLE_EQ(p.y, 0);
	EXPECT_DOUBLE_EQ(p.z, 0);
	free_matrix(vtm);
}

TEST(ViewTransformMatrix, CameraAtZaxis)
{
	double	**vtm;
	t_point	p;

	vtm = view_transform_matrix("0,0,-20 0,0,1 70");
	p = new_point(0, 0, 1);
	p = transform_vector(p, vtm);
	EXPECT_DOUBLE_EQ(p.x, 0);
	EXPECT_DOUBLE_EQ(p.y, 0);
	EXPECT_DOUBLE_EQ(p.z, -21);
	p = new_point(0, 0, -20);
	p = transform_vector(p, vtm);
	EXPECT_DOUBLE_EQ(p.x, 0);
	EXPECT_DOUBLE_EQ(p.y, 0);
	EXPECT_DOUBLE_EQ(p.z, 0);
	free_matrix(vtm);
}
