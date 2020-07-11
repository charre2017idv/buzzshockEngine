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
	class buCoreInputLayout
	{
	public:
		/**
		 * @brief 
		 */
		buCoreInputLayout() = default;
		/**
		 * @brief 
		 */
		~buCoreInputLayout() {};
		/** 
		 * @brief 
		 * @param 
		 * @return 
		 * @bug 
		 */
		virtual void 
	  init() = 0;
	private:

	};
}
