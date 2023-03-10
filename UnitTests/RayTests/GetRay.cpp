#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(GetRay, ArgcTest)
{
{
	t_point	origin = {2.0, 1.0, 4.0};
	t_point	destination = {43.0, 20.0, -36.0};
	t_ray	ray = get_ray(origin, destination);

	EXPECT_TRUE(ray.orientation.x > 0.721 && ray.orientation.x < 0.723);
	EXPECT_TRUE(ray.orientation.y > 0.335 && ray.orientation.y < 0.337);
	EXPECT_TRUE(ray.orientation.z > -0.605 && ray.orientation.z < -0.603);
	EXPECT_DOUBLE_EQ(ray.origin.x, origin.x);
	EXPECT_DOUBLE_EQ(ray.origin.y, origin.y);
	EXPECT_DOUBLE_EQ(ray.origin.z, origin.z);
}
{
	t_point	origin = {2.0, 1.0, 4.0};
	t_point	destination= {0.134, -0.134, 0.982};
	t_ray	ray = get_ray(origin, destination);

	EXPECT_DOUBLE_EQ(ray.orientation.x, destination.x);
	EXPECT_DOUBLE_EQ(ray.orientation.y, destination.y);
	EXPECT_DOUBLE_EQ(ray.orientation.z, destination.z);
	EXPECT_DOUBLE_EQ(ray.origin.x, origin.x);
	EXPECT_DOUBLE_EQ(ray.origin.y, origin.y);
	EXPECT_DOUBLE_EQ(ray.origin.z, origin.z);
}
{
	t_point	origin = {3.0, 2.0, 1.0};
	t_point	destination= {0, 0, 0};
	t_ray	ray = get_ray(origin, destination);

	EXPECT_TRUE(ray.orientation.x > -0.803 && ray.orientation.x < -0.801);
	EXPECT_TRUE(ray.orientation.y > -0.536 && ray.orientation.y < -0.534);
	EXPECT_TRUE(ray.orientation.z > -0.268 && ray.orientation.z < -0.266);
	EXPECT_DOUBLE_EQ(ray.origin.x, origin.x);
	EXPECT_DOUBLE_EQ(ray.origin.y, origin.y);
	EXPECT_DOUBLE_EQ(ray.origin.z, origin.z);
}
{
	t_point	origin = {0, 0, 0};
	t_point	destination= {10, 5, 3};
	t_ray	ray = get_ray(origin, destination);

	EXPECT_TRUE(ray.orientation.x > 0.863 && ray.orientation.x < 0.864);
	EXPECT_TRUE(ray.orientation.y > 0.431 && ray.orientation.y < 0.433);
	EXPECT_TRUE(ray.orientation.z > 0.258 && ray.orientation.z < 0.260);
	EXPECT_DOUBLE_EQ(ray.origin.x, origin.x);
	EXPECT_DOUBLE_EQ(ray.origin.y, origin.y);
	EXPECT_DOUBLE_EQ(ray.origin.z, origin.z);
}
}
