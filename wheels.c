#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int wheel_pos;
static int wheel_radius = 10;
static int angle=60;
static int gap=50;
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void wheel(){
    glutWireSphere(wheel_radius, 16, 16);
}

void display(void)
{
    glPushMatrix();
    glTranslatef(wheel_pos+gap,0,0);
    glRotatef(angle,0.0,0.0,1.0);
    wheel();
    glPopMatrix();
    glutSwapBuffers();
    
    
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(wheel_pos,0,0);
    glRotatef(angle,0.0,0.0,1.0);
    wheel();
    glPopMatrix();
    
    
}

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void keyboard (unsigned char key, int x, int y)
{
    if(key=='d'||key=='D'){
        wheel_pos+=1;
        angle=(angle+10)%360;
    }
    if(key=='a' || key=='A'){
        wheel_pos-=1;
        if(angle==0){
            angle=360;
            angle=(angle-10)%360;
        }
            
    }
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}