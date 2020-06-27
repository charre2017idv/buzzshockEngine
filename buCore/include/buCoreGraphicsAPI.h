/**
* @file buCoreGraphicsAPI.h 
* @version 1.0
* @date 25/06/2020
* @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
* @brief Class in charge of the usage of the virtual functions of buDX_API
* @bug None.
*/
#pragma once

#include <buPrerequisitesCore.h>
#include <buModule.h>
namespace buEngineSDK {

 class BU_CORE_EXPORT buCoreGraphicsAPI : public buModule<buCoreGraphicsAPI>
 {
  public:
  /**
   * @brief Default constructor
   */
  buCoreGraphicsAPI() = default;
  /**
   * @brief Destructor
   */
  ~buCoreGraphicsAPI() {};
  
  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual void 
  testFunc() {};

  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */

  private:
 
 };

 BU_CORE_EXPORT buCoreGraphicsAPI&
 g_graphicsAPI();

}
