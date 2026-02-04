#ifdef DRONE_VEC
typedef struct
{
	float x,y,z;
} Vector3;
#else
#include "raylib.h"
#endif //DRONE_VEC


class Drone
{
	public:
		Drone();
		~Drone() = default;
		void apply_accel();
		void move(float timestep);
		Vector3 get_pos();
		void impulse();
	private:
		Vector3 pos;
		Vector3 vel;
		Vector3 acc;
		float mass;
};
