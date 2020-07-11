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
#include "buCoreTexture2D.h"

namespace buEngineSDK {
 class buDXTexture2D : public buCoreTexture2D
 {
 public:
  /**
   * @brief 
   */
  buDXTexture2D();
  /**
   * @brief 
   */
  ~buDXTexture2D();
  /*
  * @brief
  * @param
  * @return
  * @bug
  */
  void
  init(String filepath, uint32 texFormat, uint32 usage, int32 width,
       int32 height, int32 mipLevels, int32 arraysize, int32 samplerDescCount,
       int32 samplerDescQuality, uint32 bindflags, uint32 CPUAccessFlags,
       uint32 miscFlags) override;
 public:
  /*
   * @brief 
   */
   ID3D11Texture2D* m_texture;
 };
}
