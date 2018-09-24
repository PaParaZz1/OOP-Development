CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(IO_interaction)

#SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${IO_interaction_SOURCE_DIR}/output)

SET(ALL_INCLUDE
    ${IO_interaction_SOURCE_DIR}/include
)

INCLUDE_DIRECTORIES(${ALL_INCLUDE})

#SET(CMAKE_C_FLAGS "-g -Wall -Werror -O3 -std=c99 -pie -fPIC")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

SET(ALL_SRC
    src/utils.cpp
    src/data_template.cpp
)

#add_executable(libjudger.so ${SOURCE})
#target_link_libraries(libjudger.so pthread seccomp)
ADD_LIBRARY(IO_interaction SHARED
    ${ALL_SRC}
)

#TARGET_LINK_LIBRARIES()

INSTALL(FILES output/libjudger.so
    PERMISSIONS OWNER_EXECUTE OWNER_READ
    DESTINATION /usr/lib/judger)

