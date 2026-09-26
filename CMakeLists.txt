cmake_minimum_required(VERSION 3.20)

project(UsersGroups VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(UsersGroups
    src/main.cpp
    src/UserManager.cpp
    src/UserManager.h
    src/UsersPage.cpp
    src/UsersPage.h
    src/EditUserDialog.cpp
    src/EditUserDialog.h
)

target_link_libraries(UsersGroups PRIVATE
    Qt6::Widgets
)
