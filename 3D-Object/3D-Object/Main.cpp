#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void DrawCube(GLfloat PositionX, GLfloat PositionY, GLfloat PositionZ, GLfloat edges);

GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "3D CUBE", NULL, NULL);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);


    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, screenWidth, screenHeight); // specifies the part of the window where object will be drawn
    glMatrixMode(GL_PROJECTION); // set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix 
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) 
    glLoadIdentity(); 

    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;


    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here

        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, -500);
        glRotatef(rotX, 1, 0, 0);
        glRotatef(rotY, 0, 1, 0);
        glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

        DrawCube(halfScreenWidth, halfScreenHeight, -500, 200);

        glPopMatrix();


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}



void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    
    const GLfloat rotationSpeed = 10;

    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_UP:
            rotX -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotX += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            rotY += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            rotY -= rotationSpeed;
            break;
        }


    }
}


void DrawCube(GLfloat PositionX, GLfloat PositionY, GLfloat PositionZ, GLfloat edges)
{
    GLfloat halfLength = edges * 0.5f;

    GLfloat vertices[] =
    {
        // front face
        PositionX - halfLength, PositionY + halfLength, PositionZ + halfLength, // top left
        PositionX + halfLength, PositionY + halfLength, PositionZ + halfLength, // top right
        PositionX + halfLength, PositionY - halfLength, PositionZ + halfLength, // bottom right
        PositionX - halfLength, PositionY - halfLength, PositionZ + halfLength, // bottom left

        // back face
        PositionX - halfLength, PositionY + halfLength, PositionZ - halfLength, // top left
        PositionX + halfLength, PositionY + halfLength, PositionZ - halfLength, // top right
        PositionX + halfLength, PositionY - halfLength, PositionZ - halfLength, // bottom right
        PositionX - halfLength, PositionY - halfLength, PositionZ - halfLength, // bottom left

        // left face
        PositionX - halfLength, PositionY + halfLength, PositionZ + halfLength, // top left
        PositionX - halfLength, PositionY + halfLength, PositionZ - halfLength, // top right
        PositionX - halfLength, PositionY - halfLength, PositionZ - halfLength, // bottom right
        PositionX - halfLength, PositionY - halfLength, PositionZ + halfLength, // bottom left

        // right face
        PositionX + halfLength, PositionY + halfLength, PositionZ + halfLength, // top left
        PositionX + halfLength, PositionY + halfLength, PositionZ - halfLength, // top right
        PositionX + halfLength, PositionY - halfLength, PositionZ - halfLength, // bottom right
        PositionX + halfLength, PositionY - halfLength, PositionZ + halfLength, // bottom left

        // top face
        PositionX - halfLength, PositionY + halfLength, PositionZ + halfLength, // top left
        PositionX - halfLength, PositionY + halfLength, PositionZ - halfLength, // top right
        PositionX + halfLength, PositionY + halfLength, PositionZ - halfLength, // bottom right
        PositionX + halfLength, PositionY + halfLength, PositionZ + halfLength, // bottom left

        // top face
        PositionX - halfLength, PositionY - halfLength, PositionZ + halfLength, // top left
        PositionX - halfLength, PositionY - halfLength, PositionZ - halfLength, // top right
        PositionX + halfLength, PositionY - halfLength, PositionZ - halfLength, // bottom right
        PositionX + halfLength, PositionY - halfLength, PositionZ + halfLength  // bottom left
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glColor3f( colour[0], colour[1], colour[2] );
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);
}