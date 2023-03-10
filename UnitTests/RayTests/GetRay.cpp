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

	EXPECT_TRUE(ray.orientation.x > 0.678 && ray.orientation.x < 0.680);
	EXPECT_TRUE(ray.orientation.y > 0.314 && ray.orientation.y < 0.316);
	EXPECT_TRUE(ray.orientation.z > -0.664 && ray.orientation.z < -0.662);
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
