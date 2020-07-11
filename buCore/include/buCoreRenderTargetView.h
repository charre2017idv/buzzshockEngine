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

namespace buEngineSDK {
	class buCoreRenderTargetView
	{
	public:
		/**
		 * @brief 
		 */
		buCoreRenderTargetView() = default;
		/**
		 * @brief 
		 */
		~buCoreRenderTargetView() {};
		/**
		 * @brief 
		 */
		virtual void 
		init() = 0;
	private:

	};
}