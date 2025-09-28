


add_library(uid_static STATIC UID.cpp)

add_library(task_static STATIC Task.cpp)
target_link_libraries(task_static uid_static)

add_library(manager_static STATIC Manager.cpp)
target_link_libraries(manager_static task_static)

