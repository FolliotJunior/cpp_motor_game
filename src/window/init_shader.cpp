#include "glad/glad.h"
#include "window.hpp"

const char *vert_shad = R"(
#version 330 core
layout (location = 0) in vec2 aPos;
void main() {
    gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

const char *frag_shad = R"(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor = vec4(1.0, 0.2, 0.2, 1.0);
}
)";

void Window::init_shaders()
{
    GLuint v_shad = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shad, 1, &vert_shad, nullptr);
    glCompileShader(v_shad);
    GLuint f_shad = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shad, 1, &frag_shad, nullptr);
    glCompileShader(f_shad);
    Window::shader_prog = glCreateProgram();
    glAttachShader(Window::shader_prog, v_shad);
    glAttachShader(Window::shader_prog, f_shad);
    glLinkProgram(Window::shader_prog);
    glDeleteShader(v_shad);
    glDeleteShader(f_shad);
}
