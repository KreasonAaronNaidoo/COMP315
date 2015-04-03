//COMP 315 : Advanced Programming 2015


//This project and all assosciated files are the property of the creators:
//Kreason Aaron Naidoo
//Liam Bernard
//Shaherin Dehaloo
//Muhammad Bassa
//and of The University of Kwa-Zulu Natal

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "planet.h"
#include "npc.h"
#include<vector>

using namespace std;

int time=0;
vector<planet> v_planet;
vector<npc> v_asteroid;
//vector< vector<float> > v_distance;
double dist;
//float point[3];
//float *ast1Loc;
//float *ast2Loc;

//float ast1Loca[3];
//float ast2Loca[3];

void split(npc ast1,npc ast2,int i,int j);
/*float z_dist_at;
float camera[3][3] = {
            {0, 0, -z_dist_at},
            {0, 0, 0},
            {0, 1.0f, 0}
    };
float lx, ly, lz;
float angle;
*/
void initGL(){
   glClearColor(0, 0, 0, 1);
   //lighting
     glShadeModel (GL_SMOOTH);

     glEnable(GL_LIGHTING); // turns on the lighting model in OpenGL

     glEnable(GL_LIGHT0);  // enables light 0

     // set the position and type of light 0 (x,y,z,w) w=1 for a point source and 0 for a directional source
     GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
     glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_DEPTH_TEST);

   planet *p=new planet(0,0,0);
   v_planet.push_back(*p);

       npc *v1=new npc(0,2,-8,1,0.1);
       v_asteroid.push_back(*v1);
       npc *v2=new npc(1,2,8,2,0.1);
       v_asteroid.push_back(*v2);
       npc *v3= new npc(4,4,6,2,0.1);
       v_asteroid.push_back(*v3);

        //cout<<*v_asteroid[0].getLocation()<<endl;
}

/*void setCamera(){

		cout << angle << " lx: " << lx << " lz:" << lz << "\n";
    	// Set the camera

		gluLookAt(	camera[0][0], camera[0][1], camera[0][2],
    				camera[1][0], camera[1][1], camera[1][2],
    				camera[2][0], camera[2][1], camera[2][2]  );

}*/

void render(){
   // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Reset transformations
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

  // setCamera();
   gluLookAt(30,30,20,
             0,0,0,
             0,1,0
             );

   //glColor3f(0,1,0);
   //glLineStipple(1,0xAAAA);
   glBegin(GL_LINES);
   glVertex3f(0,0,0);
   glVertex3f(10,0,0);
   glVertex3f(0,0,0);
   glVertex3f(0,10,0);
   glVertex3f(0,0,0);
   glVertex3f(0,0,10);
   glEnd();

   v_planet[0].update();

   //render each asteroid int the vector
   for(int i=0; i<v_asteroid.size(); i++){
       v_asteroid[i].update();
   }
   //getDistance(v_asteroid[0],v_asteroid[1]);
    //point[3]=v_asteroid[0].getLocation();//test: this works
   glutSwapBuffers();
   //glFlush();
}

/*double getDistance(npc ast1, npc ast2){
    double *ast1Loc =ast1.getLocation();
    double *ast2Loc =ast2.getLocation();

    /*for(int i=0;i<3;i++){
        cout<<"point "<<i<<": "<<*(ast1Loc+i)<<" ";
    }
    //cout<<"ast1Loc: "<<*(ast1Loc)<<endl;
    //cout<<"ast2Loc: "<<*ast2Loc<<endl;
    //cout<<"Dist: "<<*ast1Loc**ast2Loc<<endl;

   //cout<<"dist: "<<sqrt(pow(ast1Loc[0]-ast2Loc[0],2)+pow(ast1Loc[1]-ast2Loc[1],2)+pow(ast1Loc[2]-ast2Loc[2],2));
   return sqrt(pow(*ast1Loc-*ast2Loc,2)+pow(*(ast1Loc+1)-*(ast2Loc+1),2)+pow(*(ast1Loc+2)-*(ast2Loc+2),2));
}*/

void distArray(){

    for(int i=0; i<v_asteroid.size() ;i++){
        //vector<float> fVec;
       for(int j=i; j<v_asteroid.size() ;j++){
          //fVec.push_back(getDistance(v_asteroid[i],v_asteroid[j]));
          if(i!=j){
                //cout<<"i: "<<i<<" j: "<<j<<endl;//i=0,j=1
                //cout<<*v_asteroid[i].getLocation()<<endl;
            //if( getDistance(v_asteroid[i],v_asteroid[j]) < v_asteroid[i].getRadius()+v_asteroid[j].getRadius() ){
            /*dist=sqrt(pow(*v_asteroid[i].getLocation()-*v_asteroid[j].getLocation(),2)
                     +pow(*(v_asteroid[i].getLocation()+1)-*(v_asteroid[j].getLocation()+1),2)
                     +pow(*(v_asteroid[i].getLocation()+2)-*(v_asteroid[j].getLocation()+2),2));*/
              double x_loc_i=*(v_asteroid[i].getLocation());
              double y_loc_i=*(v_asteroid[i].getLocation()+1);
              double z_loc_i=*(v_asteroid[i].getLocation()+2);

              double x_loc_j=*(v_asteroid[j].getLocation());
              double y_loc_j=*(v_asteroid[j].getLocation()+1);
              double z_loc_j=*(v_asteroid[j].getLocation()+2);

              dist=sqrt(pow(x_loc_i-x_loc_j,2)
                       +pow(y_loc_i-y_loc_j,2)
                       +pow(z_loc_i-z_loc_j,2));
              //cout<<"dist: "<<dist<<endl;
              //cout<<"x_loc: "<<x_loc<<endl;

            if( dist< (v_asteroid[i].getRadius()+v_asteroid[j].getRadius()) ){
                //cout<<"i: "<<v_asteroid[i].getRadius()<<endl;
                //cout<<"j: "<<v_asteroid[j].getRadius()<<endl;
                //cout<<"Dist: "<<getDistance(v_asteroid[i],v_asteroid[j])<<endl;
                v_asteroid[i].regCollision();
                v_asteroid[j].regCollision();

                //cout<<"true.";

                split(v_asteroid[i],v_asteroid[j],i,j);
//ERASING IS A PROBLEM
                //v_asteroid.erase(v_asteroid.begin()+i-1,v_asteroid.begin()+i);
                //v_asteroid.erase(v_asteroid.begin()+j-1,v_asteroid.begin()+j-1);
            }
          }
       }
       //v_distance.push_back(fVec);
    }

    /*for(int i=0;i<v_asteroid.size();i++){
        if(v_asteroid[i].collisionState())
            cout<<" "<<i<<": "<<v_asteroid[i].collisionState();
    }*/

}

void hitDetection(){
    distArray();
    //float distance=getDistance(v_asteroid[0],v_asteroid[1]);  //test
}

/*void addAsteroids(int ast1Size,int ast2Size,double*ast1Loc,double*ast2Loc,double ast1Velocity,double ast2Velocity){
    npc *n= new npc(*(ast1Loc)+0.1,*(ast1Loc+1)+0.1,*(ast1Loc+2)+0.1,ast1Size,ast1Velocity);
    //v_asteroid.push_back(*n);
}*/

void split(npc ast1, npc ast2, int i, int j){
    //get sizes
    int ast1Size=ast1.getSize();
    int ast2Size=ast2.getSize();

    //get locations
    double *ast1Loc=ast1.getLocation();
    double *ast2Loc=ast2.getLocation();

    //cout<<"ast1Loc 1: "<<*(ast1Loc)+0.1;
    //get velocities
    double ast1Velocity=ast1.getVelocity();
    double ast2Velocity=ast2.getVelocity();


    //addAsteroids(ast1Size,ast2Size,ast1Loc,ast2Loc,ast1Velocity,ast2Velocity);

    //npc *n= new npc(*(ast1Loc)+0.1,*(ast1Loc+1)+0.1,*(ast1Loc+2)+0.1,ast1Size,ast1Velocity);

    ////npc *n= new npc(10,10,10,2,0.1);
    ////v_asteroid.push_back(*n);

    //cout<<"pushed. ";
    //delete(n);

     //v_asteroid.push_back( *new npc(*ast1Loc+.1,*(ast1Loc+1)+.1,*(ast1Loc+2)+.1,ast1Size,ast1Velocity) );
     //v_asteroid.push_back( *new npc(*ast2Loc-.1,*(ast2Loc+1)-.1,*(ast2Loc+2)-.1,ast2Size,ast2Velocity) );

    //remove asteroids from vector
     //v_asteroid.erase(v_asteroid.begin()+i-1,v_asteroid.begin()+i);
     //v_asteroid.erase(v_asteroid.begin()+j-1,v_asteroid.begin()+j);
    //remove(v_asteroid.begin(),v_asteroid.end(),ast1);
    //remove(v_asteroid.begin(),v_asteroid.end(),ast2);

    //ast1.die();
    //ast2.die();

    /*int newX1,newY1,newZ1;
         if(ast1Loc[0]>0)
             newX1=ast1Loc[0]-0.2;
         else if(ast1Loc[0]<0)
             newX1=ast1Loc[0]+0.2;
         else
             newX1=0;

         if(ast1Loc[1]>0)
             newY1=ast1Loc[1]-0.2;
         else if(ast1Loc[1]<0)
             newY1=ast1Loc[1]+0.2;
         else
             newY1=0;

         if(ast1Loc[2]>0)
             newZ1=ast1Loc[2]-0.2;
         else if(ast1Loc[2]<0)
             newZ1=ast1Loc[2]+0.2;
         else
             newZ1=0;

    /*int newX2,newY2,newZ2;
         if(ast2Loc[0]>0)
             newX2=ast2Loc[0]-0.2;
         else if(ast2Loc[0]<0)
             newX2=ast2Loc[0]+0.2;
         else
             newX2=0;

         if(ast2Loc[1]>0)
             newY2=ast2Loc[1]-0.2;
         else if(ast2Loc[1]<0)
             newY2=ast2Loc[1]+0.2;
         else
             newY2=0;

         if(ast2Loc[2]>0)
             newZ2=ast2Loc[2]-0.2;
         else if(ast2Loc[2]<0)
             newZ2=ast2Loc[2]+0.2;
         else
             newZ2=0;


//    v_asteroid.push_back( *new npc(newX1, newY1, newZ1, ast1Size-1, ast1Velocity) );

   // v_asteroid.push_back( *new npc(newX2, newY2, newZ2, ast1Size-1, ast2Velocity) );*/

}

void update(){

    time = glutGet(GLUT_ELAPSED_TIME); // get the elapsed time in milliseconds since glutInit() was executed
    // do nothing
}

void display(){

    update();
    hitDetection();
    render();

}

void reshape(int w, int h){
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)	h = 1;

    GLfloat ratio = 1.0f * (GLfloat)w / (GLfloat)h;

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the clipping volume
    gluPerspective(45, ratio, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void processNormalKeys(unsigned char key, int x, int y) {

	switch (key) {
		case 27 :  exit(0); break;
	}
    glutPostRedisplay();
}

void inputKey(int key, int ix, int iy) {

    glutPostRedisplay();
}

void idle(){
    glutPostRedisplay(); // called when there is now other event
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);

    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Astro Crisis");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(inputKey);
    glutIdleFunc(idle);
    //glutIdleFunc(spin);

    //glutTimerFunc(25,update,0);

    initGL();
    glutMainLoop();
    return 0;
}
