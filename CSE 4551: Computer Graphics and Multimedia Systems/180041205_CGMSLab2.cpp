#include <windows.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

GLint currPos=260+50;
bool flag=true; //true=expand, false=shrink.
GLint farthest=260+150;
GLint nearest=260+24;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2i(260,260);
    glVertex2i(currPos,260);
    glVertex2i(currPos,currPos);
    glVertex2i(260,currPos);
    glEnd();

    glutSwapBuffers();
    if(currPos>=farthest)
    {
        flag=false;
    }
    if(currPos<=nearest)
    {
        flag=true;
    }
    if (flag)
    {
        currPos+=3;
    }
    if (!flag)
    {
        currPos-=3;
    }
    //glFlush();

}

void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(10, Timer, 0);
}

void Initialize()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 520, 0, 520, -1, 1);
}

int main(int iArgc, char** cppArgv)
{
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(520, 520);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Box animation");
    Initialize();
    glutDisplayFunc(Draw);
    Timer(0);
    glutMainLoop();
    return 0;
}
