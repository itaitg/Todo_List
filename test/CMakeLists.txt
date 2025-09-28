
project(manager_test)
add_executable(manager_test  manager_test.cpp)
target_link_libraries(manager_test PUBLIC manager_static)

project(main)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC manager_static)