#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, InitSphereTest)
{
	char *sphere_str = (char *) "0.0,0.0,20.6 12.6 10,0,255";
	char **attributes = ft_split(sphere_str, ' ');
	union u_element element;
	int op_result = init_sphere(attributes, &element);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(element.sphere.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(element.sphere.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(element.sphere.origin.z, 20.6);
	EXPECT_DOUBLE_EQ(element.sphere.diameter, 12.6);
	EXPECT_EQ(element.sphere.color, 0x0A00FF);

	ft_free_array(attributes);
}
