#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int pos=0;
void init(void)
{
glClearColor (1.0, 1.0, 1.0, 1.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);


//Sea
glColor3f(0,1,1);
glBegin(GL_POLYGON);
glVertex2f (0,0);
glVertex2f (100,0);
glVertex2f (100,40);
glVertex2f (0, 40);
glEnd();

//Boat
glPushMatrix();
glTranslatef(pos,0,0);
glColor3f(0,0,1);
glBegin(GL_POLYGON);
glVertex2f (20,40);
glVertex2f (40,40);
glVertex2f (50,50);
glVertex2f (10,50);
glEnd();
glPopMatrix();

//Berg
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2f (80,40);
glVertex2f (90,40);
glVertex2f (85,50);
glEnd();


glutSwapBuffers();
}
void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glOrtho(0,100,0,100,-1,0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

}

void split(){
    glPushMatrix();
    glTranslatef(0,pos,0);
    glPushMatrix();
    glTranslatef(pos,0,0);
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f (80,40);
    glVertex2f (90,40);
    glVertex2f (95,50);
    glVertex2f (75,50);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void keyboard (unsigned char key, int x, int y)
{
    if(key=='q'){
        pos+=2;
        if(pos==85)
            glutDisplayFunc(split); 
    }
    glutPostRedisplay();
}
int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}