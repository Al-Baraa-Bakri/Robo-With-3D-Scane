
#include"LoadImageFile.h"

#include"DrawScene.h"

#include"DisplayScene.h"


//define function from class DisplayGameScene()
//call all function which wants to draw from class GameScene
void DisplayGameScene::letsGoooo()
{
	    GameScene gs;
		
		gs.Draw_OuterWall(LoadTexture::LoadTextureImageFile("textures/plain2.bmp"));
		gs.Draw_InnerRoom_1(LoadTexture::LoadTextureImageFile("textures/blocks.bmp"));
		gs.Draw_InnerRoom_2(LoadTexture::LoadTextureImageFile("textures/blocks.bmp"), LoadTexture::LoadTextureImageFile("textures/blocks2.bmp"));
		gs.Draw_Roof(LoadTexture::LoadTextureImageFile("textures/plain.bmp"));
		gs.Draw_Floor(LoadTexture::LoadTextureImageFile("textures/blocks3.bmp"));
		gs.Draw_main_objects(LoadTexture::LoadTextureImageFile("textures/roughwood.bmp"));
}
