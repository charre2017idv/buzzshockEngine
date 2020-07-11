/**
 * @file buCoreVieport.h
 * @version 1.0
 * @date 08/07/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief Class in charge of initialize the virtual methods for the buDXviewport
 * class.
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
  buCoreViewport(float width, float height, float minDepth, float maxDepth,
                  float topLeftX, float topLeftY);
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