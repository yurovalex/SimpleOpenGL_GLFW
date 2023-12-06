project(sources)



set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})


list(APPEND myApp_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/Interface.h
    ${CMAKE_CURRENT_LIST_DIR}/Interface.cpp
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${myApp_SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        external
        ${OPENGL_INCLUDE_DIR}
)



target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${OPENGL_gl_LIBRARY}
        glfw
        imgui
        spdlog::spdlog
        glm
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "runExample")
