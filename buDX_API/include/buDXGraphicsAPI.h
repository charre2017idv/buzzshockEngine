#pragma once
#include <buCoreGraphicsAPI.h>

namespace buEngineSDK {
 class buDXGraphicsAPI : public buCoreGraphicsAPI
 {
  public:
   buDXGraphicsAPI() = default;
   ~buDXGraphicsAPI();
  
   /**
    * @brief Test method to check if the linking between libs works.
    */
   void
   testFunc() override;
   
  private:
  
 };
 
 /** 
  * @brief Pluggin exportation data method. 
  * @return Instance of DX.
  */
 extern "C" BU_PLUGIN_EXPORT buDXGraphicsAPI *
 createGraphicAPI() {
 	buDXGraphicsAPI* pDX = new buDXGraphicsAPI();
 	return pDX;
 }
}
