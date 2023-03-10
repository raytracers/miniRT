#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidCylinderTest)
{
	char **attributes = ft_split("50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255", ' ');
	union u_object object;

	EXPECT_FALSE(init_cylinder(attributes, &object));
	EXPECT_DOUBLE_EQ(object.cylinder.origin.x, 50.0);
	EXPECT_DOUBLE_EQ(object.cylinder.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.origin.z, 20.6);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.x, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.y, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.z, 1.0);
	EXPECT_DOUBLE_EQ(object.cylinder.diameter, 14.2);
	EXPECT_DOUBLE_EQ(object.cylinder.height, 21.42);
	EXPECT_EQ(object.cylinder.color, 0x0A00FF);
	ft_free_array(attributes);

	attributes = ft_split("0.0,0.0,0.0 1.0,0.0,0.0 0.0 0.0 0,0,0", ' ');
	EXPECT_FALSE(init_cylinder(attributes, &object));
	EXPECT_DOUBLE_EQ(object.cylinder.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.origin.z, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.x, 1.0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.y, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.z, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.diameter, 0.0);
	EXPECT_DOUBLE_EQ(object.cylinder.height, 0.0);
	EXPECT_EQ(object.cylinder.color, 0x000000);
	ft_free_array(attributes);

	attributes = ft_split("-1.0,-1.0,-1.0 0,-1.0,0 -1.0 -1.0 0,0,0", ' ');
	EXPECT_FALSE(init_cylinder(attributes, &object));
	EXPECT_DOUBLE_EQ(object.cylinder.origin.x, -1.0);
	EXPECT_DOUBLE_EQ(object.cylinder.origin.y, -1.0);
	EXPECT_DOUBLE_EQ(object.cylinder.origin.z, -1.0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.x, 0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.y, -1.0);
	EXPECT_DOUBLE_EQ(object.cylinder.orientation.z, 0);
	EXPECT_DOUBLE_EQ(object.cylinder.diameter, -1.0);
	EXPECT_DOUBLE_EQ(object.cylinder.height, -1.0);
	EXPECT_EQ(object.cylinder.color, 0x000000);
	ft_free_array(attributes);
}

void	test_init_cylinder(char *input_str)
{
	union u_object object;
	char			**attributes;	

	attributes = ft_split(input_str, ' ');
	EXPECT_TRUE(init_cylinder(attributes, &object));
	ft_free_array(attributes);
}

TEST(SceneTests, InvalidCylinderTest)
{
	char *missing_color = (char *) "42.0,42.0,42.0 13.0 12.0";
	test_init_cylinder(missing_color);

	char *missing_coords = (char *) "0.0,1.0,0.0 11.0 13.0 255,255,255";
	test_init_cylinder(missing_coords);

	char *missing_diameter = (char *) "42.0,42.0,42.0 0.0,1.0,0.0 10.0 255,255,255"; 
	test_init_cylinder(missing_diameter);

	char *missing_all = (char *) " , , , , . . , , "; 
	test_init_cylinder(missing_all);

	char *normalized = (char *) "0.0,0.0,0.0 0.0,0.0,0.0 42.0 21.0 255,255,255";
	test_init_cylinder(normalized);

	char *empty = (char *) ""; 
	test_init_cylinder(empty);

	char *empty2 = (char *) "                     "; 
	test_init_cylinder(empty2);

	char *no_spaces = (char *) "0.0,0.0,0.00.0,0.0,11.0412.1312.0255,0,255"; 
	test_init_cylinder(no_spaces);

	char *wrong_delimiter = (char *) "50.0,0.0,20.6-0.0,0.0,1.0-14.2-21.42-10,0,255";
	test_init_cylinder(wrong_delimiter);
 
	char *wrong_coord_delimiter = (char *) "50.0;0.0;20.6 0.0,0.0,1.0 14.2 21.42 10,0,255";
	test_init_cylinder(wrong_coord_delimiter);

	char *wrong_color_delimiter = (char *) "50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10;0;255";
	test_init_cylinder(wrong_color_delimiter);

	char *vec4_coord = (char *) "0.0,0.0,0.0,0.0 1.0,0.0,0.0 12.0 11.0 255,0,255"; 
	test_init_cylinder(vec4_coord);

	char *triple_diameter = (char *) "0.0,0.0,0.0 1.0,0.0,0.0 12.0 25.0 30.0 255,0,255"; 
	test_init_cylinder(triple_diameter);

	char *cymk = (char *) "0.0,0.0,0.0 1.0,0.0,0.0 12.0 11.0 255,0,255,128"; 
	test_init_cylinder(cymk);
}

