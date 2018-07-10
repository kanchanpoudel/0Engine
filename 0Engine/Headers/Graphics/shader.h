#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	class Game2D;
	struct Vector2;
	struct Vector3;
	struct Matrix3;
	struct Matrix4;

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
		void SetMatrix3(const Character* name, const Matrix3& matrix) const;
		void SetMatrix4(const Character* name, const Matrix4& matrix) const;
		void SetVector3(const Character* name, const Vector3& vector) const;
		void SetVector2(const Character* name, const Vector2& vector) const;
		void SetSwitches(const Character* name, const Boolean& value) const;
		void SetTexture2D(const Character* name, const Integer& id) const;

		~Shader();

		friend class Game2D;
	};

}