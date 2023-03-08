#include <gtest/gtest.h>
#include <unistd.h>
#include <fcntl.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(SceneOpen, ValidFilenames)
{
	struct stat st = {0};
	system("mkdir ./test_dir");
	system("mkdir ./test_dir/another_dir");
	system("touch ./scene.rt");
	system("touch ./test_dir/inside_folder.rt");
	system("touch ./test_dir/another_dir/inception.rt");
	system("touch ../relative.rt");
	system("touch ../../double_relative.rt");

	char *files[6];
	files[0] = (char *)"./scene.rt";
	files[1] = (char *)"scene.rt";
	files[2] = (char *)"./test_dir/inside_folder.rt";
	files[3] = (char *)"./test_dir/another_dir/inception.rt";
	files[4] = (char *)"../relative.rt";
	files[5] = (char *)"../../double_relative.rt";
	
	int fd = -1;
	for (int i = 0; i < 6; i++) {
		fd = scene_open(files[i]);
		EXPECT_NE(fd, -1);
		close(fd);
	}
	for (int i = 0; i < 6; i++) {
		unlink(files[i]);
	}
}
