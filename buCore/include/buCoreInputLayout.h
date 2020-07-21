/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include <buPrerequisitesCore.h>
#include "buCoreVertexShader.h"

namespace buEngineSDK
{
	struct INPUT_LAYOUT_DESC
	{
		String semanticName;
		uint32 semanticIndex;
		uint32 format;
		uint32 inputSlot;
		uint32 alignedByteOffset;
		uint32 inputSlotClass;
		uint32 instanceDataStepRate;
	};
	class buCoreInputLayout
	{
	public:
		/**
		 * @brief Default constructor
		 */
		buCoreInputLayout() = default;
		
		/**
		 * @brief Destructor
		 */
		~buCoreInputLayout() {};
		
		/** 
		 * @brief Virtual method that initialize the object.
		 */
		virtual void 
	  init(INPUT_LAYOUT_DESC* _descriptor, uint32 _numElements) = 0;
	private:

	};
}
