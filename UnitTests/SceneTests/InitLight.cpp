#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidLight)
{
	char		**attributes;
	t_light		light;

	{
		attributes = ft_split((char *) "-40.0,50.0,0.0 0.6", ' ');
		EXPECT_EQ(init_light(attributes, &light), 0);
		EXPECT_DOUBLE_EQ(light.origin.x, -40.0);
		EXPECT_DOUBLE_EQ(light.origin.y, 50.0);
		EXPECT_DOUBLE_EQ(light.origin.z, 0.0);
		EXPECT_DOUBLE_EQ(light.brightness, 0.6);
		ft_free_array(attributes);
	}
	{
		attributes = ft_split((char *) "0.0,0.0,0.0 0.0", ' ');
		EXPECT_EQ(init_light(attributes, &light), 0);
		EXPECT_DOUBLE_EQ(light.origin.x, 0.0);
		EXPECT_DOUBLE_EQ(light.origin.y, 0.0);
		EXPECT_DOUBLE_EQ(light.origin.z, 0.0);
		EXPECT_DOUBLE_EQ(light.brightness, 0.0);
		ft_free_array(attributes);
	}
	{
		attributes = ft_split((char *) "42.0,42.0,42.0 1.0", ' ');
		EXPECT_EQ(init_light(attributes, &light), 0);
		EXPECT_DOUBLE_EQ(light.origin.x, 42.0);
		EXPECT_DOUBLE_EQ(light.origin.y, 42.0);
		EXPECT_DOUBLE_EQ(light.origin.z, 42.0);
		EXPECT_DOUBLE_EQ(light.brightness, 1.0);
		ft_free_array(attributes);
	}
}
