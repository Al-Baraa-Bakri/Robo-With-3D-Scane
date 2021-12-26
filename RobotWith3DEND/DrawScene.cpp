
#include"LoadImageFile.h"
#include"DrawScene.h"
#include "DisplayScene.h"
float lightturn, lightturn1;
float heading;

float bust_angle_y = 0.0f;
float bust_angle_x = 0.0f;
float right_arm_angle = 0.0f;
float left_arm_angle = 0.0f;
float right_forearm_angle = 0.0f;
float left_forearm_angle = 0.0f;
float left_thigh_angle = 0.0f;
float right_thigh_angle = 0.0f;
float right_leg_angle = 0.0f;
float left_leg_angle = 0.0f;
float yBox = 9.0;
float zBox = 14.0;
float zball = 2.0;


GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };

GLfloat mat_specularWHITE[] = { 255.0,255.0,255.0,1.0 };
GLfloat mat_ambientWHITE[] = { 255.0,255.0,255.0,1.0 };
GLfloat mat_diffuseWHITE[] = { 255.0,255.0,255.0,1.0 };
GLfloat mat_shininessWHITE[] = { 128.0 * 0.4 };

GLfloat mat_specularGRAY[] = { 0.75,0.75,0.75,1.0 };
GLfloat mat_ambientGRAY[] = { 0.5,0.5,0.5,1.0 };
GLfloat mat_diffuseGRAY[] = { 0.50,0.50,0.50,1.0 };
GLfloat mat_shininessGRAY[] = { 128.0 * 0.6 };

GLfloat mat_specularBLUE[] = { 0.75,0.75,0.75,1.0 };
GLfloat mat_ambientBLUE[] = { 0,0,1,1.0 };
GLfloat mat_diffuseBLUE[] = { 0.50,0.50,0.50,1.0 };
GLfloat mat_shininessBLUE[] = { 128.0 };

GLfloat mat_specularGREEN[] = { 0.633, 0.727811, 0.633,1.0 };
GLfloat mat_ambientGREEN[] = { 0.0215, 0.1745, 0.0215,1.0 };
GLfloat mat_diffuseGREEN[] = { 0.07568, 0.61424, 0.07568,1.0 };
GLfloat mat_shininessGREEN[] = { 128.0 };

GLfloat mat_specularYELLOW[] = { 0.75,0.75,0.75,1.0 };
GLfloat mat_ambientYELLOW[] = { 1,1,0,1.0 };
GLfloat mat_diffuseYELLOW[] = { 0.50,0.50,0.50,1.0 };
GLfloat mat_shininessYELLOW[] = { 128.0 };

GLfloat mat_specularRED[] = { 0.75,0.75,0.75,1.0 };
GLfloat mat_ambientRED[] = { 1.0,0.0,0.0,1.0 };
GLfloat mat_diffuseRED[] = { 0.50,0.50,0.50,1.0 };
GLfloat mat_shininessRED[] = { 128.0 };


GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_amb_diff[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
float zr = -20.0;
float yr = 0.0f;
float xr = 0.0f; 
float angleRo = 0.0f;

void SetMaterial(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{
	
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shin);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	
}
//define each function from file DrawScene.h from class GameScene


//draw floor


void GameScene::Draw_Floor(GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();

	for (float a = -10.0; a <= 170.0; a = a + 10.0)
	{ 
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.0 + a, 0.0, 10.0);
		glTexCoord2f(0.0, 1);
		glVertex3f(0.0 + a, 0.0, 0.0);
		glTexCoord2f(1, 1);
		glVertex3f(10.0 + a, 0.0, 0.0);
		glTexCoord2f(1, 0.0);
		glVertex3f(10.0 + a, 0.0, 10.0);
		glEnd();	
	}
	
	for (float b = -10.0; b <= 320.0; b += 10.0)
	{
		for (float a = -10.0; a <= 170.0; a = a + 10.0)
		{
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0 + a, 0.0, -(b - 10.0));
			glTexCoord2f(0.0, 6);
			glVertex3f(0.0 + a, 0.0, -b);
			glTexCoord2f(6 ,6 );
			glVertex3f(10.0 + a, 0.0, -b);
			glTexCoord2f(6, 0.0);
			glVertex3f(10.0 + a, 0.0, -(b - 10.0));
			glEnd();
		}
	}
	
	

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	LoadTexture::FreeCreatedTexture(texture);
}



//draw roof
void GameScene::Draw_Roof(GLuint texture)
{
	
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glPushMatrix();

		for (float a = -10.0; a <= 170.0; a = a + 10.0)
		{
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0.0 + a, 50.0, 20.0);
			glTexCoord2f(0.0, 2);
			glVertex3f(0.0 + a, 50.0, 0.0);
			glTexCoord2f(2 , 2);
			glVertex3f(10.0 + a, 50.0, 0.0);
			glTexCoord2f(2, 0.0);
			glVertex3f(10.0 + a, 50.0, 20.0);
			glEnd();
		}
		
		for (float b = -10.0; b <= 320.0; b += 10.0)
		{
			for (float a = -10.0; a <= 170.0; a = a + 10.0)
			{
				glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(0.0 + a, 50.0, -(b - 10.0));
				glTexCoord2f(0.0, 2);
				glVertex3f(0.0 + a, 50.0, -b);
				glTexCoord2f(2 , 2);
				glVertex3f(10.0 + a, 50.0, -b);
				glTexCoord2f(2, 0.0);
				glVertex3f(10.0 + a, 50.0, -(b - 10.0));
				glEnd();

			}
		}

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);

		LoadTexture::FreeCreatedTexture(texture);
	}



//draw outer wall
void GameScene::Draw_OuterWall(GLuint texture)
{
	
		glPushMatrix();


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);

		//wall 1

		
		for (float a = 0.0; a <= 180.0; a = a + 10.0)
		{
			glColor3f(0.7, 0.7, 0.5);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-10.0 + a, 0.0, 20.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(-10.0 + a, 50.0, 20.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(0.0 + a, 50.0, 20.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(0.0 + a, 0.0, 20.0);
			glEnd();
		}
		

		//Bad Way

		/*
		glColor3f(0.7, 0.7, 0.5);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-10.0, 0.0, 20.0);


		glTexCoord2f(0.0, 1.0);
		glVertex3f(-10.0, 50.0, 20.0);


		glTexCoord2f(1.0, 1.0);
		glVertex3f(180, 50.0, 20.0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(180, 0.0, 20.0);
		*/

		
		

		//wall 2
		for (float a = 0.0; a <= 320.0; a = a + 20.0)
		{
			glColor3f(0.7, 0.7, 0.5);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(180.0, 0.0, 0.0 - a);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(180.0, 50.0, 0.0 - a);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(180.0, 50.0, 20.0 - a);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(180.0, 0.0, 20.0 - a);
			glEnd();
		}

		//wall 3
		for (float a = 0.0; a <= 180.0; a = a + 10.0)
		{
			glColor3f(0.7, 0.7, 0.5);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(180.0 - a, 0.0, -320.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(180.0 - a, 50.0, -320.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(170.0 - a, 50.0, -320.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(170.0 - a, 0.0, -320.0);
			glEnd();
		}


		//wall 4
		for (float a = -10.0; a <= 320.0; a = a + 10.0)
		{
			glColor3f(0.7, 0.7, 0.5);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-10.0, 0.0, 0.0 - a);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(-10.0, 50.0, 0.0 - a);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(-10.0, 50.0, 10.0 - a);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(-10.0, 0.0, 10.0 - a);
			glEnd();

		}

		glDisable(GL_TEXTURE_2D);

		LoadTexture::FreeCreatedTexture(texture);

		glPopMatrix();
	}


//***********************************************************************
//draw inner room 1
void GameScene::Draw_InnerRoom_1(GLuint texture)
{
	glPushMatrix();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	
	//wall 1
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(10.0, 0.0, -5.0);
	glTexCoord2f(0.0, 2.0);
	glVertex3f(10.0, 50.0, -5.0);
	glTexCoord2f(2.0, 2.0);
	glVertex3f(12.0, 50.0, -5.0);
	glTexCoord2f(2.0, 0.0);
	glVertex3f(12.0, 0.0, -5.0);
	glEnd();
	

	//wall 2
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(12.0, 0.0, -5.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(12.0, 50.0, -5.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(12.0, 50.0, -12.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(12.0, 0.0, -12.0);
	glEnd();

	//wall 3
	for (float a = 0.0; a <= 100.0; a = a + 18.0)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(12.0 + a, 0.0, -12.0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(12.0 + a, 50.0, -12.0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(30.0 + a, 50.0, -12.0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(30.0 + a, 0.0, -12.0);
		glEnd();
	}
	
	

	//wall 4
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(120.0, 0.0, -12.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(120.0, 50.0, -12.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(120.0, 50.0, -5.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(120.0, 0.0, -5.0);
	glEnd();

	//wall 5
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(120.0, 0.0, -5.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(120.0, 50.0, -5.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(140.0, 50.0, -5.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(140.0, 0.0, -5.0);
	glEnd();
	
	//wall 6
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(140.0, 0.0, -5.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(140.0, 50.0, -5.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(140.0, 50.0, -15.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(140.0, 0.0, -15.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(140.0, 0.0, -15.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(140.0, 50.0, -15.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(140.0, 50.0, -22.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(140.0, 0.0, -22.0);
	glEnd();


	//wall 7
	glColor3f(0.8, 0.5, 0.4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(140.0, 0.0, -22.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(140.0, 50.0, -22.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(120.0, 50.0, -22.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(120.0, 0.0, -22.0);
	glEnd();

	//wall 8
	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(120.0, 0.0, -22.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(120.0, 50.0, -22.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(120.0, 50.0, -35.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(120.0, 0.0, -35.0);
	glEnd();

	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(120.0, 0.0, -35.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(120.0, 50.0, -35.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(120.0, 50.0, -55.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(120.0, 0.0, -55.0);
	glEnd();


	//wall 9
	glColor3f(0.7, 0.4, 0.3);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(120.0, 0.0, -55.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(120.0, 50.0, -55.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(100.0, 50.0, -55.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(100.0, 0.0, -55.0);
	glEnd();

	glColor3f(0.7, 0.4, 0.3);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(100.0, 0.0, -55.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(100.0, 50.0, -55.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(70.0, 50.0, -55.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(70.0, 0.0, -55.0);
	glEnd();

	//wall 10
	glColor3f(0.8, 0.5, 0.4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(70.0, 0.0, -55.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(70.0, 50.0, -55.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(70.0, 50.0, -75.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(70.0, 0.0, -75.0);
	glEnd();

	//wall 11
	glColor3f(0.8, 0.5, 0.4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(70.0, 0.0, -75.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(70.0, 50.0, -75.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(70.0, 50.0, -95.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(70.0, 0.0, -95.0);
	glEnd();
	
	//wall 12
	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(70.0, 0.0, -95.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(70.0, 50.0, -95.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(40.0, 50.0, -95.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(40.0, 0.0, -95.0);
	glEnd();

	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(40.0, 0.0, -95.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(40.0, 50.0, -95.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10.0, 50.0, -95.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(10.0, 0.0, -95.0);
	glEnd();



	//wall 13
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(10.0, 0.0, -5.0);
	glTexCoord2f(0.0, 2.0);
	glVertex3f(10.0, 50.0, -5.0);
	glTexCoord2f(2.0, 2.0);
	glVertex3f(10.0, 50.0, -25.0);
	glTexCoord2f(2.0, 0.0);
	glVertex3f(10.0, 0.0, -25.0);
	glEnd();
	

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(10.0, 0.0, -25.0);
	glTexCoord2f(0.0, 2.0);
	glVertex3f(10.0, 50.0, -25.0);
	glTexCoord2f(2.0, 2.0);
	glVertex3f(10.0, 50.0, -45.0);
	glTexCoord2f(2.0, 0.0);
	glVertex3f(10.0, 0.0, -45.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(10.0, 0.0, -55.0);
	glTexCoord2f(0.0, 2.0);
	glVertex3f(10.0, 50.0, -55.0);
	glTexCoord2f(2.0, 2.0);
	glVertex3f(10.0, 50.0, -95.0);
	glTexCoord2f(2.0, 0.0);
	glVertex3f(10.0, 0.0, -95.0);
	glEnd();



	glDisable(GL_TEXTURE_2D);

	LoadTexture::FreeCreatedTexture(texture);

	glPopMatrix();

}


//***********************************************************************************
//draw inner room 2
void GameScene::Draw_InnerRoom_2(GLuint texture,GLuint texture2)
{
	glPushMatrix();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);


	//wall 1
	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(140.0, 0.0, -35.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(140.0, 50.0, -35.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(135.0, 50.0, -35.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(135.0, 0.0, -35.0);
	glEnd();
	
	//wall 2
	glColor3f(0.8, 0.5, 0.4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(135.0, 0.0, -35.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(135.0, 50.0, -35.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(135.0, 50.0, -55.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(135.0, 0.0, -55.0);
	glEnd();

	glColor3f(0.8, 0.5, 0.4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(135.0, 0.0, -55.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(135.0, 50.0, -55.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(135.0, 50.0, -70.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(135.0, 0.0, -70.0);
	glEnd();
	
	//wall 3
	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(135.0, 0.0, -70.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(135.0, 50.0, -70.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(110.0, 50.0, -70.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(110.0, 0.0, -70.0);
	glEnd();

	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(110.0, 0.0, -70.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(110.0, 50.0, -70.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(85.0, 50.0, -70.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(85.0, 0.0, -70.0);
	glEnd();
	

	//wall 4
	glColor3f(0.8, 0.5, 0.4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(85.0, 0.0, -70.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(85.0, 50.0, -70.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(85.0, 50.0, -90.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(85.0, 0.0, -90.0);
	glEnd();

	glColor3f(0.8, 0.5, 0.4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(85.0, 0.0, -90.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(85.0, 50.0, -90.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(85.0, 50.0, -110.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(85.0, 0.0, -110.0);
	glEnd();
	
	//wall 5
	glColor3f(1.0, 0.7, 0.6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(85.0, 0.0, -110.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(85.0, 50.0, -110.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(50.0, 50.0, -110.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(50.0, 0.0, -110.0);
	glEnd();

	//wall 6
	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(50.0, 0.0, -110.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(50.0, 50.0, -110.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(50.0, 50.0, -140.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(50.0, 0.0, -140.0);
	glEnd();
	
	//wall 7
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(50.0, 0.0, -140.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(50.0, 50.0, -140.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(70.0, 50.0, -140.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(70.0, 0.0, -140.0);
	glEnd();
	

	//wall 8
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(70.0, 0.0, -140.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(70.0, 50.0, -140.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(70.0, 50.0, -160.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(70.0, 0.0, -160.0);
	glEnd();
	
	

	//wall 10
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(110.0, 0.0, -200.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(110.0, 50.0, -200.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(140.0, 50.0, -200.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(140.0, 0.0, -200.0);
	glEnd();
	

	//wall 11
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(140.0, 0.0, -200.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(140.0, 50.0, -200.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(140.0, 50.0, -195.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(140.0, 0.0, -195.0);
	glEnd();
	
	//wall 12
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(140.0, 0.0, -195.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(140.0, 50.0, -195.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(110.0, 50.0, -195.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(110.0, 0.0, -195.0);
	glEnd();

	//wall 13
	for (float a = 0.0; a <= 100.0; a += 10.0)
	{
		glColor3f(0.8, 0.8, 0.8);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(110.0, 0.0, -195.0 + a);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(110.0, 50.0, -195.0 + a);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(110.0, 50.0, -185.0 + a);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(110.0, 0.0, -185.0 + a);
		glEnd();
	}
	
	//wall 14
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(110.0, 0.0, -85.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(110.0, 50.0, -85.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(140.0, 50.0, -85.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(140.0, 0.0, -85.0);
	glEnd();

	//wall 15
	for (float a = 0.0; a <= 40.0; a += 10.0)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(140.0, 0.0, -85.0 + a);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(140.0, 50.0, -85.0 + a);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(140.0, 50.0, -75.0 + a);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(140.0, 0.0, -75.0 + a);
		glEnd();
	}

	glDisable(GL_TEXTURE_2D);

	LoadTexture::FreeCreatedTexture(texture);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture2);

	//wall 9
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(70.0, 0.0, -160.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(70.0, 50.0, -160.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(110.0, 50.0, -200.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(110.0, 0.0, -200.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	LoadTexture::FreeCreatedTexture(texture2);

	glPopMatrix();

}



//***********************************************************************************


//draw main objects
void GameScene::Draw_main_objects(GLuint texture)
{
	



	
	//Ball
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glColor3ub(0, 0, 0);
	glScalef(1.0, 1.3, 1.0);
	glTranslatef(35.5, 0.9, zball);
	glutSolidSphere(0.8, 10, 10);
	glPopMatrix();




	//draw 3 wood boxes

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	

	for (float a = 0.0; a <= 60.0; a += 30.0)
	{
		if (a == 0.0) {
			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(30.0 + a, yBox, zBox);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(40.0 + a, yBox, zBox);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(40.0 + a, 0.1, 14.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(30.0 + a, 0.1, 14.0);
			glEnd();

		} 
		else {
			glColor3f(1, 1, 1);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);
			glVertex3f(30.0 + a, 9.0, 14.0);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(40.0 + a, 9.0, 14.0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(40.0 + a, 0.1, 14.0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(30.0 + a, 0.1, 14.0);
			glEnd();
			//Ball
			//glScalef(0.3, 2.0, 0.5);	
		}
		
	

		glColor3f(0.7, 1, 1);
		
		glBegin(GL_POLYGON);
		
		glTexCoord2f(0.0, 0.0);
		glVertex3f(30.0 + a, 9.0, 14.0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(40.0 + a, 9.0, 14.0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(40.0 + a, 9.0, 19.8);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(30.0 + a, 9.0, 19.8);
		glRotatef(-180.0, 1.0, 0.0, 0.0);
		glEnd();
	

		glColor3f(0.7, 1, 1);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(30.0 + a, 9.0, 14.0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(30.0 + a, 9.0, 19.8);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(30.0 + a, 0.1, 19.8);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(30.0 + a, 0.1, 14.0);
		glEnd();

		glColor3f(0.7, 1, 1);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(40.0 + a, 9.0, 14.0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(40.0 + a, 9.0, 19.8);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(40.0 + a, 0.1, 19.8);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(40.0 + a, 0.1, 14.0);
		glEnd();
	}
	glPopMatrix();
	

	//Robot
	

	
	
	glPushMatrix();
	glScalef(1.8, 2.0, 1.0);
	glTranslatef(xr, 4, zr);

	glRotatef(angleRo , 0.0f, yr , 0.0f);

	
	glLightfv(GL_LIGHT0, GL_POSITION, ro_light_position);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


	
	
	




	//Bust

	glPushMatrix();
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3f(1.0, 0, 0);
	glScalef(1.8, 1.0, 1.0);
	glutSolidSphere(0.6, 10, 5);
	glTranslatef(0.0, -0.75, 0.0);
	


	
	glTranslatef(0, 0.3, 0);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(255, 255, 255);
	glutSolidSphere(0.5, 5, 5);

	glScalef(1.0, 0.2, 1.0);

	//Head
	SetMaterial(mat_specularYELLOW, mat_ambientYELLOW, mat_diffuseYELLOW, mat_shininessYELLOW);
	glColor3ub(255, 255, 255);
	glTranslatef(0, 7, 0);
	glScalef(0.3, 2.0, 0.5);
	//glScalef(1.0, 1.3, 1.0);
	glutSolidSphere(0.9, 10, 10);

	glTranslatef(0.0, 0.2, 0.2);
	
	glPopMatrix();



	//Right Hand

	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(right_arm_angle, 1, 0, 0);
	glTranslatef(0, -0.25, 0);


	//Top Thing

	glPushMatrix();
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glTranslatef(-1.1, 0.25, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.5, 20, 20);


	//Arm

	glTranslatef(0.0, -1.10, 0.0);
	glScalef(0.5, 1.5, 0.5);
	SetMaterial(mat_specularWHITE, mat_ambientWHITE, mat_diffuseWHITE, mat_shininessWHITE);
	glColor3ub(0, 0, 255);
	glutSolidCube(1.0);

	glPopMatrix();



	//Bottom Thing

	glPushMatrix();
	glTranslatef(1.25, -0.7, 0);
	glRotatef(right_forearm_angle, 1, 0, 0);
	glTranslatef(-1.25, 0.7, 0);
	glTranslatef(-1.1, -0.7, 0.0);
	glScalef(0.5, 0.5, 0.5);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.4, 20, 20);



	//Hand

	glTranslatef(0.0, -1.3, 0.0);
	glScalef(0.8, 2.0, 1.0);
	SetMaterial(mat_specularRED, mat_ambientRED, mat_diffuseRED, mat_shininessRED);
	glColor3ub(255, 0, 0);
	glutSolidCube(1.0);



	//Finger
	glScalef(.5, 1.0, 1.0);
	glTranslatef(0.0, -0.4, 0.0);
	glutSolidCube(.5);

	//Finger Of Finger :)
	glTranslatef(0.0, -0.25, 0.0);
	glutSolidCube(.3);
	glPopMatrix();
	glPopMatrix();


	//Left Hand

	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glRotatef(left_arm_angle, 1, 0, 0);
	glTranslatef(0, -0.25, 0);
	glPushMatrix();

	//Top Thing
	glTranslatef(1.1, 0.25, 0.0);
	glScalef(0.5, 0.5, 0.5);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.5, 20, 20);


	//Arm
	glTranslatef(0.0, -1.10, 0.0);
	glScalef(0.5, 1.5, 0.5);
	SetMaterial(mat_specularWHITE, mat_ambientWHITE, mat_diffuseWHITE, mat_shininessWHITE);
	glColor3ub(0, 0, 255);
	glutSolidCube(1.0);
	glPopMatrix();


	//Bottom Thing
	glPushMatrix();
	glTranslatef(1.25, -0.7, 0);
	glRotatef(left_forearm_angle, 1, 0, 0);
	glTranslatef(-1.25, 0.7, 0);
	glTranslatef(1.1, -0.7, 0.0);
	glScalef(0.5, 0.5, 0.5);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.4, 20, 20);


	//Hand
	glTranslatef(0.0, -1.3, 0.0);
	glScalef(0.8, 2.0, 1.0);
	SetMaterial(mat_specularRED, mat_ambientRED, mat_diffuseRED, mat_shininessRED);
	glColor3ub(255, 0, 0);
	glutSolidCube(1.0);

	//Finger
	glScalef(.5, 1.0, 1.0);
	glTranslatef(0.0, -0.4, 0.0);
	glutSolidCube(.5);

	//Finger Of Finger :)
	glTranslatef(0.0, -0.25, 0.0);
	glutSolidCube(.3);
	glPopMatrix();

	glPopMatrix();



	//Center

	glPushMatrix();
	SetMaterial(mat_specularYELLOW, mat_ambientYELLOW, mat_diffuseYELLOW, mat_shininessYELLOW);
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 2.0, 1.0);
	glutSolidCube(0.5);
	glPopMatrix();


	// LEG


	//Top Thing



	glPushMatrix();
	glTranslatef(-0.3, -1, 0.0);
	glRotatef(right_thigh_angle, 1.0, 0.0, 0.0);
	glTranslatef(0.3, 1.2, 0.0);
	glPushMatrix();


	
	glTranslatef(-0.3, -1.2, 0.0);
	glScalef(2.0, 2.0, 2.0);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.1, 20, 20);



	//Arm
	glTranslatef(0.0, -0.3, 0.0);
	glScalef(0.5, 1.5, 0.5);
	SetMaterial(mat_specularWHITE, mat_ambientWHITE, mat_diffuseWHITE, mat_shininessWHITE);
	glColor3ub(255, 255, 255);
	glutSolidCube(0.3);
	glPopMatrix();


	//Bottom Thing

	glPushMatrix();
	glTranslatef(-0.3, -2.3, 0.0);
	glRotatef(right_leg_angle, 1.0, 0.0, 0.0);
	glTranslatef(0.3, 2.3, 0.0);
	glTranslatef(-0.3, -2.3, 0.0);
	glScalef(2.0, 1.3, 2.0);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.1, 20, 20);


	//Foot

	glTranslatef(0.0, -0.5, 0.0);
	glScalef(0.5, 2.0, 0.5);
	SetMaterial(mat_specularBLUE, mat_ambientBLUE, mat_diffuseBLUE, mat_shininessBLUE);
	glColor3ub(0, 0, 255);
	glutSolidCube(0.5);

	//o-o

	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glTranslatef(0, -0.3, 0);
	glScalef(2.0, 1.0, 2.0);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(255, 0, 0);
	glutWireSphere(0.1, 20, 20);

	glPopMatrix();
	glPopMatrix();


	/*--------------------LEFT THIGH & LEG--------*/


	//Top Thing
	glPushMatrix();
	glTranslatef(0.3, -1, 0.0);
	glRotatef(left_thigh_angle, 1.0, 0.0, 0.0);
	glTranslatef(-0.3, 1.2, 0.0);
	glPushMatrix();
	glTranslatef(0.3, -1.2, 0.0);
	glScalef(2.0, 2.0, 2.0);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.1, 20, 20);



	//Arm

	glTranslatef(0.0, -0.3, 0.0);
	glScalef(0.5, 1.5, 0.5);
	SetMaterial(mat_specularWHITE, mat_ambientWHITE, mat_diffuseWHITE, mat_shininessWHITE);
	glColor3ub(255, 255, 255);
	glutSolidCube(0.3);
	glPopMatrix();



	//Bottom Thing
	glPushMatrix();
	glTranslatef(0.3, -2.3, 0.0);
	glRotatef(left_leg_angle, 1.0, 0.0, 0.0);
	glTranslatef(-0.3, 2.3, 0.0);
	glTranslatef(0.3, -2.3, 0.0);
	glScalef(2.0, 1.3, 2.0);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(128, 128, 128);
	glutSolidSphere(0.1, 20, 20);

	glTranslatef(0.0, -0.5, 0.0);
	glScalef(0.5, 2.0, 0.5);
	SetMaterial(mat_specularBLUE, mat_ambientBLUE, mat_diffuseBLUE, mat_shininessBLUE);
	glColor3ub(0, 0, 255);
	glutSolidCube(0.5);

	//foot
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glTranslatef(0, -0.3, 0);
	glScalef(2.0, 1.0, 2.0);
	SetMaterial(mat_specularGRAY, mat_ambientGRAY, mat_diffuseGRAY, mat_shininessGRAY);
	glColor3ub(255, 0, 0);
	glutWireSphere(0.1, 20, 20);

	
	//glutSolidCube(0.5);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glPopMatrix();
}

