#include<windows.h>
#include<iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<math.h>

static float	tx	=  0.0;
static float	ty	=  0.0;
static GLfloat	spin	=  0.0;

void my_inti(void)
{
    glClearColor(224,224,224,0);
    glOrtho(0,100,0,100,0,100);

}

// Define Functions

// Circle Draw Function
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = rx * cosf(theta);//calculate the x component
        float y = ry * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

// Rotation Functions
void spinDisplay_left(void)
{
    spin = spin + 0.01;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void spinDisplay_right(void)
{
    spin = spin - 0.01;
    if (spin < 360.0)
        spin = spin+360.0;
    glutPostRedisplay();
}


// Rotation by keyboard - a,d,s
void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'a':
         glutIdleFunc(spinDisplay_left);
        break;

    case 'd':
        glutIdleFunc(spinDisplay_right);
        break;


    case 's':
        glutIdleFunc(NULL);
        break;

    default:
        break;
    }
}


// Transform Function
void spe_key(int key, int x, int y)
{

    switch (key)
    {

    case GLUT_KEY_LEFT:
        tx -=0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        tx +=0.5;
        glutPostRedisplay();
        break;



    case GLUT_KEY_DOWN:
        ty -=0.5;
        glutPostRedisplay();
        break;


    case GLUT_KEY_UP:
        ty +=0.5;
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

// Display Function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);




    // Surface
    glColor3ub(222,233,236);
    DrawCircle(60,0,100,100,500);

    // Left Tree-3
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(9,1);
    glVertex2d(15,1);
    glVertex2d(12,22);
    glEnd();

    // Left Tree-4
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(13,1);
    glVertex2d(20,1);
    glVertex2d(18,30);
    glEnd();

    // Right Lower Tree-1
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(74,0);
    glVertex2d(82,0);
    glVertex2d(78,27);
    glEnd();

    // Right Lower Tree-2
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(74,16);
    glVertex2d(82,16);
    glVertex2d(78,27);
    glEnd();

    // Right Lower Tree-3
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(89,0);
    glVertex2d(93,0);
    glVertex2d(91,35);
    glEnd();

    // Right Lower Tree-4
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(85,0);
    glVertex2d(92,0);
    glVertex2d(89,25);
    glEnd();

    // Right Lower Tree-4
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2d(90,0);
    glVertex2d(96,0);
    glVertex2d(93,30);
    glEnd();

    // Lower Surface - Circle
    glColor3ub(161,208,222);
    DrawCircle(60,-15,60,30,500);

    // Left Tree-1
    glColor3ub(0,102,51);
    glBegin(GL_TRIANGLES);
    glVertex2d(5,0);
    glVertex2d(11,0);
    glVertex2d(8,7);
    glEnd();

    // Left Tree-2
    glColor3ub(0,102,51);
    glBegin(GL_TRIANGLES);
    glVertex2d(16,0);
    glVertex2d(20,0);
    glVertex2f(17.5,9);
    glEnd();

    // Right Upper Tree flag-1
    glColor3ub(192,192,192);
    glBegin(GL_TRIANGLES);
    glVertex2d(67,84);
    glVertex2d(74,80);
    glVertex2d(74,84);
    glEnd();

    // Tree Log
    glColor3ub(0,0,0);
    glRectf(73,88,74,81);

    // Right upper Tree-1
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(70,87);
    glVertex2d(77,87);
    glVertex2f(73.5,92);
    glEnd();

    // Right upper Tree-2
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(70,90);
    glVertex2d(77,90);
    glVertex2f(73.5,95);
    glEnd();

    // Right upper Tree-3
    glColor3ub(0,102,102);
    glBegin(GL_TRIANGLES);
    glVertex2d(70,93);
    glVertex2d(77,93);
    glVertex2f(73.5,98);
    glEnd();



    /////////////////////////////////////////////////
    ///////////   ICE MAN  ///////////////////////
    ///////////////////////////////////////////////



    glPushMatrix();

    // For Translate
    glTranslatef(tx,ty,0);

    // For Rotation
    glRotatef(spin, 0, 0, 1.0);

    // Skate Board
    glLineWidth (2);
    glColor3b(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(47,50);
    glVertex2d(55,50);
    glEnd();

    // grip
    glColor3b(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(55.7,52);
    glVertex2f(55,50);
    glEnd();

    // grip
    glColor3b(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(54.8,51);
    glVertex2f(54.5,50);
    glEnd();

    // Man
    glColor3b(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(49,50,0);
    glVertex3f(49.5,54,0);
    glVertex3f(51.1,56,0);
    glVertex3f(51.3,57,0);
    glVertex3f(52,60,0);
    glVertex3f(52.5,56.5,0);
    glVertex3f(52,55,0);
    glVertex3f(53,50,0);
    glVertex3f(52.5,50,0);
    glVertex3f(51,55,0);
    glVertex3f(49.5,50,0);
    glEnd();

    // Handle
    glLineWidth (3);
    glColor3b(1,0,1);
    glBegin(GL_LINES);
    glVertex2d(53,54);
    glVertex2d(50,46);
    glEnd();

    glPopMatrix();








    /////////////////////////////////////////////////
    ///////////   ICE MAN  ///////////////////////
    ///////////////////////////////////////////////




    // glutSwapBuffers();
    glFlush();
}



int main()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Ice Skating Board Game");


    my_inti();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();

    return 0;
}
