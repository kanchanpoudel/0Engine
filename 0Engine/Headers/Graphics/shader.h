#pragma once
#include "s00nya_defs.h"
#include "Math/matrix4.h"
#include "Math/vector2.h"
#include "Math/vector3.h"

namespace s00nya
{

	class Resources;

	class S00NYA_API Shader
	{
	private:
		UInteger m_id;

	private:
		Shader(const Character* vertex, const Character* fragment, const Character* geometry = nullptr);

	public:
		Shader() = default;
		Shader(const Shader& shader) = delete;
		Shader& operator=(const Shader& shader) = default;

	public:
		void Bind() const;
		void SetMatrix4(const Character* name, const Matrix4& matrix) const;
		void SetVector3(const Character* name, const Vector3& vector) const;
		void SetVector2(const Character* name, const Vector2& vector) const;

		~Shader();

		friend class Resources;
	};

}