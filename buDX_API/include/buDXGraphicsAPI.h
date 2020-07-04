#pragma once
#include <buCoreGraphicsAPI.h>
#include <d3d11.h>
#include <memory>
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
   /**
   * @brief
   * @param
   * @return
   * @bug
   */
   SPtr<buCoreViewport>
   createViewport() override;
  private:
  
 };
 
 /** 
  * @brief Plugging exportation data method. 
  * @return Instance of DX.
  */
 extern "C" BU_PLUGIN_EXPORT buDXGraphicsAPI *
 createGraphicAPI() {
 	buDXGraphicsAPI* pDX = new buDXGraphicsAPI();
 	return pDX;
 }
}
