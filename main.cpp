#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<utility>

using namespace std;

void myinit()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,100.0,0.0,100.0);
    glFlush();
}

pair<float,float> bezier(float t,float a[],float b[])
{
    float j30=pow((1-t),3);
    float j31=3*t*pow(1-t,2);
    float j32=3*t*t*(1-t);
    float j33=pow(t,3);
    float x=a[0]*j30+a[1]*j31+a[2]*j32+a[3]*j33;
    float y=b[0]*j30+b[1]*j31+b[2]*j32+b[3]*j33;
    return make_pair(x,y);

}

 
void print(float x[],float y[])
{
    for(float t=0.0;t<1;t+=.001)
    {
        pair<float,float> p=bezier(t,x,y);
        glVertex2f(p.first,p.second);
    }
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,.08,1);
    glPointSize(3);
    glBegin(GL_POINTS);

    //Shivam

    //Roof line
    {
        float x[]={10,18,27,33};
        float y[]={64,64,64,64};
        print(x,y);
    }

  
    // sha ka dusra curve bich wala
    {
        float x[]={12.5,14.5,13,11.2};
        float y[]={64,63.5,51,56};
        print(x,y);
    }
    // sha ka dusra curve niche wala
    {
        float x[]={11.2,13.5,11.5,13.8};
        float y[]={56,59,48,47};
        print(x,y);
    }
    // sha ka pichee wala danda
    {
        float x[]={16.5,16.5,16.5,16.5};
        float y[]={64,62.5,48,47};
        print(x,y);
    }
    
     {
        float x[]={11.2,11.2,16.5,16.5};
        float y[]={56,56,56,56};
        print(x,y);
    }

    // wa ka semicircle
    glBegin(GL_POINTS);
    {
        float x[]={19,19,21,21};
        float y[]={54,49,49,54};
        print(x,y);
    }
	// wa ka pichee wala danda
    {
        float x[]={19,19,24.5,24.5};
        float y[]={54,54,54,54};
        print(x,y);
    }
    
   
  // ma ka leftmost wala danda
    {
        float x[]={25,25,25,25};
        float y[]={54,54,50,50};
        print(x,y);
    }
    // ma ka curve
    {
        float x[]={25,22.5,22.5,25};
        float y[]={54,54,47,50};
        print(x,y);
    }

    // ma ka right wala danda
    {
        float x[]={28.5,28.5,28.5,28.5};
        float y[]={64,62.5,55,47};
        print(x,y);
    }

    // ma ka horizontal wala danda
    {
        float x[]={25,25.5,26.5,28.5};
        float y[]={54,54,54,54};
        print(x,y);
    }
    
    // ni ka right wala danda
    {
        float x[]={32,32,32,32};
        float y[]={64,62.5,55,47};
        print(x,y);
    }
    
    // ni ka right wala danda
    {
        float x[]={28.5,28.5,32,32};
        float y[]={64,70,70,64};
        print(x,y);
    }


    //Kumar

     //Roof line
    {
        float x[]={36,35,53,61};
        float y[]={64,64,64,64};
        print(x,y);
    }
    // ku ka agge wala danda
    {
        float x[]={41.5,41.5,41.5,41.5};
        float y[]={64,62.5,48,47};
        print(x,y);
    }
    // ku ka left curve
    glBegin(GL_POINTS);
    {
        float x[]={41.5,34.5,37.5,41.5};
        float y[]={55,65.5,43,55};
        print(x,y);
    }

     // ku ka right curve
    glBegin(GL_POINTS);
    {
        float x[]={41.5,44.5,47.5,43};
        float y[]={55,62,56,51};
        print(x,y);
    }
    //uu ki matra
    glBegin(GL_POINTS);
    {
        float x[]={40,42.5,45.5,38};
        float y[]={46,50,40,45};
        print(x,y);
    }
// ma ka leftmost wala danda
    {
        float x[]={48.5,48.5,48.5,48.5};
        float y[]={64,62.5,55,50};
        print(x,y);
    }
    // ma ka curve
    {
        float x[]={48.5,46,46,48.5};
        float y[]={54,54,47,50};
        print(x,y);
    }

    // ma ka right wala danda
    {
        float x[]={52,52,52,52};
        float y[]={64,62.5,55,47};
        print(x,y);
    }

    // ma ka horizontal wala danda
    {
        float x[]={48.5,49,50,52};
        float y[]={54,54,54,54};
        print(x,y);
    }

    // ma ka rightmost wala danda
    {
        float x[]={53.5,53.5,53.5,53.5};
        float y[]={64,62.5,55,47};
        print(x,y);
    }

     // ra ka dusra curve bich wala
    {
        float x[]={56.5,59.5,58,56.2};
        float y[]={62.5,69,51,56};
        print(x,y);
    }
    // ra ka dusra curve niche wala
    {
        float x[]={56.2,58.6,57.5,59.1};
        float y[]={56,59,48,47};
        print(x,y);
    }


    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(850,500);
    glutCreateWindow("Full name in Devnagri li; using Bezier curve");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
