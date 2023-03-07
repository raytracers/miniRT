#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(GetElement, ValidElements)
{
	EXPECT_EQ(get_element((char *)"A"), ambient_light);
	EXPECT_EQ(get_element((char *)"C"), camera);
	EXPECT_EQ(get_element((char *)"sp"), sphere);
	EXPECT_EQ(get_element((char *)"pl"), plane);
	EXPECT_EQ(get_element((char *)"cy"), cylinder);
}

TEST(GetElement, InvalidElements)
{
	EXPECT_EQ(get_element((char *)"a"), nae);
	EXPECT_EQ(get_element((char *)"AA"), nae);
	EXPECT_EQ(get_element((char *)"c"), nae);
	EXPECT_EQ(get_element((char *)"CC"), nae);
	EXPECT_EQ(get_element((char *)"sp0"), nae);
	EXPECT_EQ(get_element((char *)"SP"), nae);
	EXPECT_EQ(get_element((char *)"plb"), nae);
	EXPECT_EQ(get_element((char *)"PL"), nae);
	EXPECT_EQ(get_element((char *)"cyo"), nae);
	EXPECT_EQ(get_element((char *)"CY"), nae);
	EXPECT_EQ(get_element((char *)""), nae);
}
