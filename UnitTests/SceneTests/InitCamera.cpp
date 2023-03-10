#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneTests, ValidCamera)
{
	char		*camera_str= (char *) "-50.0,0,20 0,0,1 70";
	char		**attributes = ft_split(camera_str, ' ');
	t_camera	*cam = nullptr;

	EXPECT_FALSE(init_camera(attributes, &cam));
	ASSERT_NE(cam, nullptr);
	EXPECT_DOUBLE_EQ(cam->origin.x, -50.0);
	EXPECT_DOUBLE_EQ(cam->origin.y, 0.0);
	EXPECT_DOUBLE_EQ(cam->origin.z, 20.0);
	EXPECT_DOUBLE_EQ(cam->orientation.x, 0.0);
	EXPECT_DOUBLE_EQ(cam->orientation.y, 0.0);
	EXPECT_DOUBLE_EQ(cam->orientation.z, 1.0);
	EXPECT_EQ(cam->fov, 70);
	EXPECT_TRUE(cam->r_fov < 1.223 && cam->r_fov > 1.221);
	ft_free_array(attributes);
}

void	test_init_camera(char *input_str)
{
	t_camera		*cam = nullptr;
	char			**attributes;	
	int				op_result;	

	attributes = ft_split(input_str, ' ');
	EXPECT_TRUE(init_camera(attributes, &cam));
	ft_free_array(attributes);
}

TEST(SceneTests, InvalidCamera)
{
	char			**attributes;	
	
	char *missing_origin= (char *) "0,0,1 70";
	test_init_camera(missing_origin);

	char *missing_vector = (char *) "-50.0,0,20 70";
	test_init_camera(missing_vector);

	char *missing_fov = (char *) "-50.0,0,20 0,0,1";
	test_init_camera(missing_fov);

	char *missing_all = (char *) ",, ,,";
	test_init_camera(missing_all);

	char *empty = (char *) ""; 
	test_init_camera(empty);

	char *empty2 = (char *) "                     "; 
	test_init_camera(empty2);

	char *no_spaces = (char *) "-50.0,0,200,0,170";
	test_init_camera(no_spaces);

	char *wrong_delimiter = (char *) "-50.0,0,20-0,0,1-70";
	test_init_camera(wrong_delimiter);

	char *extra_field= (char *) "-50.0,0,20 0,0,1 70 42";
	test_init_camera(extra_field);

	char *wrong_vector= (char *) "-50.0,0,20 1,1,1 70";
	test_init_camera(wrong_vector);
}
