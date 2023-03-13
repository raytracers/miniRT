#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidAmbientLight)
{
	t_a_light *amb_light;
	char	  **attributes;

	amb_light = NULL;
	attributes = ft_split((char *) "0.2 255,255,255", ' ');
	EXPECT_EQ(init_ambient_light(attributes, &amb_light), 0);
	EXPECT_DOUBLE_EQ(amb_light->ratio, 0.2);
	EXPECT_EQ(amb_light->color, 0xFFFFFF);
	ft_free_array(attributes);
	free(amb_light);

	attributes = ft_split((char *) "0.0 0,0,0", ' ');
	EXPECT_EQ(init_ambient_light(attributes, &amb_light), 0);
	EXPECT_DOUBLE_EQ(amb_light->ratio, 0.0);
	EXPECT_EQ(amb_light->color, 0x000000);
	ft_free_array(attributes);
	free(amb_light);

	attributes = ft_split((char *) "2.0 255,255,255", ' ');
	EXPECT_EQ(init_ambient_light(attributes, &amb_light), 0);
	EXPECT_DOUBLE_EQ(amb_light->ratio, 2.0);
	EXPECT_EQ(amb_light->color, 0xFFFFFF);
	ft_free_array(attributes);
	free(amb_light);
}

void test_init_amb_light(char *str)
{
	char		**attributes;
	t_a_light	*amb_light;

	attributes = ft_split(str, ' ');
	amb_light = NULL;
	EXPECT_EQ(init_ambient_light(attributes, &amb_light), 1);
	free(amb_light);
	ft_free_array(attributes);
}

TEST(SceneTests, MissingArgInitAmbientLight)
{
	char *missing_ratio = (char *) "255,255,255";
	test_init_amb_light(missing_ratio);

	char *missing_color = (char *) "1.5";
	test_init_amb_light(missing_color);

	char *no_arg = (char *) "";
	test_init_amb_light(no_arg);

	char *empty = (char *) "                              ";
	test_init_amb_light(empty);
}

TEST(SceneTests, ExcessArgInitAmbientLight)
{
	char *excess_ratio = (char *) "0.2 1.2 255,255,255";
	test_init_amb_light(excess_ratio);

	char *excess_color_field = (char *) "0.4 255,255,255,0";
	test_init_amb_light(excess_color_field);

	char *excess_color = (char *) "0.2 255,255,255 0,0,0";
	test_init_amb_light(excess_color);
}

TEST(SceneTests, InvalidArgInitAmbientLight)
{
	char *out_of_range_ratio = (char *) "2.1 255,255,255";
	test_init_amb_light(out_of_range_ratio);

	char *out_of_range_ratio2 = (char *) "-0.1 255,255,255";
	test_init_amb_light(out_of_range_ratio2);

	char *out_of_range_ratio3 = (char *) "-2.0 255,255,255";
	test_init_amb_light(out_of_range_ratio3);

	char *out_of_range_color = (char *) "0.2 -1,255,255";
	test_init_amb_light(out_of_range_color);

	char *out_of_range_color2 = (char *) "0.2 0,122,257";
	test_init_amb_light(out_of_range_color2);

	char *wrong_order = (char *) "0,122,257 0.2";
	test_init_amb_light(wrong_order);
}

TEST(SceneTests, WrongFormatArgInitAmbientLight)
{
	char *wrong_color_delim = (char *) "0.2 255;255;255";
	test_init_amb_light(wrong_color_delim);

	char *wrong_ratio_symbol = (char *) "0,2 255,255,255";
	test_init_amb_light(wrong_ratio_symbol);

	char *just_delim = (char *) " . , , ";
	test_init_amb_light(just_delim);

	char *no_space = (char *) "2.1255,255,255";
	test_init_amb_light(no_space);

	char *wrong_separator = (char *) "0.2-255,255,255";
	test_init_amb_light(wrong_separator);

	char *missing_color_component = (char *) "1.0 255";
	test_init_amb_light(missing_color_component);
}

