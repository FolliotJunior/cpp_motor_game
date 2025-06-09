#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"

mt_vector2f_t Window::scale() const
{
    mt_vector2f_t size = Window::sizef();

    return (mt_vector2f_t){size.x / (float)Window::init_size.x,
        size.y / (float)Window::init_size.y};
}

mt_vector2f_t Window::sizef() const
{
    int width = 0;
    int height = 0;

    glfwGetWindowSize(Window::win, &width, &height);
    return (mt_vector2f_t){(float)width, (float)height};
}

mt_vector2i_t Window::sizei() const
{
    int width = 0;
    int height = 0;

    glfwGetWindowSize(Window::win, &width, &height);
    return (mt_vector2i_t){width, height};
}
