#include "raylib.h"
#include "../include/drone.hpp"

#define WIDTH 1280
#define HEIGHT 960

#define FRAMERATE 60
#define DT 1./FRAMERATE



int main()
{
	InitWindow(WIDTH,HEIGHT,"[ DRONE SIM - V-1.0]");
	if(!IsWindowReady())
	{
		return 1;
	}

	Drone d = Drone();

	Camera3D camera = {0};
	camera.position = (Vector3){0.0f,10.0f,-20.0f};
	camera.target = d.get_pos();
	camera.up = (Vector3){0.0f,1.0f,0.0f};
	camera.fovy = 90.0f;
	camera.projection = CAMERA_PERSPECTIVE;


	SetTargetFPS(FRAMERATE);

	Vector3 sphere = {0,10.f,-10.f};

	// ToggleBorderlessWindowed();
	SetWindowFocused();

	while(!WindowShouldClose() && !IsKeyPressed(KEY_Q))
	{

		if(IsKeyPressed(KEY_W))
		{
			d.impulse();
		}

		UpdateCamera(&camera, CAMERA_THIRD_PERSON);

		BeginDrawing();
		ClearBackground(WHITE);
		BeginMode3D(camera);

		DrawPlane((Vector3){0,0,0},(Vector2){100,100},GREEN);
		DrawSphere(d.get_pos(), 2,RED);

		d.apply_accel();
		d.move(DT);
		camera.target = d.get_pos();
		DrawGrid(10,10.f);


		EndMode3D();
		DrawFPS(0,0);
		EndDrawing();
	}

	CloseWindow();
	return 0;


}
