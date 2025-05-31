cmake_minimum_required(VERSION 3.16)

project(DatabaseSolution LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(DatabaseSolution SHARED
  DatabaseSolution_global.h
  databasesolution.cpp
  databasesolution.h
  ContactClass.cpp
  ContactClass.h
  privatecontactclass.h
  privatecontactclass.cpp
  personalcontactclass.h
  personalcontactclass.cpp
  databaseclass.h
  databaseclass.cpp
)

target_link_libraries(DatabaseSolution PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(DatabaseSolution PRIVATE DATABASESOLUTION_LIBRARY)
