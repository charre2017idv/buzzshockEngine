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
#include <buCoreViewport.h>

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
  ~buCoreGraphicsAPI() = default;
  /**
   * @brief Instances of this class
   */
  FORCEINLINE void 
  setObject(buCoreGraphicsAPI* _api) {
    buCoreGraphicsAPI::_instance() = _api;
  }
  
  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual void 
  testFunc() {}
  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual SPtr<buCoreViewport>
  createViewport() { return nullptr; }
 private:

 };

 BU_CORE_EXPORT buCoreGraphicsAPI&
 g_graphicsAPI();

 using fnGraphicsAPIProt = buCoreGraphicsAPI * (*)();
}
