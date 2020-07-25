#include "buDXTexture2D.h"

namespace buEngineSDK {
  buDXTexture2D::buDXTexture2D()
  {
    m_texture = nullptr;
    memset(&m_descriptor,0, sizeof(m_descriptor));
  }

  buDXTexture2D::~buDXTexture2D()
  {
    SAFE_RELEASE(m_texture);
  }
  void buDXTexture2D::init(WString filepath, uint32 texFormat, uint32 usage, 
                           float width, float height, int32 mipLevels, 
                           int32 arraysize, int32 samplerDescCount, 
                           int32 samplerDescQuality, uint32 bindflags,
                           uint32 CPUAccessFlags, uint32 miscFlags)
  {
    m_width = width;
    m_height = height;
    m_mipLevels = mipLevels;
    m_arraysize = arraysize;
    m_format = (DXGI_FORMAT)texFormat;
    m_samplerDescCount= samplerDescCount;
    m_samplerDescQuality = samplerDescQuality;
    m_usage = (D3D11_USAGE)usage;
    m_bindflag = bindflags;
    m_CPUAccessFlags = CPUAccessFlags;
    m_miscFlags = miscFlags;
    
    m_descriptor.Width = (UINT)width;
    m_descriptor.Height = (UINT)height;
    m_descriptor.MipLevels = mipLevels;
    m_descriptor.ArraySize = arraysize;
    m_descriptor.Format = (DXGI_FORMAT)texFormat;
    m_descriptor.SampleDesc.Count = samplerDescCount;
    m_descriptor.SampleDesc.Quality = samplerDescQuality;
    m_descriptor.Usage = (D3D11_USAGE)usage;
    m_descriptor.BindFlags = bindflags;
    m_descriptor.CPUAccessFlags = CPUAccessFlags;
    m_descriptor.MiscFlags = miscFlags;
  }
  void buDXTexture2D::init(WString _filepath)
  {
    m_filepath = _filepath;
  }
}