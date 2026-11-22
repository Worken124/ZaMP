cmake_minimum_required(VERSION 3.15)

set(PROJ_NAME "cmds_interpreter")
project(${PROJ_NAME})


find_package(XercesC REQUIRED)
add_subdirectory(plugin)

include_directories(${PROJECT_SOURCE_DIR}/inc)
add_executable(${PROJECT_NAME}
    src/main.cc
    src/xmlinterp.cpp
    src/LibInterface.cc
    src/Set4LibInterfaces.cpp
    src/ProgramInterpreter.cpp
    src/vec3d.cc
    src/ComChannel.cc
    src/Cube.cc
)

target_link_libraries(${PROJECT_NAME} XercesC::XercesC)


set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wl,-rpath=./plugin")
add_custom_command(TARGET ${PROJ_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo " Utworzony zostal program:  ${PROJ_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo ""
  )
