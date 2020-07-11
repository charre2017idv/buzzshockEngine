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
	class buCorePixelShader
	{
	public:
		/**
		 * @brief 
		 */
		buCorePixelShader() = default;
		/**
		 * @brief 
		 */
		~buCorePixelShader() {};
		/**
		* @brief 
		*/
		virtual void
		init(WString<WCHAR> _fileName, String _entryPoint, String _shaderModel) = 0;
	private:

	};
}
