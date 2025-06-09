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
        mt_vector2i_t size = window->sizei();
        mt_vector2f_t scale = window->scale();
        printf("%d %d %.2f %.2f\n", size.x, size.y, scale.x, scale.y);
        window->display();
    }
    delete window;
    return 0;
}
