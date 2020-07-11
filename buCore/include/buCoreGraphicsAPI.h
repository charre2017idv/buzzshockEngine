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
#include <buCoreTexture2D.h>
#include <buCoreSwapchain.h>
#include <buCoreRenderTargetView.h>
#include <buCoreVertexShader.h>
#include <buCorePixelShader.h>
#include <buCoreInputLayout.h>
#include <buCoreBuffer.h>

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
  virtual bool 
  init(WeakSPtr<buCoreViewport> _viewport,
       WeakSPtr<buCoreTexture2D> _backBuffer,
       WeakSPtr<buCoreRenderTargetView> _renderTargetView,
       WeakSPtr<buCoreVertexShader> _vertexShader,
       WeakSPtr<buCoreInputLayout> _inputLayout,
       WeakSPtr<buCorePixelShader> _pixelShader,
       WeakSPtr<buCoreBuffer> _vertexBuffer) { return false; }

  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual bool
  initWindow(void* hInstance, void* _wndProc) { return false; };
  
  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  //virtual bool
  //CompileShaderFromFile(const char* szFileName, String szEntryPoint,
  //  String szShaderModel, void** ppBlobOut) { return false; }

  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual void 
  cleanUp() {};

  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual void 
  render(WeakSPtr<buCoreRenderTargetView> _renderTargetView,
         WeakSPtr<buCoreVertexShader> _vertexShader,
         WeakSPtr<buCorePixelShader> _pixelShader) {};

  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  virtual SPtr<buCoreViewport>
  createViewport() { return nullptr; }

  /**
   * @brief
   * @param
   * @return
   * @bug
   */
  virtual SPtr<buCoreTexture2D>
  createTexture2D() { return nullptr; };

  /**
   * @brief
   * @param
   * @return
   * @bug
   */
  virtual SPtr<buCoreSwapchain>
  createSwapchain() { return nullptr; };

  /**
    * @brief
    * @param
    * @return
    * @bug
    */
  virtual SPtr<buCoreVertexShader>
  createVertexShader() { return nullptr; };

  /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
  virtual SPtr<buCorePixelShader>
  createPixelShader() { return nullptr; };

  /**
   * @brief
   * @param
   * @return
   * @bug
   */
  virtual SPtr<buCoreRenderTargetView>
  createRenderTargetView() { return nullptr; };

  /**
   * @brief
   * @param
   * @return
   * @bug
   */
  virtual SPtr<buCoreInputLayout>
  createInputLayout() { return nullptr; };

  /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
   virtual SPtr<buCoreBuffer>
   createBuffer() { return nullptr; };
 private:

 };

 BU_CORE_EXPORT buCoreGraphicsAPI&
 g_graphicsAPI();

 using fnGraphicsAPIProt = buCoreGraphicsAPI * (*)();
}
