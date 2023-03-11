#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SphereIntersection, DubleIntersectingSpheres)
{
	u_object		s;
	t_intersection	inter;
{
	char			**attributes = ft_split("0.0,0.0,0.0 5.0 0,0,0", ' ');
	ASSERT_FALSE(init_sphere(attributes, &s));
	t_point			origin = { 0, 5, 0 };
	t_point			direction = { 0, -1, 0 };
	t_ray			ray = {origin, direction};
	inter = sphere_intersection(ray, s);
}
	EXPECT_TRUE(inter.exists);
	EXPECT_DOUBLE_EQ(inter.distance, 2.5);
	EXPECT_DOUBLE_EQ(inter.location.x, 0);
	EXPECT_DOUBLE_EQ(inter.location.y, 2.5);
	EXPECT_DOUBLE_EQ(inter.location.z, 0);
	EXPECT_DOUBLE_EQ(inter.normal.x, 0);
	EXPECT_DOUBLE_EQ(inter.normal.y, 1);
	EXPECT_DOUBLE_EQ(inter.normal.z, 0);
{
	char			**attributes = ft_split("0.0,0.0,0.0 10.0 0,0,0", ' ');
	ASSERT_FALSE(init_sphere(attributes, &s));
	t_point			origin = { 0, 0, 0 };
	t_point			direction = { 0, 0, 1 };
	t_ray			ray = {origin, direction};
	inter = sphere_intersection(ray, s);
}
	EXPECT_TRUE(inter.exists);
	EXPECT_TRUE(inter.distance > 4.499 && inter.distance < 5.501);
	EXPECT_TRUE(inter.location.x > -0.001 && inter.location.x < 0.001);
	EXPECT_TRUE(inter.location.y > -0.001 && inter.location.y < 0.001);
	EXPECT_TRUE(inter.location.z > 4.499 && inter.location.z < 5.501);
	EXPECT_TRUE(inter.normal.x > -0.001 && inter.normal.x < 0.001);
	EXPECT_TRUE(inter.normal.y > -0.001 && inter.normal.y < 0.001);
	EXPECT_TRUE(inter.normal.z > 0.999 && inter.normal.z < 1.001);
}

TEST(SphereIntersection, SingleIntersectingSphere)
{
	u_object		s;
	t_intersection	inter;
{
	char			**attributes = ft_split("0.0,0.0,0.0 4.0 0,0,0", ' ');
	ASSERT_FALSE(init_sphere(attributes, &s));
	t_point			origin = { 2, 2, 0 };
	t_point			direction = { -1, 0, 0 };
	t_ray			ray = {origin, direction};
	inter = sphere_intersection(ray, s);
}
	EXPECT_TRUE(inter.exists);
	EXPECT_TRUE(inter.distance > 1.999 && inter.distance < 2.001);
	EXPECT_TRUE(inter.location.x > -0.001 && inter.location.x < 0.001);
	EXPECT_TRUE(inter.location.y > 1.999 && inter.location.y < 2.001);
	EXPECT_TRUE(inter.location.z > -0.001 && inter.location.z < 0.001);
	EXPECT_TRUE(inter.normal.x > -0.001 && inter.normal.x < 0.001);
	EXPECT_TRUE(inter.normal.y > 0.999 && inter.normal.y < 1.001);
	EXPECT_TRUE(inter.normal.z > -0.001 && inter.normal.z < 0.001);
}

TEST(SphereIntersection, NoIntersectionSphere)
{
	u_object		s;
	t_intersection	inter;
{
	char			**attributes = ft_split("0.0,0.0,0.0 2.0 0,0,0", ' ');
	ASSERT_FALSE(init_sphere(attributes, &s));
	t_point			origin = { 2, 3, 0 };
	t_point			direction = { -1, 0, 0 };
	t_ray			ray = {origin, direction};
	inter = sphere_intersection(ray, s);
}
	EXPECT_FALSE(inter.exists);
}
