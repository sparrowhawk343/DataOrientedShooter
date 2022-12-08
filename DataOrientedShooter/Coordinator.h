#pragma once
#include "ECS.h"
#include <mutex>
#include "ComponentManager.h"
#include "EntityManager.h"
#include "SystemManager.h"

class Coordinator
{
public:

	void init()
	{
		componentManager = std::make_unique<ComponentManager>();
		entityManager = std::make_unique<EntityManager>();
		systemManager = std::make_unique<SystemManager>();
	}

	Entity createEntity()
	{
		return entityManager->createEntity();
	}

	void destroyEntity(Entity entity)
	{
		entityManager->destroyEntity(entity);
	}


	template<typename T>
	void registerComponent()
	{
		componentManager->registerComponent<T>();
	}

	template<typename T>
	void addComponent(Entity entity, T component)
	{
		componentManager->addComponent<T>(entity, component);

		auto signature = entityManager->getSignature(entity);
		signature.set(componentManager->getComponentType<T>(), true));
		entityManager->setSignature(entity, signature);

		systemManager->entitySignatureChanged(entity, signature),
	}

	template<typename T>
	void removeComponent(Entity entity)
	{
		componentManager->removeComponent<T>(entity);

		auto signature = entityManager->getSignature(entity);
		signature.set(componentManager->getComponentType<T>(), false);
		entityManager->setSignature(entity, signature);

		systemManager->entitySignatureChanged(entity, signature);
	}

	template<typename T>
	T& getComponent(Entity entity)
	{
		return componentManager->getComponent<T>(entity);
	}

	template<typename T>
	ComponentType getComponentType()
	{
		return componentManager->getComponentType<T>();
	}


	template<typename T>
	std::shared_ptr<T> registerSystem()
	{
		return systemManager->registerSystem<T>();
	}

	template<typename T>
	void setSystemSignature(Signature signature)
	{
		systemManager->setSignature<T>(signature);
	}


private:
	std::unique_ptr<ComponentManager> componentManager;
	std::unique_ptr<EntityManager> entityManager;
	std::unique_ptr<SystemManager> systemManager;

};