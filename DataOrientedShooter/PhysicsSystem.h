#include "ECS.h"
#include "Coordinator.h"
#include "Component.h"

extern Coordinator coordinator;

class PhysicsSystem : System
{
public:
	void update(float deltaTime)
	{
		for (auto const& entity : entities)
		{
			auto& rigidBody = coordinator.getComponent<RigidBody>(entity);
			auto& transform = coordinator.getComponent<Transform>(entity);
			const auto& gravity = coordinator.getComponent<Gravity>(entity);

			transform.position += rigidBody.velocity * deltaTime;
			rigidBody.velocity += gravity.force * deltaTime;
		}
	}
};


