#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

void init_scene(t_scene *scene);

TEST(CylinderIntersection, SimpleCylinderIntersect)
{
	u_object		cy;
	t_intersection	inter;

{
	char **attributes = ft_split("0,10,0 0.0,1.0,0.0 12.4 10.42 10,0,255", ' ');
	ASSERT_FALSE(init_cylinder(attributes, &cy));
	t_point origin = { 0, 0, 0};
	t_point direction = {0, 1, 0 };
	t_ray ray = {origin, direction};
	inter = cylinder_intersection(ray, cy);
}
	// aligned on the y axis
	EXPECT_TRUE(inter.exists);
	EXPECT_DOUBLE_EQ(inter.distance, 10);
	EXPECT_DOUBLE_EQ(inter.location.x, 0);
	EXPECT_DOUBLE_EQ(inter.location.y, 10);
	EXPECT_DOUBLE_EQ(inter.location.z, 0);
	EXPECT_DOUBLE_EQ(inter.normal.x, 0);
	EXPECT_DOUBLE_EQ(inter.normal.y, -1);
	EXPECT_DOUBLE_EQ(inter.normal.z, 0);
	EXPECT_DOUBLE_EQ(inter.color, 655615);
{
	// aligned on the x axis.
	char **attributes = ft_split("10,10,0 -1.0,0.0,0.0 12.4 10.42 10,0,255", ' ');
	ASSERT_FALSE(init_cylinder(attributes, &cy));
	t_point origin = { 0, 0, 0};
	t_point direction = {0, 1, 0 };
	t_ray ray = {origin, direction};
	inter = cylinder_intersection(ray, cy);
}
	EXPECT_TRUE(inter.exists);
	EXPECT_DOUBLE_EQ(inter.distance, 3.8);
	EXPECT_DOUBLE_EQ(inter.location.x, 0);
	EXPECT_DOUBLE_EQ(inter.location.y, 3.8);
	EXPECT_DOUBLE_EQ(inter.location.z, 0);
	EXPECT_DOUBLE_EQ(inter.normal.x, 0);
	EXPECT_DOUBLE_EQ(inter.normal.y, -1);
	EXPECT_DOUBLE_EQ(inter.normal.z, 0);
	EXPECT_DOUBLE_EQ(inter.color, 655615);
{
	// aligned on the x axis.
	char **attributes = ft_split("0,5,0 0.0,0.0,1.0 4.50 10.42 10,0,255", ' ');
	ASSERT_FALSE(init_cylinder(attributes, &cy));
	t_point origin = { 0, 0, 0};
	t_point direction = {0, 1, 0 };
	t_ray ray = {origin, direction};
	inter = cylinder_intersection(ray, cy);
}
	EXPECT_TRUE(inter.exists);
	EXPECT_DOUBLE_EQ(inter.distance, 2.75);
	EXPECT_DOUBLE_EQ(inter.location.x, 0);
	EXPECT_DOUBLE_EQ(inter.location.y, 2.75);
	EXPECT_DOUBLE_EQ(inter.location.z, 0);
	EXPECT_DOUBLE_EQ(inter.normal.x, 0);
	EXPECT_DOUBLE_EQ(inter.normal.y, -1);
	EXPECT_DOUBLE_EQ(inter.normal.z, 0);
	EXPECT_DOUBLE_EQ(inter.color, 655615);
}

TEST(CylinderIntersection, NoIntersectionCylinder)
{
	char **attributes = ft_split("0,5,0 1.0,0.0,0.0 2.5 10.42 10,0,255", ' ');
	u_object		cy;
	t_intersection	inter;

	ASSERT_FALSE(init_cylinder(attributes, &cy));
	t_point origin = { 0, 0, 0};
	t_point direction = {0, -1, 0 };
	t_ray ray = {origin, direction};
	inter = cylinder_intersection(ray, cy);

	EXPECT_EQ(inter.exists, 0);
}
