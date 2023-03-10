#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, InitPlaneTest)
{
	char **attributes = ft_split("0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225", ' ');
	union u_object object;

	EXPECT_FALSE(init_plane(attributes, &object));
	EXPECT_DOUBLE_EQ(object.plane.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.origin.z, -10.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.x, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.y, 1.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.z, 0.0);
	EXPECT_EQ(object.plane.color, 0x0000E1);
	ft_free_array(attributes);

	attributes = ft_split("0.0,0.0,0.0 0.0,1.0,0.0 0,0,0", ' ');
	EXPECT_FALSE(init_plane(attributes, &object));
	EXPECT_DOUBLE_EQ(object.plane.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.origin.z, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.x, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.y, 1.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.z, 0.0);
	EXPECT_EQ(object.plane.color, 0x000000);
	ft_free_array(attributes);

	attributes = ft_split("-10.0,-10.0,-10.0 0.0,1.0,0.0 0,0,0", ' ');
	EXPECT_FALSE(init_plane(attributes, &object));
	EXPECT_DOUBLE_EQ(object.plane.origin.y, -10.0);
	EXPECT_DOUBLE_EQ(object.plane.origin.x, -10.0);
	EXPECT_DOUBLE_EQ(object.plane.origin.z, -10.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.x, 0.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.y, 1.0);
	EXPECT_DOUBLE_EQ(object.plane.normal.z, 0.0);
	EXPECT_EQ(object.plane.color, 0x000000);
	ft_free_array(attributes);
}

void	test_init_plane(char *input_str)
{
	union u_object object;
	char			**attributes;	

	attributes = ft_split(input_str, ' ');
	EXPECT_TRUE(init_plane(attributes, &object));
	ft_free_array(attributes);
}

TEST(SceneTests, MissingArgPlaneTest)
{
	char *missing_color = (char *) "0.0,0.0,-10.0 0.0,1.0,0.0";
	test_init_plane(missing_color);

	char *missing_coords = (char *) "0.0,1.0,0.0 0,0,225";
	test_init_plane(missing_coords);

	char *missing_normal = (char *) "0.0,0.0,-10.0 255,255,255"; 
	test_init_plane(missing_normal);

	char *normalized = (char *) "0.0,0.0,-10.0 0.0,0.0,0.0 255,255,255";
	test_init_plane(normalized);
}

TEST(SceneTests, WrongFormatPlaneTest)
{
	char *missing_all = (char *) " , , . , , "; 
	test_init_plane(missing_all);

	char *empty = (char *) ""; 
	test_init_plane(empty);

	char *empty2 = (char *) "                     "; 
	test_init_plane(empty2);

	char *no_spaces = (char *) "0.0,0.0,-10.00.0,0.0,0.055,0,255"; 
	test_init_plane(no_spaces);

	char *wrong_delimiter = (char *) "0.0,0.0,0.0-0.0,1.0,0.0-255,0,255"; 
	test_init_plane(wrong_delimiter);

	char *wrong_coord_delimiter = (char *) "0.0;0.0;0.0 0.0;1.0;0.0 255,0,255"; 
	test_init_plane(wrong_coord_delimiter);

	char *wrong_color_delimiter = (char *) "0.0,0.0,0.0 0.0,1.0,0.0 255;0;255"; 
	test_init_plane(wrong_color_delimiter);

	char *vec4_coord = (char *) "0.0,0.0,0.0,0.0 0.0,1.0,0.0 255,0,255"; 
	test_init_plane(vec4_coord);

	char *double_normal = (char *) "0.0,0.0,0.0 0.0,1.0,0.0 0.0,1.0,0.0 255,0,255"; 
	test_init_plane(double_normal);

	char *cymk = (char *) "0.0,0.0,0.0 0.0,1.0,0.0 255,0,255,128"; 
	test_init_plane(cymk);
}
