#include "GameObject/scene_2d.h"
#include <algorithm>

namespace s00nya
{

	Scene::Scene(const Vector2& nearFar, const Vector2& leftRight, const Vector2& topBottom):
		m_projectionMatrix(
			Matrix4::Orthographic(
				leftRight.x, leftRight.y, 
				topBottom.y, topBottom.x, 
				nearFar.x, nearFar.y
			)
		),
		camera()
	{
		m_projectionMatrix = Matrix4::Orthographic(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
	}

	Scene::Scene(const Vector2& nearFar, const Float& fov, const Float& aspectRatio) :
		m_projectionMatrix(
			Matrix4::Perspective(
				fov, aspectRatio, nearFar.x, nearFar.y
			)
		),
		camera()
	{
	}

	Scene::~Scene()
	{
		for (auto* object : m_renderableObjects)
			delete object;
	}

	void Scene::AddObject2D(GameObject2D* object, const Character* name)
	{
		m_renderableObjects.push_back(object);
		
		std::sort(m_renderableObjects.begin(), m_renderableObjects.end(), 
			[](const GameObject2D* first, const GameObject2D* second) 
			{
				return first->transform.position.z < second->transform.position.z;
			});

		m_renderableObjectsID[std::string(name)] = object;
	}

	GameObject2D& Scene::GetObject2D(const Character* name)
	{
		return *m_renderableObjectsID[std::string(name)];
	}

	void Scene::RemoveObject2D(const Character* name)
	{
		auto* current = m_renderableObjectsID[std::string(name)];
		for (UInteger i(0); i < m_renderableObjects.size(); i++)
		{
			if (current == m_renderableObjects[i])
				m_renderableObjects.erase(m_renderableObjects.begin() + i);
		}
		m_renderableObjectsID.erase(std::string(name));
	}

}