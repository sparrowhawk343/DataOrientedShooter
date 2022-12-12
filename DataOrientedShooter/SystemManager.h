#pragma once
#include "ECS.h"
#include <mutex>
#include <unordered_map>
#include "System.h"

class SystemManager
{
public:
	template<typename T>
	std::shared_ptr<T> registerSystem()
	{
		const char* typeName = typeid(T).name();

		assert(systems.find(typeName) == systems.end()
			&& "Trying to register system more than once.");

		auto system = std::make_shared<T>();
		systems.insert({ typeName, system });
		return system;
	}

	template<typename T>
	void setSignature(Signature signature)
	{
		const char* typeName = typeid(T).name();

		assert(systems.find(typeName) != systems.end()
			&& "Trying to use system before it is registered.");

		signatures.insert({ typeName, signature });
	}

	// erase a destroyed entity from all system lists
	// entities is a set so no check needed
	void entityDestroyed(Entity entity)
	{
		for (auto const& pair : systems)
		{
			auto const& system = pair.second;

			system->entities.erase(entity);
		}
	}

	void entitySignatureChanged(Entity entity, Signature entitySignature)
	{
		for (auto const& pair : systems)
		{
			auto const& type = pair.first;
			auto const& system = pair.second;
			auto const& systemSignature = signatures[type];

			// if entity signature matches system signature, insert into set
			if ((entitySignature & systemSignature) == systemSignature)
			{
				system->entities.insert(entity);
			}
			// if entity signature does not match system signature, erase from set
			else
			{
				system->entities.erase(entity);
			}
		}
	}

private:

	std::unordered_map<const char*, Signature> signatures{};

	std::unordered_map<const char*, std::shared_ptr<System>> systems{};
};
