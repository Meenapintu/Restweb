cmake_minimum_required (VERSION 3.5)
if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()
set (CMAKE_CXX_STANDARD 11)
add_executable(restserver
  main.cpp
  src/handler.cpp


  )

set(CMAKE_SHARED_LINKER_FLAGS "-lboost_system -lcrypto -lssl -lcpprest")
target_link_libraries(restserver ${Casablanca_LIBRARIES} ${CMAKE_SHARED_LINKER_FLAGS} )

