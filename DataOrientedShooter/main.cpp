#include <vector>
#include <random>
#include "Engine.h"
#include "Game.h"
#include "ECS.h"
#include "Coordinator.h"
#include "Component.h"
#include "PhysicsSystem.h"

Engine engine;
bool quit = false;
Uint64 previousTicks = SDL_GetPerformanceCounter();

Coordinator coordinator;
std::shared_ptr<PhysicsSystem> physicsSystem;

void update()
{
	SDL_Event event;
	quit = false;


	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

			if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			{
				player.input();
			}

			if (event.type == SDL_KEYUP && event.key.repeat == 0)
			{
				player.hasInput = false;
			}
		}

		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 deltaTicks = ticks - previousTicks;
		previousTicks = ticks;

		deltaTime = static_cast<float>((deltaTicks)) / static_cast<float>(SDL_GetPerformanceFrequency());

		//std::cout << "FPS: " << std::to_string(1.0f / deltaTime) << std::endl;
		//std::cout << "DeltaTime: " << deltaTime << std::endl;

		physicsSystem->update(deltaTime);
		player.move();
		engine.render();
		player.render();
		SDL_RenderPresent(renderer);
	}
}

int main(int argc, char* args[])
{
	std::vector<Entity> entities(MAX_ENTITIES);

	coordinator.init();

	coordinator.registerComponent<Gravity>();
	coordinator.registerComponent<RigidBody>();
	coordinator.registerComponent<Transform>();

	physicsSystem = coordinator.registerSystem<PhysicsSystem>();

	Signature signature;
	signature.set(coordinator.getComponentType<Gravity>());
	signature.set(coordinator.getComponentType<RigidBody>());
	signature.set(coordinator.getComponentType<Transform>());

	coordinator.setSystemSignature<PhysicsSystem>(signature);

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
	std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
	std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);


	float randomPosition = randPosition(generator);
	float randomRotation = randRotation(generator);
	float randomScale = randScale(generator);

	for (auto& entity : entities)
	{
		entity = coordinator.createEntity();

		coordinator.addComponent(
			entity, 
			Gravity
			{
				// force
				Vec3(0.0f, randGravity(generator), 0.0f) 
			});
		coordinator.addComponent(
			entity,
			RigidBody
			{
				// velocity
				Vec3(0.0f, 0.0f, 0.0f),
				// acceleration
				Vec3(0.0f, 0.0f, 0.0f)
			});
		coordinator.addComponent(
			entity,
			Transform
			{
				// position
				Vec3(randomPosition, randomPosition, randomPosition),
				// rotation
				Vec3(randomRotation, randomRotation, randomRotation),
				// scale
				Vec3(randomScale, randomScale, randomScale)
			});
	}

	if (!engine.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!engine.loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_BlitSurface(engine.displaySurface, NULL, engine.screenSurface, NULL);

			SDL_UpdateWindowSurface(engine.window);
		}

		update();
	}


	engine.close();
	return 0;
}