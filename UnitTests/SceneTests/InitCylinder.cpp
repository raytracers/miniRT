#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidCylinderTest)
{
	// 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
	char *cylinder_str = (char *) "50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255";
	char **attributes = ft_split(cylinder_str, ' ');
	union u_element element;
	int op_result = init_cylinder(attributes, &element);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.x, 50.0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.z, 20.6);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.x, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.y, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.z, 1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.diameter, 14.2);
	EXPECT_DOUBLE_EQ(element.cylinder.height, 21.42);
	EXPECT_EQ(element.cylinder.color, 0x0A00FF);
	ft_free_array(attributes);

	cylinder_str = (char *) "0.0,0.0,0.0 1.0,0.0,0.0 0.0 0.0 0,0,0";
	attributes = ft_split(cylinder_str, ' ');
	op_result = init_cylinder(attributes, &element);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.z, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.x, 1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.y, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.z, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.diameter, 0.0);
	EXPECT_DOUBLE_EQ(element.cylinder.height, 0.0);
	EXPECT_EQ(element.cylinder.color, 0x000000);
	ft_free_array(attributes);

	cylinder_str = (char *) "-1.0,-1.0,-1.0 -1.0,-1.0,-1.0 -1.0 -1.0 0,0,0";
	attributes = ft_split(cylinder_str, ' ');
	op_result = init_cylinder(attributes, &element);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.x, -1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.y, -1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.origin.z, -1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.x, -1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.y, -1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.orientation.z, -1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.diameter, -1.0);
	EXPECT_DOUBLE_EQ(element.cylinder.height, -1.0);
	EXPECT_EQ(element.cylinder.color, 0x000000);
	ft_free_array(attributes);
}

void	test_init_cylinder(char *input_str)
{
	union u_element element;
	char			**attributes;	
	int				op_result;	

	attributes = ft_split(input_str, ' ');
	op_result = init_sphere(attributes, &element);
	EXPECT_EQ(op_result, 1);
	ft_free_array(attributes);
}

TEST(SceneTests, InvalidCylinderTest)
{
	union u_element element;
	char			**attributes;	
	
	// missing fields
	char *missing_color = (char *) "42.0,42.0,42.0 13.0 12.0";
	test_init_cylinder(missing_color);

	char *missing_coords = (char *) "0.0,1.0,0.0 11.0 13.0 255,255,255";
	test_init_cylinder(missing_coords);

	char *missing_diameter = (char *) "42.0,42.0,42.0 0.0,1.0,0.0 11.0 10.0 255,255,255"; 
	test_init_cylinder(missing_diameter);

	char *missing_all = (char *) " , , , , . . , , "; 
	test_init_cylinder(missing_all);

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

	// more fields than necessary
	char *vec4_coord = (char *) "0.0,0.0,0.0,0.0 1.0,0.0,0.0 12.0 11.0 255,0,255"; 
	test_init_cylinder(vec4_coord);

	char *triple_diameter = (char *) "0.0,0.0,0.0 1.0,0.0,0.0 12.0 25.0 30.0 255,0,255"; 
	test_init_cylinder(triple_diameter);

	char *cymk = (char *) "0.0,0.0,0.0 1.0,0.0,0.0 12.0 11.0 255,0,255,128"; 
	test_init_cylinder(cymk);
}

