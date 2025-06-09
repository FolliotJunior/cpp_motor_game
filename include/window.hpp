#ifndef __MOTOR_WINDOW_HPP__
    #define __MOTOR_WINDOW_HPP__
    #include <iostream>
    #include <glm/glm.hpp>
    #include <GLFW/glfw3.h>
    #include "struct.hpp"
    #define EXIT_ERROR_GLFW 1


class Window
{
    private:
        struct GLFWwindow *win;
        void clear();
        GLuint shader_prog;
        GLuint VAO, VBO;

        // function to init shader
        void init_shaders();
        void init_buffers();

        // init var
        mt_vector2i_t init_size;
    public:
        Window(int width, int height, const char *name);
        ~Window();

        // window state
        bool is_open() const;
        mt_vector2f_t scale() const;
        mt_vector2f_t sizef() const;
        mt_vector2i_t sizei() const;
        void draw_triangle(float vertices[6]);
        void display();
};

#endif
