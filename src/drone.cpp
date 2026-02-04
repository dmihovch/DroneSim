#include "../include/drone.hpp"
void Drone::apply_accel()
{
	acc = (Vector3){0,-9.8,0};
}

void Drone::move(float timestep)
{
	//this isn't correct atm
	vel.x+=acc.x * timestep;
	vel.y+=acc.y * timestep;
	vel.z+=acc.z * timestep;

	pos.x+=vel.x * timestep;
	pos.y+=vel.y * timestep;
	pos.z+=vel.z * timestep;

	if(pos.y <= 0)
	{
		pos.y = 100;
		vel = {0};
	}
}

Drone::Drone()
{
	pos = (Vector3){0,100,0};
	vel = (Vector3){0,0,0};
	acc = (Vector3){0,0,0};
}

Vector3 Drone::get_pos()
{
	return pos;
}



void Drone::impulse()
{
	vel.y+=15;
}
