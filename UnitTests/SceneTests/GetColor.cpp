
#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(GetColor, ValidColors)
{
	EXPECT_EQ(get_color((char *)"255,255,255"), (255 << 16) | (255  << 8) | 255);
	EXPECT_EQ(get_color((char *)"0,0,0"), 0);
	EXPECT_EQ(get_color((char *)"42,93,191"), (42<< 16) | (93<< 8) | 191);
}

TEST(GetColor, InvalidColors)
{
	EXPECT_EQ(get_color((char *)""), -1);
	EXPECT_EQ(get_color((char *)"255255255"), -1);
	EXPECT_EQ(get_color((char *)"-42,255,255"), -1);
	EXPECT_EQ(get_color((char *)"255,-42,255"), -1);
	EXPECT_EQ(get_color((char *)"255,255,-42"), -1);
	EXPECT_EQ(get_color((char *)"420,255,255"), -1);
	EXPECT_EQ(get_color((char *)"255,420,255"), -1);
	EXPECT_EQ(get_color((char *)"255,255,420"), -1);
	EXPECT_EQ(get_color((char *)"rubbish"), -1);
}
