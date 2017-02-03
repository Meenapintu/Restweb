if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()
set (CMAKE_CXX_STANDARD 11)
project(dbms)
include_directories("${CMAKE_SOURCE_DIR}")
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/Build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
add_executable(dbms
  main.cpp
  src/Dbms.cpp

  )

set(CMAKE_SHARED_LINKER_FLAGS "-lpqxx -lpq")
target_link_libraries(dbms ${Casablanca_LIBRARIES} ${CMAKE_SHARED_LINKER_FLAGS} )
