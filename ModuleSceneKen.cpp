#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"
#include <iostream>

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneKen::ModuleSceneKen(bool start_enabled) : Module(start_enabled)
{
	//Main scene
	{
		// ground
		ground.x = 8;
		ground.y = 391;
		ground.w = 896;
		ground.h = 72;

		// TODO 2 : setup the foreground (red ship) with
		// coordinates x,y,w,h from ken_stage.png

		// Background / sky
		background.x = 72;
		background.y = 208;
		background.w = 768;
		background.h = 176;

		//Ship

		ship.x = 9;
		ship.y = 23;
		ship.w = 526;
		ship.h = 204;

		// flag animation
		flag.frames.push_back({ 848, 208, 40, 40 });
		flag.frames.push_back({ 848, 256, 40, 40 });
		flag.frames.push_back({ 848, 304, 40, 40 });
		flag.speed = 0.08f;

		// TODO 4: Setup Girl Animation from coordinates from ken_stage.png

		girlpos.x = 191;
		girlpos.y = 105;

		girl.frames.push_back({ 624, 16, 32, 56 });
		girl.frames.push_back({ 624, 80, 32, 56 });
		girl.frames.push_back({ 624, 144, 32, 56 });
		girl.speed = 0.04;
	}
	
	//Next Scene
	/*App->scene_honda->background.x = 120;
	App->scene_honda->background.y = 176;
	App->scene_honda->background.w = 639;
	App->scene_honda->background.h = 129;

	App->scene_honda->ground*/
	



	//?????
	//App->scene_honda->Disable();
	//nextScene = App->scene_honda;
	//if (App->scene_honda != nullptr);
	//cout << App->scene_honda->IsEnabled() << endl;

}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("ken_stage.png");


	// TODO 7: Enable the player module
	App->player->Enable();

	// TODO 0: trigger background music
	
	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	// TODO 5: make sure the ship goes up and down

	// Draw everything --------------------------------------
	// TODO 1: Tweak the movement speed of the sea&sky + flag to your taste
	App->renderer->Blit(graphics, 0, 0, &background, 1.0f); // sea and sky
	App->renderer->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 1.0f); // flag animation
	
	// TODO 3: Draw the ship. Be sure to tweak the speed.
	App->renderer->Blit(graphics, 0, 0, &ship, 1.0f); // sea and sky

	timer = SDL_GetTicks() / 1000;

	if (ship.y >= 29)
		ship_up = false;

	if (ship.y <= 23)
		ship_up = true;



	if (timer > lastTime) {
		if (ship_up) {
			ship.y += 3;
			girlpos.y -= 3;

		}

		else {
			ship.y -= 3;
			girlpos.y += 3;
		}
		lastTime = timer;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
		App->scene_ken->Disable();
		App->fade->FadeToBlack(App->scene_honda, nullptr, 3.0f);

	}


	// TODO 6: Draw the girl. Make sure it follows the ship movement!
	App->renderer->Blit(graphics, girlpos.x, girlpos.y, &(girl.GetCurrentFrame()), 1.0f);
	App->renderer->Blit(graphics, 0, 170, &ground);

	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	// using FadeToBlack module

	return UPDATE_CONTINUE;
}