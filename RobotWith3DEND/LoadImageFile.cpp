#include"LoadImageFile.h"

//load image & set it as a texture with dimension as 256*256

GLuint LoadTexture :: LoadTextureImageFile(const char * filename)
{
	GLuint texture = 0;
	int width, height;
	BYTE * data = NULL;
	FILE * file;

	// open texture data
	fopen_s(&file, filename, "rb");

	if (&file == NULL) return 0;

	// allocate buffer
	width = 256;
	height = 256;

	data = (BYTE*)malloc(width * height * 3);

	// read texture data
	fread(data, width * height * 3, 1, file);
	fclose(file);

	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	//  texture MIP maps
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_BGRA_EXT, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_TEXTURE_ENV_COLOR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// free buffer
	free(data);

	return texture;

}



void LoadTexture :: FreeCreatedTexture(GLuint texture)
{
	glDeleteTextures(1, &texture);
}
