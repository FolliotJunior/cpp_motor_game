#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"

// fonction pour initialiser
Window::Window(int width, int height, const char *name)
{
    if (glfwInit() == GLFW_FALSE) {
        std::cout << "Erreur GLW\n";
        std::exit(EXIT_ERROR_GLFW);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window::win = glfwCreateWindow(width, height, name, nullptr, nullptr);
    if (Window::win == nullptr) {
        std::cerr << "Erreur lors de la creation de la fenetre\n";
        glfwTerminate();
        std::exit(EXIT_ERROR_GLFW);
    }
    glfwMakeContextCurrent(Window::win);
}

// fonction qui detruit la class
Window::~Window()
{
    glfwDestroyWindow(Window::win);
    glfwTerminate();
}

// fonction piur checker que la fenetre est ouverte
bool Window::is_open() const
{
    return !glfwWindowShouldClose(Window::win);
}

void Window::display() {
    glfwSwapBuffers(Window::win);
    glfwPollEvents();
}

void Window::clear() {
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
