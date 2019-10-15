#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

#include <iostream>
// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	//Main scene

	background.x = 216;
	background.y = 176;
	background.w = 545;
	background.h = 131;

	bath.x = 312;
	bath.y = 336;
	bath.w = 336;
	bath.h = 32;

	bath_water.x = 312;
	bath_water.y = 312;
	bath_water.w = 336;
	bath_water.y = 20;

	ground.x = 8;
	ground.y = 376;
	ground.w = 849;
	ground.h = 65;

}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading honda scene");

	graphics = App->textures->Load("honda_stage.png");

	// TODO 7: Enable the player module
	App->player->Enable();

	// TODO 0: trigger background music

	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{


	// Draw everything --------------------------------------
	//App->renderer->Blit(graphics, -150, 160, &ground);
	//App->renderer->Blit(graphics, 0, 25, &background, 1.0f);
	//App->renderer->Blit(graphics, 100, 145, &bath, 1.0f);
	App->renderer->Blit(graphics,100, 0, &bath_water, 1.0f);





	return UPDATE_CONTINUE;
}