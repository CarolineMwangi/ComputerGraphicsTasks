#include <GLFW/glfw3.h>
#include<math.h>


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


        //First colored circle, makes the cresent
        glBegin(GL_POLYGON);
        glColor3f(0.824, 0.412, 0.118);
        double radius = 0.2;
        double ori_x = 0.7;                        
        double ori_y = 0.8;
        for (int i = 0; i <= 300; i++) {
            double angle = 2 * 3.412 * i / 300;
            double x = cos(angle) * radius;
            double y = sin(angle) * radius;
            glVertex2d(ori_x + x, ori_y + y);
        }
        glEnd();

        //Second white circle
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        double radius2 = 0.2;
        double ori_x2 = 0.78;                         
        double ori_y2 = 0.86;
        for (int i = 0; i <= 300; i++) {
            double angle2 = 2 * 3.412 * i / 300;
            double x2 = cos(angle2) * radius;
            double y2= sin(angle2) * radius;
            glVertex2d(ori_x2 + x2, ori_y2 + y2);
        }
        glEnd();


       
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}