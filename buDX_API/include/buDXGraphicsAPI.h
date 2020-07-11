#pragma once
#include <buCoreGraphicsAPI.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <memory>
#include <buVector3F.h>
#include "buDXViewport.h"
#include "buDXTexture2D.h"
#include "buDXSwapchain.h"
#include "buDXRenderTargetView.h"
#include "buDXVertexShader.h"
#include "buDXPixelShader.h"
#include "buDXInputLayout.h"
#include "buDXBuffer.h"

namespace buEngineSDK {
  struct SimpleVertex
  {
    buVector3F Pos;
  };

 class buDXGraphicsAPI : public buCoreGraphicsAPI
 {
  public:
   buDXGraphicsAPI();
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
   bool 
   init(WeakSPtr<buCoreViewport> _viewport, 
        WeakSPtr<buCoreTexture2D> _backBuffer,
        WeakSPtr<buCoreRenderTargetView> _renderTargetView,
        WeakSPtr<buCoreVertexShader> _vertexShader,
        WeakSPtr<buCoreInputLayout> _inputLayout,
        WeakSPtr<buCorePixelShader> _pixelShader,
        WeakSPtr<buCoreBuffer> _vertexBuffer) override;

   /**
   * @brief
   * @param
   * @return
   * @bug
   */
   bool
   initWindow(void* hInstance, void* _wndProc) override;

  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  void 
  cleanUp() override;

  /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
  void 
  render(WeakSPtr<buCoreRenderTargetView> _renderTargetView,
         WeakSPtr<buCoreVertexShader> _vertexShader,
         WeakSPtr<buCorePixelShader> _pixelShader) override;

   /**
   * @brief
   * @param
   * @return
   * @bug
   */
   SPtr<buCoreViewport>
   createViewport() override;
   
   /** 
   * @brief 
   * @param 
   * @return 
   * @bug 
   */
   SPtr<buCoreTexture2D> 
   createTexture2D() override;

   /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
   SPtr<buCoreSwapchain>
   createSwapchain() override;

   /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
   SPtr<buCoreRenderTargetView>
   createRenderTargetView() override;

   /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
   SPtr<buCoreVertexShader>
   createVertexShader() override;

   /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
   SPtr<buCorePixelShader>
   createPixelShader() override;

   /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
   SPtr<buCoreInputLayout>
   createInputLayout() override;

   /** 
    * @brief 
    * @param 
    * @return 
    * @bug 
    */
   SPtr<buCoreBuffer>
   createBuffer() override;

   /** 
    * @brief 
    * @param 
    * @return  
    * @bug 
    */
   LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam);
  private:
    /**
     * @brief 
     */
    ID3D11Device* m_device = NULL;
    /**
     * @brief 
     */
    ID3D11DeviceContext* m_deviceContext = NULL;
    /**
     * @brief 
     */
    IDXGISwapChain* m_swapchain = NULL;
    /**
     * @brief 
     */
    DXGI_SWAP_CHAIN_DESC m_swapchainDesc;
    //--------------------------------------------------------------------------------------
  // Structures
  //--------------------------------------------------------------------------------------
    


    //--------------------------------------------------------------------------------------
    // Global Variables
    //--------------------------------------------------------------------------------------
   
    void*               g_hInst;
    HWND                    g_hWnd = NULL;
    D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
    D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
    
    
    

    //ID3D11Buffer* g_pVertexBuffer = NULL;
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
