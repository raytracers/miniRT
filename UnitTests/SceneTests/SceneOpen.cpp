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
	if (stat("./test_dir", &st) == -1) {
		mkdir("./test_dir", 0700);
	}
	if (access("./scene.rt", F_OK) == -1) {
		int new_fd = open("./scene.rt", O_CREAT);
		close(new_fd);
	}
	if (access("./test_dir/inside_folder.rt", F_OK) == -1) {
		int new_fd = open("./test_dir/inside_folder.rt", O_CREAT);
		close(new_fd);
	}
	int fd;
	std::cout << "THIS IS CWD " << getcwd(NULL, 0) << std::endl;
	fd = scene_open((char *)"./scene.rt");
	EXPECT_NE(fd, -1);
	close(fd);

	fd = scene_open((char *)"./test_dir/inside_folder.rt");
	EXPECT_NE(fd, -1);
	close(fd);
}
