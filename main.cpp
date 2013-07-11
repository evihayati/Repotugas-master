#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <cstdlib>
#include <iostream>

GLuint   mega; 
float sumbux=0.0, sumbuy=0.0, sumbuz=0.0;
float sudut=0.0f;
float vektorx=0.0f, vektorz=-1.0f;
float x=0.0f, z=5.0f;
float pindahx =0.0, pindahy=0.0, pindahz=0.0;
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, putary=0, angle=0.0; //Rotasi Sudut
float inner, outer; int garisv,garish; //Variabel Torus
void   matahari(void);
void   elang(void);
void   awan(void);
 
void bangun (int w, int h)
{
     if (h == 0)
		h = 1;
	float rasio =  w * 1.0 / h;
     
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     glViewport (0,0, w, h);
     gluPerspective(70.0f, rasio, 0.3f, 100.0f);
     glMatrixMode(GL_MODELVIEW);
     glOrtho(0.0,2.0,0.0,2.0,-2.0,2.0);
}

void init (void)
{
     GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat mat_shininess[] = {50.0};
     GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
     GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.0}; 
     
     glClearColor (0.0, 0.0, 0.0, 0.0);
     glShadeModel (GL_SMOOTH);
     
     //SHADING
     glMaterialfv(GL_FRONT,GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT,GL_SHININESS, mat_shininess);
     glLightfv(GL_LIGHT0, GL_POSITION, light_position);
     glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
     
     glEnable(GL_DEPTH_TEST);
}
//Garis Koordinat
void koordinatx(void)
{
     glBegin(GL_LINE_STRIP);
     glVertex2f(-4,0);
     glVertex2f(-2.6,0);
     glEnd();
}

void koordinaty(void)
{
     glBegin(GL_LINE_STRIP);
     glVertex2f(0,3);
     glVertex2f(0,-3);
     glEnd();
}

void koordinatz(void)
{
     glBegin(GL_LINE_STRIP);
     glVertex2f(0,0);
     glVertex2f(5.4,3);
     glEnd();
}
// Akhir Garis Koordinat

//kerucut

void cone (float diameter, float tinggi, int garisv, int garish)
{
     glutSolidCone(diameter,tinggi,garisv,garish);
}

void wirecone (float diameter, float tinggi, int garisv, int garish)
{
     glutWireCone(diameter,tinggi,garisv,garish);
}

//BANGUN
void kubus (void)
{
     glutWireCube(0.5);
}
void kubussolid (void)
{
     glutSolidCube(0.5);
}

void bola ()
{
     glutWireSphere(0.5,10,10);
}
void bolasolid (float diameter, int garisv, int garish)
{
     glutSolidSphere(diameter,garisv,garish);
}

void torus(float inner, float outer, int garisv, int garish)
{
     glutWireTorus(inner,outer,garisv,garish);
}

void torussolid(float inner, float outer, int garisv, int garish)
{
     glutSolidTorus(inner,outer,garisv,garish);
}

void icosahedron()
{
     glutWireIcosahedron();
}

void dodecahedron()
{
     glutWireDodecahedron();
}

void dodecahedronsolid()
{
     glutSolidDodecahedron();
}

void kotak ()
{
     glBegin(GL_QUADS);
     glVertex2f(0.1,0.2);
     glVertex2f(0.2,0.2);
     glVertex2f(0.2,0.1);
     glVertex2f(0.1,0.1);
     glEnd();
}

void awan(void)
{
mega = glGenLists(1);  // untuk menginisialisasi mega yaitu bentuk awan
glNewList(mega, GL_COMPILE); //mengcompilenya dimasukan kedalam list
glPushMatrix();
glColor3ub(153, 223, 255);
glutSolidSphere(10, 50, 50);
glPopMatrix();
glPushMatrix();
glTranslatef(10,0,1);
glutSolidSphere(5, 20, 20);
glPopMatrix();
glPushMatrix();
glTranslatef(-2,6,-2);
glutSolidSphere(7, 50, 50);
glPopMatrix();
glPushMatrix();
glTranslatef(-10,-3,0);
glutSolidSphere(7, 50, 50);
glPopMatrix();
glPushMatrix();
glTranslatef(6,-2,2);
glutSolidSphere(7, 50, 50);
glPopMatrix();
glEndList(); //untuk menutup glnewlist
}


void dasar()
{
     glBegin(GL_QUADS); //Jalan atas kota
     glColor3f(0.25f, 0.25f, 0.25f); 
     glVertex3f(-0.3,3.5,0.01);
     glVertex3f(-3.1,3.5,0.01);
     glVertex3f(-3.1,3.1,0.01);
     glVertex3f(-0.3,3.1,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan kanan kota
     glColor3f(0.25f, 0.25f, 0.25f); 
     glVertex3f(-0.3,3.1,0.01);
     glVertex3f(-0.7,3.1,0.01);
     glVertex3f(-0.7,0.2,0.01);
     glVertex3f(-0.3,0.2,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan tengah
     glColor3f(0.25f, 0.25f, 0.25f);  
     glVertex3f(3.5,-0.2,0.01);
     glVertex3f(-3.1,-0.2,0.01);
     glVertex3f(-3.1,0.2,0.01);
     glVertex3f(3.5,0.2,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan kiri
     glColor3f(0.25f, 0.25f, 0.25f); 
     glVertex3f(-3.5,3.5,0.01);
     glVertex3f(-3.1,3.5,0.01);
     glVertex3f(-3.1,-3.1,0.01);
     glVertex3f(-3.5,-3.1,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan taman bawah
     glColor3f(0.25f, 0.25f, 0.25f); 
     glVertex3f(-3.5,-3.5,0.01);
     glVertex3f(3.5,-3.5,0.01);
     glVertex3f(3.5,-3.1,0.01);
     glVertex3f(-3.5,-3.1,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan taman kanan 
     glColor3f(0.25f, 0.25f, 0.25f); 
     glVertex3f(3.5,-0.2,0.01);
     glVertex3f(3.1,-0.2,0.01);
     glVertex3f(3.1,-3.1,0.01);
     glVertex3f(3.5,-3.1,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan di dalam taman kanan 
     glColor3f(0.6f, 0.6f, 0.6f); 
     glVertex3f(1.6,-0.2,0.01);
     glVertex3f(1.4,-0.2,0.01);
     glVertex3f(1.4,-3.1,0.01);
     glVertex3f(1.6,-3.1,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan di dalam taman bawah
     glColor3f(0.6f, 0.6f, 0.6f);  
     glVertex3f(1.4,-2.3,0.01);
     glVertex3f(-3.1,-2.3,0.01);
     glVertex3f(-3.1,-2.5,0.01);
     glVertex3f(1.4,-2.5,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Jalan di dalam taman kanan tengah
     glColor3f(0.6f, 0.6f, 0.6f); 
     glVertex3f(3.1,-1.3,0.01);
     glVertex3f(1.6,-1.3,0.01);
     glVertex3f(1.6,-1.5,0.01);
     glVertex3f(3.1,-1.5,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Kotak dasar
     glColor3f(0.0,0.2,0.0);
     glVertex2f(-4.0,-4.0);
     glVertex2f(4.0,-4.0);
     glVertex2f(4.0,4.0);
     glVertex2f(-4.0,4.0);
     glEnd();
// Lapangan bulutangkis
     glBegin(GL_QUADS); //Bulutangkis atas 1
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.68,-1.68,0.01);
     glVertex3f(1.9,-1.68,0.01);
     glVertex3f(1.9,-1.7,0.01);
     glVertex3f(2.68,-1.7,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis atas 2
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.68,-1.62,0.01);
     glVertex3f(1.9,-1.62,0.01);
     glVertex3f(1.9,-1.64,0.01);
     glVertex3f(2.68,-1.64,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis bawah 1
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.68,-2.80,0.01);
     glVertex3f(1.9,-2.80,0.01);
     glVertex3f(1.9,-2.78,0.01);
     glVertex3f(2.68,-2.78,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis bawah 2
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.68,-2.74,0.01);
     glVertex3f(1.9,-2.74,0.01);
     glVertex3f(1.9,-2.76,0.01);
     glVertex3f(2.68,-2.76,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis kanan 1
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.68,-2.80,0.01);
     glVertex3f(2.69,-2.80,0.01);
     glVertex3f(2.69,-1.62,0.01);
     glVertex3f(2.68,-1.62,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis kanan 2
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.625,-2.80,0.01);
     glVertex3f(2.635,-2.80,0.01);
     glVertex3f(2.635,-1.62,0.01);
     glVertex3f(2.625,-1.62,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis kiri 1
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(1.89,-2.80,0.01);
     glVertex3f(1.9,-2.80,0.01);
     glVertex3f(1.9,-1.62,0.01);
     glVertex3f(1.89,-1.62,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis kiri 2
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(1.945,-2.80,0.01);
     glVertex3f(1.955,-2.80,0.01);
     glVertex3f(1.955,-1.62,0.01);
     glVertex3f(1.945,-1.62,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis tengah atas
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.625,-2.0,0.01);
     glVertex3f(1.955,-2.00,0.01);
     glVertex3f(1.955,-1.98,0.01);
     glVertex3f(2.625,-1.98,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis tengah bawah
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.625,-2.48,0.01);
     glVertex3f(1.955,-2.48,0.01);
     glVertex3f(1.955,-2.46,0.01);
     glVertex3f(2.625,-2.46,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis tengah atas lurus
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.29,-2.80,0.01);
     glVertex3f(2.30,-2.80,0.01);
     glVertex3f(2.30,-2.48,0.01);
     glVertex3f(2.29,-2.48,0.01);
     glEnd();
     
     glBegin(GL_QUADS); //Bulutangkis tengah atas lurus
     glColor3f(1.0f, 1.0f, 1.0f); 
     glVertex3f(2.29,-1.62,0.01);
     glVertex3f(2.30,-1.62,0.01);
     glVertex3f(2.30,-1.98,0.01);
     glVertex3f(2.29,-1.98,0.01);
     glEnd();
}
     //Akhir lapang bulutangkis 
//CAMERA
void camera (void) {
    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glTranslated(-xpos,-ypos,-zpos);
}



void display (void)
{
     const double waktu = glutGet (GLUT_ELAPSED_TIME) / 1000.0;
     const double lama1 = 50*waktu, lama2 = 10*waktu, lama3 = waktu/10, lama4=10*waktu;
     GLdouble eqn[4] = {0.0, 0.0, 1.0, 0.0};
     GLdouble eqn2[4] = {1.0, 0.0, 0.0, 0.0};  
     GLdouble eqn3[4] = {0.0, 1.0, 0.0, 0.0};   
     GLfloat mat_transparent[] = { 0.1, 0.8, 0.8, 0.6 };
     GLfloat mat_emission[] = { 0.0, 0.3, 0.3, 0.6 };
     GLfloat mat_solid[] = { 0.75, 0.75, 0.0, 1.0 };
     GLfloat mat_zero[] = { 0.0, 0.0, 0.0, 1.0 };
     



     //GLfloat light_position[] = {0.0, 0.0, 1.0, 1.0};  
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glClearColor(0.7,0.7,1.0,0.5);
     
     glLoadIdentity();
     
     //Setting Kamera
     gluLookAt(x, 0.0, z, x+vektorx, 0.0, z+vektorz, 0.0, 1.0, 0.0);
     camera();
     glEnable(GL_TEXTURE_2D);
     glEnable(GL_COLOR_MATERIAL);
     //glColorMaterial(GL_FRONT,GL_SPECULAR);
     glPushMatrix();
      //CLIP untuk Y < 0
     glClipPlane(GL_CLIP_PLANE0,eqn);
     glEnable(GL_CLIP_PLANE0);
     
     //CLIP untuk X < 0
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glPopMatrix();
     glDisable(GL_CLIP_PLANE0);
     glDisable(GL_CLIP_PLANE1);
    
//------------------------------------ TANAH DASAR HIJAU------------------
     glPushMatrix();
     glTranslatef(0.0,-1.0,0.0);
     glRotatef(-90.0,1.0,0.0,0.0);
     dasar();
     glPopMatrix();
//-------------------------------------- AKHIR DASAR ------------------------
     
// -------------------------------------- GEDUNG KANAN -----------------------
// --------------------------------------- AKHIR GEDUNG KANAN -----------------
     
//Tangga ditengah taman
     glPushMatrix();
     glColor3f(.6,0.5,0.5);
     glTranslatef(-0.5,-0.935,1.3);
     glScalef(3.5,0.1,2.5);
     kubussolid();
     glPopMatrix();
//Tangga ditengah taman 1
     glPushMatrix();
     glColor3f(0.7,0.5,0.5);
     glTranslatef(-0.5,-0.885,1.3);
     glScalef(1.0,0.10,-0.50);
     kubussolid();
     glPopMatrix();
//Tangga ditengah taman 2
     glPushMatrix();
     glColor3f(0.7,0.5,0.5);
     glTranslatef(-0.5,-0.885,1.3);
     glScalef(0.80,0.20,-0.60);
     kubussolid();
     glPopMatrix();
//Tangga ditengah taman 3
     glPushMatrix();
     glColor3f(0.8,0.5,0.5);
     glTranslatef(-0.5,-0.83,1.3);
     glScalef(0.70,0,1.-0.50);
     kubussolid();
     glPopMatrix();
//tihang bendera ditengah
     glPushMatrix();
     glColor3f(0.3,0.3,0.3);
     glTranslatef(-0.5,-0.885,1.3);
     glScalef(0.06,3.0,0.06);
     kubussolid();
     glPopMatrix();
     
     
    //-----------------------------------DINDING TAMAN---------------------
//Dinding taman kiri atas
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(-1.5,-0.93,1.25);
     glScalef(0.3,0.25,4.2);
     kubussolid();
     glPopMatrix();
    
//Dinding taman kiri bawah atas
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(-3.03,-0.93,2.8);
     glScalef(0.3,0.25,1.2);
     kubussolid();
     glPopMatrix();
     
//Dinding taman kiri bawah kiri
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(-0.775,-0.93,3.025);
     glScalef(8.72,0.25,0.3);
     kubussolid();
     glPopMatrix();
     
//Dinding taman kiri atas kiri
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(-0.775,-0.93,0.275);
     glScalef(8.72,0.25,0.3);
     kubussolid();
     glPopMatrix();
     
//Dinding taman kanan bawah kanan
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(3.03,-0.93,2.3);
     glScalef(0.3,0.25,3.2);
     kubussolid();
     glPopMatrix();
     
//Dinding taman kanan atas kanan
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(3.03,-0.93,0.75);
     glScalef(0.3,0.25,2.2);
     kubussolid();
     glPopMatrix();
    
//Dinding taman bawah kanan
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(2.28,-0.93,0.275);
     glScalef(2.72,0.25,0.3);
     kubussolid();
     glPopMatrix();
    
//Dinding taman atas kanan
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(2.28,-0.93,3.025);
     glScalef(2.72,0.25,0.3);
     kubussolid();
     glPopMatrix();
    //--------------------------------AKHIR DINDING TAMAN---------------
     
//---------------------------TAMAN DALAM DINDING-------------------
//taman kiri bawah
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-1.5,-0.84,1.25);
     glScalef(0.1,0.5,4.1);
     kubussolid();
     glPopMatrix();
     
//taman kiri atas
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-3.03,-0.84,2.8);
     glScalef(0.1,0.5,1.1);
     kubussolid();
     glPopMatrix();
     
//taman kiri bawah kiri
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.78,-0.84,3.025);
     glScalef(8.62,0.5,0.1);
     kubussolid();
     glPopMatrix();
     
//taman kiri atas kiri
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.775,-0.84,0.275);
     glScalef(8.62,0.5,0.1);
     kubussolid();
     glPopMatrix();
     
//taman kanan bawah kanan
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(3.03,-0.84,2.3);
     glScalef(0.1,0.5,3.1);
     kubussolid();
     glPopMatrix();
     
//taman kanan atas kanan
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(3.03,-0.84,0.75);
     glScalef(0.1,0.5,2.1);
     kubussolid();
     glPopMatrix();
     
//taman bawah kanan
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(2.28,-0.84,3.025);
     glScalef(2.62,0.5,0.1);
     kubussolid();
     glPopMatrix();
     
//taman atas kanan
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(2.28,-0.84,0.275);
     glScalef(2.62,0.5,0.1);
     kubussolid();
     glPopMatrix();
     
      //---------------------------TAMAN DALAM DINDING 2 -------------------
//---------------------------TAMAN DALAM DINDING-------------------  
//Dinding taman kiri atas
     glPushMatrix();
     glColor3f(0.34,0.35,0.35);
     glTranslatef(-3.03,-0.93,1.25);
     glScalef(0.3,0.25,4.2);
     kubussolid();
     glPopMatrix();
     
//taman kiri bawah
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-3.05,-0.84,1.25);
     glScalef(0.1,0.5,4.1);
     kubussolid();
     glPopMatrix();
     
//taman kiri atas kiri
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-0.775,-0.84,0.275);
     glScalef(8.62,0.5,0.1);
     kubussolid();
     glPopMatrix();
          
//taman kanan atas kanan
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(3.03,-0.84,0.75);
     glScalef(0.1,0.5,2.1);
     kubussolid();
     glPopMatrix();
  
//taman kiri bawah
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.5,-0.84,1.25);
     glScalef(0.1,0.5,4.1);
     kubussolid();
     glPopMatrix();
     //--------------------------AKHIR TAMAN DALAM DINDING-------------
     
//-----------------------KURSI DI TAMAN -------------------------
//kursi dalam taman kiri
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-2.30,-0.885,1.3);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-2.30,-0.885,1.3);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix(); 
          
//kursi dalam taman kiri
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-2.30,-0.885,1.6);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-2.30,-0.895,1.6);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix();
     
//kursi dalam taman kiri
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-2.30,-0.895,2.1);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-2.30,-0.895,2.1);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix();
     
//kursi kiri 1
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-2.6,-0.987,2.7);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-2.6,-0.972,2.724);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix(); 
          
//kursi kiri 2
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-2.0,-0.987,2.7);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-2.0,-0.972,2.724);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix(); 
     
//kursi 3
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-1.4,-0.987,2.7);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-1.4,-0.972,2.724);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix(); 
     
//kursi 4
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-0.8,-0.987,2.7);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-0.8,-0.972,2.724);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix(); 
     
//kursi 5
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(-0.2,-0.987,2.7);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(-0.2,-0.972,2.724);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix(); 
     
//kursi 6
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(0.4,-0.987,2.7);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(0.4,-0.972,2.724);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix();
     
//kursi 7
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(1.0,-0.987,2.7);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(1.0,-0.972,2.724);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix();
     
//kursi dalam taman kanan samping kolam
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(2.38,-0.972,1.22);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(2.38,-0.972,1.22);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix();
     
//kursi dalam taman kanan samping kolam
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(2.15,-0.972,1.22);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(2.15,-0.972,1.22);
     glScalef(0.32,0.07,0.15);
     kubussolid();
     glPopMatrix();
     
    
     //-------------------AKHIR KURSI DI TAMAN---------------------
     
//------------------TROTOAR-------------------------------
//--------TROTOAR 1
//trotoar 1
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.65,-0.98,-0.28);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
//trotoar 2
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.60,-0.98,-0.28);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
//trotoar 3
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.55,-0.98,-0.28);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
//trotoar 4
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.50,-0.98,-0.28);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
//trotoar 5
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.45,-0.98,-0.28);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
//trotoar 6
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.40,-0.98,-0.28);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
          
//trotoar 7
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.35,-0.98,-0.28);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
//-------------TROTOAR 2
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.98,-0.15);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.98,-0.10);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.98,-0.05);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.98,0.0);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.98,0.05);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.98,0.1);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.98,0.15);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix(); 
     
//-------------TROTOAR 3
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.45,-0.98,0.35);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.4,-0.98,0.35);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.35,-0.98,0.35);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.3,-0.98,0.35);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.25,-0.98,0.35);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.2,-0.98,0.35);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     //-----------------AKHIR TROTOAR--------------------------
 
 //-------------------MOBIL-------------------------
//MOBIL 
     for (float i=0;i<1; i++)
     {
         for (float j=0; j<4; j++)
         {
     glPushMatrix();
     glTranslatef(-0.6+(i/5),-0.899,-0.55-(j/3));
     glRotatef(90.0,0.0,1.0,0.0);
     glScalef(0.13,0.13,0.13);
     
//BADAN MOBIL
     glPushMatrix();
     glTranslatef(0.0,-0.135,0.0);
     glScalef(3.0,1.47,2.0);
     glColor3f(0.4+((i/5)/(j/8)),0.4+(j/5),0.4+(i/10));
     kubussolid();
     glColor3f(0.8,0.8,0.8);
     kubus();
     glPopMatrix();
     //AKHIR BADAN MOBIL
     
//KAP MOBIL
     glPushMatrix();
     glTranslatef(-1.13,-0.25,0.0);
     glScalef(1.5,1.0,2.0);
     glColor3f(0.4,0.4+(j/9),0.4+(i/10));
     kubussolid();
     glPopMatrix();
     //AKHIR KAP MOBIL
      
//RODA KIRI DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,0.65); 
     glColor3f(0.5,0.5,0.5);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA KIRI DEPAN
     
//RODA KANAN DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA KANAN DEPAN
     
//RODA KIRI BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA KIRI BELAKANG
     
//RODA KANAN BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA KANAN BELAKANG
     
//RODA CADANGAN
     glPushMatrix();
     glTranslatef(0.85,-0.15,0.0);
     glRotatef(90.0,0.0,1.0,0.0);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA CADANGAN
     
//LAMPU KIRI
     glPushMatrix();
     glTranslatef(-1.5,-0.25,0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
     //AKHIR LAMPU KIRI
     
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(-1.5,-0.25,-0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
     //AKHIR LAMPU KANAN
     
     glPopMatrix();
     glPopMatrix();
     }
     }
//AKHIR MOBIL
     //--------------AKHIR MOBIL----------------
 
 //MOBIL
     for (float i=0;i<1; i++)
     {
         for (float j=0; j<1; j++)
         {
     glPushMatrix();
     glTranslatef(-0.4+(i/5),-0.899,-0.4-(j/3));
     glRotatef(90.0,0.0,1.0,0.0);
     glScalef(0.13,0.13,0.13);
     
//BADAN MOBIL
     glPushMatrix();
     glTranslatef(0.0,-0.135,0.0);
     glScalef(3.0,1.47,2.0);
     glColor3f(0.4+((i/5)/(j/8)),0.4+(j/5),0.4+(i/10));
     kubussolid();
     glColor3f(0.8,0.8,0.8);
     kubus();
     glPopMatrix();
//AKHIR BADAN MOBIL
     
//KAP MOBIL
     glPushMatrix();
     glTranslatef(-1.13,-0.25,0.0);
     glScalef(1.5,1.0,2.0);
     glColor3f(0.4,0.4+(j/9),0.4+(i/10));
     kubussolid();
     glPopMatrix();
//AKHIR KAP MOBIL
      
//RODA KIRI DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,0.65); 
     glColor3f(0.5,0.5,0.5);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI DEPAN
     
//RODA KANAN DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN DEPAN
     
//RODA KIRI BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI BELAKANG
     
//RODA KANAN BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN BELAKANG
     
//RODA CADANGAN
     glPushMatrix();
     glTranslatef(0.85,-0.15,0.0);
     glRotatef(90.0,0.0,1.0,0.0);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA CADANGAN
     
//LAMPU KIRI
     glPushMatrix();
     glTranslatef(-1.5,-0.25,0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KIRI
     
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(-1.5,-0.25,-0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
     //AKHIR LAMPU KANAN
     
     glPopMatrix();
     glPopMatrix();
     }
     }
//AKHIR MOBIL
 
//mobil baru
//MOBIL
     for (float i=0;i<1; i++)
     {
         for (float j=0; j<4; j++)
         {
     glPushMatrix();
     glTranslatef(-3.4+(i/5),-0.899,1.7-(j/3));
     glRotatef(270.0,0.0,1.0,0.0);
     glScalef(0.13,0.13,0.13);
     
//BADAN MOBIL
     glPushMatrix();
     glTranslatef(0.0,-0.135,0.0);
     glScalef(3.0,1.47,2.0);
     glColor3f(0.4+((i/5)/(j/8)),0.4+(j/5),0.4+(i/10));
     kubussolid();
     glColor3f(0.8,0.8,0.8);
     kubus();
     glPopMatrix();
//AKHIR BADAN MOBIL
     
//KAP MOBIL
     glPushMatrix();
     glTranslatef(-1.13,-0.25,0.0);
     glScalef(1.5,1.0,2.0);
     glColor3f(0.4,0.4+(j/9),0.4+(i/10));
     kubussolid();
     glPopMatrix();
//AKHIR KAP MOBIL
      
//RODA KIRI DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,0.65); 
     glColor3f(0.5,0.5,0.5);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI DEPAN
     
//RODA KANAN DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN DEPAN
     
//RODA KIRI BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI BELAKANG     

//RODA KANAN BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN BELAKANG

//RODA CADANGAN
     glPushMatrix();
     glTranslatef(0.85,-0.15,0.0);
     glRotatef(90.0,0.0,1.0,0.0);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA CADANGAN
     
//LAMPU KIRI
     glPushMatrix();
     glTranslatef(-1.5,-0.25,0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KIRI
     
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(-1.5,-0.25,-0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KANAN
     
     glPopMatrix();
     glPopMatrix();
     }
     }
//AKHIR MOBIL     
     //-------------------LAMPU LALU LINTAS----------------
     //-----------LALU LINTAS 1
//TIANG LAMPU
     glPushMatrix();
     glColor3f(0.15,0.15,0.15);
     glTranslatef(-0.715,-0.89,-0.28);
     glScalef(0.06,0.4,0.06);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.1,0.1,0.1);
     glTranslatef(-0.72,-0.71,-0.28);
     glScalef(0.1,0.37,0.1);
     kubussolid();
     glPopMatrix();
     //AKHIR TIAANG LAMPU
     
//LAMPU MERAH
     glPushMatrix();
     glTranslatef(-0.72,-0.655,-0.295);
     glScalef(0.055,0.055,0.055);
     glColor3f(1.0,0.0,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU MERAH
     
//LAMPU KUNING
     glPushMatrix();
     glTranslatef(-0.72,-0.705,-0.295);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.8,0.8,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU KUNING
     
//LAMPU HIJAU
     glPushMatrix();
     glTranslatef(-0.72,-0.755,-0.295);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.0,1.0,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU HIJAU
     
     //------------LALU LINTAS 2
//TIANG LAMPU
     glPushMatrix();
     glColor3f(0.15,0.15,0.15);
     glTranslatef(-0.815,-0.89,-0.28);
     glScalef(0.06,0.4,0.06);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.1,0.1,0.1);
     glTranslatef(-0.82,-0.71,-0.28);
     glScalef(0.1,0.37,0.1);
     kubussolid();
     glPopMatrix();
     //AKHIR TIAANG LAMPU
     
//LAMPU MERAH
     glPushMatrix();
     glTranslatef(-0.835,-0.655,-0.28);
     glScalef(0.055,0.055,0.055);
     glColor3f(1.0,0.0,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU MERAH
     
//LAMPU KUNING
     glPushMatrix();
     glTranslatef(-0.835,-0.705,-0.28);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.8,0.8,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU KUNING
     
//LAMPU HIJAU
     glPushMatrix();
     glTranslatef(-0.835,-0.755,-0.28);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.0,1.0,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU HIJAU
     
//------------LALU LINTAS 3
     glPushMatrix();
     glColor3f(0.15,0.15,0.15);
     glTranslatef(-3.55,-0.89,0.35);
     glScalef(0.06,0.4,0.06);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.1,0.1,0.1);
     glTranslatef(-3.55,-0.71,0.35);
     glScalef(0.1,0.37,0.1);
     kubussolid();
     glPopMatrix();
     
//LAMPU MERAH
     glPushMatrix();
     glTranslatef(-3.55,-0.655,0.365);
     glScalef(0.055,0.055,0.055);
     glColor3f(1.0,0.0,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU MERAH
     
//LAMPU KUNING
     glPushMatrix();
     glTranslatef(-3.55,-0.705,0.365);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.8,0.8,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
     //AKHIR LAMPU KUNING
     
//LAMPU HIJAU
     glPushMatrix();
     glTranslatef(-3.55,-0.755,0.365);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.0,1.0,0.0);
     bolasolid(0.3,30,30);
     glPopMatrix();
//AKHIR LAMPU HIJAU
     //-------------AKHIR LAMPU LALU LINTAS-----------------------------------------------
     
//------------KOLAM IKAN------------------
//Dinding kolam kanan
     glPushMatrix();
     glColor3f(0.7,0.6,0.7);
     glTranslatef(2.6,-0.987,0.81);
     glScalef(0.05,0.05,0.75);
     kubussolid();
     glPopMatrix();
     
//Dinding kolam kiri
     glPushMatrix();
     glColor3f(0.7,0.6,0.7);
     glTranslatef(1.89,-0.987,0.81);
     glScalef(0.05,0.05,0.75);
     kubussolid();
     glPopMatrix();
     
//Dinding kolam bawah
     glPushMatrix();
     glColor3f(0.7,0.6,0.7);
     glTranslatef(2.245,-0.987,0.987);
     glScalef(1.37,0.05,0.05);
     kubussolid();
     glPopMatrix();
     
//Dinding kolam atas
     glPushMatrix();
     glColor3f(0.7,0.6,0.7);
     glTranslatef(2.245,-0.987,0.635);
     glScalef(1.37,0.05,0.05);
     kubussolid();
     glPopMatrix();
     
//kolam ikan
     glPushMatrix();
     glColor3f(0.0,0.7,0.7);
     glTranslatef(2.245,-0.997,0.81);
     glScalef(1.37,0.01,0.67);
     kubussolid();
     glPopMatrix();
//------------------ AKHIR KOLAM IKAN-------------------------------------------------------
     
//--------------TIANG NET-----------------
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(1.85,-0.91,2.2);
     glScalef(0.03,0.35,0.03);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.35,0.35,0.35);
     glTranslatef(2.73,-0.91,2.2);
     glScalef(0.03,0.35,0.03);
     kubussolid();
     glPopMatrix();
//---------AKHIR TIANG NET------------------
     
     // -------------------------------------- GEDUNG KEMBAR KANAN -----------------------------------------
//GEDUNG 1    
     glPushMatrix();
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glColor3f(1.0,1.0,1.0);
     glTranslatef(0.2,-0.49,-2.2);
     glScalef(1.2,2.0,3.9);
     kubussolid();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     glPopMatrix();
     
//GEDUNG 2    
     glPushMatrix();
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glColor3f(1.0,1.0,0.5);
     glTranslatef(1.1,-0.49,-2.2);
     glScalef(1.2,2.0,3.9);
     kubussolid();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     glPopMatrix();  
//halaman gedung
     glPushMatrix();
     glTranslatef(0.65,-0.99,-1.85);
     glScalef(3.0,0.001,5.5);
     glColor3f(0.3,0.3,0.3);
     kubussolid();
     glPopMatrix();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     
     glPushMatrix();
     glTranslatef(0.65,-0.99,-0.82);
     glScalef(1.0,0.001,2.5);
     glColor3f(0.3,0.3,0.3);
     kubussolid();
     glPopMatrix();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0); 
     
     glPushMatrix();
     glTranslatef(0.65,-0.99,-0.82);
     glScalef(1.0,0.001,3.5);
     glColor3f(0.3,0.3,0.3);
     kubussolid();
     glPopMatrix();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0); 
     
     
     //-------------------------------------------- DINDING PEMBATAS ---------------------------------
       //Dinding kiri
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(-0.07,-0.95,-1.0);
     glScalef(0.1,0.15,1.8);
     kubussolid();
     glPopMatrix();
     //Dinding kanan
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(1.37,-0.95,-1.0);
     glScalef(0.1,0.15,1.8);
     kubussolid();
     glPopMatrix();
      //Dinding atas kanan
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(1.145,-0.95,-0.53);
     glScalef(1.0,0.15,0.1);
     kubussolid();
     glPopMatrix();
    //Dinding atas kiri
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(0.155,-0.95,-0.53);
     glScalef(1.0,0.15,0.1);
     kubussolid();
     glPopMatrix();
     //------------------------------------------------------ AKHIR --------------------------------------------------
     //---------------------------------------------------- BUNDARAN JALAN -------------------------------------------
     glPushMatrix();
     glTranslatef(0.65,-0.97,-0.82);
     glScalef(0.60,0.001,0.5);
     glColor3f(0.0,0.2,0.0);
     kubussolid();
     glPopMatrix();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     
     //dinding1
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(0.65,-0.95,-0.93);
     glScalef(0.59,0.03,0.07);
     kubussolid();
     glPopMatrix();
    
    //dinding2
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(0.65,-0.95,-0.68);
     glScalef(0.59,0.03,0.07);
     kubussolid();
     glPopMatrix();
     
     //dinding3
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(0.5,-0.95,-0.805);
     glScalef(0.1,0.03,0.57);
     kubussolid();
     glPopMatrix();
    //dinding4
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(0.8,-0.95,-0.805);
     glScalef(0.1,0.03,0.57);
     kubussolid();
     glPopMatrix();
     
     //--------------------------------------------- AKHIR BUNDARAN ----------------------------------------

// JENDELA GEDUNG SATU
//samping kiri
     for(int i=0; i<=8; i++)
     {
        for(int j=0; j<6; j++)
        {
      glPushMatrix();
      glTranslatef(0.0,-(j/10.0)*1.5,-(i/10.0)*2.0); 
     //jendela 1.1
     glPushMatrix();
     glColor3f(0.0,0.0,0.0);
     glTranslatef(-0.1,-0.12,-1.4);
     glScalef(0.001,0.2,0.25);
     kubussolid();
     glPopMatrix();
  
//jendela 1.1.2
     glPushMatrix();
     glColor3f(1.0,1.0,1.9);
     glTranslatef(-0.101,-0.117,-1.398);
     glScalef(0.001,0.17,0.15);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     }
     }
//samping kanan
     for(int i=0; i<=8; i++)
     {
        for(int j=0; j<6; j++)
        {
      glPushMatrix();
      glTranslatef(0.0,-(j/10.0)*1.5,-(i/10.0)*2.0); 
      
//jendela 1.1
     glPushMatrix();
     glColor3f(0.0,0.0,0.0);
     glTranslatef(0.5,-0.12,-1.4);
     glScalef(0.001,0.2,0.25);
     kubussolid();
     glPopMatrix();
  
//jendela 1.1.2
     glPushMatrix();
     glColor3f(1.0,1.0,1.9);
     glTranslatef(0.502,-0.117,-1.398);
     glScalef(0.001,0.17,0.15);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     }
     }
//jendela depan gedung 1
      
// JENDELA GEDUNG DUA
//sebelah kiri
     for(int i=0; i<=8; i++)
     {
        for(int j=0; j<6; j++)
        {
      glPushMatrix();
      glTranslatef(0.0,-(j/10.0)*1.5,-(i/10.0)*2.0); 
//jendela 1.1
     glPushMatrix();
     glColor3f(0.0,0.0,0.8);
     glTranslatef(0.8,-0.12,-1.4);
     glScalef(0.001,0.2,0.25);
     kubussolid();
     glPopMatrix();
//jendela 1.1.2
     glPushMatrix();
     glColor3f(0.7,1.0,0.9);
     glTranslatef(0.799,-0.12,-1.4);
     glScalef(0.001,0.17,0.15);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     }
     }
     
//sebelah depan
      for(int i=0; i<=2; i++)
     {
          for(int j=0; j<4; j++)
     {
     glPushMatrix();
     glTranslatef((i/10.0)*2.0,-(j/10.0)*1.5,0.0); 
     glPushMatrix();
     glScalef(1.0,1.0,1.32);
     glTranslatef(0.25,0.0,0.74);
     glRotatef(-90.0,0.0,1.0,0.0);
     glPushMatrix();
     glColor3f(0.0,0.0,0.8);
     glTranslatef(-1.667,-0.2,0.249);
     glScalef(0.001,0.2,0.25);
     kubussolid();
     glPopMatrix();
          
//jendela 
     glPushMatrix();
     glColor3f(0.7,1.0,0.9);
     glTranslatef(-1.665,-0.2,0.249);
     glScalef(0.001,0.12,0.21);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     }
     }
     
//sebelah kanan
     for(int i=0; i<=8; i++)
     {
        for(int j=0; j<6; j++)
        {
      glPushMatrix();
      glTranslatef(0.0,-(j/10.0)*1.5,-(i/10.0)*2.0); 
//jendela 
     glPushMatrix();
     glColor3f(0.0,0.0,0.8);
     glTranslatef(1.4,-0.12,-1.4);
     glScalef(0.001,0.2,0.25);
     kubussolid();
     glPopMatrix();
     
//jendela
     glPushMatrix();
     glColor3f(0.7,1.0,0.9);
     glTranslatef(1.401,-0.12,-1.4);
     glScalef(0.001,0.17,0.15);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     }
     }
     
//sebelah depan
      for(int i=0; i<=2; i++)
     {
          for(int j=0; j<4; j++)
     {
     glPushMatrix();
     glTranslatef((i/10.0)*2.0,-(j/10.0)*1.5,0.0); 
     glPushMatrix();
     glScalef(1.0,1.0,1.32);
     glTranslatef(0.25,0.0,0.74);
     glRotatef(-90.0,0.0,1.0,0.0);
     glPushMatrix();
     glColor3f(0.0,0.0,0.8);
     glTranslatef(-1.667,-0.2,-0.65);
     glScalef(0.001,0.2,0.25);
     kubussolid();
     glPopMatrix();
              
//jendela 2.1.2
     glPushMatrix();
     glColor3f(0.7,1.0,0.9);
     glTranslatef(-1.665,-0.2,-0.65);
     glScalef(0.001,0.12,0.21);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     }
     }
     
// LOBBY GEDUNG 1
//atap lobby
     glPushMatrix();
     glTranslatef(0.2,-0.8,-1.14);
     glScalef(0.5,0.04,0.3);
     glColor3f(1.0,0.4,0.1);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     
//lantai lobby
     glPushMatrix();
     glColor3f(0.5,0.5,0.35);
     glTranslatef(0.2,-0.98,-1.14);
     glScalef(0.5,0.03,0.3);
     kubussolid();
     glPopMatrix();
     
//tiang lobby 1 gedung 1
     glPushMatrix();
     glColor3f(0.9,0.9,0.9);
     glTranslatef(0.1,-0.9,-1.13);
     glScalef(0.05,0.35,0.05);
     kubussolid();
     glPopMatrix();
//tiang lobby 2 gedung 1
     glPushMatrix();
     glColor3f(0.9,0.9,0.9);
     glTranslatef(0.3,-0.9,-1.13);
     glScalef(0.05,0.35,0.05);
     kubussolid();
     glPopMatrix();     
//pintu lobby gedung 1
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(0.2,-0.9,-1.2);
     glScalef(0.27,0.3,0.0);
//glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     kubussolid();
     glPopMatrix();
     
// LOBBY GEDUNG 2
//atap lobby
     glPushMatrix();
     glTranslatef(1.1,-0.8,-1.14);
     glScalef(0.5,0.04,0.3);
     glColor3f(1.0,0.4,0.1);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     
//lantai lobby
     glPushMatrix();
     glColor3f(0.5,0.5,0.35);
     glTranslatef(1.1,-0.98,-1.14);
     glScalef(0.5,0.03,0.3);
     kubussolid();
     glPopMatrix();
     
//tiang lobby 1 gedung 1
     glPushMatrix();
     glColor3f(0.9,0.9,0.9);
     glTranslatef(1.0,-0.9,-1.1);
     glScalef(0.05,0.35,0.05);
     kubussolid();
     glPopMatrix();
     
//tiang lobby 2 gedung 1
     glPushMatrix();
     glColor3f(0.9,0.9,0.9);
     glTranslatef(1.2,-0.9,-1.1);
     glScalef(0.05,0.35,0.05);
     kubussolid();
     glPopMatrix();
     
//pintu lobby gedung 1
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(1.1,-0.9,-1.2);
     glScalef(0.27,0.3,0.0);
//glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     kubussolid();
     glPopMatrix();
     // --------------------------------------- AKHIR GEDUNG KANAN ---------------------------------------     
// --------------------------------------- MEMBUAT MASJID  ------------------------------------------
// masjid
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glPushMatrix();
     glTranslatef(2.5,-0.79,-2.43);
     glScalef(3.0,0.8,3.0);
     glColor3f(0.3,0.2,0.0);
     kubussolid();
     glPopMatrix();
 
//lantai    
     glPushMatrix();
     glTranslatef(2.5,-0.99,-0.45);
     glScalef(1.0,0.01,1.0);
     glColor3f(0.3,0.3,0.3);
     kubussolid();
     glPopMatrix();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0); 
        
// lantai 2 masjid  
     glPushMatrix();
     glTranslatef(2.5,-0.46,-2.43);
     glScalef(1.8,0.5,2.2);
     glColor3f(0.3,0.3,0.0);
     kubussolid();
     glPopMatrix();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     
// atap masjid besar
     glPushMatrix();
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glTranslatef(2.5,-0.34,-2.445);
     glScalef(0.8,1.0,-0.9);
     glRotatef(90.0,0.0,0.0,1.0);
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glColor3f(1.0,1.0,0.6);
     bolasolid(0.5,20,20);
     glDisable(GL_CLIP_PLANE1);
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     glPopMatrix(); 
//akhir
     // tiang kecil masjid -------------------------------------------------------------------    
//tiang masjid 1 kiri
     glPushMatrix();
     glTranslatef(1.8,-0.5,-1.75);
     glScalef(0.1,0.9,0.08);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
//tiang masjid 4 kiri
     glPushMatrix();
     glTranslatef(1.8,-0.5,-3.15);
     glScalef(0.1,0.9,0.08);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
//tiang masjid 2 kanan
     glPushMatrix();
     glTranslatef(3.2,-0.5,-1.75);
     glScalef(0.1,0.9,0.08);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
//tiang masjid 3 kanan
     glPushMatrix();
     glTranslatef(3.2,-0.5,-3.15);
     glScalef(0.1,0.9,0.08);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
// atap masjid tiang  1 kiri
     glPushMatrix();
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glTranslatef(1.8,-0.3,-1.75);
     glScalef(0.05,0.13,0.038);
     glRotatef(90.0,0.0,0.0,1.0);
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glColor3f(1.0,1.0,0.6);
     bolasolid(0.5,20,20);
     glDisable(GL_CLIP_PLANE1);
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     glPopMatrix();
     
// atap masjid tiang 4 kiri
     glPushMatrix();
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glTranslatef(1.8,-0.3,-3.15);
     glScalef(0.05,0.13,0.038);
     glRotatef(90.0,0.0,0.0,1.0);
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glColor3f(1.0,1.0,0.6);
     bolasolid(0.5,20,20);
     glDisable(GL_CLIP_PLANE1);
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     glPopMatrix();
     
// atap masjid tiang  2 kanan
     glPushMatrix();
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glTranslatef(3.2,-0.3,-1.75);
     glScalef(0.05,0.13,0.038);
     glRotatef(90.0,0.0,0.0,1.0);
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glColor3f(1.0,1.0,0.6);
     bolasolid(0.5,20,20);
     glDisable(GL_CLIP_PLANE1);
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     glPopMatrix();
     
// atap masjid tiang  3 kanan
     glPushMatrix();
//glEnable(GL_LIGHTING);
//glEnable(GL_LIGHT0);
     glTranslatef(3.2,-0.3,-3.15);
     glScalef(0.05,0.13,0.038);
     glRotatef(90.0,0.0,0.0,1.0);
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glColor3f(1.0,1.0,0.6);
     bolasolid(0.5,20,20);
     glDisable(GL_CLIP_PLANE1);
//glDisable(GL_LIGHTING);
//glDisable(GL_LIGHT0);
     glPopMatrix();
//akhir tiang kecil masjid
     
//jendela masjid depan
    for(int i=0; i<=1; i++)
     {
        for(int j=0; j<1; j++)
        {
      glPushMatrix();
      glTranslatef(0.0,-(j/8.0)*1.5,-(i/10.0)*2.0); 
//jendela 1.1
     glPushMatrix();
     glColor3f(0.0,0.0,0.8);
     glTranslatef(2.5,-0.8,-2.33);
     glScalef(2.6,0.5,2.635);
     kubussolid();
     glPopMatrix();
     
//jendela 1.1.2
     glPushMatrix();
     glColor3f(0.7,1.0,0.9);
     glTranslatef(2.5,-0.8,-2.33);
     glScalef(2.35,0.35,2.67);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     //akhir jendela
     
//lantai masjid
     glPushMatrix();
//glEnable(GL_LIGHTING);
//glEnable(GL_LIGHT0);
     glTranslatef(3.2,-0.3,-3.15);
     glScalef(0.05,0.13,0.038);
     glRotatef(90.0,0.0,0.0,1.0);
     glClipPlane(GL_CLIP_PLANE1,eqn2);
     glEnable(GL_CLIP_PLANE1);
     glColor3f(1.0,1.0,0.6);
     bolasolid(0.5,20,20);
     glDisable(GL_CLIP_PLANE1);
//glDisable(GL_LIGHTING);
//glDisable(GL_LIGHT0);
     glPopMatrix();
     }
     }   
//jendela masjid samping
   for(int i=0; i<=1; i++)
     {
        for(int j=0; j<1; j++)
        {
      glPushMatrix();
      glTranslatef(0.0,-(j/8.0)*1.5,-(i/10.0)*2.0); 
//jendela 1.1
     glPushMatrix();
     glColor3f(0.0,0.0,0.8);
     glTranslatef(2.5,-0.8,-2.33);
     glScalef(3.1,0.5,2.0);
     kubussolid();
     glPopMatrix();
//jendela 1.1.2
     glPushMatrix();
     glColor3f(0.7,1.0,0.9);
     glTranslatef(2.5,-0.8,-2.33);
     glScalef(3.15,0.35,1.8);
     kubussolid();
     glPopMatrix();
     glPopMatrix();
     }
     }
// lantai depan masjid
     glPushMatrix();
     glTranslatef(2.5,-0.99,-1.18);
     glScalef(3.0,0.001,2.0);
     glColor3f(1.0,1.0,1.0);
     kubussolid();
     glPopMatrix();
     glDisable(GL_LIGHTING);
     glDisable(GL_LIGHT0);
     // --------------------------------------- AKHIR MASJID -------------------------------------------------
//mobil dijalan kiri
      for (float i=0;i<1; i++)
     {
         for (float j=0; j<1; j++)
         {
     glPushMatrix();
     glTranslatef(-0.0+(i/5),-0.89,0.1-(j/4));
     glRotatef(360.0,0.0,1.0,0.0);
     glScalef(0.15,0.15,0.1);
//BADAN MOBIL
     glPushMatrix();
     glTranslatef(0.0,-0.135,0.0);
     glScalef(3.0,1.47,2.0);
     glColor3f(0.0,0.0,0.0);
     kubussolid();
     glColor3f(0.8,0.8,0.8);
     kubus();
     glPopMatrix();
     //AKHIR BADAN MOBIL
     
//KAP MOBIL
     glPushMatrix();
     glTranslatef(-1.13,-0.25,0.0);
     glScalef(1.5,1.0,2.0);
     glColor3f(0.4,0.4+(j/9),0.4+(i/10));
     kubussolid();
     glPopMatrix();
     //AKHIR KAP MOBIL
     
//JENDELA DEPAN
     glPushMatrix();
     glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid);glColor3f(0.1,0.1,1.0);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
     glEnable(GL_BLEND);
     glDepthMask(GL_TRUE);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE);
     glTranslatef(-0.75,0.0,0.0);
     glScalef(0.8,0.7,2.0);
     glRotatef(45,0.0,0.0,1.0); 
     kubussolid(); 
     glDisable(GL_BLEND);
     glPopMatrix();
     //AKHIR JENDELA
      
//RODA KIRI DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,0.65); 
     glColor3f(0.5,0.5,0.5);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI DEPAN
     
//RODA KANAN DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN DEPAN
     
//RODA KIRI BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI BELAKANG
     
//RODA KANAN BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN BELAKANG
     
//LAMPU KIRI
     glPushMatrix();
     glTranslatef(-1.5,-0.25,0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KIRI
     
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(-1.5,-0.25,-0.3);     
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     }
     }
//LAMPU KIRI
     glPushMatrix();
     glTranslatef(-1.5,-0.25,0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KIRI
     
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(-1.5,-0.25,-0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KANAN
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();  
     
     
             
// mobil parkir di depan masjid ------------------------------------------------------------------
//mobil kiri kiri
     for (float i=0;i<1; i++)
     {
         for (float j=0; j<4; j++)
         {
     glPushMatrix();
     glTranslatef(1.9+(i/5),-0.89,-0.8-(j/4));
     glRotatef(180.0,0.0,1.0,0.0);
     glScalef(0.15,0.15,0.1);
//BADAN MOBIL
     glPushMatrix();
     glTranslatef(0.0,-0.135,0.0);
     glScalef(3.0,1.47,2.0);
     glColor3f(0.0,0.0,0.0);
     kubussolid();
     glColor3f(0.8,0.8,0.8);
     kubus();
     glPopMatrix();
//AKHIR BADAN MOBIL
     
//KAP MOBIL
     glPushMatrix();
     glTranslatef(-1.13,-0.25,0.0);
     glScalef(1.5,1.0,2.0);
     glColor3f(0.4,0.4+(j/9),0.4+(i/10));
     kubussolid();
     glPopMatrix();
//AKHIR KAP MOBIL
     
//JENDELA DEPAN
     
      glPushMatrix();
     glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid);glColor3f(0.1,0.1,1.0);
     
      glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
      glEnable(GL_BLEND);
      glDepthMask(GL_TRUE);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE);
     glTranslatef(-0.75,0.0,0.0);
     glScalef(0.8,0.7,2.0);
     glRotatef(45,0.0,0.0,1.0); 
     kubussolid(); 
     glDisable(GL_BLEND);
     glPopMatrix();
//AKHIR JENDELA
      
//RODA KIRI DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,0.65); 
     glColor3f(0.5,0.5,0.5);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI DEPAN
     
//RODA KANAN DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN DEPAN
     
//RODA KIRI BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI BELAKANG
     
//RODA KANAN BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN BELAKANG
     
//RODA CADANGAN
     glPushMatrix();
     glTranslatef(0.85,-0.15,0.0);
     glRotatef(90.0,0.0,1.0,0.0);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA CADANGAN
     
//LAMPU KIRI
     glPushMatrix();
     glTranslatef(-1.5,-0.25,0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KIRI
     
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(-1.5,-0.25,-0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KANAN
     glPopMatrix();
     glPopMatrix();
     }
     }
     
//mobil kanan
//mobil kiri kiri
     for (float i=0;i<1; i++)
     {
         for (float j=0; j<4; j++)
         {
     glPushMatrix();
     glTranslatef(3.1+(i/5),-0.89,-0.8-(j/4));
     glRotatef(360.0,0.0,1.0,0.0);
     glScalef(0.15,0.15,0.1);
//BADAN MOBIL
     glPushMatrix();
     glTranslatef(0.0,-0.135,0.0);
     glScalef(3.0,1.47,2.0);
     glColor3f(0.0,0.0,0.0);
     kubussolid();
     glColor3f(0.8,0.8,0.8);
     kubus();
     glPopMatrix();
//AKHIR BADAN MOBIL
     
//KAP MOBIL
     glPushMatrix();
     glTranslatef(-1.13,-0.25,0.0);
     glScalef(1.5,1.0,2.0);
     glColor3f(0.4,0.4+(j/9),0.4+(i/10));
     kubussolid();
     glPopMatrix();
//AKHIR KAP MOBIL
     
//JENDELA DEPAN     
     glPushMatrix();
     glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid);glColor3f(0.1,0.1,1.0);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
     glEnable(GL_BLEND);
     glDepthMask(GL_TRUE);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE);
     glTranslatef(-0.75,0.0,0.0);
     glScalef(0.8,0.7,2.0);
     glRotatef(45,0.0,0.0,1.0); 
     kubussolid(); 
     glDisable(GL_BLEND);
     glPopMatrix();
//AKHIR JENDELA
      
//RODA KIRI DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,0.65); 
     glColor3f(0.5,0.5,0.5);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI DEPAN
     
//RODA KANAN DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA KANAN DEPAN
     
//RODA KIRI BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA KIRI BELAKANG
     
//RODA KANAN BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(0.4,-0.6,-0.65); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA KANAN BELAKANG
     
//RODA CADANGAN
     glPushMatrix();
     glTranslatef(0.85,-0.15,0.0);
     glRotatef(90.0,0.0,1.0,0.0);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
     //AKHIR RODA CADANGAN
     
//LAMPU KIRI
     glPushMatrix();
     glTranslatef(-1.5,-0.25,0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
     //AKHIR LAMPU KIRI
     
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(-1.5,-0.25,-0.3);
     glScalef(0.1,0.2,0.2);
     glColor3f(0.8,0.8,0.8);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     }
     }
     //akhir mobil parkir
     
//lampu Hias Bulat Depan
//LAMPU KANAN
     glPushMatrix();
     glTranslatef(3.22,-0.5,-0.7);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(3.22,-0.77,-0.69);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
//lampu  kiri
     glPushMatrix();
     glTranslatef(1.77,-0.5,-0.7);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(1.77,-0.77,-0.69);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
//akhir masjid
          
//LAMPU taman Kanan Atas
     glPushMatrix();
     glTranslatef(2.85,-0.5,0.5);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.85,-0.77,0.5);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();

//LAMPU taman tengah Atas
     glPushMatrix();
     glTranslatef(-1.30,-0.5,0.5);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(-1.30,-0.77,0.5);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();   
//LAMPU taman Kiri Atas
     glPushMatrix();
     glTranslatef(-2.85,-0.5,0.5);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(-2.85,-0.77,0.5);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();   
     
//LAMPU taman Kanan Bawah
     glPushMatrix();
     glTranslatef(2.85,-0.5,2.8);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.85,-0.77,2.8);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
//LAMPU taman Kanan Bawah
     glPushMatrix();
     glTranslatef(-2.85,-0.5,2.8);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(-2.85,-0.77,2.8);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
//LAMPU taman kiri tengan
     glPushMatrix();
     glTranslatef(1.15,-0.5,2.8);
     glScalef(0.15,0.15,0.15);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(1.15,-0.77,2.8);
     glScalef(0.05,0.9,0.05);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
//SEKOLAH 1
     glPushMatrix();
     glColor3f(0.9,0.8, 0.7); 
     glTranslatef(-2.75,-0.9,-2.2);
     glScalef(1.2,0.8,3.5);
     kubussolid();
     glPopMatrix();
     
//penutup atap
      glPushMatrix();
      glTranslatef(-3.1,-0.8,-1.43);
      glBegin(GL_TRIANGLES);
      glColor3f(0.9,0.8, 0.7); 
      glVertex3f(0.35f, 0.4,0.1); 
      glVertex3f(0.0f,  0.1f,0.1); 
      glVertex3f(0.7f,  0.1f,0.1); 
      
      glEnd();
      glPopMatrix();
     
      glPushMatrix();
      glTranslatef(-3.1,-0.8,-3.17);
      glBegin(GL_TRIANGLES);
      glColor3f(0.9,0.8, 0.7); 
      glVertex3f(0.35f, 0.4,0.1); 
      glVertex3f(0.0f,  0.1f,0.1); 
      glVertex3f(0.7f,  0.1f,0.1); 
      glEnd();
      glPopMatrix();
     
//pintu kelas
     float i=-1.5;
     while(i>-3)
     {
        glPushMatrix();
         glColor3f(0.3,0.2,0.2);
         glTranslatef(-2.45,-0.9,i);
         glScalef(0.01,0.4,0.2);
         kubussolid();
         glPopMatrix();
         i=i-0.55;
     }

//jendela
       glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-1.7);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-1.9);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-2.2);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-2.4);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-2.8);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-3.0);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         
         
//atap sekolah
     glPushMatrix();
       glColor3f(0.3,0.2,0.0);
     glTranslatef(-2.5,-0.6,-2.2);
     glRotatef(45.0,0.0,0.0,1.0);
     glScalef(0.1,1.2,3.5);
     kubussolid();

     glPopMatrix();
     
     glPushMatrix();

      glColor3f(0.3,0.2,0.0);
     glTranslatef(-3.0,-0.6,-2.2);
     glRotatef(132.0,0.0,0.0,1.0);
     glScalef(0.1,1.1,3.5);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.3,0.2,0.0);
     glTranslatef(-2.75,-0.4,-2.2);
     glScalef(0.2,0.1,3.5);
     kubussolid();
     glPopMatrix();
     
//sekolah 2
     glPushMatrix();   
     glTranslatef(0.0,0.0,-3.4);
    glRotatef(90.0,0.0,1.0,0.0);  
     glPushMatrix();
     glColor3f(0.9,0.8, 0.7); 
     glTranslatef(-2.75,-0.9,-2.2);
     glScalef(1.2,0.8,3.5);
     kubussolid();
     glPopMatrix();
     
//pintu kelas
     i=-1.5;
     while(i>-3)
     {
         glPushMatrix();
         glColor3f(0.3,0.2,0.2);
         glTranslatef(-2.45,-0.9,i);
         glScalef(0.01,0.4,0.2);
         kubussolid();
         glPopMatrix();
         i=i-0.55;
     }
//jendela
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-1.7);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-1.9);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-2.2);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-2.4);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-2.8);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
         
         glPushMatrix();
         glColor3f(0.6, 0.8, 1.0);
         glTranslatef(-2.45,-0.9,-3.0);
         glScalef(0.01,0.2,0.2);
         kubussolid();
         glPopMatrix();
 
//atap sekolah
     glPushMatrix();
     glColor3f(0.3,0.2,0.0);
     glTranslatef(-2.5,-0.6,-2.2);
     glRotatef(45.0,0.0,0.0,1.0);
     glScalef(0.1,1.2,3.5);
     kubussolid();

     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.3,0.2,0.0);
     glTranslatef(-3.0,-0.6,-2.2);
     glRotatef(132.0,0.0,0.0,1.0);
     glScalef(0.1,1.1,3.5);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.3,0.2,0.0);
     glTranslatef(-2.75,-0.4,-2.2);
     glScalef(0.2,0.1,3.5);
     kubussolid();
     glPopMatrix();
     
//penutup atap
      glPushMatrix();
      glTranslatef(-3.1,-0.8,-1.43);
      glBegin(GL_TRIANGLES);
      glColor3f(0.9,0.8, 0.7); 
      glVertex3f(0.35f, 0.4,0.1); 
      glVertex3f(0.0f,  0.1f,0.1); 
      glVertex3f(0.7f,  0.1f,0.1); 
      
      glEnd();
      glPopMatrix();
      
      glPushMatrix();
      glTranslatef(-3.1,-0.8,-3.17);
      glBegin(GL_TRIANGLES);
      glColor3f(0.9,0.8, 0.7); 
      glVertex3f(0.35f, 0.4,0.1); 
      glVertex3f(0.0f,  0.1f,0.1); 
      glVertex3f(0.7f,  0.1f,0.1); 
      glEnd();
      glPopMatrix();
      glPopMatrix();   
     
//gapura
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.9,-1.6);
     glRotatef(90.0,0.0,1.0,0.0);
     glScalef(0.2,0.25,0.2);
     glClipPlane(GL_CLIP_PLANE1,eqn3);
     glEnable(GL_CLIP_PLANE1);
     torussolid(0.1,0.7,20,30);
     glDisable(GL_CLIP_PLANE1);
     glPopMatrix();
     
//pagar
      glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.9,-2.4);
     glScalef(0.1,0.35,2.7);
     kubussolid();
     glPopMatrix();

//pagar
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.8,-0.9,-0.9);
     glScalef(0.1,0.35,2.3);
     kubussolid();
     glPopMatrix();
        
//pagar
     glPushMatrix();
     glRotatef(90.0,0.0,1.0,0.0);
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(0.3,-0.9,-1.95);
     glScalef(0.1,0.35,4.65);
     kubussolid();
     glPopMatrix();
     glPopMatrix();

//pagar
     glPushMatrix();
     glRotatef(90.0,0.0,1.0,0.0);
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(3.1,-0.9,-1.95);
     glScalef(0.1,0.35,4.65);
     kubussolid();
     glPopMatrix();
     glPopMatrix();

//pagar
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.1,-0.9,-1.7);
     glScalef(0.1,0.35,5.6);
     kubussolid();
     glPopMatrix();
    
//lapangan
     glPushMatrix();
     glColor3f(0.6f, 0.6f, 0.6f);
     glTranslatef(-2.1,-1.0,-1.7);
     glScalef(5.0,0.01,5.7);
     kubussolid();
     glPopMatrix();
//tihang bendera Sekolah
     glPushMatrix();
     glColor3f(0.3,0.3,0.3);
     glTranslatef(-1.2,-0.2,-2.2);
     glScalef(0.06,3.0,0.06);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(1.0,0.0,0.0);
     glTranslatef(-1.2,0.4,-2.05);
     glScalef(0.01,0.3,0.55);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-1.2,0.25,-2.05);
     glScalef(0.01,0.3,0.55);
     kubussolid();
     glPopMatrix();

//1
     glPushMatrix();
     glColor3f(0.25f, 0.25f, 0.25f);
     glTranslatef(-1.2,-0.945,-2.2);
     glScalef(0.7,0.15,0.8);
     kubussolid();
     glPopMatrix();
//2
     glPushMatrix();
     glColor3f(0.7,0.7,0.6);
     glTranslatef(-1.2,-0.9,-2.2);
     glScalef(0.4,0.07,0.5);
     kubussolid();
     glPopMatrix();
     
//kantor satpam
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(-1.1,-0.9,-0.7);
     glScalef(0.5,0.6,0.5);
     kubussolid();
     glPopMatrix();
          
     glPushMatrix();
     glColor3f(0.3,0.2,0.2);
     glTranslatef(-1.1,-0.75,-0.7);
     glScalef(0.03,0.30,0.03);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (6.5,0.9,50,8);
     glPopMatrix();
     
//pintu satpam
     glPushMatrix();
     glColor3f(0.3,0.2,0.2);
     glTranslatef(-1.1,-0.9,-0.85);
     glScalef(0.2,0.4,0.01);
     kubussolid();
     glPopMatrix();
     
//--------Tempat duduk taman--------
//Alas
     glPushMatrix();
     glColor3f(0.9,0.8, 0.7);
     glTranslatef(0.9,-0.92,1.3);
     glScalef(1.2,0.3,1.2);
     kubussolid();
     glPopMatrix();
     
//Alas Tiang 1
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(0.7,-0.827,1.10);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();
     
//Alas Tiang 2
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(1.1,-0.827,1.10);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();

//Alas Tiang 1.1
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(0.7,-0.827,1.5);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();
     
//Alas Tiang 2.1
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(1.1,-0.827,1.5);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();
     
//Tiang 1
     glPushMatrix();
     glColor3f(0.95,0.95,0.95);
     glTranslatef(0.7,-0.67,1.10);
     glScalef(0.08,0.55,0.08);
     kubussolid();
     glPopMatrix();
     
//Tiang 2
     glPushMatrix();
     glColor3f(0.95,0.95,0.95);
     glTranslatef(1.1,-0.67,1.10);
     glScalef(0.08,0.55,0.08);
     kubussolid();
     glPopMatrix();
     
//Tiang 3
     glPushMatrix();
     glColor3f(0.95,0.95,0.95);
     glTranslatef(0.7,-0.67,1.5);
     glScalef(0.08,0.55,0.08);
     kubussolid();
     glPopMatrix();
     
//Tiang 4
     glPushMatrix();
     glColor3f(0.95,0.95,0.95);
     glTranslatef(1.1,-0.67,1.5);
     glScalef(0.08,0.55,0.08);
     kubussolid();
     glPopMatrix();
     
//Atas Tiang 1
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(0.7,-0.52,1.10);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();
     
//Atas Tiang 2
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(1.1,-0.52,1.10);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();

//Atas Tiang 3
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(0.7,-0.52,1.5);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();
     
//Atas Tiang 4
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(1.1,-0.52,1.5);
     glScalef(0.15,0.07,0.15);
     kubussolid();
     glPopMatrix();
     
//Atap
     glPushMatrix();
     glColor3f(0.3,0.2,0.0);
     glTranslatef(0.9,-0.503,1.3);
     glScalef(0.03,0.30,0.03);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (13.0,0.9,50,8);
     glPopMatrix();
     
//Tangga 1
     glPushMatrix();
     glColor3f(0.8,0.8,0.8);
     glTranslatef(0.6,-0.945,1.3);
     glScalef(0.1,0.2,0.5);
     kubussolid();
     glPopMatrix();
     
//Tangga 2
     glPushMatrix();
     glColor3f(0.7,0.7,0.7);
     glTranslatef(0.58,-0.962,1.3);
     glScalef(0.1,0.15,0.5);
     kubussolid();
     glPopMatrix();
     
//Tangga 3
     glPushMatrix();
     glColor3f(0.6,0.6,0.6);
     glTranslatef(0.56,-0.974,1.3);
     glScalef(0.1,0.1,0.5);
     kubussolid();
     glPopMatrix();
     
//Tangga 4
     glPushMatrix();
     glColor3f(0.5,0.5,0.5);
     glTranslatef(0.54,-0.987,1.3);
     glScalef(0.1,0.05,0.5);
     kubussolid();
     glPopMatrix();
//---------Akhir Tempat duduk taman---------
          
//--------LAMPU DI JALAN ---
//==============LAMPU JALAN kiri tengah
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-3.55,-0.79,0.05);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-3.5,-0.6,0.05);     
     glScalef(0.2,0.05,0.1);
     kubussolid();
     glPopMatrix();     
//LAMPU
     glPushMatrix();
     glTranslatef(-3.48,-0.615,0.05);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
//==============Akhir LAMPU JALAN kiri tengah

//==============LAMPU JALAN kiri bawah
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-3.55,-0.79,3.3);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-3.5,-0.6,3.3);
     glScalef(0.2,0.05,0.1);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(-3.48,-0.615,3.3);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
     //==============Akhir LAMPU JALAN kiri bawah
     
//==============LAMPU JALAN kiri atas
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-3.55,-0.79,-3.3);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-3.5,-0.6,-3.3);
     glScalef(0.2,0.05,0.1);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(-3.48,-0.615,-3.3);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
     //==============Akhir LAMPU JALAN kiri atas
     
//==============LAMPU JALAN kanan bawah
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(3.55,-0.79,3.3);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(3.5,-0.6,3.3);
     glScalef(0.2,0.05,0.1);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(3.48,-0.615,3.3);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
     //==============AKhir LAMPU JALAN kanan bawah
     
//==============LAMPU JALAN kanan tengah
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(3.55,-0.79,0.05);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(3.5,-0.6,0.05);
     glScalef(0.2,0.05,0.1);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(3.48,-0.615,0.05);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
     //==============AKhir LAMPU JALAN kanan tengah
     
//==============LAMPU JALAN kanan atas
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-0.25,-0.79,-3.3);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-0.3,-0.6,-3.3);
     glScalef(0.2,0.05,0.1);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(-0.32,-0.615,-3.3);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
     //==============Akhir LAMPU JALAN kanan atas
     
//==============LAMPU JALAN kanan atas tengah
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-0.25,-0.79,-0.3);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(-0.3,-0.6,-0.3);
     glScalef(0.2,0.05,0.1);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(-0.32,-0.615,-0.3);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
     //==============Akhir LAMPU JALAN kanan atas tengah
     
     
//==============LAMPU JALAN tengah bawah
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(0.95,-0.79,3.55);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(0.95,-0.6,3.5);
     glScalef(0.1,0.05,0.2);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(0.95,-0.615,3.48);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();

//==============LAMPU JALAN tengah bawah 2
//Bawah
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(1.75,-0.79,3.55);
     glScalef(0.04,0.8,0.04);
     kubussolid();
     glPopMatrix();
//Atas
     glPushMatrix();
     glColor3f(0.75,0.75,0.75);
     glTranslatef(1.75,-0.6,3.5);
     glScalef(0.1,0.05,0.2);
     kubussolid();
     glPopMatrix();
//LAMPU
     glPushMatrix();
     glTranslatef(1.75,-0.615,3.48);
     glScalef(0.055,0.055,0.055);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.4,40,40);
     glPopMatrix();
     //----------------Akhir LAMPU JALAN tengah bawah
     //---------------Akhir LAMPU DI JALAN----------------------------------------------
     
//-------------- mobil dijalan depan -------------------------------------------------------------
      for (float i=0;i<1; i++)
     {
         for (float j=0; j<1; j++)
         {
     glPushMatrix();
     glTranslatef(-0.0+(i/5),-0.89,0.1-(j/4));
     glRotatef(360.0,0.0,1.0,0.0);
     glScalef(0.15,0.15,0.1);
//BADAN MOBIL
     glPushMatrix();
     glTranslatef(0.0,1.0,33.05);
     glScalef(2.90,1.47,2.0);
     glColor3f(0.9,1.0,1.1);
     kubussolid();
     glColor3f(0.8,0.8,0.8);
     kubus();
     glPopMatrix();
     //AKHIR BADAN MOBIL
     
//KAP MOBIL
     glPushMatrix();
     glTranslatef(-1.13,1.0,33.05);
     glScalef(0.9,1.0,1.1);
     glColor3f(0.8,0.8,0.8);;
     kubussolid();
     glPopMatrix();
     //AKHIR KAP MOBIL
     
//JENDELA DEPAN
     glPushMatrix();
     glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid);glColor3f(0.1,0.1,1.0);
     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
     glEnable(GL_BLEND);
     glDepthMask(GL_TRUE);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE);
     glTranslatef(-1.25,1.0,33.15);
     glScalef(1.0,0.7,2.0);
     glRotatef(90,0.0,0.0,1.0); 
     kubussolid(); 
     glDisable(GL_BLEND);
     glPopMatrix();
     //AKHIR JENDELA
      
//RODA KIRI DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.30,1.0,41.95); 
     glColor3f(0.0,0.0,0.0);
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI DEPAN
     
//RODA KANAN DEPAN
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-1.30,1.0,40.70); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN DEPAN
     
//RODA KIRI BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-0.001,0.95,41.95); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KIRI BELAKANG
     
//RODA KANAN BELAKANG
     glPushMatrix();
     glScalef(0.8,0.8,0.8);
     glTranslatef(-0.0001,0.95,40.70); 
     torussolid(0.1,0.2,20,20);
     glPopMatrix();
//AKHIR RODA KANAN BELAKANG--------------------------------------------------------------
     
//LAMPU KIRI DEPAN
     glPushMatrix();
     glTranslatef(-1.30,1.0,33.70);
     glScalef(0.2,0.2,0.2);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.5,20,20);
     glPopMatrix();
//AKHIR LAMPU KIRI
     
//LAMPU KANAN DEPAN
     glPushMatrix();
     glTranslatef(-1.30,1.0,32.45);     
     glScalef(0.2,0.2,0.2);
     glColor3f(0.9,0.9,0.2);
     bolasolid(0.5,20,20);
     glPopMatrix();
     glPopMatrix();
     glPopMatrix();
     }
     }         
     //-------------------Pohon Dalam Taman -------------------------------
//tangkal
     glPushMatrix();
     glTranslatef(-2.55,-0.78,2.1);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
         
//pohon1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.85,2.1);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
//pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.75,2.1);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
//pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.65,2.1);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     //------------------- Pohon tengah  -------------------------------
//tangkal
     glPushMatrix();
     glTranslatef(-2.15,-0.78,2.1);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
         
//pohon1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.15,-0.85,2.1);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
//pohon kanan depan
//tangkal
     glPushMatrix();
     glTranslatef(1.1,-0.78,2.1);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.85,2.1);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
//pohon kanan belakang
//tangkal
     glPushMatrix();
     glTranslatef(1.1,-0.78,0.57);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.85,0.57);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
//pohon dalam1
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.75,0.57);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
//pohon dalam2
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(1.1,-0.65,0.57);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix(); 
     
//pohon kiri belakang
//tangkal
     glPushMatrix();
     glTranslatef(-2.55,-0.78,0.57);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
            
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.85,0.57);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
          
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.75,0.57);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.65,0.57);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
// pohon kiri belakang 2
     glPushMatrix();
     glTranslatef(-2.15,-0.78,0.57);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
            
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.15,-0.85,0.57);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
// pohon tengah
//tangkal
     glPushMatrix();
     glTranslatef(-2.05,-0.78,1.30);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
            
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.05,-0.85,1.30);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.15,-0.75,0.57);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
          
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.15,-0.65,0.57);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
// pohon tengah 2
//tangkal
     glPushMatrix();
     glTranslatef(-2.55,-0.78,1.30);
     glScalef(0.09,0.9,0.09);
     glColor3f(0.5,0.2,0.2);
     kubussolid();
     glPopMatrix();
            
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.55,-0.85,1.30);
     glScalef(0.3,1.30,0.3);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
          
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.15,-0.75,0.57);
     glScalef(0.290,1.10,0.290);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
     
     glPushMatrix();
     glColor3f(0.0,0.35,0.0);
     glTranslatef(-2.15,-0.65,0.57);
     glScalef(0.280,1.0,0.280);
     glRotatef(-90.0,1.0,0.0,0.0);
     cone (0.5,0.7,30,6);
     glPopMatrix();
//--------Akhir Pohon taman
   
//--------------- bunga di kolam --------------
     glPushMatrix();
     glTranslatef(2.0,-0.99,0.8);
     glScalef(0.09,0.01,0.03);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.08,-0.99,0.8);
     glScalef(0.09,0.01,0.03);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.04,-0.99,0.74);
     glScalef(0.03,0.01,0.09);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.04,-0.99,0.86);
     glScalef(0.03,0.01,0.09);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
//kelopak bunga     
     glPushMatrix();
     glTranslatef(2.04,-0.96,0.81);
     glScalef(0.05,0.05,0.05);
     glColor3f(1.0,0.0,0.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
      
//bunga kolam yg ke 2
     glPushMatrix();
     glTranslatef(2.4,-0.99,0.8);
     glScalef(0.09,0.01,0.03);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.48,-0.99,0.8);
     glScalef(0.09,0.01,0.03);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.44,-0.99,0.74);
     glScalef(0.03,0.01,0.09);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(2.44,-0.99,0.86);
     glScalef(0.03,0.01,0.09);
     glColor3f(1.0,1.0,1.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
//kelopak bunga
     glPushMatrix();
     glTranslatef(2.44,-0.96,0.81);
     glScalef(0.05,0.05,0.05);
     glColor3f(1.0,0.0,0.0);
     bolasolid(0.5,20,20);
     glPopMatrix();
     
     //GARIS PEMBATAS JALAN RAYA ------------------------------------------------------------------    
//garis tengah dalem bnget
i=-0.5;
 while(i>-3)
     {
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-0.50,-0.98,i);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     i=i-0.3;
   }
   
 //garis tengah dalem kiri
i=-0.5;
 while(i>-3)
     {
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.3,-0.98,i);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     i=i-0.3;
   }   
 //garis kiri bawah
 i=0.6;
 while(i<3)
     {
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(-3.3,-0.98,i);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     i=i+0.3;
   }   
 
  //garis kanan bawah
 i=0.3;
 while(i<3)
     {
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(3.3,-0.98,i);
     glScalef(0.05,0.02,0.25);
     kubussolid();
     glPopMatrix();
     i=i+0.3;
   }   
 
   //garis bawah tengah
 i=-0.4;
 while(i<3)
     {
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(i,-0.98,0.0);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix();
     i=i+0.3;
   }
 
 i=-3.0;
 while(i<-1)
     {
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(i,-0.98,0.0);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix();
     i=i+0.3;
   }
 // garis bawah atas sekali
  i=-3.0;
 while(i<-0.7)
     {
     glPushMatrix();
     glColor3f(1.0,1.0,1.0);
     glTranslatef(i,-0.98,-3.3);
     glScalef(0.25,0.02,0.05);
     kubussolid();
     glPopMatrix();
     i=i+0.3;
   }
     
//kursi pinggir jalan
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(0.50,-1.0,3.55);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(0.50,-1.0,3.55);
     glScalef(0.32,0.11,0.05);
     kubussolid();
     glPopMatrix();
     
//kursi pinggir jalan
     glPushMatrix();
     glColor3f(0.8f, 0.5f, 0.3f);
     glTranslatef(2.20,-1.0,3.55);
     glScalef(0.35,0.05,0.15);
     kubussolid();
     glPopMatrix(); 
     
     glPushMatrix();
     glColor3f(0.85f, 0.5f, 0.3f);
     glTranslatef(2.20,-1.0,3.55);
     glScalef(0.32,0.13,0.05);
     kubussolid();
     glPopMatrix();
     
     
//---------AKHIR gedung double  */
     glFlush();
     glutSwapBuffers();
     angle++;
}

//FUNGSI KEYBOARD
void keyboard (unsigned char key, int x, int y)
{
     float detik = 1000.0;
     const double time = glutGet(GLUT_ELAPSED_TIME) / detik;
     
     switch (key){
            case 'w':
            case 'W':
                 xrot += 1;
              if (xrot >90) 
              xrot -= 90;
            break;
            case 's':
            case 'S':
                  xrot -= 1;
              if (xrot < -5) 
              xrot += 5;
            break;
            case 'a':
            case 'A':
                 yrot += 1;
              if (yrot >360) 
              yrot -= 360;
            break;
            case 'd':
            case 'D':
                 yrot -= 1;
              if (yrot < -360)
              yrot += 360;
            //case 'q':
            //case 'Q':
            break;
            case 'f':
            case 'F':
                 putary -= 90;
              if (putary < -360)
              putary += 360;
            break;
            case 'h':
            case 'H':
                 putary += 90;
              if (putary >360) 
              putary -= 360;
            break;
            case 27:
                  //glutLeaveGameMode();
                 exit (0);
                }
     
}
void mouse(int klik, int state, int xx, int yy)
{
     
     switch(klik){
                  case GLUT_LEFT_BUTTON:
                       
                       if((putary==-270)||(putary==90))
                       {
                       pindahx  +=0.1f;
                       }
                       if((putary==180)||(putary==-180))
                       {
                       pindahy  -=0.1f;
                       }
                       if((putary==-90)||(putary==270))
                       {
                       pindahx  -=0.1f;
                       }
                       if((putary==0) || (putary==360) || (putary==-360))
                       {
                       pindahy  +=0.1f;
                       }
                  }
    switch(klik){
                  case GLUT_RIGHT_BUTTON:
                       
                       if((putary==-270)||(putary==90))
                       {
                       pindahx  -=0.1f;
                       }
                       if((putary==180)||(putary==-180))
                       {
                       pindahy  +=0.1f;
                       }
                       if((putary==-90)||(putary==270))
                       {
                       pindahx  +=0.1f;
                       }
                       if((putary==0) || (putary==360) || (putary==-360))
                       {
                       pindahy  -=0.1f;
                       }
                  }            
}
void ketik(int key, int xx, int yy)
{
     int mod;
     float fraksi = 0.1f;
          switch(key){
         case GLUT_KEY_F1:
              mod = glutGetModifiers();
              if(mod == (GLUT_ACTIVE_ALT)){
                     sumbux=1.0;
                     sumbuy=0.0;
                     sumbuz=0.0;
                     }
              break;
         case GLUT_KEY_F2:
              sumbux=0.0;
              sumbuy=1.0;
              sumbuz=0.0;
              break;
         case GLUT_KEY_F3:
              sumbux=0.0;
              sumbuy=0.0;
              sumbuz=1.0;
              break;
         case GLUT_KEY_LEFT:
              sudut -=0.01f;
              vektorx = sin(sudut);
              vektorz = -cos(sudut);
              break;
         case GLUT_KEY_RIGHT:
              sudut += 0.01f;
			  vektorx = sin(sudut);
			  vektorz = -cos(sudut);
			break;
         case GLUT_KEY_UP:
              x += vektorx * fraksi;
			  z += vektorz * fraksi;
			break;
         case GLUT_KEY_DOWN:
              x -= vektorx * fraksi;
			  z -= vektorz * fraksi;
         break; 
         case GLUT_KEY_PAGE_UP:
              xrot += 1;
              if (xrot >360) 
              xrot -= 360;
         break;
         case GLUT_KEY_PAGE_DOWN:
              xrot -= 1;
              if (xrot < -360) 
              xrot += 170;
         break;
         case GLUT_KEY_HOME:
              yrot -= 1;
              if (yrot < -360)
              yrot += 360;
         break;
         case GLUT_KEY_END:
              yrot += 1;
              if (yrot >360) 
              yrot -= 360;
         }
              
}

using namespace std;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutGameModeString( "1024×768:32@75" ); //the settings for fullscreen mode
    //glutEnterGameMode(); //set glut to fullscreen using the settings in the line above
    glutInitWindowSize(1010,690);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Program Tugas Besar");
    init();
    
    awan();


    glutDisplayFunc(display);
    glutReshapeFunc(bangun);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutSpecialFunc(ketik);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
