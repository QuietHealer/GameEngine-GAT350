#include "pch.h"
#include "CameraComponent.h"
#include "Core/Factory.h"
#include "Framework/Actor.h"

namespace nu
{
	FACTORY_REGISTER(CameraComponent)

		void CameraComponent::Update(float dt)
	{
		auto view = glm::lookAtRH(m_owner->GetTransform().position, m_owner->GetTransform().position + glm::vec3{0, 0, -1}, glm::vec3{0, 1, 0});
		float aspectRatio = Engine::Get().GetRenderer().GetWidth() / (float)Engine::Get().GetRenderer().GetHeight();
		m_projection = glm::perspective(glm::radians(m_fov), aspectRatio, 0.01f, 200.0f);
	}

	void CameraComponent::Draw(const Renderer& renderer)
	{
	}

	void CameraComponent::Read(const json::value_t& value)
	{
		JSON_READ_NAME(value, "fov", m_fov);
		JSON_READ_NAME(value, "near_plane", m_nearPlane);
		JSON_READ_NAME(value, "far_plane", m_farPlane);
	}
}
