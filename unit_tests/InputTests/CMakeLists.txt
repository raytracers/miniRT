cmake_minimum_required(VERSION 3.14)

set(this InputTests)

set(Sources 
	InputTest.cpp)

add_executable(${this} ${Sources})

target_link_libraries(${this} PUBLIC
	GTest::gtest_main
	mini_rt)

add_test(
		NAME ${this}
		COMMAND ${this}
	)
