cmake_minimum_required(VERSION 3.15)

project(ThePankeyEngine_Support_Math)

if(NOT TARGET ThePankeyEngine_Support_Math)

    add_library(ThePankeyEngine_Support_Math INTERFACE)

    target_include_directories(
        ThePankeyEngine_Support_Math
          INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()