cmake_minimum_required(VERSION 3.14)

set(this SceneTests)

set(Sources 
	GetElement.cpp
	SceneOpen.cpp
	GetColor.cpp
	GetPoint.cpp
	IsNormalized.cpp
	InitCylinder.cpp
	InitSphere.cpp	
	InitCamera.cpp	
	InitPlane.cpp
	InitAmbientLight.cpp
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
