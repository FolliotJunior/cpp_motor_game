#ifndef __MOTOR_WINDOW_HPP__
    #define __MOTOR_WINDOW_HPP__
    #include <iostream>
    #define EXIT_ERROR_GLFW 1


class Window
{
    private:
        struct GLFWwindow *win;
    public:
        Window(int widht, int height, const char *name);
        ~Window();

        // window state
        bool is_open() const;
        void display();
        void clear();
};

#endif