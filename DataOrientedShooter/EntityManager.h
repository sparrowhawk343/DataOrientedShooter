#include "ECS.h"
#include <queue>
#include <array>

class EntityManager
{
public:
	EntityManager()
	{
		for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
		{
			availableEntities.push(entity);
		}
	}

	Entity createEntity();
	void destroyEntity(Entity entity);
	void setSignature(Entity entity, Signature signature);
	Signature getSignature(Entity entity);


private:
	std::queue<Entity> availableEntities{};
	std::array<Signature, MAX_ENTITIES> signatures{};
	uint32_t livingEntityCount{};
};