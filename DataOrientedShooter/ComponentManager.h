#pragma once
#include <unordered_map>
#include <mutex>
#include "ECS.h"
#include "ComponentArray.h"

class ComponentManager
{
public:
	template<typename T>
	void registerComponent()
	{
		const char* typeName = typeid(T).name();

		assert(componentTypes.find(typeName) == componentTypes.end()
			&& "Trying to register component type more than once.");

		componentTypes.insert({ typeName, nextComponentType });
	}

	template<typename T>
	ComponentType getComponentType()
	{
		const char* typeName = typeid(T).name();

		assert(componentTypes.find(typeName) != componentTypes.end()
			&& "Trying to use component before it was registered.");

		return componentTypes[typeName];
	}

	template<typename T>
	void addComponent(Entity entity, T component)
	{
		GetComponentArray<T>()->insertData(entity, component);
	}

	template<typename T>
	void removeComponent(Entity entity)
	{
		getComponentArray<T>() - removeData(entity);
	}

	template<typename T>
	T& getComponent(Entity entity)
	{
		return getComponentArray<T>()->getData(entity);
	}

	// notify every component array that an entity has been destroyed
	// if the array has a component for that entity, it gets removed
	void entityDestroyed(Entity entity)
	{
		for (auto const& pair : componentArrays)
		{
			auto const& component = pair.second;
			component->entityDestroyed(entity);
		}
	}

private:

	std::unordered_map<const char*, ComponentType> componentTypes{};
	
	std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays{};

	ComponentType nextComponentType{};

	// convenience function to get the statically casted pointer to the ComponentArray of type T.
	template<typename T>
	std::shared_ptr<ComponentArray<T>> GetComponentArray()
	{
		const char* typeName = typeid(T).name();

		assert(componentTypes.find(typeName) != componentTypes.end() && "Component not registered before use.");

		return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
	}

};