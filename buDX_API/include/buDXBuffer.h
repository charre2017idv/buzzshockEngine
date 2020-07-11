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
#include "buCoreBuffer.h"

namespace buEngineSDK {
 class buDXBuffer : public buCoreBuffer
 {
 public:
 	/**
 	 * @brief 
 	 */
 	buDXBuffer();
 	/**
 	 * @brief 
 	 */
 	~buDXBuffer();
  /**
	 * @brief 
	 */
	void
	init(uint32 Usage, uint32 ByteWidth, uint32 BindFlags,
		   uint32 CPUAccessFlags, uint32 startSlot, uint32 numBuffers,
			 uint32 stride, uint32 offset, void* bufferData) override;
 public:
 	/**
 	 * @brief 
 	 */
 	ID3D11Buffer* m_buffer;
  /**
   * @brief 
   */
  D3D11_BUFFER_DESC m_descriptor;
  /*
   * @brief 
   */
  D3D11_SUBRESOURCE_DATA m_subresourceData;
  /**
   * @brief 
   */
  uint32 m_usage;
  /**
   * @brief 
   */
  uint32 m_byteWidth;
  /**
   * @brief 
   */
  uint32 m_bindFlags;
  /**
   * @brief 
   */
  uint32 m_CPUAccessFlags;
  /**
   * @brief 
   */
  uint32 m_startSlot;
  /**
   * @brief 
   */
  uint32 m_numBuffers;
  /**
   * @brief 
   */
  uint32 m_stride; 
  /**
   * @brief 
   */
  uint32 m_offset;
  /**
   * @brief 
   */
  void* m_bufferData;
 };
}
