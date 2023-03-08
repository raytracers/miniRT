#include <gtest/gtest.h>

extern "C"
{
	#include "../../libft/libft.h"
}

TEST(IsDoubleStrTests, ValidStrings)
{
	EXPECT_TRUE(ft_isdouble_str((char *)"-42.42"));
	EXPECT_TRUE(ft_isdouble_str((char *)"+42.42"));
	EXPECT_TRUE(ft_isdouble_str((char *)"42.42"));
	EXPECT_TRUE(ft_isdouble_str((char *)"+42"));
	EXPECT_TRUE(ft_isdouble_str((char *)"-42"));
	EXPECT_TRUE(ft_isdouble_str((char *)"42"));
}

TEST(IsDoubleStrTests, ExtraSigns)
{
	EXPECT_FALSE(ft_isdouble_str((char *)"++42.42"));
	EXPECT_FALSE(ft_isdouble_str((char *)"--42.42"));
}
TEST(IsDoubleStrTests, ForeignChars)
{
	EXPECT_FALSE(ft_isdouble_str((char *)"42..42"));
	EXPECT_FALSE(ft_isdouble_str((char *)"F42.42"));
	EXPECT_FALSE(ft_isdouble_str((char *)"42.42F"));
	EXPECT_FALSE(ft_isdouble_str((char *)"42f"));
	EXPECT_FALSE(ft_isdouble_str((char *)" 42"));
	EXPECT_FALSE(ft_isdouble_str((char *)"42 "));
	EXPECT_FALSE(ft_isdouble_str((char *)"42.42 "));
}
