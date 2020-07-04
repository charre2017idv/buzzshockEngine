/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include"buPrerequisitesCore.h"

namespace buEngineSDK {
 class buCoreTexture2D
 {
  public:
  /**
   * @brief 
   */
  buCoreTexture2D() = default;
  /**
   * @brief 
   */
  ~buCoreTexture2D();
  /* 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual void
  Init(String filepath, uint32 texFormat, uint32 usage, int32 width,
       int32 height, int32 mipLevels, int32 arraysize, int32 samplerDescCount,
       int32 samplerDescQuality, uint32 bindflags, uint32 CPUAccessFlags,
       uint32 miscFlags) = 0;

  private:
  
 };
}
