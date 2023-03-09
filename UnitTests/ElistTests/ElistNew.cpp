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
	EXPECT_DOUBLE_EQ(node->element.sphere.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(node->element.sphere.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(node->element.sphere.origin.z, 20.6);
	EXPECT_DOUBLE_EQ(node->element.sphere.diameter, 12.6);
	EXPECT_EQ(node->element.sphere.color, 0x0A00FF);

	free(node);
	ft_free_array(content);
	
	content = ft_split("0.0,0.0,20.6 10,0,255", ' ');
	node = elist_new(sphere, content);
	EXPECT_EQ(node, nullptr);

	free(node);
	ft_free_array(content);
}
