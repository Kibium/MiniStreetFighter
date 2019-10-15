#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleSceneHonda.h"

struct SDL_Texture;

class ModuleSceneKen : public Module
{
public:
	ModuleSceneKen( bool start_enabled = true);
	~ModuleSceneKen();

	bool Start();
	update_status Update();
	bool CleanUp();
	float timer, lastTime;


public:
	
	SDL_Texture* graphics = nullptr;
	bool ship_up;

	SDL_Rect ground;
	SDL_Rect background;
	SDL_Rect ship;
	SDL_Rect girlpos, man1pos, man2pos, man3pos, man4pos, man5pos;
	Animation flag, girl, man1, man2, man3, man4, man5;
};

#endif // __MODULESCENEKEN_H__