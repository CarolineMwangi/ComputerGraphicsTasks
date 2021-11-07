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
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1, 1, 1, 1);

        //Outer frame
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2f(-0.7, 0.7);
        glVertex2f(0.5, 0.7);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.4, 0.5);
        glVertex2f(0.4, -0.3);
        glVertex2f(-0.6, -0.3);
        glVertex2f(-0.6, 0.5);
        glVertex2f(-0.8, 0.5);
        glVertex2f(-0.8, 0.7);
        
        glEnd();


        //window on the left
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2f(-0.5f, 0.3f);
        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.3f, 0.5f);
        glVertex2f(-0.5f, 0.5);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(-0.5f, 0.4f);
        glVertex2f(-0.3f, 0.4f);
        glVertex2f(-0.4f, 0.3f);
        glVertex2f(-0.4f, 0.5f);
        glEnd();



        //window on the right
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2f(0.1f, 0.3f);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.3f, 0.5f);
        glVertex2f(0.1f, 0.5f);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2f(0.1f, 0.4f);
        glVertex2f(0.3f, 0.4f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.2f, 0.5f);
        glEnd();

        //door
        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2f(-0.2f, -0.3f);
        glVertex2f(0.0f, -0.3f);
        glVertex2f(0.0f, 0.1f);
        glVertex2f(-0.2f, 0.1f);
        glEnd();



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}