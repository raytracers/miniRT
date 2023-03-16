#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(CameraTransformation, CameraAtRandompos)
{
	t_camera	*c;
	char		**attr = ft_split("-50.0,0,20 1,0,0 70", ' ');
	init_camera(attr, &c);
	ASSERT_NE(c, nullptr);
	double	**vtm = get_vtm(c);
	transform_camera(c, vtm);

	EXPECT_DOUBLE_EQ(c->origin.x, 0);
	EXPECT_DOUBLE_EQ(c->origin.y, 0);
	EXPECT_DOUBLE_EQ(c->origin.z, 0);
	EXPECT_DOUBLE_EQ(c->orientation.x, 0);
	EXPECT_DOUBLE_EQ(c->orientation.y, 0);
	EXPECT_DOUBLE_EQ(c->orientation.z, 0);
}
