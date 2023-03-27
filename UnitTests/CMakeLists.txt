cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b73f27fd164456fea9aba56163f5511355a03272.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(This MiniRT)

project(${This} C CXX)

# GoogleTest requires C++
set(CMAKE_CXX_STANDARD 14)

enable_testing()

set(Headers
	../headers/mini_rt.h
)

set(Sources
	../sources/input/scene_open.c
	../sources/input/scene_loader.c
	../sources/input/error.c
	../sources/input/arg_validator.c
	../sources/input/get_element.c
	../sources/input/get_color.c
	../sources/input/get_point.c
	../sources/input/is_normalized.c
	../sources/types/init_plane.c
	../sources/types/init_sphere.c
	../sources/types/init_camera.c
	../sources/types/init_cylinder.c
	../sources/types/init_ambient_light.c
	../sources/types/init_light.c
	../sources/types/t_elist.c
	../sources/types/new_point.c
	../sources/types/get_ray.c
	../sources/operations/quadratic_solver.c
	../sources/operations/vector_operations.c
	../sources/operations/cross_product.c
	../sources/operations/transform_vector.c
	../sources/operations/transform_elements.c
	../sources/operations/vtm.c
	../sources/operations/rtm.c
	../sources/operations/matrix.c
	../sources/operations/get_distance.c
	../sources/render/sphere_intersection.c
	../sources/app/destroy_scene.c
)

add_library(${This} ${Sources} ${Libft} ${Headers})

add_library(ft STATIC IMPORTED)
set_target_properties(ft PROPERTIES IMPORTED_LOCATION
	${CMAKE_SOURCE_DIR}/../libft/libft.a
) 


# this will add all the subdirectories with unit tests
add_subdirectory(InputTests)
add_subdirectory(SceneTests)
add_subdirectory(LibftTests)
add_subdirectory(RayTests)
add_subdirectory(MathTests)
add_subdirectory(ElistTests)
add_subdirectory(IntersectionTests)
