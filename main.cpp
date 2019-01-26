// Copyright 2019 Stuart Thompson.

// This file is part of LoadBitmap.

// LoadBitmap is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// LoadBitmap is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with LoadBitmap. If not, see <http://www.gnu.org/licenses/>.

#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
using namespace glm;

int main(void) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW.";
        return -1;
    }

    // Describe window
    glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a new window
    window = glfwCreateWindow(1280, 720, "LoadBitmap", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to open GLFW window.";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW.";
        glfwTerminate();
        return -1;
    }

    // Set clear color to red
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

    while (glfwWindowShouldClose(window) == 0) {
        // Clear the window
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap display buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}
