cmake_minimum_required(VERSION 3.15)
project(plugins_4_program)

set(PLUGINS
    Interp4Move
    Interp4Set
    Interp4Pause
)

foreach(PLUGIN ${PLUGINS})
    add_library(${PLUGIN} MODULE src/${PLUGIN}.cpp)

    target_include_directories(${PLUGIN} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../inc
    )

    add_custom_command(TARGET ${PLUGIN} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PLUGIN}> /tmp/bk_downloads
        COMMAND ${CMAKE_COMMAND} -E echo ""
        COMMAND ${CMAKE_COMMAND} -E echo " Utworzony zostal plugin: $<TARGET_FILE_NAME:${PLUGIN}>"
        COMMAND ${CMAKE_COMMAND} -E echo ""
    )
endforeach()