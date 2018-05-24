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
		const Material& material
	):
		transform(transform), 
		material(material), 
		m_flags(RENDER_OBJECT)
	{
	}

	GameObject2D::GameObject2D(
		const Transform2D& transform, 
		const Material& material, 
		const Collider2D& collider
	):
		transform(transform), 
		material(material), 
		collider(collider), 
		m_flags(RENDER_OBJECT | DETECT_COLLISION)
	{
	}

	GameObject2D::GameObject2D(
		const Transform2D& transform, 
		const Material& material, 
		const Collider2D& collider, 
		const RigidBody& body
	):
		transform(transform),
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