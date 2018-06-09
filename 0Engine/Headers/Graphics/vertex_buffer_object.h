#pragma once
#include "s00nya_defs.h"

namespace s00nya
{
	/*
	 * VertexBufferObject is responsible for creation and destruction of:
	 	- Vertex Array Object
		- Vertex Buffer Object
		- Element Buffer Object
	 * Data and size of the buffer are not reserved / allocated by this class
	 * Buffer size and data are to be mainted by the class / classes that derive this class
	*/
	class S00NYA_API VertexBufferObject
	{
	private:
		UInteger m_id;
		UInteger m_bufferID;
		UInteger m_indexID;

	public:
		// Vertex Array is left Binded un the creation of the class
		// All the base classes are also expected to leave the Vertex Array bound
		VertexBufferObject();
		void Bind() const;

		/*
		 * UnBind() method is not created because they are expensive and redundant
		 * Programmer is trusted to Bind() the correct Vertex Array before doing the processing
		*/
		//void UnBind() const;

		virtual ~VertexBufferObject();
	};

}