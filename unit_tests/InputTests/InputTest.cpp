#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(InputTests, ArgcTest)
{
	EXPECT_EQ(check_argc(1), 0);
	EXPECT_EQ(check_argc(0), 1);
	EXPECT_EQ(check_argc(2), 1);
}

TEST(InputTests, FilenameTest)
{
	EXPECT_EQ(check_file_extension((char *) "scene.rt"), 0);
	EXPECT_EQ(check_file_extension((char *) ".rt"), 1);
	EXPECT_EQ(check_file_extension((char *) ""), 1);
	EXPECT_EQ(check_file_extension((char *) "rt"), 1);
	EXPECT_EQ(check_file_extension((char *) "scene"), 1);
}
