#include <iostream>
#include <array>
#include "window.hpp"

int main(void)
{
    Window *window = new Window(800, 600, "Premiere fenetre");
    std::array<float, 6> triangle = {
         0.0f, 0.0f,
         0.5f, -0.5f,
         1.0f,  1.0f
    };
    std::array<float, 6> tr2 = {
         0.0f,  0.0f,
        -0.5f, -0.5f,
        -1.0f,  1.0f
    };
    while (window->is_open()) {
        window->draw_triangle(triangle.data());
        window->draw_triangle(tr2.data());
        window->display();
    }
    delete window;
    return 0;
}
