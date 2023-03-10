#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidSphereTest)
{
	char *sphere_str = (char *) "0.0,0.0,20.6 12.6 10,0,255";
	char **attributes = ft_split(sphere_str, ' ');
	union u_object object;
	int op_result = init_sphere(attributes, &object);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.z, 20.6);
	EXPECT_DOUBLE_EQ(object.sphere.diameter, 12.6);
	EXPECT_EQ(object.sphere.color, 0x0A00FF);
	ft_free_array(attributes);

	sphere_str = (char *) "-1.0,-1.0,-1.0 -42.42 255,255,255";
	attributes = ft_split(sphere_str, ' ');
	op_result = init_sphere(attributes, &object);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.y, -1.0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.x, -1.0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.z, -1.0);
	EXPECT_DOUBLE_EQ(object.sphere.diameter, -42.42);
	EXPECT_EQ(object.sphere.color, 0xFFFFFF);
	ft_free_array(attributes);

	sphere_str = (char *) "0.0,0.0,0.0 0.0 0,0,0";
	attributes = ft_split(sphere_str, ' ');
	op_result = init_sphere(attributes, &object);
	EXPECT_EQ(op_result, 0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.y, 0.0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.x, 0.0);
	EXPECT_DOUBLE_EQ(object.sphere.origin.z, 0.0);
	EXPECT_DOUBLE_EQ(object.sphere.diameter, 0.0);
	EXPECT_EQ(object.sphere.color, 0x000000);
	ft_free_array(attributes);
}

void	test_init_sphere(char *input_str)
{
	union u_object object;
	char			**attributes;	
	int				op_result;	

	attributes = ft_split(input_str, ' ');
	op_result = init_sphere(attributes, &object);
	EXPECT_EQ(op_result, 1);
	ft_free_array(attributes);
}

TEST(SceneTests, InvalidSphereTest)
{
	union u_object object;
	char			**attributes;	
	int				op_result;	
	
	// missing fields
	char *missing_color = (char *) "42.0,42.0,42.0 13.0";
	test_init_sphere(missing_color);

	char *missing_coords = (char *) "13.0 255,255,255";
	test_init_sphere(missing_coords);

	char *missing_diameter = (char *) "0.0,0.0,0.0 255,255,255"; 
	test_init_sphere(missing_diameter);

	char *missing_all = (char *) " , , . , , "; 
	test_init_sphere(missing_all);

	char *empty = (char *) ""; 
	test_init_sphere(empty);

	char *empty2 = (char *) "                     "; 
	test_init_sphere(empty2);

	char *no_spaces = (char *) "0.0,0.0,0.012.0255,0,255"; 
	test_init_sphere(no_spaces);

	char *wrong_delimiter = (char *) "0.0,0.0,0.0-12.0-255,0,255"; 
	test_init_sphere(wrong_delimiter);

	char *wrong_coord_delimiter = (char *) "0.0;0.0;0.0 12.0 255,0,255"; 
	test_init_sphere(wrong_coord_delimiter);

	char *wrong_color_delimiter = (char *) "0.0,0.0,0.0 12.0 255;0;255"; 
	test_init_sphere(wrong_color_delimiter);

	// more fields than necessary
	char *vec4_coord = (char *) "0.0,0.0,0.0,0.0 12.0 255,0,255"; 
	test_init_sphere(vec4_coord);

	char *double_diameter = (char *) "0.0,0.0,0.0 12.0 25.0 255,0,255"; 
	test_init_sphere(double_diameter);

	char *cymk = (char *) "0.0,0.0,0.0 12.0 255,0,255,128"; 
	test_init_sphere(cymk);
}

