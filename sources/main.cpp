#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <GL/glu.h>
#include "GLFW/glfw3.h"
#include  "Interface.h"
#include "spdlog/spdlog.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace std;

//Performing vector-matrix multiplication
bool testMatrixGLM()
{
    glm::vec4 vector1 {10,10,10,1};
    glm::mat4x4 matrix1({1,0,0,10},
                        {0,1,0,0},
                        {0,0,1,0},
                        {0,0,0,1});

    glm::vec4 result = vector1 * matrix1;
    spdlog::info("Result vector: {0},{1},{2},{3}", result[0],result[1],result[2],result[3] );

    return true;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
     if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(void)
{
     if (!testMatrixGLM()) return 0;
     //SomeInterface::Interface obj;

     std::unique_ptr<SomeInterface::Interface> ptr_Interface
              = std::make_unique<SomeInterface::Interface>();

    //Initialize GLFW and create a GLFW window object (800 x 600):

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Simple GLFW Example", NULL, NULL);
    if (!window)
    {
        spdlog::info("{0} :Code error: {1}", "Failed to create GLFW window", -1 );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);


    //Init imGui
    ptr_Interface->InitImGui(window);


    //Define a loop that terminates when the window is closed:
    while (!glfwWindowShouldClose(window))
    {
    //Set up the viewport (using the width and height of the window)
    //and clear the screen color buffer:

        float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = (float) width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.5f,0.5f,0.5f,1);
    //Set up the camera matrix. Note that further details on the camera model
    //Interactive 3D Data Visualization:

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    //Draw a rotating triangle and set a different color (red, green, and blue channels)
    //for each vertex (x, y, and z) of the triangle.
    //The first line rotates the triangle over time:

        if (ptr_Interface->GetRotateflag() == true)
        {
            glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        }

        glBegin(GL_QUADS);

        glColor3f(1.f/ptr_Interface->GetGradientRedColor(), 0.f, 0.f);
        glVertex3f(-0.8f, -0.8f, 0.f);
        glVertex3f(-0.8f, 0.8f, 0.f);
        glVertex3f(0.8f, 0.8f, 0.f);
        glVertex3f(0.8f, -0.8f, 0.f);
        glEnd();

        glBegin(GL_TRIANGLES);

        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

    //Swap the front and back buffers (GLFW uses double buffering)
    //to update the screen and process all pending events:

        //Create interface with imGui
        ptr_Interface->UsingImGui(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSetKeyCallback(window, key_callback);
    }
    //we must do some cleanup when the loop ends.
    ptr_Interface->DestroyImGui();

    //Release the memory and terminate the GLFW library. Then, exit the application:
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
