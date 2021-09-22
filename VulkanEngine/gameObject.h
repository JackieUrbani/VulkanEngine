#pragma once

#include <memory>
#include "glm/gtc/matrix_transform.hpp"

#include "model.h"

struct TransformComponent {
	glm::vec3 translation{};
	glm::vec3 scale{ 1.f, 1.f, 1.f };
	glm::vec3 rotation{ 1.f, 0.f, 0.f };

	glm::mat4 mat4() {
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, translation);
		transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f)); 
		transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f)); 
		transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f)); 
		transform = glm::scale(transform, scale);

		return transform;
	};
};

class GameObject {
public:
	using id_t = unsigned int;

	std::shared_ptr<Model> model{};
	glm::vec3 color{};
	TransformComponent transform{};

	static GameObject createGameObject() {
		static id_t currentId = 0;
		return GameObject{ currentId++ };
	}

	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;
	GameObject(GameObject&&) = default;
	GameObject& operator=(GameObject&&) = default;

	id_t getId() {
		return id;
	}

private:
	id_t id;

	GameObject(id_t objId) : id{ objId } {}
};

