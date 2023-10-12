#include <windows.h>
#include<GL/glut.h>
#include<string.h>
#include <iostream>

int i,flag=0,flagb=1,flags=0,flagt=0,flagp=0,flagw=1,flagx=0;
float a=0.0f,b=0.0f,c=0.0f,m=0.0f,n=0.0f,o=0.0f,p=0.0f,q=0.0f,r=0.0f,x=0.0f,y=0.0f,z=0.0f,a1=0.0,a2=0.0,a3=0.0;
double posx = 0, posy = 0, posz = 2, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;
float j;

double  translatex=1.0,translatez=1.2,translatey=-0.73;
double boatscalex=0.5,boatscaley=0.5, boatscalez=0.5;
int boatanglex=0, boatangley=0,boatanglez=0;

void water()
{
    glBegin(GL_QUADS);
    glColor3f(0.0,0.4,0.7);
    glVertex3f(-5.0,-0.415,5.0);
    glVertex3f(5.0,-0.415,5.0);
    glVertex3f(5.0,-0.415,-5.0);
    glVertex3f(-5.0,-0.415,-5.0);
    glEnd();
}

void lines()
{
    float t1,t2;
    glBegin(GL_LINES);
    for(t1=0.0;t1<=10.0;t1+=0.4)
    {
     for(t2=0.0;t2<=10.0;t2+=0.4)
     {
       glColor3f(0.7,0.7,0.7);
       glVertex3f(-5.0+t2,-0.41,-4.5+t1);
       glVertex3f(-4.95+t2,-0.41,-4.5+t1);
     }
    }
    glEnd();
}

void base()
{
    float i;
    for(i=0.0;i<1.0;i+=0.8)
    {
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);  //front
    glVertex3f(-0.5+i,-0.4,0.2);
    glVertex3f(-0.3+i,-0.4,0.2);
    glVertex3f(-0.3+i,-0.25,0.2);
    glVertex3f(-0.5+i,-0.25,0.2);

    glColor3f(0.3,0.3,0.3);  //left
    glVertex3f(-0.5+i,-0.4,0.2);
    glVertex3f(-0.5+i,-0.4,-0.2);
    glVertex3f(-0.5+i,-0.25,-0.2);
    glVertex3f(-0.5+i,-0.25,0.2);

    glColor3f(0.1,0.1,0.1);  //back
    glVertex3f(-0.5+i,-0.4,-0.2);
    glVertex3f(-0.3+i,-0.4,-0.2);
    glVertex3f(-0.3+i,-0.25,-0.2);
    glVertex3f(-0.5+i,-0.25,-0.2);

    glColor3f(0.3,0.3,0.3);  //right
    glVertex3f(-0.3+i,-0.4,0.2);
    glVertex3f(-0.3+i,-0.4,-0.2);
    glVertex3f(-0.3+i,-0.25,-0.2);
    glVertex3f(-0.3+i,-0.25,0.2);

    glColor3f(0.5,0.5,0.5);  //top
    glVertex3f(-0.5+i,-0.25,0.2);
    glVertex3f(-0.3+i,-0.25,0.2);
    glVertex3f(-0.3+i,-0.25,-0.2);
    glVertex3f(-0.5+i,-0.25,-0.2);
    glEnd();
    }
}

void earth()
{
    float i;
    for(i=0.0;i<4.0;i+=3.5)
    {
    glBegin(GL_QUADS);
    glColor3f(0.0,0.6,0.0);
    glVertex3f(-3.0+i,-0.4,0.17);  //front
    glVertex3f(-0.5+i,-0.4,0.17);
    glVertex3f(-0.5+i,-0.25,0.17);
    glVertex3f(-3.0+i,-0.25,0.17);

    glVertex3f(-3.0+i,-0.4,-0.17); //back
    glVertex3f(-0.5+i,-0.4,-0.17);
    glVertex3f(-0.5+i,-0.25,-0.17);
    glVertex3f(-3.0+i,-0.25,-0.17);

    glColor3f(0.0,0.5,0.0);   //top
    glVertex3f(-3.0+i,-0.25,0.17);
    glVertex3f(-0.5+i,-0.25,0.17);
    glVertex3f(-0.5+i,-0.25,-0.17);
    glVertex3f(-3.0+i,-0.25,-0.17);
    glEnd();
    }
}

void pillars()
{
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(-0.35,-0.25,0.2);
    glVertex3f(-0.31,-0.25,0.2);
    glVertex3f(-0.31,0.2,0.2);
    glVertex3f(-0.35,0.2,0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(-0.35,-0.25,0.2);
    glVertex3f(-0.35,-0.25,0.15);
    glVertex3f(-0.35,0.2,0.15);
    glVertex3f(-0.35,0.2,0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(-0.35,-0.25,0.15);
    glVertex3f(-0.31,-0.25,0.15);
    glVertex3f(-0.31,0.2,0.15);
    glVertex3f(-0.35,0.2,0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(-0.31,-0.25,0.2);
    glVertex3f(-0.31,-0.25,0.15);
    glVertex3f(-0.31,0.2,0.15);
    glVertex3f(-0.31,0.2,0.2);
    //back
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(-0.35,-0.25,-0.2);
    glVertex3f(-0.31,-0.25,-0.2);
    glVertex3f(-0.31,0.2,-0.2);
    glVertex3f(-0.35,0.2,-0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(-0.35,-0.25,-0.2);
    glVertex3f(-0.35,-0.25,-0.15);
    glVertex3f(-0.35,0.2,-0.15);
    glVertex3f(-0.35,0.2,-0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(-0.35,-0.25,-0.15);
    glVertex3f(-0.31,-0.25,-0.15);
    glVertex3f(-0.31,0.2,-0.15);
    glVertex3f(-0.35,0.2,-0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(-0.31,-0.25,-0.2);
    glVertex3f(-0.31,-0.25,-0.15);
    glVertex3f(-0.31,0.2,-0.15);
    glVertex3f(-0.31,0.2,-0.2);
    //top
    glColor3f(0.2,0.2,0.5);
    glVertex3f(-0.35,0.2,0.3);
    glVertex3f(-0.31,0.2,0.3);
    glVertex3f(-0.31,0.25,0.3);
    glVertex3f(-0.35,0.25,0.3);

    glColor3f(0.3,0.3,0.5);
    glVertex3f(-0.35,0.2,0.3);
    glVertex3f(-0.35,0.2,-0.3);
    glVertex3f(-0.35,0.25,-0.3);
    glVertex3f(-0.35,0.25,0.3);

    glColor3f(0.2,0.2,0.5);
    glVertex3f(-0.35,0.2,-0.3);
    glVertex3f(-0.31,0.2,-0.3);
    glVertex3f(-0.31,0.25,-0.3);
    glVertex3f(-0.35,0.25,-0.3);

    glColor3f(0.3,0.3,0.5);
    glVertex3f(-0.31,0.2,0.3);
    glVertex3f(-0.31,0.2,-0.3);
    glVertex3f(-0.31,0.25,-0.3);
    glVertex3f(-0.31,0.25,0.3);

    glColor3f(0.3,0.3,0.6);
    glVertex3f(-0.35,0.25,0.3);
    glVertex3f(-0.31,0.25,0.3);
    glVertex3f(-0.31,0.25,-0.3);
    glVertex3f(-0.35,0.25,-0.3);
    //top piller
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(-0.35,0.25,0.2);
    glVertex3f(-0.31,0.25,0.2);
    glVertex3f(-0.31,0.35,0.2);
    glVertex3f(-0.35,0.35,0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(-0.35,0.25,0.2);
    glVertex3f(-0.35,0.25,0.15);
    glVertex3f(-0.35,0.35,0.15);
    glVertex3f(-0.35,0.35,0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(-0.35,0.25,0.15);
    glVertex3f(-0.31,0.25,0.15);
    glVertex3f(-0.31,0.35,0.15);
    glVertex3f(-0.35,0.35,0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(-0.31,0.25,0.2);
    glVertex3f(-0.31,0.25,0.15);
    glVertex3f(-0.31,0.35,0.15);
    glVertex3f(-0.31,0.35,0.2);
    //back
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(-0.35,0.25,-0.2);
    glVertex3f(-0.31,0.25,-0.2);
    glVertex3f(-0.31,0.35,-0.2);
    glVertex3f(-0.35,0.35,-0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(-0.35,0.25,-0.2);
    glVertex3f(-0.35,0.25,-0.15);
    glVertex3f(-0.35,0.35,-0.15);
    glVertex3f(-0.35,0.35,-0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(-0.35,0.25,-0.15);
    glVertex3f(-0.31,0.25,-0.15);
    glVertex3f(-0.31,0.35,-0.15);
    glVertex3f(-0.35,0.35,-0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(-0.31,0.25,-0.2);
    glVertex3f(-0.31,0.25,-0.15);
    glVertex3f(-0.31,0.35,-0.15);
    glVertex3f(-0.31,0.35,-0.2);
    glEnd();

    //right side
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(0.35,-0.25,0.2);
    glVertex3f(0.31,-0.25,0.2);
    glVertex3f(0.31,0.2,0.2);
    glVertex3f(0.35,0.2,0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(0.35,-0.25,0.2);
    glVertex3f(0.35,-0.25,0.15);
    glVertex3f(0.35,0.2,0.15);
    glVertex3f(0.35,0.2,0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(0.35,-0.25,0.15);
    glVertex3f(0.31,-0.25,0.15);
    glVertex3f(0.31,0.2,0.15);
    glVertex3f(0.35,0.2,0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(0.31,-0.25,0.2);
    glVertex3f(0.31,-0.25,0.15);
    glVertex3f(0.31,0.2,0.15);
    glVertex3f(0.31,0.2,0.2);
    //back
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(0.35,-0.25,-0.2);
    glVertex3f(0.31,-0.25,-0.2);
    glVertex3f(0.31,0.2,-0.2);
    glVertex3f(0.35,0.2,-0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(0.35,-0.25,-0.2);
    glVertex3f(0.35,-0.25,-0.15);
    glVertex3f(0.35,0.2,-0.15);
    glVertex3f(0.35,0.2,-0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(0.35,-0.25,-0.15);
    glVertex3f(0.31,-0.25,-0.15);
    glVertex3f(0.31,0.2,-0.15);
    glVertex3f(0.35,0.2,-0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(0.31,-0.25,-0.2);
    glVertex3f(0.31,-0.25,-0.15);
    glVertex3f(0.31,0.2,-0.15);
    glVertex3f(0.31,0.2,-0.2);
    //top
    glColor3f(0.2,0.2,0.5);
    glVertex3f(0.35,0.2,0.3);
    glVertex3f(0.31,0.2,0.3);
    glVertex3f(0.31,0.25,0.3);
    glVertex3f(0.35,0.25,0.3);

    glColor3f(0.3,0.3,0.5);
    glVertex3f(0.35,0.2,0.3);
    glVertex3f(0.35,0.2,-0.3);
    glVertex3f(0.35,0.25,-0.3);
    glVertex3f(0.35,0.25,0.3);

    glColor3f(0.2,0.2,0.5);
    glVertex3f(0.35,0.2,-0.3);
    glVertex3f(0.31,0.2,-0.3);
    glVertex3f(0.31,0.25,-0.3);
    glVertex3f(0.35,0.25,-0.3);

    glColor3f(0.3,0.3,0.5);
    glVertex3f(0.31,0.2,0.3);
    glVertex3f(0.31,0.2,-0.3);
    glVertex3f(0.31,0.25,-0.3);
    glVertex3f(0.31,0.25,0.3);

    glColor3f(0.3,0.3,0.6);
    glVertex3f(0.35,0.25,0.3);
    glVertex3f(0.31,0.25,0.3);
    glVertex3f(0.31,0.25,-0.3);
    glVertex3f(0.35,0.25,-0.3);
    //top piller
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(0.35,0.25,0.2);
    glVertex3f(0.31,0.25,0.2);
    glVertex3f(0.31,0.35,0.2);
    glVertex3f(0.35,0.35,0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(0.35,0.25,0.2);
    glVertex3f(0.35,0.25,0.15);
    glVertex3f(0.35,0.35,0.15);
    glVertex3f(0.35,0.35,0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(0.35,0.25,0.15);
    glVertex3f(0.31,0.25,0.15);
    glVertex3f(0.31,0.35,0.15);
    glVertex3f(0.35,0.35,0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(0.31,0.25,0.2);
    glVertex3f(0.31,0.25,0.15);
    glVertex3f(0.31,0.35,0.15);
    glVertex3f(0.31,0.35,0.2);
    //back
    glColor3f(0.1,0.1,0.5);  //front
    glVertex3f(0.35,0.25,-0.2);
    glVertex3f(0.31,0.25,-0.2);
    glVertex3f(0.31,0.35,-0.2);
    glVertex3f(0.35,0.35,-0.2);

    glColor3f(0.1,0.1,0.3);   //left
    glVertex3f(0.35,0.25,-0.2);
    glVertex3f(0.35,0.25,-0.15);
    glVertex3f(0.35,0.35,-0.15);
    glVertex3f(0.35,0.35,-0.2);

    glColor3f(0.1,0.1,0.5);  //back
    glVertex3f(0.35,0.25,-0.15);
    glVertex3f(0.31,0.25,-0.15);
    glVertex3f(0.31,0.35,-0.15);
    glVertex3f(0.35,0.35,-0.15);

    glColor3f(0.1,0.1,0.3);  //right
    glVertex3f(0.31,0.25,-0.2);
    glVertex3f(0.31,0.25,-0.15);
    glVertex3f(0.31,0.35,-0.15);
    glVertex3f(0.31,0.35,-0.2);
    glEnd();
    //slops front
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.5);
    glVertex3f(-0.6,-0.25,0.17);
    glVertex3f(-0.5,-0.25,0.17);
    glVertex3f(-0.35,0.2,0.17);
    glVertex3f(-0.35,0.25,0.17);
    //BACK
    glVertex3f(-0.6,-0.25,-0.17);
    glVertex3f(-0.5,-0.25,-0.17);
    glVertex3f(-0.35,0.2,-0.17);
    glVertex3f(-0.35,0.25,-0.17);
    //right front
    glVertex3f(0.6,-0.25,0.17);
    glVertex3f(0.5,-0.25,0.17);
    glVertex3f(0.35,0.2,0.17);
    glVertex3f(0.35,0.25,0.17);
    //Back
    glVertex3f(0.6,-0.25,-0.17);
    glVertex3f(0.5,-0.25,-0.17);
    glVertex3f(0.35,0.2,-0.17);
    glVertex3f(0.35,0.25,-0.17);
    glEnd();
}

void bridge()
{
    glBegin(GL_QUADS);
    glColor3f(0.1,0.2,0.3);
    glVertex3f(-0.3,-0.25,0.15);
    glVertex3f(0.3,-0.25,0.15);
    glVertex3f(0.3,-0.23,0.15);
    glVertex3f(-0.3,-0.23,0.15);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(-0.3,-0.25,0.15);
    glVertex3f(-0.3,-0.25,-0.15);
    glVertex3f(-0.3,-0.23,-0.15);
    glVertex3f(-0.3,-0.23,0.15);

    glColor3f(0.1,0.2,0.3);
    glVertex3f(-0.3,-0.25,-0.15);
    glVertex3f(0.3,-0.25,-0.15);
    glVertex3f(0.3,-0.23,-0.15);
    glVertex3f(-0.3,-0.23,-0.15);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(0.3,-0.25,0.15);
    glVertex3f(0.3,-0.25,-0.15);
    glVertex3f(0.3,-0.23,-0.15);
    glVertex3f(0.3,-0.23,0.15);

    glColor3f(0.3,0.3,0.4);
    glVertex3f(-0.3,-0.23,0.15);
    glVertex3f(0.3,-0.23,0.15);
    glVertex3f(0.3,-0.23,-0.15);
    glVertex3f(-0.3,-0.23,-0.15);
    glEnd();
    //pillers
    //left front
    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.1);
    glVertex3f(-0.3,-0.23,0.15);
    glVertex3f(-0.28,-0.23,0.15);
    glVertex3f(-0.28,0.1,0.15);
    glVertex3f(-0.3,0.1,0.15);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(-0.3,-0.23,0.15);
    glVertex3f(-0.3,-0.23,0.12);
    glVertex3f(-0.3,0.1,0.12);
    glVertex3f(-0.3,0.1,0.15);

    glColor3f(0.3,0.2,0.1);
    glVertex3f(-0.3,-0.23,0.12);
    glVertex3f(-0.28,-0.23,0.12);
    glVertex3f(-0.28,0.1,0.12);
    glVertex3f(-0.3,0.1,0.12);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(-0.28,-0.23,0.15);
    glVertex3f(-0.28,-0.23,0.12);
    glVertex3f(-0.28,0.1,0.12);
    glVertex3f(-0.28,0.1,0.15);
    glEnd();
    //right front
    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.1);
    glVertex3f(0.3,-0.23,0.15);
    glVertex3f(0.28,-0.23,0.15);
    glVertex3f(0.28,0.1,0.15);
    glVertex3f(0.3,0.1,0.15);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(0.3,-0.23,0.15);
    glVertex3f(0.3,-0.23,0.12);
    glVertex3f(0.3,0.1,0.12);
    glVertex3f(0.3,0.1,0.15);

    glColor3f(0.3,0.2,0.1);
    glVertex3f(0.3,-0.23,0.12);
    glVertex3f(0.28,-0.23,0.12);
    glVertex3f(0.28,0.1,0.12);
    glVertex3f(0.3,0.1,0.12);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(0.28,-0.23,0.15);
    glVertex3f(0.28,-0.23,0.12);
    glVertex3f(0.28,0.1,0.12);
    glVertex3f(0.28,0.1,0.15);
    glEnd();
    //left back
    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.1);
    glVertex3f(-0.3,-0.23,-0.15);
    glVertex3f(-0.28,-0.23,-0.15);
    glVertex3f(-0.28,0.1,-0.15);
    glVertex3f(-0.3,0.1,-0.15);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(-0.3,-0.23,-0.15);
    glVertex3f(-0.3,-0.23,-0.12);
    glVertex3f(-0.3,0.1,-0.12);
    glVertex3f(-0.3,0.1,-0.15);

    glColor3f(0.3,0.2,0.1);
    glVertex3f(-0.3,-0.23,-0.12);
    glVertex3f(-0.28,-0.23,-0.12);
    glVertex3f(-0.28,0.1,-0.12);
    glVertex3f(-0.3,0.1,-0.12);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(-0.28,-0.23,-0.15);
    glVertex3f(-0.28,-0.23,-0.12);
    glVertex3f(-0.28,0.1,-0.12);
    glVertex3f(-0.28,0.1,-0.15);
    glEnd();
    //right back
    glBegin(GL_QUADS);
    glColor3f(0.3,0.2,0.1);
    glVertex3f(0.3,-0.23,-0.15);
    glVertex3f(0.28,-0.23,-0.15);
    glVertex3f(0.28,0.1,-0.15);
    glVertex3f(0.3,0.1,-0.15);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(0.3,-0.23,-0.15);
    glVertex3f(0.3,-0.23,-0.12);
    glVertex3f(0.3,0.1,-0.12);
    glVertex3f(0.3,0.1,-0.15);

    glColor3f(0.3,0.2,0.1);
    glVertex3f(0.3,-0.23,-0.12);
    glVertex3f(0.28,-0.23,-0.12);
    glVertex3f(0.28,0.1,-0.12);
    glVertex3f(0.3,0.1,-0.12);

    glColor3f(0.3,0.2,0.3);
    glVertex3f(0.28,-0.23,-0.15);
    glVertex3f(0.28,-0.23,-0.12);
    glVertex3f(0.28,0.1,-0.12);
    glVertex3f(0.28,0.1,-0.15);
    glEnd();
    //top left
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-0.3,0.1,0.15);
    glVertex3f(-0.28,0.1,0.15);
    glVertex3f(-0.28,0.13,0.15);
    glVertex3f(-0.3,0.13,0.15);

    glColor3f(0.5,0.3,0.2);
    glVertex3f(-0.3,0.1,0.15);
    glVertex3f(-0.3,0.1,-0.15);
    glVertex3f(-0.3,0.13,-0.15);
    glVertex3f(-0.3,0.13,0.15);

    glColor3f(0.4,0.3,0.2);
    glVertex3f(-0.3,0.1,-0.15);
    glVertex3f(-0.28,0.1,-0.15);
    glVertex3f(-0.28,0.13,-0.15);
    glVertex3f(-0.3,0.13,-0.15);

    glColor3f(0.5,0.3,0.2);
    glVertex3f(-0.28,0.1,0.15);
    glVertex3f(-0.28,0.1,-0.15);
    glVertex3f(-0.28,0.13,-0.15);
    glVertex3f(-0.28,0.13,0.15);
    glEnd();

    //top right
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(0.3,0.1,0.15);
    glVertex3f(0.28,0.1,0.15);
    glVertex3f(0.28,0.13,0.15);
    glVertex3f(0.3,0.13,0.15);

    glColor3f(0.5,0.3,0.2);
    glVertex3f(0.3,0.1,0.15);
    glVertex3f(0.3,0.1,-0.15);
    glVertex3f(0.3,0.13,-0.15);
    glVertex3f(0.3,0.13,0.15);

    glColor3f(0.4,0.3,0.2);
    glVertex3f(0.3,0.1,-0.15);
    glVertex3f(0.28,0.1,-0.15);
    glVertex3f(0.28,0.13,-0.15);
    glVertex3f(0.3,0.13,-0.15);

    glColor3f(0.5,0.3,0.2);
    glVertex3f(0.28,0.1,0.15);
    glVertex3f(0.28,0.1,-0.15);
    glVertex3f(0.28,0.13,-0.15);
    glVertex3f(0.28,0.13,0.15);
    glEnd();
    //sides front
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.5);
    glVertex3f(-0.28,-0.15,0.15);
    glVertex3f(0.28,-0.15,0.15);
    glVertex3f(0.28,-0.12,0.15);
    glVertex3f(-0.28,-0.12,0.15);

    glVertex3f(-0.28,-0.15,0.12);
    glVertex3f(0.28,-0.15,0.12);
    glVertex3f(0.28,-0.12,0.12);
    glVertex3f(-0.28,-0.12,0.12);
    //back
    glVertex3f(-0.28,-0.15,-0.15);
    glVertex3f(0.28,-0.15,-0.15);
    glVertex3f(0.28,-0.12,-0.15);
    glVertex3f(-0.28,-0.12,-0.15);

    glVertex3f(-0.28,-0.15,-0.12);
    glVertex3f(0.28,-0.15,-0.12);
    glVertex3f(0.28,-0.12,-0.12);
    glVertex3f(-0.28,-0.12,-0.12);
    glEnd();
    //top
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.5);
    glVertex3f(-0.28,0.1,0.15);
    glVertex3f(0.28,0.1,0.15);
    glVertex3f(0.28,0.13,0.15);
    glVertex3f(-0.28,0.13,0.15);

    glVertex3f(-0.28,0.1,0.12);
    glVertex3f(0.28,0.1,0.12);
    glVertex3f(0.28,0.13,0.12);
    glVertex3f(-0.28,0.13,0.12);
    //back
    glVertex3f(-0.28,0.1,-0.15);
    glVertex3f(0.28,0.1,-0.15);
    glVertex3f(0.28,0.13,-0.15);
    glVertex3f(-0.28,0.13,-0.15);

    glVertex3f(-0.28,0.1,-0.12);
    glVertex3f(0.28,0.1,-0.12);
    glVertex3f(0.28,0.13,-0.12);
    glVertex3f(-0.28,0.13,-0.12);
    glEnd();
    //house
    glColor3f(0.8,0.1,0.1);
    glPushMatrix();
    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(0.25);
    glPopMatrix();
    glBegin(GL_QUADS); //WINDOW
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.05,0.18,0.16);
    glVertex3f(0.05,0.18,0.16);
    glVertex3f(0.05,0.25,0.16);
    glVertex3f(-0.05,0.25,0.16);
    glEnd();

    glBegin(GL_TRIANGLES);  //ROOF
    glColor3f(1.0,0.8,0.0);
    glVertex3f(-0.16,0.35,0.16);
    glVertex3f(0.16,0.35,0.16);
    glVertex3f(0.0,0.5,0.0);

    glVertex3f(-0.16,0.35,0.16);
    glVertex3f(-0.16,0.35,-0.16);
    glVertex3f(0.0,0.5,0.0);

    glVertex3f(-0.16,0.35,-0.16);
    glVertex3f(0.16,0.35,-0.16);
    glVertex3f(0.0,0.5,0.0);

    glVertex3f(0.16,0.35,0.16);
    glVertex3f(0.16,0.35,-0.16);
    glVertex3f(0.0,0.5,0.0);
    glEnd();
}

void track()
{
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    //left
    glVertex3f(-3.0,-0.23,0.12);
    glVertex3f(-0.3,-0.23,0.12);

    glVertex3f(-3.0,-0.23,0.1);
    glVertex3f(-0.3,-0.23,0.1);

    glVertex3f(-3.0,-0.23,-0.12);
    glVertex3f(-0.3,-0.23,-0.12);

    glVertex3f(-3.0,-0.23,-0.1);
    glVertex3f(-0.3,-0.23,-0.1);
    //right
    glVertex3f(3.0,-0.23,0.12);
    glVertex3f(0.3,-0.23,0.12);

    glVertex3f(3.0,-0.23,0.1);
    glVertex3f(0.3,-0.23,0.1);

    glVertex3f(3.0,-0.23,-0.12);
    glVertex3f(0.3,-0.23,-0.12);

    glVertex3f(3.0,-0.23,-0.1);
    glVertex3f(0.3,-0.23,-0.1);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    for(j=0.0;j<=2.6;j+=0.1)
    {
        glVertex3f(-3.0+j,-0.23,0.1);
        glVertex3f(-3.0+j,-0.23,-0.1);
    }
    for(j=0.0;j<=3;j+=0.1)
    {
        glVertex3f(0.3+j,-0.23,0.1);
        glVertex3f(0.3+j,-0.23,-0.1);
    }
    glEnd();
}

void ship()
{
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);   //base
    glVertex3f(-0.2,-0.4,-3.5);
    glVertex3f(0.2,-0.4,-3.5);
    glVertex3f(0.2,-0.3,-3.5);
    glVertex3f(-0.2,-0.3,-3.5);

    glColor3f(0.8,0.8,1.0);
    glVertex3f(-0.2,-0.4,-3.5);
    glVertex3f(-0.2,-0.4,-4.8);
    glVertex3f(-0.2,-0.3,-5.0);
    glVertex3f(-0.2,-0.3,-3.5);

    glColor3f(0.8,0.8,0.8);
    glVertex3f(-0.2,-0.4,-4.8);
    glVertex3f(0.2,-0.4,-4.8);
    glVertex3f(0.2,-0.3,-5.0);
    glVertex3f(-0.2,-0.3,-5.0);

    glColor3f(0.8,0.8,1.0);
    glVertex3f(0.2,-0.4,-3.5);
    glVertex3f(0.2,-0.4,-4.8);
    glVertex3f(0.2,-0.3,-5.0);
    glVertex3f(0.2,-0.3,-3.5);

    glColor3f(1.0,0.8,1.0);
    glVertex3f(-0.2,-0.3,-3.5);
    glVertex3f(0.2,-0.3,-3.5);
    glVertex3f(0.2,-0.3,-5.0);
    glVertex3f(-0.2,-0.3,-5.0);
    //top
    glColor3f(1.0,0.0,0.7);
    glVertex3f(-0.18,-0.3,-3.7);
    glVertex3f(0.18,-0.3,-3.7);
    glVertex3f(0.18,-0.2,-3.7);
    glVertex3f(-0.18,-0.2,-3.7);

    glColor3f(1.0,0.0,0.5);
    glVertex3f(-0.18,-0.3,-3.7);
    glVertex3f(-0.18,-0.3,-4.8);
    glVertex3f(-0.18,-0.2,-4.8);
    glVertex3f(-0.18,-0.2,-3.7);

    glColor3f(1.0,0.0,0.7);
    glVertex3f(-0.18,-0.3,-3.7);
    glVertex3f(0.18,-0.3,-4.8);
    glVertex3f(0.18,-0.2,-4.8);
    glVertex3f(-0.18,-0.2,-3.7);

    glColor3f(1.0,0.0,0.5);
    glVertex3f(0.18,-0.3,-3.7);
    glVertex3f(0.18,-0.3,-4.8);
    glVertex3f(0.18,-0.2,-4.8);
    glVertex3f(0.18,-0.2,-3.7);

    glColor3f(1.0,0.1,0.8);
    glVertex3f(-0.18,-0.2,-3.7);
    glVertex3f(0.18,-0.2,-3.7);
    glVertex3f(0.18,-0.2,-4.8);
    glVertex3f(-0.18,-0.2,-4.8);
    glEnd();
    //front
    glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.5,0.7);
    glVertex3f(-0.2,-0.4,-3.5);
    glVertex3f(-0.2,-0.3,-3.5);
    glVertex3f(0.0,-0.15,-2.2);

    glColor3f(0.5,0.8,0.7);
    glVertex3f(-0.2,-0.4,-3.5);
    glVertex3f(0.2,-0.4,-3.5);
    glVertex3f(0.0,-0.15,-2.2);

    glColor3f(0.5,0.5,0.7);
    glVertex3f(0.2,-0.4,-3.5);
    glVertex3f(0.2,-0.3,-3.5);
    glVertex3f(0.0,-0.15,-2.2);
    glEnd();
    //TOP PILLARS
    glBegin(GL_QUADS);
    glColor3f(1.0,0.8,0.1);
    glVertex3f(-0.05,-0.2,-3.8);
    glVertex3f(0.05,-0.2,-3.8);
    glVertex3f(0.05,0.1,-3.8);
    glVertex3f(-0.05,0.1,-3.8);

    glColor3f(1.0,0.8,0.2);
    glVertex3f(-0.05,-0.2,-3.8);
    glVertex3f(-0.05,-0.2,-4.0);
    glVertex3f(-0.05,0.1,-4.0);
    glVertex3f(-0.05,0.1,-3.8);

    glColor3f(1.0,0.8,0.1);
    glVertex3f(-0.05,-0.2,-4.0);
    glVertex3f(0.05,-0.2,-4.0);
    glVertex3f(0.05,0.1,-4.0);
    glVertex3f(-0.05,0.1,-4.0);

    glColor3f(1.0,0.8,0.2);
    glVertex3f(0.05,-0.2,-3.8);
    glVertex3f(0.05,-0.2,-4.0);
    glVertex3f(0.05,0.1,-4.0);
    glVertex3f(0.05,0.1,-3.8);
    //back
    glColor3f(1.0,0.5,0.1);
    glVertex3f(-0.05,-0.2,-4.2);
    glVertex3f(0.05,-0.2,-4.2);
    glVertex3f(0.05,0.2,-4.2);
    glVertex3f(-0.05,0.2,-4.2);

    glColor3f(1.0,0.6,0.2);
    glVertex3f(-0.05,-0.2,-4.2);
    glVertex3f(-0.05,-0.2,-4.5);
    glVertex3f(-0.05,0.2,-4.5);
    glVertex3f(-0.05,0.2,-4.2);

    glColor3f(1.0,0.5,0.1);
    glVertex3f(-0.05,-0.2,-4.5);
    glVertex3f(0.05,-0.2,-4.5);
    glVertex3f(0.05,0.2,-4.5);
    glVertex3f(-0.05,0.2,-4.5);

    glColor3f(1.0,0.6,0.2);
    glVertex3f(0.05,-0.2,-4.2);
    glVertex3f(0.05,-0.2,-4.5);
    glVertex3f(0.05,0.2,-4.5);
    glVertex3f(0.05,0.2,-4.2);
    glEnd();
}

void train()
{
    glBegin(GL_QUADS);   //engine
    glColor3f(0.8,0.6,0.4);
    glVertex3f(1.0,-0.23,0.1);
    glVertex3f(1.15,-0.23,0.1);
    glVertex3f(1.15,-0.14,0.1);
    glVertex3f(1.0,-0.14,0.1);

    glColor3f(0.5,0.5,0.8);
    glVertex3f(1.0,-0.23,0.1);
    glVertex3f(1.0,-0.23,-0.1);
    glVertex3f(1.0,-0.14,-0.1);
    glVertex3f(1.0,-0.14,0.1);

    glColor3f(0.8,0.6,0.4);
    glVertex3f(1.0,-0.23,-0.1);
    glVertex3f(1.15,-0.23,-0.1);
    glVertex3f(1.15,-0.14,-0.1);
    glVertex3f(1.0,-0.14,-0.1);

    //FRONT
    glColor3f(0.0,0.1,0.9);
    glVertex3f(1.0,-0.14,0.1);
    glVertex3f(1.15,-0.05,0.1);
    glVertex3f(1.15,-0.05,-0.1);
    glVertex3f(1.0,-0.14,-0.1);

    glColor3f(0.8,0.6,0.2);
    glVertex3f(1.02,-0.12,0.1);
    glVertex3f(1.13,-0.05,0.1);
    glVertex3f(1.13,-0.05,-0.06);
    glVertex3f(1.02,-0.12,-0.06);
    glEnd();
    //side
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(1.0,-0.14,0.1);
    glVertex3f(1.15,-0.14,0.1);
    glVertex3f(1.15,-0.05,0.1);

    glVertex3f(1.0,-0.14,-0.1);
    glVertex3f(1.15,-0.14,-0.1);
    glVertex3f(1.15,-0.05,-0.1);
    glEnd();
    //bogies
    glBegin(GL_QUADS);
    for(j=0.0;j<2;j+=0.27)
    {
    glColor3f(0.5,0.0,0.1);
    glVertex3f(1.15+j,-0.23,0.1);
    glVertex3f(1.4+j,-0.23,0.1);
    glVertex3f(1.4+j,-0.05,0.1);
    glVertex3f(1.15+j,-0.05,0.1);

    glColor3f(0.5,0.0,0.5);
    glVertex3f(1.15+j,-0.23,0.1);
    glVertex3f(1.15+j,-0.23,-0.1);
    glVertex3f(1.15+j,-0.05,-0.1);
    glVertex3f(1.15+j,-0.05,0.1);

    glColor3f(0.5,0.0,0.1);
    glVertex3f(1.15+j,-0.23,-0.1);
    glVertex3f(1.4+j,-0.23,-0.1);
    glVertex3f(1.4+j,-0.05,-0.1);
    glVertex3f(1.15+j,-0.05,-0.1);

    glColor3f(0.5,0.0,0.5);
    glVertex3f(1.4+j,-0.23,0.1);
    glVertex3f(1.4+j,-0.23,-0.1);
    glVertex3f(1.4+j,-0.05,-0.1);
    glVertex3f(1.4+j,-0.05,0.1);

    glColor3f(0.8,0.3,0.5);
    glVertex3f(1.15+j,-0.05,0.1);
    glVertex3f(1.4+j,-0.05,0.1);
    glVertex3f(1.4+j,-0.05,-0.1);
    glVertex3f(1.15+j,-0.05,-0.1);
    }
    glEnd();
}

void signal()
{
    glBegin(GL_QUADS);
    glColor3f(0.1,0.2,0.1);
    glVertex3f(0.7,-0.25,-0.17);
    glVertex3f(0.73,-0.25,-0.17);
    glVertex3f(0.73,0.15,-0.17);
    glVertex3f(0.7,0.15,-0.17);

    glColor3f(0.1,0.1,0.2);
    glVertex3f(0.67,0.15,-0.17);
    glVertex3f(0.76,0.15,-0.17);
    glVertex3f(0.76,0.3,-0.17);
    glVertex3f(0.67,0.3,-0.17);
    glEnd();
}
void light1()
{
    if(b>0.0)
        glColor3f(1.0,0.0,0.0);
    else
            glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(0.715,0.25,-0.17);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();

}

void light2()
{
    if(p<-0)
          glColor3f(0.0,1.0,0.0);
    else
          glColor3f(0.0,0.0,0.0);

    if(p<-3.5)
          glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(0.715,0.19,-0.17);
    glutSolidSphere(0.03,10,10);
    glPopMatrix();

}


void boat(){

 glColor3f (.29, 0.19, .19);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.4, 1.6);
    glVertex3f (0.3, 0.3, 1.6);
    glVertex3f (0.8, 0.3, 1.6);
    glVertex3f (1.0, 0.4, 1.6);
    glVertex3f (0.8, 0.0, 1.2);
    glVertex3f (0.3, 0.0, 1.2);
    glVertex3f (0.1, 0.4, 1.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.4, 0.8);
    glVertex3f (0.3, 0.3, 0.8);
    glVertex3f (0.8, 0.3, 0.8);
    glVertex3f (1.0, 0.4, 0.8);
    glVertex3f (0.8, 0.0, 1.2);
    glVertex3f (0.3, 0.0, 1.2);
    glVertex3f (0.1, 0.4, 0.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.4, 1.6);
    glVertex3f (0.1, 0.4, 0.8);
    glVertex3f (0.3, 0.0, 1.2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.4, 1.6);
    glVertex3f (0.1, 0.4, 0.8);
    glVertex3f (-0.3, 0.6, 1.2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f (1.0, 0.4, 1.6);
    glVertex3f (1.0, 0.4, 0.8);
    glVertex3f (1.4, 0.6, 1.2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f (1.0, 0.4, 1.6);
    glVertex3f (1.0, 0.4, 0.8);
    glVertex3f (0.8, 0.0, 1.2);
    glEnd();
    glColor3f (.75, .55, .35);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.3, 1.5);
    glVertex3f (0.9, 0.3, 1.5);
    glVertex3f (0.8, 0.6, 1.3);
    glVertex3f (0.3, 0.6, 1.3);
    glEnd();
    glBegin(GL_POLYGON);
   glVertex3f (0.2, 0.3, 1.1);
    glVertex3f (0.9, 0.3, 1.1);
    glVertex3f (0.8, 0.6, 1.3);
    glVertex3f (0.3, 0.6, 1.3);
    glEnd();


}


void new1()
{
    glTranslatef(a,b,c);
    bridge();
}
void new2()
{
    glTranslatef(m,n,o);
    ship();
}
void new3()
{
    glTranslatef(p,q,r);
    train();
}

void new5()
{
    glTranslatef(a1,a2,a3);
    lines();
}

void update(int value)
{
    if(flagx==1)
    {
     if(flagb==1)
     {
        b+=0.02f;
        if(b>0.5)
        {
            flagb=2;
            flags=1;
        }

     }
     if(flags==1)
     {
        o+=0.07f;
        if(o>2.0)
            flagp=1;
        if(o>6.0)
        {
            flagb=0;
        }
     }
     if(flagb==0)
     {
        b-=0.02f;
        if(b<0.01)
        {
            flagb=1;
            flagt=1;
        }
     }
     if(flagt==1)
     {
           p-=0.05f;
     }
     if(flagp==1)
     {
        x+=0.03;
     }
      if(flagw==1)
      {
        a1+=0.006;
      }
    }
    glutPostRedisplay();
    glutTimerFunc(100,update,0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0,0.5,1.0,0.0);
    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    base();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    pillars();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    earth();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    track();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    new1();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    new2();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    new3();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    water();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    new5();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(1.2,0.9,-5.1);
    glutSolidSphere(0.08,20,20);
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    signal();
    glPopMatrix();

    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    light1();
    glPopMatrix();


    glPushMatrix();
    glRotatef(20.0,0.25,0.5,0.0);
    light2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(translatex, translatey, translatez);
    glScalef(boatscalex,boatscaley,boatscalez);
    glRotatef(boatangley,0,1,0);
    glRotatef(boatanglex,1,0,0);
    glRotatef(boatanglez,0,0,1);


    boat();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //drawBoat();
    gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);
    glFlush();
}


void mykeyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 13 :flag=1;
                break;
        case 83 :if(flag==1)
                   flagx=1;
                break;
        case 115:if(flag==1)
                    flagx=1;
                break;
        case 84 :flagx=0;
                break;
        case 116 :flagx=0;
                break;
        case 27:exit(0);
        case 'w': (boatangley -=5) %= 360; break;
        case 'x': (boatangley +=5) %= 360;break;
        case 'a': (boatanglez -=5) %= 360; break;
        case 'd': (boatanglez +=5) %= 360; break;
    }
     glutPostRedisplay();
}

void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: translatex = (translatex - 0.1);
                        break;
    case GLUT_KEY_RIGHT: translatex = (translatex + 0.1);
                        break;
    case GLUT_KEY_UP: translatez = (translatez - 0.1);
                        break;
    case GLUT_KEY_DOWN: translatez = (translatez + 0.1);
                        break;
    case GLUT_KEY_HOME: translatey = (translatey - 0.1);
                        break;
    case GLUT_KEY_END: translatey = (translatey + 0.1);
                        break;
    case GLUT_KEY_F1: boatscalex = (boatscalex + 0.01);
                        break;
    case GLUT_KEY_F2: boatscalex = (boatscalex - 0.01);
                        break;
    case GLUT_KEY_F3: boatscaley = (boatscaley + 0.01);
                        break;
    case GLUT_KEY_F4: boatscaley = (boatscaley - 0.01);
                        break;
    case GLUT_KEY_F5: boatscalez = (boatscalez + 0.01);
                        break;
    case GLUT_KEY_F6: boatscalez = (boatscalez - 0.01);
                        break;

	case GLUT_KEY_PAGE_UP: (boatanglex -=5) %= 360; break;
    case GLUT_KEY_PAGE_DOWN: (boatanglex +=5) %= 360; break;

    case GLUT_KEY_F7: posx += 0.5; break;
    case GLUT_KEY_F8: posx -= 0.5; break;
    case GLUT_KEY_F9: posy += 0.5; break;
    case GLUT_KEY_F10: posy -= 0.5; break;
    case GLUT_KEY_F11: posz += 0.5; break;
    case GLUT_KEY_F12: posz -= 0.5; break;
    default: return;
  }
  glutPostRedisplay();
}


void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-1.1,1.1,1.1*(GLfloat)h/(GLfloat)w,1.1*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-1.1*(GLfloat)w/(GLfloat)h,1.1*(GLfloat)w/(GLfloat)h,-1.1,1.1,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init() {

    // Set the current clear color to black and the current drawing color to
  // white.
  glClearColor (0.4, 0.85, 1.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);

  // Set the camera lens to have a 60 degree (vertical) field of view, an
  // aspect ratio of 4/3, and have everything closer than 1 unit to the
  // camera and greater than 40 units distant clipped away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 4.0/3.0, 1, 20);

  // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  // <0, 1, 0> pointing upward.


}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1500,1000);
    glutCreateWindow("VLBS");
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(mykeyboard);
    glutSpecialFunc(special);
    glutTimerFunc(200,update,0);
    init();
    glutMainLoop();
    return 0;
}
