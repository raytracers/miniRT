#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(GetElement, ValidElements)
{
	int op_code;

	EXPECT_EQ(get_element((char *)"A", 0), ambient_light);
	EXPECT_EQ(get_element((char *)"C", 0), camera);
	EXPECT_EQ(get_element((char *)"sp", 0), sphere);
	EXPECT_EQ(get_element((char *)"pl", 0), plane);
	EXPECT_EQ(get_element((char *)"cy", 0), cylinder);
}

TEST(GetElement, InvalidElements)
{
	EXPECT_EQ(get_element((char *)"a", 0), nae);
	EXPECT_EQ(get_element((char *)"AA", 0), nae);
	EXPECT_EQ(get_element((char *)"c", 0), nae);
	EXPECT_EQ(get_element((char *)"CC", 0), nae);
	EXPECT_EQ(get_element((char *)"sp0", 0), nae);
	EXPECT_EQ(get_element((char *)"SP", 0), nae);
	EXPECT_EQ(get_element((char *)"plb", 0), nae);
	EXPECT_EQ(get_element((char *)"PL", 0), nae);
	EXPECT_EQ(get_element((char *)"cyo", 0), nae);
	EXPECT_EQ(get_element((char *)"CY", 0), nae);
	EXPECT_EQ(get_element((char *)"", 0), nae);
}
