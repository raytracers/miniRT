#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(PlaneIntersection, SimplePlaneIntersect)
{
	u_object		pl;
	t_intersection	inter;
	t_ray			r; 

	char			**attributes = ft_split("10.0,10.0,-10.0 0,1,0 0,0,255", ' ');
	ASSERT_FALSE(init_plane(attributes, &pl));
	t_point			origin = { 0, 0, 0 };
	t_point			direction = { 0, 1, 0 };
	t_ray			ray = {origin, direction};
	inter = plane_intersection(ray, pl);	

	EXPECT_TRUE(inter.exists);
	EXPECT_DOUBLE_EQ(inter.distance, 10);
	EXPECT_DOUBLE_EQ(inter.location.x, 0);
	EXPECT_DOUBLE_EQ(inter.location.y, 10);
	EXPECT_DOUBLE_EQ(inter.location.z, 0);
	EXPECT_DOUBLE_EQ(inter.normal.x, 0);
	EXPECT_DOUBLE_EQ(inter.normal.y, -1);
	EXPECT_DOUBLE_EQ(inter.normal.z, 0);
	EXPECT_DOUBLE_EQ(inter.color, 255);
}

TEST(PlaneIntersection, PlaneBehind)
{
	u_object		pl;
	t_intersection	inter;
	t_ray			r;

	char			**attributes = ft_split("10.0,10.0,-10.0 0,1,0 0,0,255", ' ');
	ASSERT_FALSE(init_plane(attributes, &pl));
	t_point			origin = { 0, 0, 0 };
	t_point			direction = { 0, -1, 0 };
	t_ray			ray = {origin, direction};
	inter = plane_intersection(ray, pl);

	EXPECT_FALSE(inter.exists);
}

TEST(PlaneIntersection, PlaneOppositeNormalBehind)
{
	u_object		pl;
	t_intersection	inter;
	t_ray			r;

	char			**attributes = ft_split("10.0,10.0,-10.0 0,-1.0,0 0,0,255", ' ');
	ASSERT_FALSE(init_plane(attributes, &pl));
	t_point			origin = { 0, 0, 0 };
	t_point			direction = { 0, 1, 0 };
	t_ray			ray = {origin, direction};
	inter = plane_intersection(ray, pl);

	EXPECT_TRUE(inter.exists);
	EXPECT_DOUBLE_EQ(inter.distance, 10);
	EXPECT_DOUBLE_EQ(inter.location.x, 0);
	EXPECT_DOUBLE_EQ(inter.location.y, 10);
	EXPECT_DOUBLE_EQ(inter.location.z, 0);
	EXPECT_DOUBLE_EQ(inter.normal.x, 0);
	EXPECT_DOUBLE_EQ(inter.normal.y, -1);
	EXPECT_DOUBLE_EQ(inter.normal.z, 0);
	EXPECT_DOUBLE_EQ(inter.color, 255);
}
