#include <raylib.h>

#define WIDTH 1280
#define HEIGHT 960

#define FRAMERATE 60
#define DT 1/FRAMERATE

int main()
{
	InitWindow(WIDTH,HEIGHT,"[ DRONE SIM - V-1.0]");
	if(!IsWindowReady())
	{
		return 1;
	}

	Camera3D camera = {0};
	camera.position = (Vector3){0.0f,10.0f,10.0f};
	camera.target = (Vector3){0,0,0};
	camera.up = (Vector3){0.0f,1.0f,0.0f};
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	SetTargetFPS(FRAMERATE);

	Vector3 sphere = {0,10.f,-10.f};

	while(!WindowShouldClose() && !IsKeyPressed(KEY_Q))
	{

		BeginDrawing();
		ClearBackground(WHITE);
		BeginMode3D(camera);

		DrawSphere(sphere,5,RED);

		sphere.y-= 1.*DT;


		DrawGrid(10,10.f);

		EndMode3D();
		DrawFPS(0,0);
		EndDrawing();
	}

	CloseWindow();
	return 0;


}
