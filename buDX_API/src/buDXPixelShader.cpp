#include "buDXPixelShader.h"

namespace buEngineSDK {
  buDXPixelShader::buDXPixelShader()
  {
    m_pixelShader = nullptr;
    m_compilePixelShader = nullptr;
  }

  buDXPixelShader::~buDXPixelShader()
  {
    SAFE_RELEASE(m_pixelShader);
  }

  void buDXPixelShader::init(WString<WCHAR> _fileName, 
                             String _entryPoint,
                             String _shaderModel)
  {
    CompileShaderFromFile(_fileName, _entryPoint, _shaderModel, &m_compilePixelShader);
  }
  bool buDXPixelShader::CompileShaderFromFile(WString<WCHAR> szFileName,
                                              String szEntryPoint,
                                              String szShaderModel, 
                                              ID3DBlob** ppBlobOut)
  {
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

    ID3DBlob* pErrorBlob;

    hr = D3DCompileFromFile(szFileName.c_str(),
      NULL,
      NULL,
      szEntryPoint.c_str(),
      szShaderModel.c_str(),
      dwShaderFlags,
      0,
      ppBlobOut,
      &pErrorBlob);
    if (FAILED(hr))
    {
      if (pErrorBlob != NULL)
        //OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
        if (pErrorBlob) pErrorBlob->Release();
      return hr;
    }
    if (pErrorBlob) pErrorBlob->Release();

    return S_OK;
  }
}