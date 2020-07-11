#include "buDXInputLayout.h"

namespace buEngineSDK {
  buDXInputLayout::buDXInputLayout()
  {
    m_inputLayout = nullptr;
  }

  buDXInputLayout::~buDXInputLayout()
  {
    SAFE_RELEASE(m_inputLayout);
  }

  void buDXInputLayout::init()
  {
    m_descriptor.push_back(
      { "POSITION",
        0,
        DXGI_FORMAT_R32G32B32_FLOAT,
        0,
        D3D11_APPEND_ALIGNED_ELEMENT,
        D3D11_INPUT_PER_VERTEX_DATA,
        0 }
    );
  }
}