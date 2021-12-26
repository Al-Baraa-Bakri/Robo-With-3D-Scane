#ifndef _LOADIMAGEFILE_H
#define _LOADIMAGEFILE_H

#include<Windows.h>
#include<stdio.h>
#include<gl/GL.h>
#include<GL/GLU.h>
#include<gl/glut.h>
#include<stdio.h>
#include<math.h>


class LoadTexture
{
public :
	static GLuint LoadTextureImageFile(const char *);
	static void FreeCreatedTexture(GLuint);
};




#endif