#include<GL/glut.h>
float r = 1.0f, g = 0.0f, b = 0.0f;
float tx = 0, ty = 0, tz = 0;
float sx = 1, sy = 1, sz = 1, angle = 0.0f;

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-30, 30, -30, 30, -30, 30);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
   
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glPushMatrix();
    glScalef(2, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(-4.0, -4.0);
    glVertex2f(-4.0, 4.0);
    glVertex2f(4.0, 4.0);
    glVertex2f(4.0, -4.0);
    glEnd();
    glPopMatrix();

    glColor3f(0, 1, 0);
    glPushMatrix();
    glTranslatef(0, 8, 0);
    glBegin(GL_QUADS);
    glVertex2f(-4.0, -4.0);
    glVertex2f(-4.0, 4.0);
    glVertex2f(4.0, 4.0);
    glVertex2f(4.0, -4.0);
    glEnd();
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-4, -4, 0); 
    glutSolidSphere(2, 10, 10);
    glPopMatrix();
   glPushMatrix();
    glTranslatef(4, -4, 0);
    glutSolidSphere(2, 10, 10);
    glPopMatrix();
    glPopMatrix();

    glFlush();
}
//for event handling
void keyPress(unsigned char key, int x, int y) {
    switch (key)
    {
    case 'l':
        tx = tx - 1;
        break;
    case 'r':
        tx = tx +1;
        break;
    case 'b':
        r = 0.0f, g = 0.0f, b = 1.0f;
        break;
    }
    glutPostRedisplay();
}

void mousePress(int button, int state, int x, int y) {
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) {
            sx = sx - 0.2;
            //tx = tx - 1;
            //r = 1.0f, g = 1.0f, b = 0.0f;
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN) {
            sx = sx + 0.2;
            //tx = tx + 1;
            //r = 1.0f, g = 0.0f, b = 1.0f;
        }
        break;
    }
    glutPostRedisplay();
}
//animate
void animate() {
    if (tx < 30.0f) {
        tx = tx + 0.001;
        angle = angle + 0.1;
    }
    else {
        tx = -30.0f;
    }
    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(600, 600);
    glutCreateWindow("event handling");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPress);
    glutMouseFunc(mousePress);
    glutIdleFunc(animate);
    glutMainLoop();
}