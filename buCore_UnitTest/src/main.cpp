/**
 * @file main.cpp
 * @version 1.0
 * @date 27/06/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief File in charge of Checking the unit testing of the Core.
 */
#include <buPrerequisitesCore.h>
#include <buPluggin.h>
#include <buCoreGraphicsAPI.h>
#include <gtest/gtest.h>

using namespace buEngineSDK;
LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam);

int
main(int argc, char** argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  switch (Msg)
  {
  default: return DefWindowProc(Hw, Msg, wParam, lParam);
  }
}

 /**
  * @brief 
  * @param 
  * @return 
  * @bug 
  */
 TEST(buCore, FuncTest) {
   // ARRANGE
   buPluggin plug;

   // ACT
   

   if (plug.createPluggin("buDX_APId.dll")) {
     //using fnProt = buCoreGraphicsAPI * (*)();

     auto createGraphicsAPI = reinterpret_cast<fnGraphicsAPIProt>(
       plug.getProcedureByName("createGraphicAPI"));

     buCoreGraphicsAPI::startUp();
     buCoreGraphicsAPI* graphicAPI = createGraphicsAPI();
     g_graphicsAPI().setObject(graphicAPI);
     buCoreGraphicsAPI::instance().testFunc();
    // buCoreGraphicsAPI::instance().Initialize(nullptr, nullptr, nullptr, 10);

     // Initialize 
     auto& graphMan = g_graphicsAPI();
     // Init window
     buCoreGraphicsAPI::instance().initWindow(plug.m_instance, WndProc);
     // Create the back buffer
     SPtr<buCoreTexture2D> backBuffer = graphMan.createTexture2D();
     // Create render target view
     SPtr<buCoreRenderTargetView> renderTargetView = graphMan.createRenderTargetView();
     // Create Viewport
     SPtr<buCoreViewport> viewport = graphMan.createViewport();
     viewport->init(640, 480, 0.0f, 1.0f, 0.0f, 0.0f);
     // Create Vertex Shader
     SPtr<buCoreVertexShader> vertexShader = graphMan.createVertexShader();
     vertexShader->init(L"SimpleTriangleForEngine.fx", "VS", "vs_5_0");
     SPtr<buCoreInputLayout> inputLayout = graphMan.createInputLayout();
     inputLayout->init();
     // Create Pixel shader 
     SPtr<buCorePixelShader> pixelShader = graphMan.createPixelShader();
     pixelShader->init(L"SimpleTriangleForEngine.fx", "PS", "ps_5_0");
     // Create Vertex Buffer
     SPtr<buCoreBuffer> vertexBuffer = graphMan.createBuffer();
    
     buCoreGraphicsAPI::instance().init(viewport, 
                                        backBuffer, 
                                        renderTargetView,
                                        vertexShader,
                                        inputLayout,
                                        pixelShader, 
                                        vertexBuffer);

     MSG msg = { 0 };
     while (WM_QUIT != msg.message)
     {
       if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
       {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
       }
       else
       {
         buCoreGraphicsAPI().instance().render(renderTargetView, 
                                               vertexShader, pixelShader);
       }
     }

     buCoreGraphicsAPI().instance().cleanUp();


     buCoreGraphicsAPI::shutDown();
     //delete graphicAPI;
     plug.destroy();
   }
   else {
     std::cout << "Plugin not found!" << std::endl;
   }
   



   // ASSERT
   ASSERT_EQ(plug.createPluggin("buDX_APId.dll"), true);

 }