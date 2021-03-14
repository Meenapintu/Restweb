cmake_minimum_required (VERSION 3.9)
if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif(UNIX)
project(restserver)
set (CMAKE_CXX_STANDARD 11)
option(DBMS "Dbms" OFF)
include_directories("${CMAKE_SOURCE_DIR}")
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/Build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)


add_executable(restserver
  main.cpp
  src/handler.cpp
  )
find_package(cpprestsdk REQUIRED)
find_package(ssl REQUIRED)
find_package(boost_system REQUIRED)
find_package(crypto REQUIRED)

set(Casablanca_LIBRARIES "-lboost_system -lcrypto -lssl")
set(LINKING_LIBRARIES ${Casablanca_LIBRARIES} cpprestsdk::cpprest)

if(DBMS)
	set(NEW_DB_SRC_DIR ${CMAKE_SOURCE_DIR}/dbms/src)
	add_library(dbms SHARED
		${NEW_DB_SRC_DIR}/Dbms.cpp
		)
	set(Dbms_dep_lib "-lpqxx -lpq")
	set(LINKING_LIBRARIES ${LINKING_LIBRARIES} dbms ${Dbms_dep_lib})
endif(DBMS)

if (UNIX)
	# Linking POSIX threads
	find_package(Threads REQUIRED)
	set(LINKING_LIBRARIES ${LINKING_LIBRARIES} Threads::Threads)
endif (UNIX)

target_link_libraries(restserver PRIVATE ${LINKING_LIBRARIES})
