/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include <buPrerequisitesDX.h>
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
  init(String filepath, uint32 texFormat, uint32 usage, float width,
       float height, int32 mipLevels, int32 arraysize, int32 samplerDescCount,
       int32 samplerDescQuality, uint32 bindflags, uint32 CPUAccessFlags,
       uint32 miscFlags) override;

  /**
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  void 
  init(String _filepath) override;
 public:
  /*
   * @brief 
   */
   ID3D11Texture2D* m_texture;
   /**
    * @brief 
    */
   D3D11_TEXTURE2D_DESC m_descriptor;
   /**
    * @brief
    */
   ID3D11ShaderResourceView* m_shaderSubresource;
   /**
    * @brief 
    */
   String m_filepath;
   /**
    * @brief 
    */
   uint32 m_format;
   /**
    * @brief 
    */
   uint32 m_usage; 
   /**
   * @brief 
   */
   uint32 m_width;
   /**
    * @brief 
    */
   uint32 m_height;
   /**
    * @brief 
    */
   int32 m_mipLevels;
   /**
    * @brief 
    */
   int32 m_arraysize;
   /**
    * @brief 
    */
   int32 m_samplerDescCount;
   /**
    * @brief 
    */
   int32 m_samplerDescQuality;
   /**
    * @brief 
    */
   uint32 m_bindflag;
   /**
    * @brief 
    */
   uint32 m_CPUAccessFlags;
   /**
    * @brief 
    */
   uint32 m_miscFlags;
   /**
    * @brief 
    */
   unsigned char* image;
 };
}
