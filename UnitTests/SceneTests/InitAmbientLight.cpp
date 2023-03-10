#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidAmbientLight)
{
	t_a_light amb_light;
	char	  **attributes;

	attributes = ft_split((char *) "0.2 255,255,255", ' ');
	EXPECT_EQ(init_ambient_light(attributes, &amb_light), 0);
	EXPECT_DOUBLE_EQ(amb_light.ratio, 0.2);
	EXPECT_EQ(amb_light.color, 0xFFFFFF);
}
