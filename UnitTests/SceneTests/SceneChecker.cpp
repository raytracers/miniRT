#include <gtest/gtest.h>

extern "C"
{
  #include "../../headers/mini_rt.h"
}

void init_scene(t_scene *scene);

void scene_read(char *input_file, t_scene *scene)
{
	init_scene(scene);
	int fd = scene_open(input_file);
	ASSERT_NE(fd, -1);
	EXPECT_EQ(scene_load(fd, scene), 0);
	close(fd);
}

TEST(SceneTests, NoLightFound)
{
	t_scene scene;

	scene_read((char *) "../../../scenes/tests/no_light.rt", &scene);
	EXPECT_EQ(scene_check(&scene), 1);
}

TEST(SceneTests, NoCameraFound)
{
	t_scene scene;

	scene_read((char *) "../../../scenes/tests/no_camera.rt", &scene);
	EXPECT_EQ(scene_check(&scene), 1);
}

TEST(SceneTests, NoCameraNoLight)
{
	t_scene scene;
	scene_read((char *) "../../../scenes/tests/nolight_nocamera.rt", &scene);
	EXPECT_EQ(scene_check(&scene), 1);
}
