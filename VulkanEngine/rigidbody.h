#pragma once

#include <vector>

enum Collider { box, ball, mesh };

class Rigidbody {
public:
	/* --- Physics Data --- */
	glm::vec3 velocity{ 0.f, 0.f, 0.f };
	glm::vec3 acceleration{ 0.f, 0.f, 0.f };
	/* --- Physics Properties --- */
	float mass = 1;
	float drag = 0;
	float angular_drag = 0;
	/* --- Collider --- */
	Collider shape = box;
	glm::vec3 collider_size{ 1.0f, 1.0f, 1.0f };
	/* --- Object Locking ---
	// 0 = unlocked, 1 = locked */
	glm::vec3 position_lock{ 0, 0, 0 };
	glm::vec3 rotation_lock{ 0, 0, 0 };
	/* --- Other Properties --- */
	float gravity_multiplier = 1;

	Rigidbody(float mass, Collider shape) {
		this->mass = mass;
		this->shape = shape;
	}

	glm::vec3 force() {
		return mass * acceleration;
	}

private:
	
};
