#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fcntl.h>
#include <stdlib.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
	t_scene scene; 
}

void init_scene(t_scene *scene);
void init_array(double *array, double x, double y, double z);
void point_cmp(t_point *point1, double values[3]);
void check_ambient_light(t_a_light *amb_light, double ratio, int color);
void check_camera(t_camera *camera, double origin[3], double orientation[3], int fov);
void check_light(t_light *light, double origin[3], double b_ratio);
void check_plane(union u_object *u, double origin[3], double normal[3], int color);
void check_sphere(union u_object *u, double origin[3], double sp_diam, int color);
void check_cylinder(union u_object *u, double origin[3], double orientation[3], \
	double diam1, double diam2, int color);

TEST(SceneTests, SceneLoaderValid)
{
	t_scene scene;
	double	origin[3];
	double	orientation[3];
	int		scene_fd;

	{
		scene_fd = open("../../../scenes/scene.rt", O_RDONLY);
		EXPECT_NE(scene_fd, -1);
		init_scene(&scene);
		EXPECT_EQ(scene_load(scene_fd, &scene), 0);

		check_ambient_light(scene.a_light, 0.2, 0xFFFFFF);

		init_array(origin, -50.0, 0, 20);
		init_array(orientation, 0, 0, 1);
		check_camera(scene.camera, origin, orientation, 70);

		init_array(origin, -40,0,30);
		check_light(scene.light, origin, 0.7);
		close(scene_fd);

		init_array(origin, 0, 0, 0);
		init_array(orientation, 0, 1.0, 0);
		check_plane(&scene.elements->object, origin, orientation, 0xFF00E1);

		init_array(origin, 0.0, 0.0, 20);
		check_sphere(&scene.elements->next->object, origin, 20, 0xFF0000);

		init_array(origin, 50.0, 0.0, 20.6);
		init_array(orientation, 0, 0, 1.0);
		check_cylinder(&scene.elements->next->next->object, origin, orientation,\
			14.2, 21.42, 0x0A00FF);
		close(scene_fd);
	}
}

TEST(SceneTests, LoadSingleElement)
{
	t_scene scene;
	int		scene_fd;
	double	origin[3];
	double  orientation[3];
	init_scene(&scene);

	{
		scene_fd = open("../../../scenes/tests/ambient.rt", O_RDONLY);
		EXPECT_NE(scene_fd, -1);
		EXPECT_EQ(scene_load(scene_fd, &scene), 0);
		check_ambient_light(scene.a_light, 0.2, 0xFFFFFF);
		close(scene_fd);
	}
	{
		scene_fd = open("../../../scenes/tests/camera.rt", O_RDONLY);	
		EXPECT_NE(scene_fd, -1);
		EXPECT_EQ(scene_load(scene_fd, &scene), 0);
		init_array(origin, -50.0, 0, 20);
		init_array(orientation, 0, 0, 1);
		check_camera(scene.camera, origin, orientation, 70);
		close(scene_fd);
	}
	{
		scene_fd = open("../../../scenes/tests/light.rt", O_RDONLY);	
		EXPECT_NE(scene_fd, -1);
		EXPECT_EQ(scene_load(scene_fd, &scene), 0);
		init_array(origin, -40,0,30);
		check_light(scene.light, origin, 0.7);
		close(scene_fd);
	}
}

TEST(SceneTests, LoadEmptyScenes)
{
	int		scene_fd;
	t_scene scene;

	{
		scene_fd = open("../../../scenes/tests/empty.rt", O_RDONLY);
		EXPECT_NE(scene_fd, -1);
		init_scene(&scene);
		EXPECT_EQ(scene_load(scene_fd, &scene), 0);
		EXPECT_EQ(scene.a_light, nullptr);
		EXPECT_EQ(scene.camera, nullptr);
		EXPECT_EQ(scene.light, nullptr);
		EXPECT_EQ(scene.elements, nullptr);
		close(scene_fd);
	}
	{
		scene_fd = open("../../../scenes/tests/spaces.rt", O_RDONLY);
		EXPECT_NE(scene_fd, -1);
		init_scene(&scene);
		EXPECT_EQ(scene_load(scene_fd, &scene), 0);
		EXPECT_EQ(scene.a_light, nullptr);
		EXPECT_EQ(scene.camera, nullptr);
		EXPECT_EQ(scene.light, nullptr);
		EXPECT_EQ(scene.elements, nullptr);
		close(scene_fd);
	}
}

TEST(SceneTests, DuplicateUniqueObjects)
{
	int scene_fd;
	t_scene scene;
	
	{
		scene_fd = open("../../../scenes/tests/duplicate_alight.rt", O_RDONLY);
		EXPECT_NE(scene_fd, -1);

		EXPECT_EQ(scene_load(scene_fd, &scene), 1);
		close(scene_fd);
	}
	{
		scene_fd = open("../../../scenes/tests/duplicate_light.rt", O_RDONLY);
		EXPECT_NE(scene_fd, -1);

		EXPECT_EQ(scene_load(scene_fd, &scene), 1);
		close(scene_fd);
	}
	{
		scene_fd = open("../../../scenes/tests/duplicate_camera.rt", O_RDONLY);
		EXPECT_NE(scene_fd, -1);

		EXPECT_EQ(scene_load(scene_fd, &scene), 1);
		close(scene_fd);
	}
}

void init_scene(t_scene *scene)
{
	scene->a_light = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->elements = NULL;
	scene->next = NULL;
}

void point_cmp(t_point *point1, double values[3])
{
	EXPECT_DOUBLE_EQ(point1->x, values[0]);
	EXPECT_DOUBLE_EQ(point1->y, values[1]);
	EXPECT_DOUBLE_EQ(point1->z, values[2]);
}

void check_camera(t_camera *camera, double origin[3], double orientation[3], int fov)
{
	point_cmp(&camera->origin, origin);
	point_cmp(&camera->orientation, orientation);
	EXPECT_EQ(camera->fov, fov);
}

void check_light(t_light *light, double origin[3], double b_ratio)
{
	point_cmp(&light->origin, origin);
	EXPECT_DOUBLE_EQ(light->brightness, b_ratio);
}

void check_ambient_light(t_a_light *amb_light, double ratio, int color)
{
	EXPECT_DOUBLE_EQ(amb_light->ratio, ratio);
	EXPECT_EQ(amb_light->color, color);
}

void check_plane(union u_object *u, double origin[3], double normal[3], int color)
{
	t_plane *pl = &u->plane;
	point_cmp(&pl->origin, origin);
	point_cmp(&pl->normal, normal);
	EXPECT_EQ(pl->color, color);
}

void check_sphere(union u_object *u, double origin[3], double sp_diam, int color)
{
	t_sphere *sp = &u->sphere;
	point_cmp(&sp->origin, origin);
	EXPECT_DOUBLE_EQ(sp->diameter, sp_diam);
	EXPECT_EQ(sp->color, color);
}

void check_cylinder(union u_object *u, double origin[3], double orientation[3], \
	double diam1, double diam2, int color)
{
	t_cylinder *cy = &u->cylinder;
	point_cmp(&cy->origin, origin);
	point_cmp(&cy->orientation, orientation);
	EXPECT_DOUBLE_EQ(cy->diameter, diam1);
	EXPECT_DOUBLE_EQ(cy->height, diam2);
	EXPECT_EQ(cy->color, color);
}

void init_array(double *array, double x, double y, double z)
{
	array[0] = x;
	array[1] = y;
	array[2] = z;
}
