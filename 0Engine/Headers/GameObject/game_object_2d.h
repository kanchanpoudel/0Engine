#pragma once
#include "Math/transform_2d.h"
#include "Math/dimension.h"
#include "Graphics/material.h"
#include "Physics/collider_2d.h"
#include "Physics/rigid_body.h"
#include "s00nya_defs.h"

#define RENDER_OBJECT 		0x001 << 0
#define DETECT_COLLISION 	0x001 << 1
#define DYNAMIC_OBJECT 		0x001 << 2

namespace s00nya 
{

	class S00NYA_API GameObject2D
	{
	public:
		Transform2D transform;
		Dimension size;
		Material material;
		Collider2D collider;
		RigidBody body;

		/*
			BIT 1 : Render on / off
			BIT 2 : Collision on / off
			BIT 3 : Dynamic on / off
		*/
	private:
		UInteger m_flags;

	public:
		GameObject2D();
		GameObject2D(const Transform2D& transform, const Dimension& dimension, const Material& material);
		GameObject2D(const Transform2D& transform, const Dimension& dimension, const Material& material, const Collider2D& collider);
		GameObject2D(const Transform2D& transform, const Dimension& dimension, const Material& material, const Collider2D& collider, const RigidBody& body);

		void SetFlags(UInteger falgs);
		const UInteger& GetFlags();

		virtual void FixedUpdate();
		virtual void Update();

		virtual void OnTrigger();
	};

}