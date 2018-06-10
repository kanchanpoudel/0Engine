#include "Game/locator.h"
#include "Debugger/logger.h"
#include "Graphics/window.h"
#include "Utility/timer.h"
#include "Input/input.h"
#include "Input/input_manager.h"
#include "Utility/events.h"
#include "Utility/event_manager.h"
#include "Utility/resource_manager.h"
#include "Graphics/renderer.h"
#include "Graphics/shader.h"

namespace s00nya
{

	Locator* Locator::instance(nullptr);

	Locator::Locator()
	{
	}

	Locator::~Locator()
	{
		if (instance)
			delete instance;
	}

	Window* Locator::WindowService(const Character* title, const Integer& width, const Integer& height) const
	{
		Window* temp = new Window(title, width, height);
		return temp;
	}

	Timer* s00nya::Locator::TimerService() const
	{
		return new Timer();
	}

	Input* Locator::InputService(const Window* window) const
	{
		return new Input(window->m_id);
	}

	InputManager* Locator::InputManagerService(Input* input) const
	{
		return new InputManager(input);
	}

	EventManager* Locator::EventManagerService() const
	{
		return new EventManager();
	}

	Resources* Locator::ResourceService() const
	{
		return new Resources();
	}

	Shader* Locator::ShaderService(const Character* path) const
	{
		// Read all content from the file
		std::ifstream file(path, std::ios::in);
		std::stringstream stream;
		stream << file.rdbuf();
		file.close();
		std::string content(stream.str());

		/*
		 * All shader code are expected in a single file
		 * Three types of shaders are suppported : Vertex, Fragment and Geometry
		 * Geometry shader is optional
		 * Shader code must be in the order: Vertex, Geometry and Fragment with Goemetry being optional
		 * Every shader must begin with a declaration of their respective type
		 	- `@Vertex Shader` : Vertex Shader
			- `@Fragment Shader` : Fragment Shader
			- `@Geometry Shader` : Geometry Shader
		*/

		// Extract codes for Vertex, Geometry (if available) and Fragment Shader
		PDUInteger vertexPos = content.find("@Vertex Shader");
		PDUInteger fragmentPos = content.find("@Fragment Shader");
		PDUInteger geometryPos = content.find("@Geometry Shader");
		// Given file content error / unsatisfied
		if (vertexPos == std::string::npos || fragmentPos == std::string::npos)
		{
			Debug::Add("Could not load Shader - " + std::string(path), Debug::S00NYA_LOG_WARNING);
			return nullptr;
		}

		// Return the Shader
		if (geometryPos == std::string::npos)
		{
			std::string vertex(content.substr(vertexPos + 14, fragmentPos - vertexPos - 14));
			std::string fragment(content.substr(fragmentPos + 16, content.length() - fragmentPos - 16));
			const Character* vertexCstr(vertex.c_str());
			const Character* fragmentCstr(fragment.c_str());
			return new Shader(vertexCstr, fragmentCstr);
		}
		else
		{
			std::string vertex(content.substr(vertexPos + 14, geometryPos - vertexPos - 14));
			std::string geometry(content.substr(geometryPos + 16, fragmentPos - geometryPos - 16));
			std::string fragment(content.substr(fragmentPos + 16, content.length() - fragmentPos - 16));
			const Character* vertexCstr(vertex.c_str());
			const Character* geometryCstr(geometry.c_str());
			const Character* fragmentCstr(fragment.c_str());
			return new Shader(vertexCstr, fragmentCstr, geometryCstr);
		}
	}

	Renderer* Locator::RendererService(const Integer& frameWidth, const Integer& frameHeight, const Integer& displayWidth, const Integer& displayHeight) const
	{
		return new Renderer(frameWidth, frameHeight, displayWidth, displayHeight);
	}

	std::vector<GameObject2D*>& Locator::GetAllObjects2D(Scene* scene)
	{
		return scene->m_renderableObjects;
	}

	std::vector<Camera*>& Locator::GetAllCameras(Scene* scene)
	{
		return scene->m_cameras;
	}

	Locator& Locator::Get()
	{
		if (instance) return *instance;
		instance = new Locator();
		return *instance;
	}

}