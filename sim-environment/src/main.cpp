#include <raylib.h>

#define WIDTH 1280
#define HEIGHT 960

#define FRAMERATE 60
#define DT 1/FRAMERATE

class Drone
{
	public:
		Drone();
		~Drone();
		void apply_accel();
		void move();
	private:
		Vector3 pos;
		Vector3 vel;
		Vector3 acc;
		float mass;
};

void Drone::apply_accel()
{
	acc = (Vector3){0,-9.8,0};
}

void Drone::move()
{
	//this isn't correct atm
	vel.x+=acc.x * DT;
	vel.y+=acc.y * DT;
	vel.z+=acc.z * DT;

	pos.x+=vel.x * DT;
	pos.y+=vel.y * DT;
	pos.z+=vel.z * DT;
}

Drone::Drone()
{
	pos = (Vector3){0,10,0};
	vel = (Vector3){0,0,0};
	acc = (Vector3){0,0,0};
}

int main()
{
	InitWindow(WIDTH,HEIGHT,"[ DRONE SIM - V-1.0]");
	if(!IsWindowReady())
	{
		return 1;
	}

	Camera3D camera = {0};
	camera.position = (Vector3){0.0f,10.0f,-20.0f};
	camera.target = (Vector3){0,10,0};
	camera.up = (Vector3){0.0f,1.0f,0.0f};
	camera.fovy = 90.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Drone d = Drone();

	SetTargetFPS(FRAMERATE);

	Vector3 sphere = {0,10.f,-10.f};

	// ToggleBorderlessWindowed();
	SetWindowFocused();

	while(!WindowShouldClose() && !IsKeyPressed(KEY_Q))
	{

		UpdateCamera(&camera, CAMERA_THIRD_PERSON);

		BeginDrawing();
		ClearBackground(WHITE);
		BeginMode3D(camera);

		DrawPlane((Vector3){0,0,0},(Vector2){100,100},GREEN);
		DrawSphere(camera.target, 2,RED);


		DrawGrid(10,10.f);

		EndMode3D();
		DrawFPS(0,0);
		EndDrawing();
	}

	CloseWindow();
	return 0;


}
