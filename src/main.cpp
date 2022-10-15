/************************************************************************************
 *  MYCRAFT PROJECT                                                                 *
 *  Copyright (c) 2022 Chris Cheng (orbitgw) <15086960386@163.com>                  *
 * -------------------------------------------------------------------------------- *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy    *
 *  of this software and associated documentation files (the "Software"), to deal   *
 *  in the Software without restriction, including without limitation the rights    *
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       *
 *  copies of the Software, and to permit persons to whom the Software is           *
 *  furnished to do so, subject to the following conditions:                        *
 *                                                                                  *
 *  The above copyright notice and this permission notice shall be included in all  *
 *  copies or substantial portions of the Software.                                 *
 *                                                                                  *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
 *  SOFTWARE.                                                                       *
 ************************************************************************************/
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

extern int set_window_icon(GLFWwindow* window);

int main(){
    GLFWwindow* window;
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW." <<std::endl;
        return -1;
    }

    window = glfwCreateWindow(800, 640, "MYCRAFT", NULL, NULL);
    if (!window){
        std::cerr << "Failed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to load glad." << std::endl;
    }

    if (!set_window_icon(window)) {
        std::cerr << "Failed to load icon." << std::endl;
    }

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.5f);
        
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

