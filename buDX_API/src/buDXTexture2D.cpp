#include "buDXTexture2D.h"

namespace buEngineSDK {
  buDXTexture2D::buDXTexture2D()
  {
    m_texture = nullptr;
  }

  buDXTexture2D::~buDXTexture2D()
  {
    SAFE_RELEASE(m_texture);
  }
  void buDXTexture2D::init(String filepath, uint32 texFormat, uint32 usage, 
                           int32 width, int32 height, int32 mipLevels, 
                           int32 arraysize, int32 samplerDescCount, 
                           int32 samplerDescQuality, uint32 bindflags,
                           uint32 CPUAccessFlags, uint32 miscFlags)
  {
  }
}