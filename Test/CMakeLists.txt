include_directories(${PROJECT_SOURCE_DIR}/VanillaSTL)
set(APP_SRC test.cpp ../VanillaSTL/allocator_traits.h)
add_executable(stltest ${APP_SRC})