#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int pos1=0;
static int pos2=0;
static int cod=110;
static int spin_hour=0;
static int spin_min=0;
static int flag=0;
static int y=20;

void init(void)
{
    glClearColor (1.0, 0.7, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
}


void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    pos1+=1;
    
    
    //Sky
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f (0,50);
    glVertex2f (300,50);
    glVertex2f (300,300);
    glVertex2f (0,300);
    glEnd();
    
    //Road
    glColor3f(0.5,1,0.5);
    glBegin(GL_POLYGON);
    glVertex2f (0,0);
    glVertex2f (300,0);
    glVertex2f (300,50);
    glVertex2f (0,50);
    glEnd();
    
    
    if(flag==0){
    //Flight-body
    glPushMatrix();
    glTranslatef(pos1,pos2,0);
    glColor3f(1,0.7,0);
    glBegin(GL_POLYGON);
    glVertex2f (30,200);
    glVertex2f (100,200);
    glVertex2f (100,215);
    glVertex2f (30,215);
    glEnd();
    
    //Flight-tail
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f (10,200);
    glVertex2f (30,200);
    glVertex2f (30,215);
    glVertex2f (10,225);
    glEnd();
    
    //Flight-wing1
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f (60,200);
    glVertex2f (80,200);
    glVertex2f (70,190);
    glVertex2f (40,190);
    glEnd();
    
    //Flight-wing2
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f (60,215);
    glVertex2f (80,215);
    glVertex2f (70,225);
    glVertex2f (40,225);
    glEnd();
    
    //Flight-front
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f (100,200);
    glVertex2f (cod,207);
    glVertex2f (100,215);
    glEnd();
    glPopMatrix();
    
    
    
    }
    //Building
    glColor3f(0.8,0.3,0);
    glBegin(GL_POLYGON);
    glVertex2f (240,50);
    glVertex2f (290,50);
    glVertex2f (290,200);
    glVertex2f (240,200);
    glEnd();
    
    //Building top
    glColor3f(0.8,0.3,0);
    glBegin(GL_POLYGON);
    glVertex2f (290,200);
    glVertex2f (240,200);
    glVertex2f (265,270);
    glEnd();
    
    
    //Clock
    glPushMatrix();
    glTranslatef(265,200,0);
    glColor3f (1.0, 1.0, 1.0);
    glutWireSphere(15, 16, 16);
    glFlush ();
    
    glColor3f (1,1,1);
    glRotatef(spin_hour,0.0,0.0,1.0);
    glBegin(GL_LINES);
    glVertex2f (0.0, 0.0);
    glVertex2f (0.0, 10);
    glEnd();
    
    glColor3f (1,1,1);
    glRotatef(spin_min,0.0,0.0,1.0);
    glBegin(GL_LINES);
    glVertex2f (0.0, 0.0);
    glVertex2f (-10, 0.0);
    glEnd();
    glPopMatrix();
    
    
    //Blast
    if((pos1+cod)==240){
        
        flag=1;
    }
    if(flag==1){
       
        y-=1;
        //Polygon1
        glPushMatrix();
        glColor3f(1,1,0);
        glBegin(GL_POLYGON);
        glVertex2f (230,250);
        glVertex2f (250,225);
        glVertex2f (250,205);
        glEnd();
        
        glColor3f(1,1,0);
        glBegin(GL_POLYGON);
        glVertex2f (280,250);
        glVertex2f (250,225);
        glVertex2f (250,205);
        glEnd();
        
        glColor3f(1,1,0);
        glBegin(GL_POLYGON);
        glVertex2f (290,170);
        glVertex2f (250,225);
        glVertex2f (250,205);
        glEnd();
        
        glColor3f(1,1,0);
        glBegin(GL_POLYGON);
        glVertex2f (210,170);
        glVertex2f (250,225);
        glVertex2f (250,205);
        glEnd();
        
        
        //Polygon2
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex2f (200,200);
        glVertex2f (250,220);
        glVertex2f (250,180);
        glEnd();
        
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex2f (250,220);
        glVertex2f (250,180);
        glVertex2f (300,200);
        glEnd();
        
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex2f (260,260);
        glVertex2f (230,200);
        glVertex2f (260,200);
        glEnd();
        
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex2f (230,200);
        glVertex2f (260,200);
        glVertex2f (260,160);
        glEnd();
        glPopMatrix();
        
        
        //Piece1
        glPushMatrix();
        glTranslatef(0,y,0);
        glColor3f(1,0.7,0);
        glBegin(GL_POLYGON);
        glVertex2f (170,200);
        glVertex2f (170,185);
        glVertex2f (200,185);
        glVertex2f (200,200);
        glEnd();
        
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f (150,210);
        glVertex2f (170,200);
        glVertex2f (170,185);
        glVertex2f (150,185);
        glEnd();
        
        glColor3f(1,0.7,0);
        glBegin(GL_POLYGON);
        glVertex2f (210,185);
        glVertex2f (225,185);
        glVertex2f (225,200);
        glVertex2f (210,200);
        glEnd();
        
        glColor3f(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2f (217,210);
        glVertex2f (225,200);
        glVertex2f (210,200);
        glEnd();
        
        
        glPopMatrix();
       
       // glutIdleFunc(NULL);
        //sleep(1);
        //flag=1;
        glutPostRedisplay();
    }
    
    


    
    
    
    glutSwapBuffers();
}


void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(0,300,0,300,-1,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}

void spinDisplay(void)
{
    spin_min=spin_min+10;
    if(spin_min>360){
        spin_min=spin_min%360;
        spin_hour=(spin_hour+10)%360;
    }
    glutPostRedisplay();
}



void keyboard (unsigned char key, int x, int y)
{
    if(key=='q'){
        glutIdleFunc(spinDisplay);
        //glutIdleFunc(display); 
    }
    
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




