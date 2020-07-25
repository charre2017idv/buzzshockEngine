#include "buGameApp_UnitTest.h"
#include <buMath.h>

namespace buEngineSDK
{
  buGameApp_UnitTest::buGameApp_UnitTest()
  {
    m_World = buMatrix4x4::IDENTITY;
    m_view = buMatrix4x4::ZERO;
    m_projection = buMatrix4x4::ZERO;
  } 

  buGameApp_UnitTest::~buGameApp_UnitTest()
  {
  }

  void buGameApp_UnitTest::onCreate()
  {
    auto& graphMan = g_graphicsAPI();

    // Initialize 
    // Create the back buffer
    backBuffer = graphMan.createTexture2D();

    // Create depth stencil texture
    depthStencil = graphMan.createTexture2D();
    depthStencil->init(L"",
                       DXGI_FORMAT_D24_UNORM_S8_UINT,
                       D3D11_USAGE_DEFAULT,
                       m_screenWidth, 
                       m_screenHeight,
                       1,
                       1,
                       1,
                       0,
                       D3D11_BIND_DEPTH_STENCIL,
                       0,
                       0);

    // Create depth stencil View
    depthStencilView = graphMan.createDepthStencilView();

    // Create render target view
    renderTargetView = graphMan.createRenderTargetView();

    // Create Viewport
    viewport = graphMan.createViewport();
    viewport->init(m_screenWidth, m_screenHeight, 0.0f, 1.0f, 0.0f, 0.0f);

    // Create Vertex Shader
    vertexShader = graphMan.createVertexShader();
    vertexShader->init(L"Data/Shaders/CubeProjectFor.fx",
                       "VS",
                       "vs_5_0");

    // Create input layout
    inputLayout = graphMan.createInputLayout();
    Vector<INPUT_LAYOUT_DESC> layoutDesc;
    layoutDesc.resize(2);
    // Positions
    layoutDesc[0].semanticName = "POSITION";
    layoutDesc[0].semanticIndex = 0;
    layoutDesc[0].format = DXGI_FORMAT_R32G32B32_FLOAT;
    layoutDesc[0].inputSlot = 0;
    layoutDesc[0].alignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
    layoutDesc[0].inputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    layoutDesc[0].instanceDataStepRate = 0;
    // texcoords
    layoutDesc[1].semanticName = "TEXCOORD";
    layoutDesc[1].semanticIndex = 0;
    layoutDesc[1].format = DXGI_FORMAT_R32G32_FLOAT;
    layoutDesc[1].inputSlot = 0;
    layoutDesc[1].alignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
    layoutDesc[1].inputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
    layoutDesc[1].instanceDataStepRate = 0;

    inputLayout->init(&layoutDesc[0], 2);

    // Create Pixel shader 
    pixelShader = graphMan.createPixelShader();
    pixelShader->init(L"Data/Shaders/CubeProjectFor.fx", 
                      "PS", 
                      "ps_5_0");

    // Create Vertex Buffer
    
    vertexBuffer = graphMan.createBuffer();
    vertexBuffer->init(D3D11_USAGE_DEFAULT,
                       sizeof(SimpleVertex) * m_numVertices,
                       D3D11_BIND_VERTEX_BUFFER,
                       0,
                       0,
                       1,
                       sizeof(SimpleVertex),
                       0,
                       mvertices);
    // Create Index Buffer
    
    indexBuffer = graphMan.createBuffer();
    indexBuffer->init(D3D11_USAGE_DEFAULT,
                      sizeof(uint32) * m_numIndices,
                      D3D11_BIND_INDEX_BUFFER,
                      0,
                      0,
                      1,
                      0,
                      0,
                      mindices);
    // Create Never Changes
    neverChanges = graphMan.createBuffer();
    neverChanges->init(D3D11_USAGE_DEFAULT,
                       sizeof(CBNeverChanges),
                       D3D11_BIND_CONSTANT_BUFFER,
                       0,
                       0,
                       0,
                       0,
                       0,
                       nullptr);
    // Create Change On Resize
    changeOnResize = graphMan.createBuffer();
    changeOnResize->init(D3D11_USAGE_DEFAULT,
                         sizeof(CBChangeOnResize),
                         D3D11_BIND_CONSTANT_BUFFER,
                         0,
                         0,
                         0,
                         0,
                         0,
                         nullptr);
    // Create Change Every Frame
    changeEveryFrame = graphMan.createBuffer();
    changeEveryFrame->init(D3D11_USAGE_DEFAULT,
                           sizeof(CBChangesEveryFrame),
                           D3D11_BIND_CONSTANT_BUFFER,
                           0,
                           0,
                           0,
                           0,
                           0,
                           nullptr);
    // Mesh Texture
    meshTexture = graphMan.createTexture2D();
    meshTexture->init(L"seafloor.dds");

    // Sampler
    sampler = graphMan.createSampler();
    sampler->init(D3D11_FILTER_MIN_MAG_MIP_LINEAR,
                  D3D11_TEXTURE_ADDRESS_WRAP,
                  D3D11_TEXTURE_ADDRESS_WRAP,
                  D3D11_TEXTURE_ADDRESS_WRAP,
                  D3D11_COMPARISON_NEVER,
                  0,
                  D3D11_FLOAT32_MAX);
    
    //m_graphicsAPI->createDeviceAndSwapChain(m_window);
    m_graphicsAPI->createTextureForBackBuffer(backBuffer);
    m_graphicsAPI->createTexture(depthStencil);
    m_graphicsAPI->createDepthStencilView(depthStencil, depthStencilView);
    m_graphicsAPI->createRenderTargetView(backBuffer, renderTargetView);
    m_graphicsAPI->createVertexShader(vertexShader);
    m_graphicsAPI->createInputLayout(vertexShader, inputLayout);
    m_graphicsAPI->createPixelShader(pixelShader);
    // Create vertex buffer
    m_graphicsAPI->createBuffer(vertexBuffer);
    // Create Index Buffer
    m_graphicsAPI->createBuffer(indexBuffer);
    // Create Constant Buffer - Never Changes
    m_graphicsAPI->createBuffer(neverChanges);
    // Create Constant Buffer - Changes On Resize
    m_graphicsAPI->createBuffer(changeOnResize);
    // Create Constant Buffer - Change Every Frame
    m_graphicsAPI->createBuffer(changeEveryFrame);
    // Load texture
    //if (_meshTexture.expired()) {
    //  return false;
    //}
    //auto MTObj = _meshTexture.lock();
    //auto tmpMT = reinterpret_cast<buDXTexture2D*>(MTObj.get());
    // stb-image
    //hr = DirectX::CreateDDSTextureFromFile(m_device, tmpMT->m_filepath.c_str(), NULL, &tmpMT->m_shaderSubresource);
    // hr = D3DX11CreateShaderResourceViewFromFile(g_pd3dDevice, L"seafloor.dds", NULL, NULL, &g_pTextureRV, NULL);
    // Create sampler
    m_graphicsAPI->createSamplerState(sampler);
    // Create view matrix
    m_World = buMatrix4x4::IDENTITY;

    // Initialize View matrix
    buVector3F Eye(0.0f, 3.0f, -6.0f);
    buVector3F At(0.0f, 1.0f, 0.0f);
    buVector3F Up(0.0f, 1.0f, 0.0f);

    m_view.lookAtMatrixLH(Eye, At, Up);
    //m_view.transpose();

    CBNeverChanges cbNeverChanges;
    cbNeverChanges.mView = m_view;
    m_graphicsAPI->updateSubresource(neverChanges,
                                     0,
                                     nullptr,
                                     &cbNeverChanges,
                                     0,
                                     0);
    // Initialize the projection matrix
    m_projection.perspectiveMatrixfovLH(buDegrees(45).getRadians(),
                                        static_cast<float>(m_screenWidth) /
                                        static_cast<float>(m_screenHeight),
                                        0.01f,
                                        100.0f);
    //m_projection.transpose();

    CBChangeOnResize cbChangesOnResize;
    cbChangesOnResize.mProjection = m_projection;
    m_graphicsAPI->updateSubresource(changeOnResize,
                                     0,
                                     nullptr, 
                                     &cbChangesOnResize, 
                                     0,
                                     0);
  }

  void buGameApp_UnitTest::onDestroy()
  {
    m_graphicsAPI->cleanUp();
    // Shutdown module
    buCoreGraphicsAPI::shutDown();
    //delete graphicAPI;
    m_directXPlug.destroy();
  }

  void buGameApp_UnitTest::onUpdate(float _deltaTime)
  {
    m_graphicsAPI->update();
    m_World.rotateMatrixY(_deltaTime);
    m_meshColor.x = (buMath::sinf(_deltaTime * 1.0f) + 1.0f) * 0.5f;
    m_meshColor.y = (buMath::cosf(_deltaTime * 3.0f) + 1.0f) * 0.5f;
    m_meshColor.z = (buMath::sinf(_deltaTime * 5.0f) + 1.0f) * 0.5f;
  }


  void buGameApp_UnitTest::onRender()
  {
    // Set viewport
    m_graphicsAPI->setViewport(viewport);
    // Set Render Targets
    m_graphicsAPI->setRenderTargets(1, renderTargetView, depthStencilView);
    // Clear the back buffer 
    m_graphicsAPI->clearRenderTargetView(renderTargetView, ClearColor);
    // Clear depth stencil view
    m_graphicsAPI->clearDepthStencilView(depthStencilView, 
                                         D3D11_CLEAR_DEPTH,
                                         1.0f, 
                                         0);
    // Set primitive topology
    m_graphicsAPI->setPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    // Update variables that change once per frame
    CBChangesEveryFrame cb;
    //m_World.transpose();
    cb.mWorld = m_World;
    cb.vMeshColor = m_meshColor;
     
    m_graphicsAPI->updateSubresource(changeEveryFrame, 0, nullptr, &cb, 0, 0);
    // Set vertex buffer
    m_graphicsAPI->setVertexBuffers(vertexBuffer);
    // Set Index buffer
    m_graphicsAPI->setIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
    // Set Vertex Shader
    m_graphicsAPI->setVertexShader(vertexShader);
    // Set never changes constant buffers
    m_graphicsAPI->VSsetConstantBuffers(neverChanges, 0, 1);
    // Set changes on resize constant buffersm_numVertices
    m_graphicsAPI->VSsetConstantBuffers(changeOnResize, 1, 1);
    // Set change every frame constant buffers
    m_graphicsAPI->VSsetConstantBuffers(changeEveryFrame, 2, 1);
    // Set the input layout
    m_graphicsAPI->setInputLayout(inputLayout);
    // Set Pixel shader
    m_graphicsAPI->setPixelhader(pixelShader);
    // Set change every frame buffer.
    m_graphicsAPI->PSsetConstantBuffers(changeEveryFrame, 2, 1);
    // Set Mesh texture
    //if (_meshTexture.expired()) {
    //  return;
    //}
    //auto MTObj = _meshTexture.lock();
    //auto tmpMT = reinterpret_cast<buDXTexture2D*>(MTObj.get());
    //m_deviceContext->PSSetShaderResources(0, 1, &tmpMT->m_shaderSubresource);
    // Set Sampler

    // Set samplers
    m_graphicsAPI->PSsetSamplers(sampler, 0, 1);
    // Draw
    m_graphicsAPI->drawIndexed(m_numIndices, 0, 0);
    // Present
    m_graphicsAPI->present(0, 0); 
  }
}