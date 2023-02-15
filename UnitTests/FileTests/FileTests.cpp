
#include <gtest/gtest.h>
#include <stdio.h>
#include <unistd.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(FileTests, sceneOpenTest)
{
	int fd;

	fd = scene_open((char *) "../../FileTests/default.rt");
	EXPECT_GE(fd, 0);
	close(fd);
	
	fd = 0;
	fd = scene_open((char *) "../../FileTests/no_permission.rt");
	EXPECT_EQ(fd, -1);

	fd = 0;
	fd = scene_open((char *) "nao_existo.rt");
	EXPECT_EQ(fd, -1);
}
