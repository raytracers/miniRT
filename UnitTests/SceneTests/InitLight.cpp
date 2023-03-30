#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidLight)
{
	char		**attributes;
	t_light		*light;

	{
		light = NULL;
		attributes = ft_split((char *) "-40.0,50.0,0.0 0.6", ' ');
		EXPECT_EQ(init_light(attributes, &light), 0);
		EXPECT_DOUBLE_EQ(light->origin.x, -40.0);
		EXPECT_DOUBLE_EQ(light->origin.y, 50.0);
		EXPECT_DOUBLE_EQ(light->origin.z, 0.0);
		EXPECT_DOUBLE_EQ(light->brightness, 0.6);
		EXPECT_EQ(light->color, 0XFFFFFF);
		ft_free_array(attributes);
	}
	{
		light = NULL;
		attributes = ft_split((char *) "0.0,0.0,0.0 0.0 0,0,0", ' ');
		EXPECT_EQ(init_light(attributes, &light), 0);
		EXPECT_DOUBLE_EQ(light->origin.x, 0.0);
		EXPECT_DOUBLE_EQ(light->origin.y, 0.0);
		EXPECT_DOUBLE_EQ(light->origin.z, 0.0);
		EXPECT_DOUBLE_EQ(light->brightness, 0.0);
		EXPECT_EQ(light->color, 0);
		ft_free_array(attributes);
	}
	{
		light = NULL;
		attributes = ft_split((char *) "42.0,42.0,42.0 1.0 255,0,255", ' ');
		EXPECT_EQ(init_light(attributes, &light), 0);
		EXPECT_DOUBLE_EQ(light->origin.x, 42.0);
		EXPECT_DOUBLE_EQ(light->origin.y, 42.0);
		EXPECT_DOUBLE_EQ(light->origin.z, 42.0);
		EXPECT_DOUBLE_EQ(light->brightness, 1.0);
		EXPECT_EQ(light->color, 0XFF00FF);
		ft_free_array(attributes);
	}
}

void	test_init_light(char *str)
{
	char		**attributes;
	t_light		*light;

	light = NULL;
	attributes = ft_split(str, ' ');
	EXPECT_EQ(init_light(attributes, &light), 1);
	ft_free_array(attributes);
}

TEST(SceneTests, MissingArgInitLight)
{
	char *missing_brightness = (char *) "-40.0,50.0,0.0";
	test_init_light(missing_brightness);

	char *missing_origin = (char *) "1.0";
	test_init_light(missing_origin);

	char *no_arg = (char *) "";
	test_init_light(no_arg);

	char *empty = (char *) "                              ";
	test_init_light(empty);
}

TEST(SceneTests, ExcessArgInitLight)
{
	char *excess_brightness = (char *) "-40.0,50.0,0.0 0.5 0.6";
	test_init_light(excess_brightness);

	char *excess_point_field = (char *) "-40.0,50.0,0.0,1.0 0.5";
	test_init_light(excess_point_field);
}

TEST(SceneTests, InvalidArgInitLight)
{
	char *out_of_range_brightness = (char *) "-40.0,50.0,0.0 1.1";
	test_init_light(out_of_range_brightness);

	char *out_of_range_brightness2 = (char *) "-40.0,50.0,0.0 -0.1";
	test_init_light(out_of_range_brightness2);

	char *out_of_range_brightness3 = (char *) "-40.0,50.0,0.0 -1.0";
	test_init_light(out_of_range_brightness3);

	char *wrong_order = (char *) "0.2 -40.0,50.0,0.0";
	test_init_light(wrong_order);
}

TEST(SceneTests, WrongFormatArgInitLight)
{
	char *wrong_brightness_delim = (char *) "-40.0,50.0,0.0 0,2";
	test_init_light(wrong_brightness_delim);

	char *wrong_point_delim = (char *) "-40.0;50.0;0.0 0.2";
	test_init_light(wrong_point_delim);

	char *just_delim = (char *) " . , , ";
	test_init_light(just_delim);

	char *no_space = (char *) "-40.0,50.0,0.00.2";
	test_init_light(no_space);
 
	char *wrong_separator = (char *) "-40.0,50.0,0.0-0.2";
	test_init_light(wrong_separator);

	char *missing_point_component = (char *) "-40.0,0.0 0.2";
	test_init_light(missing_point_component);
}
