#pragma once
#include "s00nya_defs.h"
#include "Math/matrix4.h"
#include "Math/vector2.h"
#include "GameObject/game_object_2d.h"
#include "GameObject/camera.h"
#include <map>
#include <string>
#include <vector>

namespace s00nya
{

	class Game2D;
	class Renderer;

	class Scene
	{
	private:
		Camera* m_activeCamera;
		std::vector<Camera*> m_cameras;
		std::map<std::string, Camera*> m_camerasID;

		std::vector<GameObject2D*> m_renderableObjects;
		std::map<std::string, GameObject2D*> m_renderableObjectsID;

	public:
		Camera camera;

		Scene();
		Scene(Camera* camera, const Character* name);
		~Scene();

		void AddObject2D(GameObject2D* object, const Character* name);
		GameObject2D& GetObject2D(const Character* name);
		void RemoveObject2D(const Character* name);

		void AddCamera(Camera* camera, const Character* name);
		Camera& GetCamera(const Character* name);
		void RemoveCamera(const Character* name);
		void SwitchCamera(const Character* name);

		friend class Game2D;
		friend class Renderer;
	};

}