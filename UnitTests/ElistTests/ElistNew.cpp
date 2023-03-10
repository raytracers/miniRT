#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(ElistNew, NewSphere)
{
	t_elist	*node;
	char **content = ft_split("0.0,0.0,20.6 12.6 10,0,255", ' ');

	node = elist_new(sphere, content);
	ASSERT_NE(node, nullptr);
	EXPECT_DOUBLE_EQ(node->object.sphere.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(node->object.sphere.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(node->object.sphere.origin.z, 20.6);
	EXPECT_DOUBLE_EQ(node->object.sphere.diameter, 12.6);
	EXPECT_EQ(node->object.sphere.color, 0x0A00FF);

	free(node);
	ft_free_array(content);
	
	content = ft_split("0.0,0.0,20.6 10,0,255", ' ');
	node = elist_new(sphere, content);
	EXPECT_EQ(node, nullptr);

	free(node);
	ft_free_array(content);
}

TEST(ElistNew, NewCylinder)
{
	t_elist	*node;
	char **content = ft_split("50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255", ' ');

	node = elist_new(cylinder, content);
	ASSERT_NE(node, nullptr);
	EXPECT_DOUBLE_EQ(node->object.cylinder.origin.x, 50.0);
	EXPECT_DOUBLE_EQ(node->object.cylinder.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(node->object.cylinder.origin.z, 20.6);
	EXPECT_DOUBLE_EQ(node->object.cylinder.orientation.x, 0.0);
	EXPECT_DOUBLE_EQ(node->object.cylinder.orientation.y, 0.0);
	EXPECT_DOUBLE_EQ(node->object.cylinder.orientation.z, 1.0);
	EXPECT_DOUBLE_EQ(node->object.cylinder.diameter, 14.2);
	EXPECT_DOUBLE_EQ(node->object.cylinder.height, 21.42);
	EXPECT_EQ(node->object.cylinder.color, 0x0A00FF);

	free(node);
	ft_free_array(content);
	
	content = ft_split("50.0,0.0,20.6 14.2 21.42 10,0,255", ' ');
	node = elist_new(cylinder, content);
	EXPECT_EQ(node, nullptr);

	free(node);
	ft_free_array(content);
}
