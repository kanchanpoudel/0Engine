#include "GameObject/scene_2d.h"

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
		m_renderableObjectsID[std::string(name)] = m_renderableObjects.size() - 1;
	}

	GameObject2D& Scene::GetObject2D(const Character* name)
	{
		return *m_renderableObjects[m_renderableObjectsID[std::string(name)]];
	}

	void Scene::RemoveObject2D(const Character* name)
	{
		m_renderableObjects.erase(m_renderableObjects.begin() + m_renderableObjectsID[std::string(name)]);
		m_renderableObjectsID.erase(std::string(name));
	}

}