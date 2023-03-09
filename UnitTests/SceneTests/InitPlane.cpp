#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, InitPlaneTest)
{
	char *plane_str = (char *) "0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225";
	char **attributes = ft_split(plane_str, ' ');
	union u_element element;
	int op_result = init_plane(attributes, &element);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(element.plane.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.origin.z, -10.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.x, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.y, 1.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.z, 0.0);
	EXPECT_EQ(element.plane.color, 0x0000FF);
	ft_free_array(attributes);

	plane_str = (char *) "0.0,0.0,0.0 0.0,1.0,0.0 0,0,0";
	attributes = ft_split(plane_str, ' ');
	op_result = init_plane(attributes, &element);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(element.plane.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.origin.z, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.x, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.y, 1.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.z, 0.0);
	EXPECT_EQ(element.plane.color, 0x000000);
	ft_free_array(attributes);

	plane_str = (char *) "-10.0,-10.0,-10.0 0.0,1.0,0.0 0,0,0";
	attributes = ft_split(plane_str, ' ');
	op_result = init_plane(attributes, &element);
	EXPECT_DOUBLE_EQ(element.plane.origin.y, -10.0);
	EXPECT_DOUBLE_EQ(element.plane.origin.x, -10.0);
	EXPECT_DOUBLE_EQ(element.plane.origin.z, -10.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.x, 0.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.y, 1.0);
	EXPECT_DOUBLE_EQ(element.plane.normal.z, 0.0);
	EXPECT_EQ(element.plane.color, 0x000000);
	ft_free_array(attributes);
}
