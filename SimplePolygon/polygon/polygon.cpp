#include <GL/glut.h>

void init()
{
	//Background color (Black)
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display()
{
	//Clear the buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Define the primitive
	glBegin(GL_POLYGON);

	//Specify vertex coordinates and give each vertex its own color
	glColor3f(0,1,1); glVertex2f(-0.3f, 0.3f);
	glColor3f(0,0,0); glVertex2f(0.3f, 0.3f);
	glColor3f(1,0,0); glVertex2f(0.6f, 0.0f);
	glColor3f(1,1,0); glVertex2f(0.3f, -0.3f);
	glColor3f(1,0,0); glVertex2f(-0.3f, -0.3f);
	glColor3f(0,0,1); glVertex2f(-0.6f, 0.0f);

	glEnd();

	//Empty all buffers to execute the drawing immediately
	glFlush();
}

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv); //Initialize glut library
	glutCreateWindow("Simple Polygon"); //Create the display window
	glutInitWindowSize(500, 500); //Set size of diplay window
	glutInitWindowPosition(100, 100); //Set the position of the display window
	glutDisplayFunc(display); //Dispaly callback for the current window
	init();
	glutMainLoop(); //Keep calling display functions
	return 0;
}

