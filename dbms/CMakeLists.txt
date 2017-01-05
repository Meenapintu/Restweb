if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()
set (CMAKE_CXX_STANDARD 11)
add_executable(dbms
  main.cpp
  src/Dbms.cpp

  )

set(CMAKE_SHARED_LINKER_FLAGS "-lpqxx -lpq")
target_link_libraries(dbms ${Casablanca_LIBRARIES} ${CMAKE_SHARED_LINKER_FLAGS} )
