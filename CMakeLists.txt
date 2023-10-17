project(ForwardList)
set(CMAKE_CXX_STANDARD 20)
add_executable(Sharedptr main.cpp)
target_include_directories(Sharedptr PRIVATE sharedptr.h)