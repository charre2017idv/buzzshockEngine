/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include "buPrerequisitesCore.h"

namespace buEngineSDK {
 class buCoreViewport
 {
 public:
 	/**
 	 * @brief 
 	 */
 	buCoreViewport() = default;
 	/**
 	 * @brief 
 	 */
 	~buCoreViewport() {};
  /**
   * @brief 
   */
  virtual void 
  init(float width, float height, float minDepth, float maxDepth, 
       float topLeftX, float topLeftY) = 0;
 private:
 };
}