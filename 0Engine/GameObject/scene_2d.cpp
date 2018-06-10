#include "GameObject/scene_2d.h"
#include <algorithm>

namespace s00nya
{

	Scene::Scene():
		m_activeCamera(nullptr)
	{
	}

	Scene::Scene(Camera* camera, const Character* cameraName)
	{
		AddCamera(camera, cameraName);
		SwitchCamera(cameraName);
	}

	Scene::~Scene()
	{
		for (auto* object : m_renderableObjects)
			delete object;

		for (auto camera : m_cameras)
			delete camera;
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

	void Scene::AddCamera(Camera* camera, const Character* name)
	{
		m_cameras.push_back(camera);
		m_camerasID[std::string(name)] = camera;
	}

	Camera& Scene::GetCamera(const Character* name)
	{
		return *m_camerasID[std::string(name)];
	}

	void Scene::RemoveCamera(const Character* name)
	{
		auto* current = m_camerasID[std::string(name)];
		for (UInteger i(0); i < m_cameras.size(); i++)
		{
			if (current == m_cameras[i])
				m_renderableObjects.erase(m_renderableObjects.begin() + i);
		}
		m_camerasID.erase(std::string(name));
	}

	void Scene::SwitchCamera(const Character* name)
	{
		m_activeCamera = m_camerasID[std::string(name)];
	}

}