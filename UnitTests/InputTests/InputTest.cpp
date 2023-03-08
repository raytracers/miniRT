#include <gtest/gtest.h>

#define TRUE 1
#define FALSE 0

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(InputTests, ArgcTest)
{
	EXPECT_EQ(check_argc(1), TRUE);
	EXPECT_EQ(check_argc(0), FALSE);
	EXPECT_EQ(check_argc(2), FALSE);
	EXPECT_EQ(check_argc(-1), FALSE);
	EXPECT_EQ(check_argc(-2), FALSE);
	EXPECT_EQ(check_argc(-99), FALSE);
}

TEST(InputTests, FilenameTest)
{
	// The expected output
	EXPECT_EQ(check_file_extension((char *) "scene.rt"), TRUE);
	EXPECT_EQ(check_file_extension((char *) " .rt"), TRUE);
	EXPECT_EQ(check_file_extension((char *) "-.rt"), TRUE);
	EXPECT_EQ(check_file_extension((char *) "a.rt"), TRUE);
	EXPECT_EQ(check_file_extension((char *) "42.rt"), TRUE);
	EXPECT_EQ(check_file_extension((char *) "       .rt"), TRUE);
	EXPECT_EQ(check_file_extension((char *) ".rt.rt"), TRUE);

	// edge cases
	EXPECT_EQ(check_file_extension((char *) "scene.RT"), FALSE);
	EXPECT_EQ(check_file_extension((char *) "scene.Rt"), FALSE);
	EXPECT_EQ(check_file_extension((char *) "scene.rT"), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rt"), FALSE);
	EXPECT_EQ(check_file_extension((char *) ""), FALSE);
	EXPECT_EQ(check_file_extension((char *) "rt"), FALSE);
	EXPECT_EQ(check_file_extension((char *) "scene"), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rt"), FALSE);

	// testing for chars after the extension 
	EXPECT_EQ(check_file_extension((char *) ".rt "), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rt      "), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rta"), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rt-"), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rt0"), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rt!"), FALSE);
	EXPECT_EQ(check_file_extension((char *) ".rt\0"), FALSE);
}
