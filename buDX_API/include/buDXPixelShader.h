/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include <d3d11.h>
#include "buCorePixelShader.h"
#include <d3dcompiler.h>

namespace buEngineSDK {
	class buDXPixelShader : public buCorePixelShader
	{
	public:
		/**
		 * @brief 
		 */
		buDXPixelShader();
		/**
		 * @brief 
		 */
		~buDXPixelShader();
		/**
		* @brief 
		*/
		void
		init(WString<WCHAR> _fileName, String _entryPoint, String _shaderModel) override;
		/**
     * @brief
     * @param
     * @return
     * @bug
     */
    bool
    CompileShaderFromFile(WString<WCHAR> szFileName, String szEntryPoint,
                          String szShaderModel, ID3DBlob** ppBlobOut);
	public:
		/**
		 * @brief 
		 */
		ID3D11PixelShader* m_pixelShader;
		/**
		 * @brief 
		 */
		ID3DBlob* m_compilePixelShader;
	};
}
