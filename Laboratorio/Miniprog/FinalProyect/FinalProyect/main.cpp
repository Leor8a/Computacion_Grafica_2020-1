//
//  main.cpp
//  FinalProyect
//
//  Created by Luis Ernesto Ochoa Rios on 10/19/19.
//  Copyright © 2019 Luis Ernesto Ochoa Rios. All rights reserved.
//

#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window;
    
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);
    
    int screenWidth, screenHeight;

    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        
        return -1;
    }
    
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    glfwMakeContextCurrent(window);
    std::cout << glGetString(GL_VERSION) << std::endl;
    glewExperimental = GL_TRUE;
    
    if (GLEW_OK != glewInit()){
        std::cout << "Failed to initialize GLEEW" << std::endl;
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    
    //GAMELOOP
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;


}
















