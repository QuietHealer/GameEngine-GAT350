#include "pch.h"
#include "Scene.h"
#include "Actor.h"
#include "Core/Factory.h"
#include "Component.h"
#include "Renderer/Renderer.h"
#include "Components/CameraComponent.h"
#include "Renderer/Light.h"
#include "Components/LightComponent.h"

namespace nu
{
	void Scene::AddActor(std::unique_ptr<Actor> actor)
	{ 
		actor->m_scene = this;
		m_pendingActors.push_back(std::move(actor)); 
	}

	void Scene::RemoveAllActors(bool force)
	{
		std::erase_if(m_actors, [force](auto& actor) {return actor->GetPersistent() || force;});
	}

	bool Scene::Load(const std::string& sceneName)
	{
		json::document_t document;
		if (json::Load(sceneName, document))
		{
			if (JSON_HAS_NAME(document, "actors"))
			{
				for (auto& actorValue : JSON_GET_NAME(document, "actors").GetArray())
				{
					std::string typeName;
					JSON_READ_NAME(actorValue, "type", typeName);

					auto actor = Factory::Instance().Create<Actor>(typeName);
					actor->Read(actorValue);

					bool prototype = false;
					JSON_READ(actorValue, prototype);

					if (prototype)
					{
						std::string name;
						JSON_READ(actorValue, name);
				
						Factory::Instance().RegisterPrototype<Actor>(name, std::move(actor));
					}
					else
					{
						AddActor(std::move(actor));
					}

				}
			}

			/*std::string type;
			JSON_READ(document);



			std::cout << player->GetName() << std::endl;
			std::cout << player->GetTag() << std::endl;

			std::cout << player->GetTransform().rotation << std::endl;

	*/

				//m_scene->AddActor(std::move(player));
		}
		return false;
	}

	void Scene::Update(float dt)
	{
		for (auto& actor : m_actors)
		{
			actor->Update(dt);
		}

		for (auto& actor : m_actors)
		{
			if (actor->m_destroyed) actor->OnDestroy();
		}
		std::erase_if(m_actors, [](auto& actor) {return actor->m_destroyed;});

		for (auto& actor : m_pendingActors)
		{
			actor->Start();
			m_actors.push_back(std::move(actor));
		}
		m_pendingActors.clear();
		//m_actors.insert(m_actors.end(), m_pendingActors.begin(), m_pendingActors.end());
		//m_pendingActors.clear();
	}

	void Scene::Draw(const Renderer& renderer)
	{
		FrameUniform frameUniform{};

		auto camera = GetActorByName("Camera");
		if (camera)
		{
			auto cameraComponent = camera->GetComponent<CameraComponent>();
			if (cameraComponent)
			{
				frameUniform.cameraPosition = camera->GetTransform().position;
				frameUniform.view = cameraComponent->GetView();
				frameUniform.projection = cameraComponent->GetProjection();
				frameUniform.viewProjection = frameUniform.projection * frameUniform.view;

				renderer.SetVertexUniform(UniformSlot::Frame, &frameUniform, sizeof(frameUniform));
				renderer.SetFragmentUniform(UniformSlot::Frame, &frameUniform, sizeof(frameUniform));
			}
		}
		LightUniform lightUniform{};
		lightUniform.ambient = glm::vec3{ 0.2f };

		auto lights = GetActorByTag("Lights");
		for (auto light : lights)
		{
			auto lightComponent = light->GetComponent<LightComponent>();
			if (lightComponent)
			{
				lightUniform.lights[lightUniform.count++] = lightComponent->GetLightData();
			}
		}

		renderer.SetVertexUniform(UniformSlot::Light, &lightUniform, sizeof(lightUniform));
		renderer.SetFragmentUniform(UniformSlot::Light, &lightUniform, sizeof(lightUniform));

		for (const auto& actor : m_actors)
		{
			if (actor && actor->IsActive())
				actor->Draw(renderer);
		}
	}
}