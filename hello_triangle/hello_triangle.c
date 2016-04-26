#include <stdio.h>

#include <GL/glew.h>
#include <GL/glfw.h>

int main()
{
    if (!glfwInit()) {
        fprintf(stderr, "ERROR! Could not start GLFW3!\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(
                            640,
                            480,
                            "Hello Triangle",
                            NULL,
                            NULL
    );
    if (!window) {
        fprintf(stderr, "Error: Could not open window with GLFW3.\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version  = glGetString(GL_VERSION);

    printf("Render: %s\n", renderer);
    printf("OpenGL Version supported: %s\n", version);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwTerminate();
    return 0;
}
