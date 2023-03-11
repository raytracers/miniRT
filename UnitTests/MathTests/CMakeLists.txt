cmake_minimum_required(VERSION 3.14)

set(this MathTests)

set(Sources 
	QuadraticSolver.cpp
	VectorOperations.cpp
)

add_executable(${this} ${Sources})

target_link_libraries(${this} PUBLIC
	GTest::gtest_main
	MiniRT
	ft
)

add_test(
		NAME ${this}
		COMMAND ${this}
)
