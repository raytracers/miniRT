#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

void	print_matrix(double **m)
{
	std::cout << m[0][0] << '|' << m[0][1] << '|' << m[0][2] << '|' << m[0][3] << '|' << std::endl;
	std::cout << m[1][0] << '|' << m[1][1] << '|' << m[1][2] << '|' << m[1][3] << '|' << std::endl;
	std::cout << m[2][0] << '|' << m[2][1] << '|' << m[2][2] << '|' << m[2][3] << '|' << std::endl;
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
	return (vtm);
}

TEST(ViewTransformMatrix, PointAtRandomPosition)
{
	double	**vtm;
	t_point	p;

	vtm = view_transform_matrix("0,0,0 0,1,0 70");
	print_matrix(vtm);
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
}

TEST(ViewTransformMatrix, CameraAtZaxis)
{
	double	**vtm;
	t_point	p;

	vtm = view_transform_matrix("0,0,-20 0,0,1 70");
	print_matrix(vtm);
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
}
