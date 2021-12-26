#ifndef _DRAWSCENE_H
#define _DRAWSCENE_H

//declare GameScene class & functions which needs to draw
class GameScene
{
public:
	void Draw_OuterWall(GLuint);

	void Draw_InnerRoom_1(GLuint);

	void Draw_InnerRoom_2(GLuint,GLuint);



	void Draw_Roof(GLuint);

	void Draw_Floor(GLuint);



	void Draw_main_objects(GLuint);

	



};

extern float bust_angle_y; 
extern float zr; 
extern float yr;
extern float xr;
extern float yBox;
extern float zBox;
extern float zball; 
extern float angleRo;
extern float bust_angle_y;
extern float bust_angle_x ;
extern float right_arm_angle ;
extern float left_arm_angle ;
extern float right_forearm_angle;
extern float left_forearm_angle ;
extern float left_thigh_angle ;
extern float right_thigh_angle;
extern float right_leg_angle;
extern float left_leg_angle ;

#endif