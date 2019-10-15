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
	bath.y = 316;
	bath.w = 336;
	bath.h = 52;

	water.frames.push_back({ 8, 448, 284, 8 });
	water.frames.push_back({ 296, 448, 284, 13 });
	water.frames.push_back({ 588, 448, 284, 18 });
	water.speed = 0.04f;

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

	App->player->Enable();
	App->audio->PlayMusic("../Game/honda.ogg");

	App->player->position.x = 100;
	App->player->position.y = 100;

	App->renderer->camera.x = App->renderer->camera.y = 0;



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
	App->renderer->Blit(graphics, -150, 160, &ground);
	App->renderer->Blit(graphics, 0, 25, &background);

	App->renderer->Blit(graphics, 100, 125, &bath);
	App->renderer->Blit(graphics, 100, 138, &(water.GetCurrentFrame()), 1.0f); // flag animation





	return UPDATE_CONTINUE;
}