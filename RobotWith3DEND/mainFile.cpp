
#include"LoadImageFile.h"

#include"DrawScene.h"

#include"DisplayScene.h"

float _Angle = 0.0;
float _moveLeftRight = 0.0;
float X = 6.0, Z = 5.0;
float X_2 = 0.0, Z_2 = -1.0;
float Y = 6.0;
int _moveForeBack = 0;
int moveUp = 0;
int _width, _height;


GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 0.0 };
GLfloat mat_shininess[] = { 10.0 };
GLfloat ball_light_position[] = { 35.5, 0.9, zball - 10, 0.0 };
GLfloat ro_light_position[] = { xr, yr , zr, 1.0 };
GLfloat scane_light_position[] = { 1 , 0 , -10 , 0.0 };
GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat position[] = { 5.0, 0.0, -20.0, 1.0 };
GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat local_view[] = { 0.0 };


void ballLights(void)
{

	glLightfv(GL_LIGHT0, GL_POSITION, ro_light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
}


void Initialize_OpenGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	

}

//function to move left or right directions
void Moving_Left_Right_Direction(float angle)
{
	X_2 = sin(angle);
	Z_2 = -cos(angle);
	glLoadIdentity();
	gluLookAt(X, Y, Z, X + X_2, Y, Z + Z_2, 0.0f, 1.0f, 0.0f);
}


//function to move forward or backward directions
void Moving_Foreword_Backword_Direction(int loc)
{
	X = X + loc*(X_2);
	Z = Z + loc*(Z_2);
	glLoadIdentity();
	gluLookAt(X, Y, Z, X + X_2, Y, Z + Z_2, 0.0f, 1.0f, 0.0f);
}


//main display scene function
void Display_Scene()
{
	if (_moveForeBack)
	{
		Moving_Foreword_Backword_Direction(_moveForeBack);
	}

	if (_moveLeftRight)
	{
		_Angle += _moveLeftRight;
		Moving_Left_Right_Direction(_Angle);
	}

	//clears the buffer & depth 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//call function from DisplayGameScene class which will be displayed
	DisplayGameScene::letsGoooo();

	glutSwapBuffers();
}
void end() {
	right_arm_angle -= 1.2f;
	if (right_arm_angle <= 0.0) {
		right_arm_angle = 0.0;	
	}
	glutPostRedisplay();

}
void closeBox() {
	yBox += 0.1;
	zBox += 0.1;
	right_arm_angle -= 1.2f;
	if (yBox > 9.0 || zBox > 14.0) {
		yBox = 9.0;
		zBox = 14.0;
		//glutIdleFunc(end);

	}
	if (right_arm_angle <= 0.0) {
		right_arm_angle = 0.0;
	}
	glutPostRedisplay();
}
void moveBall() {
	zball += 0.2f;
	left_leg_angle -= 5.2f;
	if (left_leg_angle < 0.0f) left_leg_angle = 0.0f;
	if (zball > 17.0) {
		zball = 17.0;
		glutIdleFunc(closeBox);

	}
	glutPostRedisplay();

}
void footShotHead (){
	left_leg_angle += 5.2f;
	if (left_leg_angle > 50.0f) {
		left_leg_angle = 50.0f;
		glutIdleFunc(moveBall);

		}
	glutPostRedisplay();

}
void footShotBack() {
	left_leg_angle -= 5.2f;
	if (left_leg_angle < -100.0f ) {
		glutIdleFunc(footShotHead);

	}
	glutPostRedisplay();

}
void openBox() {

	yBox -= 0.1;
	zBox -= 0.1;


	if (yBox < 0 || zBox < 6) {
		yBox = 0; 
		zBox = 6;
		glutIdleFunc(footShotBack);

	}
	glutPostRedisplay();

}
void leftRo() {
	angleRo += 0.8;
	if (angleRo > -180.0) {
		angleRo = -180.0;
		glutIdleFunc(openBox);
	}
	glutPostRedisplay();
}
void go4() {
	xr -= 0.8; 
	if (xr < 20) {
		xr = 20; 
		glutIdleFunc(leftRo);

	}

	glutPostRedisplay();

}
void rightRo3() {
	angleRo -= 0.8;
	if (angleRo < -270.0) {
		angleRo = -270.0;
		glutIdleFunc(go4);

	}
	glutPostRedisplay();

}
void go3() {
	ballLights(); 
	zr += 0.8; 

	if (zr > 0) {
		zr = 0; 
		glutIdleFunc(rightRo3);
	}
	glutPostRedisplay();

}
void armUp() {
	right_arm_angle += 1.2f;
	if (right_arm_angle >= 90.0) {
		right_arm_angle = right_arm_angle;
		glutIdleFunc(go3);
	}
	glutPostRedisplay();

}
void rightRo2() {
	angleRo -= 0.8;
	if (angleRo < -180.0) {
		angleRo = -180.0;
		glutIdleFunc(armUp);
	}
	glutPostRedisplay();
}
void go2() {
	xr += 0.4;
	if (xr > 90) {
		xr = 90;
		glutIdleFunc(rightRo2);

	}
	glutPostRedisplay();



}
void rightRo() {
	yr = 1;
	angleRo -= 0.8; 
	if (angleRo < -90.0) {
		angleRo = -90.0;
		glutIdleFunc(go2);
	}
	glutPostRedisplay();

}
void go() {
	zr = zr - 0.8;
	if (zr < -210.0) {
		zr = -210.0;
		glutIdleFunc(rightRo);
	}
	
	glutPostRedisplay();
}

//keyboard function
void Keyboard_function(unsigned char key, int x, int y)
{
	switch (key)
	{

	//Exit
	case 27:
		exit(EXIT_SUCCESS);
		break;
	//Main Move
	case 'A': 
		glutIdleFunc(go);
		break;


	//Right Arm
	case 'L': 
		right_arm_angle += 5.2f;
		break;
	case 'l': 
		right_arm_angle -= 5.2f;
		break;

    //Right Hand
	case 'K':
		right_forearm_angle += 5.2f;
		if (right_forearm_angle > 90.0f) right_forearm_angle = 90.0f;
		break;
	case 'k':
		right_forearm_angle -= 5.2f;
		if (right_forearm_angle < -90.0f) right_forearm_angle = -90.0f;
		break;
	//Left Arm
	case 'S':
		left_arm_angle += 5.2f;
		break;
	case 's':
		left_arm_angle -= 5.2f;
		break;
	//Left Hand
	case 'D':
		left_forearm_angle += 5.2f;
		if (left_forearm_angle > 90.0f) left_forearm_angle = 90.0f;
		break;
	case 'd':
		left_forearm_angle -= 5.2f;
		if (left_forearm_angle < -90.0f) left_forearm_angle = -90.0f;
		break;
	//Left Arm Foot
	case 'C':
		left_leg_angle += 5.2f;
		if (left_leg_angle > 100.0f) left_leg_angle = 100.0f;
		break;
	case 'c':
		left_leg_angle -= 5.2f;
		if (left_leg_angle < -100.0f) left_leg_angle = -100.0f;
		break;
	//Right Arm Foot
	case 'M':
		right_leg_angle += 5.2f;
		if (right_leg_angle > 100.0f) right_leg_angle = 100.0f;
		break;
	case 'm': 
		right_leg_angle -= 5.2f;
		if (right_leg_angle < -100.0f) right_leg_angle = -100.0f;
		break;
	//Right foot
	case 'X':
		right_thigh_angle -= 5.2f;
		break;
	case 'x': 
		right_thigh_angle += 5.2f;
		break;
	//Left Foot
	case 'Z': 
		left_thigh_angle -= 5.2f;
		break;
	case 'z':
		left_thigh_angle += 5.2f;
		break;
	}
	
}




//key pressed function
void Key_Pressed(int key, int x, int y)
{ 
	if (key == 65) {
		bust_angle_y += bust_angle_y + 10;

	}
	if (key == GLUT_KEY_LEFT)
	{
		_moveLeftRight = -0.03;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		_moveLeftRight = 0.03;
	}
	else if (key == GLUT_KEY_UP)
	{
		_moveForeBack = 1;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		_moveForeBack = -1;
	}
	else if (key == GLUT_KEY_UP && key == GLUT_KEY_LEFT)
	{
		_moveLeftRight = 0.01;
	}
	else if (key == GLUT_KEY_UP && key == GLUT_KEY_RIGHT)
	{
		_moveLeftRight = 0.01;
	}

	 if ( key == GLUT_KEY_PAGE_UP)
	{
		Y = Y + 0.5;
		
		glLoadIdentity();
		gluLookAt(X, Y, Z, X + X_2, Y, Z + Z_2, 0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
	}
	 else if (key == GLUT_KEY_PAGE_DOWN)
	 {
		 if (Y <= 0.2)
		 {
			 Y = 1.0;
		 }
		 else
		 {
			 Y = Y - 0.5;
			
			 glLoadIdentity();
			 gluLookAt(X, Y, Z, X + X_2, Y, Z + Z_2, 0.0f, 1.0f, 0.0f);
			 glutPostRedisplay();
		 }
	 }
	 
	
}


//key released function
void Key_Released(int key, int x, int y)
{
	
	switch (key)
	{
	case GLUT_KEY_LEFT:
		//if (_moveLeftRight < 0.0f)
			_moveLeftRight = 0.0f;
		break;

	case GLUT_KEY_RIGHT:
		//if (_moveLeftRight > 0.0f)
			_moveLeftRight = 0.0f;
		break;

	case GLUT_KEY_UP:
		//if (_moveForeBack > 0)
			_moveForeBack = 0;

		break;

	case GLUT_KEY_DOWN:
		//if (_moveForeBack < 0)
			_moveForeBack = 0;
		break;
	
	}
	
	
}



//reshape function
void Reshape_Function(int width, int height)
{
	if (height == 0)
		height = 1;

	_width = width;
	_height = height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, _width, _height);
	gluPerspective(45, 1.0*(width / height), 1.0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(X, Y, Z, X + X_2, Y, Z + Z_2, 0.0f, 1.0f, 0.0f);

}


void CallingAllCallBacks()
{
	//glutIgnoreKeyRepeat(1);
	glutDisplayFunc(Display_Scene);
	glutKeyboardFunc(Keyboard_function);
	glutSpecialFunc(Key_Pressed);
	glutSpecialUpFunc(Key_Released);
	glutIdleFunc(Display_Scene);
	glutReshapeFunc(Reshape_Function);
	Initialize_OpenGL();
}

//function that set fore & back color to console window



//main function
int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("3D Home Scene");
	CallingAllCallBacks();
	glutFullScreen();
	glutMainLoop();
	return(0);

}

