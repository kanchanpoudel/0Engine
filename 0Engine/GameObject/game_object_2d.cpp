#include "GameObject/game_object_2d.h"
#include "Math/matrix4.h"

namespace s00nya 
{

	GameObject2D::GameObject2D():
		m_flags(0x00)
	{
	}

	GameObject2D::GameObject2D(
		const Transform2D& transform, 
		const Dimension& dimension,
		const Material& material
	):
		transform(transform), 
		size(dimension),
		material(material), 
		m_flags(RENDER_OBJECT)
	{
	}

	GameObject2D::GameObject2D(
		const Transform2D& transform, 
		const Dimension& dimension,
		const Material& material, 
		const Collider2D& collider
	):
		transform(transform), 
		size(dimension),
		material(material), 
		collider(collider), 
		m_flags(RENDER_OBJECT | DETECT_COLLISION)
	{
	}

	GameObject2D::GameObject2D(
		const Transform2D& transform, 
		const Dimension& dimension,
		const Material& material, 
		const Collider2D& collider, 
		const RigidBody& body
	):
		transform(transform),
		size(dimension),
		material(material),
		collider(collider),
		body(body),
		m_flags(RENDER_OBJECT | DETECT_COLLISION | DYNAMIC_OBJECT)
	{
	}

	void GameObject2D::SetFlags(UInteger flags)
	{
		m_flags = flags;
	}

	const UInteger& GameObject2D::GetFlags()
	{
		return m_flags;
	}

	void GameObject2D::FixedUpdate()
	{
	}

	void GameObject2D::Update()
	{
	}

	void GameObject2D::OnTrigger()
	{
	}

}