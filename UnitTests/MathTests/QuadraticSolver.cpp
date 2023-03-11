#include <gtest/gtest.h>

extern "C"
{
	#include "../../headers/mini_rt.h"
}

TEST(QuadraticSolver, MultipleSolutions)
{
	EXPECT_DOUBLE_EQ(quadratic_solver(-4.0, 3.0), 1.0);
	EXPECT_DOUBLE_EQ(quadratic_solver(-42.0, 0.0), 0.0);
	EXPECT_DOUBLE_EQ(quadratic_solver(0.0, -16.0), 4.0);
	EXPECT_DOUBLE_EQ(quadratic_solver(6.0, -7.0), 1.0);
	EXPECT_DOUBLE_EQ(quadratic_solver(-10.0, 18.75), 2.5);
}

TEST(QuadraticSolver, SingleSolution)
{
	EXPECT_DOUBLE_EQ(quadratic_solver(0.0, 0.0), 0.0);
	EXPECT_DOUBLE_EQ(quadratic_solver(-4.0, 4.0), 2.0);
}

TEST(QuadraticSolver, NoSolution)
{
	EXPECT_DOUBLE_EQ(quadratic_solver(42.0, 42.0), -1.0);
	EXPECT_DOUBLE_EQ(quadratic_solver(25.0, 21.0), -1.0);
	EXPECT_DOUBLE_EQ(quadratic_solver(2.0, 1.0), -1.0);
}
