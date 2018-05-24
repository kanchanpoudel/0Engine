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

	void Scene::AddObject2D(const GameObject2D& object, const Character* name)
	{
		m_renderableObjects[std::string(name)] = object;
	}

	GameObject2D& Scene::GetObject2D(const Character* name)
	{
		return m_renderableObjects[std::string(name)];
	}

	void Scene::RemoveObject2D(const Character* name)
	{
		m_renderableObjects.erase(std::string(name));
	}

}