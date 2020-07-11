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
	class buCoreVertexShader
	{
	public:
		/**
		 * @brief 
		 */
		buCoreVertexShader() = default;
		/**
		 * @brief 
		 */
		~buCoreVertexShader() {};
		/**
		* @brief 
		*/
		virtual void
		init(WString<WCHAR> _fileName, String _entryPoint, String _shaderModel) = 0;
		/**
	   * @brief
	   * @param
	   * @return
	   * @bug
	   */
		//virtual bool
	  //CompileShaderFromFile(WString<WCHAR> szFileName, String szEntryPoint,
		//											String szShaderModel, void** ppBlobOut) = 0;
	private:

	};
}