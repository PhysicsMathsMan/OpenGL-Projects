#include <GL/freeglut.h>
#include <GL/gl.h>
#include<string.h>
#include<math.h>
int i,j,k,l;
void DrawTextXY(double x,double y,double z,double scale,char *s)
{
	
   int i,l=strlen(s);
   glPushMatrix();
   glTranslatef(x,y,z);
   glScalef(scale,scale,scale);
   for (i=0;i <l;i++)
      glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
   glPopMatrix();
}

void drawText(float x,float y,float r,float g,float b,char *s)
{
	int j=strlen(s);
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
	for(int i=0;i<j;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,s[i]);
	}

}

void drawText1(float x,float y,float r,float g,float b,char *s)
{
	int j=strlen(s);
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
	for(int i=0;i<j;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	}

}

void polygon(int x,int y,int width,int height)
{
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+width,y);
	glVertex2i(x+width,y+height);
	glVertex2i(x,y+height);
	glEnd();
}

void circle(GLfloat x, GLfloat y, GLdouble radius)
{
	float x2, y2;
	float angle;
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x,y);
	for (angle = 1.0; angle < 361.0f; angle += 0.2)
	{
		x2 = x + sin(angle)*radius;
		y2 = y + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void tree2(int x,int y)
{
	circle(x-5,y+100,35);
	circle(x-5,y+100,35);
	circle(x-30,y+120,35);
	circle(x-8,y+150,35);
	circle(x+40,y+100,35);
	circle(x+35,y+150,35);
	glColor3ub(184,134,11);
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+30,y);
	glVertex2i(x+28,y+80);
	glVertex2i(x+8,y+80);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(x+10,y+80);
	glVertex2i(x+28,y+80);
	glVertex2i(x+38,y+110);
	glVertex2i(x+28,y+110);
	glEnd();	
	glBegin(GL_POLYGON);
	glVertex2i(x+28,y+80);
	glVertex2i(x+8,y+80);
	glVertex2i(x-15,y+100);
	glVertex2i(x-15,y+110);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(x+28,y+80);
	glVertex2i(x+8,y+80);
	glVertex2i(x-15,y+100);
	glVertex2i(x-15,y+110);
	glEnd();
}

void cloud(int x,int y,int r,int i)
{	
	circle(x+i,y,r);
	circle(x+i,y,r);
	circle(x+10+i,y+30,r-10);
	circle(x+55+i,y+20,r+10);
	circle(x+100+i,y+25,r-5);
	circle(x+90+i,y,r+10);
	circle(x+120+i,y+15,r-10);
}

void tree(int x,int y,int width,int height)
{
	glBegin(GL_TRIANGLES);
	glVertex2i(x-45,y+40);
	glVertex2i(x+width+45,y+40);
	glVertex2f(x+(width/2),y+(height-10));
	glVertex2i(x-40,y+60);
	glVertex2i(x+width+40,y+60);
	glVertex2f(x+(width/2),y+height+30);
	glVertex2i(x-35,y+80);
	glVertex2i(x+width+35,y+80);
	glVertex2f(x+(width/2),y+height+50);
	glEnd();
	glColor3ub(139,69,19);
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+width,y);
	glVertex2i(x+width,y+40);
	glVertex2i(x,y+40);
	glEnd();
}


void tree1(int x,int y,int width,int height)
{
	glBegin(GL_TRIANGLES);
	glVertex2i(x-30,y+height);
	glVertex2i(x+width+30,y+height);
	glVertex2f(x+(width/2),y+height+30);
	glVertex2i(x-25,y+height+10);
	glVertex2i(x+width+25,y+height+10);
	glVertex2f(x+(width/2),y+height+30+10);
	glVertex2i(x-20,y+height+20);
	glVertex2i(x+width+20,y+height+20);
	glVertex2f(x+(width/2),y+height+30+20);
	glEnd();
	glColor3ub(139,69,19);
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+width,y);
	glVertex2i(x+width,y+height);
	glVertex2i(x,y+height);
	glEnd();
}

void grass(int x,int y,int width,int height)
{
	i=x;
	for(l=0;l<height;l++)
	{	
		for(k=0;k<width;k++)
		{
			glBegin(GL_TRIANGLES);
			glVertex2f(x,y);
			glVertex2f(x+10,y);
			glVertex2f(x+5,y+15);
			glVertex2f(x,y);
			glVertex2f(x+12,y);
			glVertex2f(x-5,y+10);
			glVertex2f(x-3,y);
			glVertex2f(x+10,y);
			glVertex2f(x+15,y+10);
			glEnd();
			x+=16;
		}
		y+=8;
		x=i;
	}
}

void homePage()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1,1,1);
	polygon(0,0,800,650);
	glColor3f(1,0,0);
	polygon(80,0,1,650);
	polygon(82,0,1,650);
	polygon(0,550,800,1);
	polygon(0,552,800,1);
	glColor3f(0,0,1);
	j=50;
	for(i=0;i<20;i++)
	{
		polygon(0,j,800,1);
		j+=25;
	}
	glColor3f(0.5,0,0);
	DrawTextXY(300,600,0,0.3,"DSI CAMPUS");
	DrawTextXY(301,600,0,0.3,"DSI CAMPUS");
	DrawTextXY(302,600,0,0.3,"DSI CAMPUS");
	DrawTextXY(200,570,0,0.2,"Simulated Using Computer Graphics");

	drawText(85,255,0,0,0,"Submitted By:");
	drawText1(85,227,0,0,0,"Manjunatha K");
	drawText1(85,202,0,0,0,"Rohit Yadav");
	drawText1(85,177,0,0,0,"Sangu");

	drawText1(83,77,0,0,0,"Press 1, 2 or 3");
	drawText1(83,53,0,0,0,"Press q to exit"); 
}

void contents()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1,1,1);
	polygon(0,0,800,650);
	glColor3f(1,0,0);
	polygon(80,0,1,650);
	polygon(82,0,1,650);
	polygon(0,550,800,1);
	polygon(0,552,800,1);
	glColor3f(0,0,1);
	j=50;
	for(i=0;i<20;i++)
	{
		polygon(0,j,800,1);
		j+=25;
	}


}
void autorikshsa(int k)
{
	glColor3f(0.2,0.2,0.2);
	circle(620-k,22,15);
	circle(620-k,22,15);
	glColor3f(0.1,0.1,0.1);
	circle(620-k,22,10);	
	glColor3f(0.2,0.2,0.2);
	circle(745-k,22,15);
	glColor3f(0.1,0.1,0.1);
	circle(745-k,22,10);
	glColor3ub(137,67,17);
	polygon(667-k,43,15,8);
	polygon(680-k,43,8,28);
	polygon(710-k,45,20,8);
	glColor3f(0.2,0.2,0.2);
	polygon(682-k,45,2,60);
	glColor3f(0.5,0,0);
	polygon(610-k,40,10,10);
	polygon(768-k,43,6,12);
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex2f(720-k,50);
	glVertex2f(770-k,50);
	glVertex2f(770-k,80);
	glVertex2f(760-k,95);
	glVertex2f(730-k,110);
	glVertex2f(720-k,110);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(640-k,105);
	glVertex2f(720-k,105);
	glVertex2f(720-k,110);
	glVertex2f(650-k,110);
	glEnd();
	glColor3f(0,0.2,0);
	polygon(720-k,25,50,25);
	polygon(645-k,25,80,6);
	polygon(675-k,25,15,20);
	glBegin(GL_POLYGON);
	glVertex2f(615-k,50);
	glVertex2f(615-k,40);
	glVertex2f(622-k,30);
	glVertex2f(628-k,26);
	glVertex2f(630-k,25);
	glVertex2f(645-k,25);
	glVertex2f(645-k,50);
	glEnd();
	glColor3ub(70,130,180);
	glBegin(GL_POLYGON);
	glVertex2f(645-k,105);
	glVertex2f(630-k,95);
	glVertex2f(625-k,90);
	glVertex2f(620-k,80);
	glVertex2f(615-k,70);
	glVertex2f(615-k,65);
	glVertex2f(615-k,50);
	glVertex2f(645-k,50);
	glEnd();
}

void entrance()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glColor3ub(224,255,255);
		glVertex2f(0,300);
		glVertex2f(800,300);
		glColor3ub(0,191,255);
		glVertex2f(800,650);
		glVertex2f(0,650);
	glEnd();	
	//path
	glColor3f(0.827450,0.827450,0.827450);
	polygon(0,0,1000,300);
	//-----------------------------------------------
	//behind library
	//-----------------------------------------------
	glColor3f(0.766,0.655,0.433);
	polygon(0,230,180,330);
	glBegin(GL_QUADS);
	glColor3f(0.7,0.6,0.4);
	glVertex2i(180,230);
	glVertex2i(360,290);
	glVertex2i(360,620);
	glVertex2i(180,560);
	glEnd();
	//stripes
	glColor3f(0.66,0.55,0.33);
	polygon(0,500,180,30);
	polygon(0,440,180,30);
	polygon(0,380,180,30);
	polygon(0,320,180,30);
	glBegin(GL_QUADS);
	glColor3f(0.6,0.5,0.3);
	glVertex2i(180,500);
	glVertex2i(180,530);
	glVertex2i(360,590);
	glVertex2i(360,560);	
	glVertex2i(180,440);
	glVertex2i(180,470);
	glVertex2i(360,530);
	glVertex2i(360,500);
	glVertex2i(180,380);
	glVertex2i(180,410);
	glVertex2i(360,470);
	glVertex2i(360,440);
	glVertex2i(180,320);
	glVertex2i(180,350);
	glVertex2i(360,410);
	glVertex2i(360,380);
	glEnd();
	//glass dividees
	i=30,j;
	for(j=0;j<5;j++)
	{
		glBegin(GL_LINES);
		glVertex2f(i,230);
		glVertex2f(i,560);
		glEnd();
		i+=180;
		glBegin(GL_LINES);
		glVertex2f(i,230);
		glVertex2f(i,620);
		glEnd();
		i-=150;
	}
	for(j=230;j<580;j+=30)
	{
		glBegin(GL_LINES);
		glVertex2f(0,j);
		glVertex2f(180,j);
		glEnd();
		
		glBegin(GL_LINES);
		glVertex2f(180,j);
		glVertex2f(360,j+60);
		glEnd();
	}
	//terrace
	glBegin(GL_QUADS);
	glColor3f(0.786,0.665,0.443);
	glVertex2i(0,560);
	glVertex2i(180,560);
	glVertex2i(360,620);
	glVertex2i(180,620);
	glEnd();
	glColor3ub(85,107,47);
	tree2(750,300);	
	glColor3f(0,0.5,0);
	grass(720,290,10,2);
	//-----------------------------------------------
	//library
	//-----------------------------------------------
	glColor3f(0.1,0.6,0.6);
	polygon(210,230,240,270);
	glBegin(GL_QUADS);
	glColor3f(0.0,0.46,0.46);
	glVertex2i(450,230);
	glVertex2i(700,290);
	glVertex2i(700,560);
	glVertex2i(450,500);
	glEnd();
	//blue sripes
	glColor3f(0.1,0.1,0.5);
	polygon(210,440,240,30);
	polygon(210,380,240,30);
	polygon(210,320,240,30);
	glBegin(GL_QUADS);
	glVertex2i(450,440);
	glVertex2i(450,470);
	glVertex2i(700,530);
	glVertex2i(700,500);
	glVertex2i(450,380);
	glVertex2i(450,410);
	glVertex2i(700,470);
	glVertex2i(700,440);
	glVertex2i(450,320);
	glVertex2i(450,350);
	glVertex2i(700,410);
	glVertex2i(700,380);
	glEnd();
	//glass divider
	glColor3f(0.4,0.4,0.6);
	i=250,j;
	for(j=1;j<6;j++)
	{
		glBegin(GL_LINES);
		glVertex2f(i,230);
		glVertex2f(i,500);
		glEnd();
		i+=240;
		glBegin(GL_LINES);
		glVertex2f(i,230+(j*9));
		glVertex2f(i,500+(j*12));
		glEnd();
		i-=200;
	}
	for(j=230;j<530;j+=30)
	{
		glBegin(GL_LINES);
		glVertex2f(210,j);
		glVertex2f(450,j);
		glVertex2f(450,j);
		glVertex2f(700,j+60);
		glEnd();
	}
	//door
	glColor3f(0.1,0.1,0.5);
	glBegin(GL_QUADS);
	glVertex2i(530,249);
	glVertex2i(610,269);
	glVertex2i(610,330);
	glVertex2i(530,310);
	//terrace
	glColor3f(0.0,0.66,0.66);
	glVertex2i(200,500);
	glVertex2i(450,500);
	glVertex2i(700,560);
	glVertex2i(450,560);
	glEnd();
	//gate
	//left part
	glColor3f(0.0,0.0,0.0);
	polygon(175,122,200,2);
	polygon(175,147,200,2);
	polygon(175,247,200,2);
	polygon(175,258,200,2);
	polygon(374,100,2,200);

	glColor3f(0.1,0.1,0.1);
	glBegin(GL_POLYGON);
	glVertex2i(160,100);
	glVertex2i(180,100);
	glVertex2i(175,260);
	glVertex2i(165,260);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(175,260);
	glVertex2i(180,280);
	glVertex2i(170,300);
	glVertex2i(160,280);
	glVertex2i(165,260);	
	glEnd();
	i=180;
	for(j=100;j<139;j++)
	{
		glBegin(GL_LINES);
		glVertex2f(i,100);
		glVertex2f(i,j+162);
		glEnd();
		i+=5;
	}
	//right part
	glColor3f(0.0,0.0,0.0);
	polygon(375,122,200,2);
	polygon(375,147,200,2);
	polygon(375,247,200,2);
	polygon(375,258,200,2);
	polygon(375,100,2,200);
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);
	glVertex2i(570,100);
	glVertex2i(590,100);
	glVertex2i(585,260);
	glVertex2i(575,260);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2i(585,260);
	glVertex2i(590,280);
	glVertex2i(580,300);
	glVertex2i(570,280);
	glVertex2i(575,260);	
	glEnd();
	i=380;
	for(j=140;j>101;j-=1)
		{
			glBegin(GL_LINES);
			glVertex2f(i,100);
			glVertex2f(i,j+160);
			glEnd();
			i+=5;
		}
	glColor3f(0.1,0.1,0.1);
	polygon(0,0,1000,70);
	//DSI board
	//-------------------------------------
	//pillers
	//-------------------------------------
	glColor3f(0.329412,0.329412,0.329412);
	polygon(100,100,50,400);
	polygon(600,100,50,400);
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);
	glVertex2i(100,100);
	glVertex2i(90,120);
	glVertex2i(90,480);
	glVertex2i(100,500);
	glVertex2i(650,100);
	glVertex2i(660,110);
	glVertex2i(660,480);
	glVertex2i(650,500);
	glEnd();
	glColor3f(0.658,0.658,0.658);
	glBegin(GL_POLYGON);
	glVertex2f(150,480);
	glVertex2f(190,510);
	glVertex2f(560,510);
	glVertex2f(560,450);
	glVertex2f(190,450);
	glVertex2f(150,410);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(560,510);
	glVertex2f(600,490);
	glVertex2f(600,430);
	glVertex2f(560,450);
	glEnd();
	drawText1(175,467,0.137255,0.137255,0.556863,"DAYANANDA SAGAR INSTITUTIONS");
	drawText1(176,468,0.137,0.137,0.556,"DAYANANDA SAGAR INSTITUTIONS");
	glColor3f(0,0.4,0);
	tree2(50,70);
	glColor3f(0,0.3,0);
	grass(0,70,10,1);	
}

void canveno(int l)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glColor3ub(224,255,255);
		glVertex2f(0,230);
		glVertex2f(800,230);
		glColor3ub(0,191,255);
		glVertex2f(800,650);
		glVertex2f(0,650);
	glEnd();
	glColor3ub(176,224,230);
	cloud(600,600,30,-l);
	glColor3ub(173,216,230);
	cloud(100,580,30,l);
	//path
	glColor3f(0.88,0.78,0.68);
	polygon(0,0,800,230);
	//trees
	glColor3f(0,0.5,0);
	tree2(50,230);
	glColor3ub(87,122,15);
	tree2(180,230);
	glColor3ub(107,142,35);
	tree(130,230,20,100);
	//medical dept
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.5,1.0);
	glVertex2i(240,230);;
	glVertex2i(680,230);
	glVertex2i(700,550);
	glColor3f(0.0,0.3,0.8);
	glVertex2i(200,600);
	glEnd();
	glColor3f(0.90,0.90,0.95);
	glBegin(GL_POLYGON);
	glVertex2i(280,230);
	glVertex2i(400,230);
	glVertex2i(400,580);
	glVertex2i(350,585);
	glVertex2i(350,500);
	glVertex2i(280,500);
	glEnd();
	//glass dividers
	glColor3f(0.4,0.4,0.8);
	i=240,j;
	for(j=300;j>255;j-=4)
	{
		glBegin(GL_LINES);
		glVertex2f(i,230);
		glVertex2f(i,j+300);
		glEnd();
		i+=40;	
	}
	float x1=238;
	for(j=260;j<620;j+=30)
	{
		glBegin(GL_LINES);
		glVertex2f(x1,j);
		glVertex2f(x1+470,j);
		glEnd();
		x1-=3.4;
	}
	//terrace
	glColor3ub(65,105,255);
	glBegin(GL_POLYGON);
	glVertex2i(700,550);
	glColor3f(0.0,0.4,0.9);
	glVertex2i(200,600);
	glVertex2i(300,620);
	glVertex2i(800,580);
	glEnd();
	glColor3f(0.90,0.90,0.95);
	polygon(560,230,120,90);
	glColor3f(0,0.4,0);
	grass(0,200,35,4);
	//CS board
	glColor3ub(184,134,11);
	polygon(110,210,10,40);
	glColor3ub(192,192,192);
	glBegin(GL_POLYGON);
	glVertex2f(125-70,310-60);
	glVertex2f(230-70,310-60);
	glVertex2f(230-70,330-60);
	glVertex2f(125-70,330-60);
	glVertex2f(120-70,320-60);
	glEnd();
	drawText(60,257,0,0,0,"Computer Science Dept.");
	glColor3ub(119,136,153);
	polygon(420,205,105,50);
	drawText(430,240,1,1,1,"     Dayanada Sagar");
	drawText(430,230,1,1,1,"         College Of");
	drawText(430,220,1,1,1,"DENTAL SCIENCE");
	//canveno
	glColor3f(0,0.2,0);
	grass(660,20,6,11);
	grass(620,172,3,3);
	glColor3f(0.154,0.311,0.782);//0.3823,0.3392,0.6459
	glBegin(GL_POLYGON);
	glColor3ub(65,105,225);
	glVertex2f(750,20);
	glVertex2f(750,650);
	glColor3ub(30,80,205);
	glVertex2f(650,500);
	glVertex2f(650,200);
	glEnd();
	glColor3ub(30,80,225);
	polygon(750,20,50,630);
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(660,180);
	glVertex2f(700,110);
	glVertex2f(700,238);
	glVertex2f(660,234);
	glEnd();
	//grass
	glColor3f(0,0.4,0);
	grass(0,0,10,17);
	glColor3f(0.88,0.78,0.68);
	glBegin(GL_POLYGON);
	glVertex2f(60,0);
	glVertex2f(180,200);
	glVertex2f(620,200);
	glVertex2f(708,0);
	glEnd();
}

void CSE()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glColor3ub(224,255,255);
		glVertex2f(0,0);
		glVertex2f(800,0);
		glColor3ub(0,191,255);
		glVertex2f(800,650);
		glVertex2f(0,650);
	glEnd();
	glColor3f(0.88,0.78,0.68);
	polygon(0,0,800,200);
	glColor3ub(4,107,4);
	grass(0,0,51,24);
	//cse bouilding
	glColor3f(0.7,0.4,0.3);
	polygon(0,150,680,410);
	glColor3f(0.71,0.48,0.38);
	glBegin(GL_POLYGON);
		glVertex2f(680,150);
		glVertex2f(740,180);
		glVertex2f(740,590);
		glVertex2f(680,560);
	glEnd();
	glColor3f(0.8137,0.5882,0.4784);
	glBegin(GL_POLYGON);
		glVertex2f(0,560);
		glVertex2f(680,560);
		glVertex2f(740,590);
		glVertex2f(50,590);
	glEnd();
	//cs board
	glColor3f(0.1372,0.1372,0.5568);
	polygon(280,520,305,36);
	//windows
	glColor3f(0.8274,0.8274,0.8274);
	polygon(565,435,80,80);
	polygon(565,300,80,100);
	polygon(565,185,80,80);
	polygon(400,435,130,80);
	polygon(400,300,130,100);
	polygon(230,435,130,80);
	polygon(230,300,130,100);
	polygon(30,435,160,80);
	polygon(30,300,160,100);
	glColor3f(0.7,0.4,0.3);
	polygon(100,300,10,220);
	polygon(290,300,10,220);
	polygon(460,300,10,220);
	polygon(600,185,10,340);
	polygon(0,375,680,10);
	polygon(0,490,680,10);
	//entrance
	glColor3f(0.75,0.75,0.75);
	polygon(280,150,220,130);
	glColor3f(0.9411,0.9725,0.999);
	polygon(300,150,100,100);
	//trees
	glColor3ub(1,102,1);
	tree2(730,120);
	glColor3ub(0,98,0);
	tree(20,130,30,100);		
	glColor3ub(65,87,27);
	tree2(160,0);		
	glColor3ub(75,97,37);
	tree(610,0,20,100);
	//path
	glColor3f(1,0.921,0.831);//1,0.921568,0.803921
	glBegin(GL_POLYGON);
	glVertex2i(200,0);
	glVertex2i(580,0);
	glVertex2i(505,150);
	glVertex2i(275,150);
	glEnd();
	//stairs
	glColor3f(0.76,0.67,0.51);
	polygon(200,0,380,10);
	polygon(205,20,370,10);
	polygon(215,40,350,10);
	//sides
	glColor3f(1,0.6941,0.52);
	glBegin(GL_QUADS);
	glVertex2i(580,0);
	glVertex2i(590,0);
	glVertex2i(505,190);
	glVertex2i(505,150);
	glVertex2i(190,0);
	glVertex2i(200,0);
	glVertex2i(275,150);
	glVertex2i(275,190);
	glEnd();
	drawText(400,544,1,1,1,"Department Of");
	drawText1(295,524,1,1,1,"Computer Science & Engg.");
}

void display1()
{
	for(int i=0;i<500;i+=3)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		for(GLint j=0;j<10000;j++)
			for(GLint h=0;h<1000;h++);
		entrance();
		autorikshsa(i);
		glFlush();
	}
	
}

void display2()
{
	for(int i=0;i<500;i+=3)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		for(GLint j=0;j<10000;j++)
			for(GLint h=0;h<1000;h++);
		canveno(i);
		glFlush();
	}
}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	CSE();
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	homePage();
	glFlush();
}

void menu(int value)
{
	 switch(value)
	 {
     case 1:display1();	     
		    break;
     case 2:display2();
		    break;
	 case 3:display3();
			break;
	 case 4:exit(0);
	 }
} 
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case '1':display1();
			break;
    case '2':display2();
			break;
	case '3':display3();
			break;
	case 't':
	case 'T':contents();
		break;
	case 'q': exit(0);	
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_SINGLE);
	glutInitWindowSize(800,650);
	glutCreateWindow("DSI CAMPUS");
	glClearColor(0.50,0.88,0.96,0);
	gluOrtho2D(0,800,0,650);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);	
	glutCreateMenu(menu);
	glutAddMenuEntry("Entrance",1);
   	glutAddMenuEntry("Canveno", 2);
	glutAddMenuEntry("CSE", 3);
	glutAddMenuEntry("Quit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}