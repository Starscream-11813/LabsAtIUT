#include<iostream>
#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

using namespace std;

struct Point
{
    GLint x;
    GLint y;
};
struct Color
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
};
GLint seedx, seedy;

/* Initialize OpenGL Graphics */

void initGL()
{
    //glViewport(0,0,520,520);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
    glOrtho(0,520,0,520,-1,1);
    //glMatrixMode(GL_MODELVIEW);
}
Color getPixelColor(GLint x, GLint y)
{
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGBA, GL_FLOAT, &color);
    return color;
}
void setPixelColor(GLint x, GLint y, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}
Color newColor = {0.0f, 1.0f, 1.0f};//Cyan (Colors with floating point RGB values don't work.)
Color oldColor = {0.0f, 0.0f, 0.0f};//Black
Color bColor = {1.0f, 1.0f, 0.0f};//Yellow
void floodFill(GLint x, GLint y)
{
    Color color;
    color = getPixelColor(x, y);
    if((color.r != bColor.r || color.g != bColor.g || color.b != bColor.b) && (color.r != newColor.r || color.g != newColor.g || color.b != newColor.b))
    {
        //cout<<"Here"<<endl;
        setPixelColor(x, y, newColor);
        floodFill((GLint)x+1, y);
        floodFill(x, (GLint)y+1);
        floodFill((GLint)x-1, y);
        floodFill(x, (GLint)y-1);
    }
    return;
}
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
    //glClearColor(0.2, 0.4,0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glPointSize(1);
    //glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2i(0, 0);
    glVertex2i(100, 0);
    glVertex2i(100, 100);
    glEnd();
    glFlush();  // Render now
    floodFill(seedx,seedy);
}

/* Main function: GLUT runs as a console application starting at main()  */

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    //glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(520, 520);   // Set the window's initial width & height
    glutInitWindowPosition(500, 70); // Position the window's initial top-left corner
    //seedx=10,seedy=5;
    cout << "Enter seedx, seedy (Seed point must be within the triangle having vertices (0,0), (100,0) and (100,100)): ";
    cin >> seedx >> seedy; //the seed point should be inside the polygon
    glutCreateWindow("Drawing polygons");  // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}

