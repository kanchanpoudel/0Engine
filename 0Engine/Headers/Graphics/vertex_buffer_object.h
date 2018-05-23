#pragma once
#include "s00nya_defs.h"

#define MAX_RENDER_VERTEX 2000

namespace s00nya
{

	class S00NYA_API VertexBufferObject
	{
	private:
		UInteger m_id;
		UInteger m_bufferID;
		UInteger m_indexID;

	public:
		VertexBufferObject();
		void Bind() const;
		~VertexBufferObject();
	};

}