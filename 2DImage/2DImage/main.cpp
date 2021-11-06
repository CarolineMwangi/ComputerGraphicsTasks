#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(840, 680, "2D Image", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        /*glClear(GL_COLOR_BUFFER_BIT); */
        glBegin(GL_POLYGON);

        glVertex2f(-0.7, 0.7);
        glVertex2f(0.5, 0.7);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.4, 0.5);
        glVertex2f(0.4, -0.3);
        glVertex2f(-0.7, -0.3);
        glVertex2f(-0.6, 0.5);
        glVertex2f(-0.8, 0.5);
        glVertex2f(-0.8, 0.7);
        
        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}