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

	class Locator;
	class Renderer;

	class Scene
	{
	private:
		Matrix4 m_projectionMatrix;
		std::vector<GameObject2D*> m_renderableObjects;
		std::map<std::string, GameObject2D*> m_renderableObjectsID;
		
	public:
		Camera camera;

		Scene(const Vector2& nearFar, const Vector2& leftRight, const Vector2& topBottom);
		Scene(const Vector2& nearFar, const Float& fov, const Float& aspectRatio);
		~Scene();

		void AddObject2D(GameObject2D* object, const Character* name);
		GameObject2D& GetObject2D(const Character* name);
		void RemoveObject2D(const Character* name);

		friend class Locator;
		friend class Renderer;
	};

}