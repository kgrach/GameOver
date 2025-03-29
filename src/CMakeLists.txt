cmake_minimum_required(VERSION 3.22)

project(gameoverd VERSION 0.1
				  DESCRIPTION "This deamon manage computer time")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-ggdb -Wall -Wextra -pedantic -O0")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    set(CMAKE_CXX_FLAGS "-DNDEBUG -ggdb -Wall -Wextra -pedantic -O2")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-DNDEBUG -Wall -Wextra -pedantic -O2")
endif()

# Configure .service file
#if(NOT EXISTS ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.service)
	configure_file(${CMAKE_SOURCE_DIR}/systemd/daemonpp.service.in ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.service)
#endif()

# Configure .conf file
#if(NOT EXISTS ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.conf)
	configure_file(${CMAKE_SOURCE_DIR}/systemd/daemonpp.conf.in ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.conf)
#endif()

# Configure install.sh file
#if(NOT EXISTS ${CMAKE_BINARY_DIR}/install.sh)
	configure_file(${CMAKE_SOURCE_DIR}/systemd/install.sh.in ${CMAKE_BINARY_DIR}/install.sh)
#endif()



add_executable(${PROJECT_NAME} 
	main.cpp
)