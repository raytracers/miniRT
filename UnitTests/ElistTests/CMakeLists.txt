cmake_minimum_required(VERSION 3.14)

set(this ElistTests)

set(Sources 
	ElistNew.cpp
	ElistAddback.cpp
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
