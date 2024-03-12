#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class GLintPoint {
public:
    GLint x, y;
};

void drawDot(GLint x, GLint y) 
{
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

int random(int m) { return rand() % m; }

void Sierpinski_Gasket() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    GLintPoint T[3] = {{1, 1}, {320, 639}, {630, 1}};
    
    int index = random(3);
    GLintPoint point = T[index];
    drawDot(point.x, point.y);

    for (int i = 0; i < 3000000; ++i) {
        index = random(3);
        point.x = (point.x + T[index].x) / 2;
        point.y = (point.y + T[index].y) / 2;
        drawDot(point.x, point.y);
    }
    glFlush();
}

void MyInit(void) 
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640.0, 0, 640.0);
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("My first attempt");

    glutDisplayFunc(Sierpinski_Gasket);
    
    MyInit();
    glutMainLoop();

    return 0;
}

