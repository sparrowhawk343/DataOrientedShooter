#pragma once
#include "ECS.h"
#include <array>
#include <unordered_map>
#include <cassert>

class IComponentArray
{
public:
	virtual ~IComponentArray() = default;
	virtual void entityDestroyed(Entity entity) = 0;
};


template<typename T>
class ComponentArray : public IComponentArray
{
public:
	void insertData(Entity entity, T component)
	{
		assert(entityToIndexMap.find(entity) == entityToIndexMap.end() 
			&& "Trying to add component to same entity more than once.");

		size_t newIndex = size;
		entityToIndexMap[entity] = newIndex;
		indexToEntityMap[newIndex] = entity;
		componentArray[newIndex] = component;
		++size;
	}

	void removeData(Entity entity)
	{
		assert(entityToIndexMap.find(entity) != entityToIndexMap.end()
			&& "Trying to remove non-existent component.");

		size_t indexOfRemovedEntity = entityToIndexMap[entity];
		size_t indexOfLastElement = size - 1;
		componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];
		
		Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
		entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
		indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

		entityToIndexMap.erase(entity);
		indexToEntityMap.erase(indexOfLastElement);
		
		--size;
	}

	T& getData(Entity entity)
	{
		assert(entityToIndexMap.find(entity) != entityToIndexMap.end()
			&& "Trying to retrieve non-existent component.");

		return componentArray[entityToIndexMap[entity]];
	}

	void entityDestroyed(Entity entity) override
	{
		if (entityToIndexMap.find(entity) != entityToIndexMap.end())
		{
			removeData(entity);
		}
	}

private:
	std::array<T, MAX_ENTITIES> componentArray;
	std::unordered_map<Entity, size_t> entityToIndexMap;
	std::unordered_map<size_t, Entity> indexToEntityMap;
	size_t size;
};