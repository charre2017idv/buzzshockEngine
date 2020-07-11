#include "buDXGraphicsAPI.h"

namespace buEngineSDK {
  buDXGraphicsAPI::buDXGraphicsAPI()
  {
    m_swapchain = nullptr;
    m_device = nullptr;
    m_deviceContext = nullptr;
  }

  buDXGraphicsAPI::~buDXGraphicsAPI()
  {
    SAFE_RELEASE(m_swapchain);
    SAFE_RELEASE(m_deviceContext);
    SAFE_RELEASE(m_device);
  }

  void buDXGraphicsAPI::testFunc()
  {
    std::cout << "TestFunc in DX API" << std::endl;
  }

  bool buDXGraphicsAPI::init(WeakSPtr<buCoreViewport> _viewport,
                             WeakSPtr<buCoreTexture2D> _backBuffer,
                             WeakSPtr<buCoreRenderTargetView> _renderTargetView,
                             WeakSPtr<buCoreVertexShader> _vertexShader,
                             WeakSPtr<buCoreInputLayout> _inputLayout,
                             WeakSPtr<buCorePixelShader> _pixelShader,
                             WeakSPtr<buCoreBuffer> _vertexBuffer)
  {
    HRESULT hr = S_OK;

    RECT rc;
    GetClientRect(g_hWnd, &rc);
    UINT width = rc.right - rc.left;
    UINT height = rc.bottom - rc.top;

    UINT createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    Vector<D3D_DRIVER_TYPE> driverTypes = 
    {
      D3D_DRIVER_TYPE_HARDWARE,
      D3D_DRIVER_TYPE_WARP,
      D3D_DRIVER_TYPE_REFERENCE 
    };

    Vector<D3D_FEATURE_LEVEL> featureLevels =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    
    memset(&m_swapchainDesc, 0, sizeof(m_swapchainDesc));
    m_swapchainDesc.BufferCount = 1;
    m_swapchainDesc.BufferDesc.Width = width;
    m_swapchainDesc.BufferDesc.Height = height;
    m_swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    m_swapchainDesc.BufferDesc.RefreshRate.Numerator = 60;
    m_swapchainDesc.BufferDesc.RefreshRate.Denominator = 1;
    m_swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    m_swapchainDesc.OutputWindow = g_hWnd;
    m_swapchainDesc.SampleDesc.Count = 1;
    m_swapchainDesc.SampleDesc.Quality = 0;
    m_swapchainDesc.Windowed = TRUE;

    for (uint32 i = 0; i < driverTypes.size(); i++) {
      g_driverType = driverTypes[i];
      hr = D3D11CreateDeviceAndSwapChain(NULL, 
                                         g_driverType,
                                         NULL,
                                         createDeviceFlags,
                                         featureLevels.data(),
                                         featureLevels.size(),
                                         D3D11_SDK_VERSION, 
                                         &m_swapchainDesc,
                                         &m_swapchain,
                                         &m_device, 
                                         &g_featureLevel,
                                         &m_deviceContext);
      if (SUCCEEDED(hr)) {
        break;
      }
    }
    if (FAILED(hr)) {
      return hr;
    }

    // Create back buffer
    if (_backBuffer.expired()) {
      return false;
    }
    auto bbObj = _backBuffer.lock();
    auto tmpBB = reinterpret_cast<buDXTexture2D*>(bbObj.get());
    //ID3D11Texture2D* pBackBuffer = NULL;
    hr = m_swapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&tmpBB->m_texture);
    if (FAILED(hr)) {
      return hr;
    }

    // Create a render target view
    if (_renderTargetView.expired()) {
      return false;
    }
    auto RTVObj = _renderTargetView.lock();
    auto tmpRTV = reinterpret_cast<buDXRenderTargetView*>(RTVObj.get());

    hr = m_device->CreateRenderTargetView(tmpBB->m_texture, NULL, 
                                          &tmpRTV->m_renderTargetView);

    tmpBB->m_texture->Release();
    if (FAILED(hr)) {
      return hr;
    }

    m_deviceContext->OMSetRenderTargets(1, &tmpRTV->m_renderTargetView, NULL);

    // Setup the viewport
    
    if (_viewport.expired()) {
      return false;
    }
    auto vpObj = _viewport.lock();
    auto tmpvp = reinterpret_cast<buDXViewport*>(vpObj.get());
    
    m_deviceContext->RSSetViewports(1, &tmpvp->m_viewport);

    // Compile the vertex shader
    if (_vertexShader.expired()) {
      return false;
    }
    auto vsObj = _vertexShader.lock();
    auto tmpVS= reinterpret_cast<buDXVertexShader*>(vsObj.get());

    // Create the vertex shader
    hr = m_device->CreateVertexShader(tmpVS->m_compileVertexShader->GetBufferPointer(),
                                      tmpVS->m_compileVertexShader->GetBufferSize(),
                                      NULL, 
                                      &tmpVS->m_vertexShader);
    
    if (FAILED(hr)) {
      tmpVS->m_compileVertexShader->Release();
      return hr;
    }

    // Define the input layout

    if (_inputLayout.expired()) {
      return false;
    }
    auto ILObj = _inputLayout.lock();
    auto tmpIL = reinterpret_cast<buDXInputLayout*>(ILObj.get());

    // Create the input layout
    hr = m_device->CreateInputLayout(tmpIL->m_descriptor.data(),
                                     tmpIL->m_descriptor.size(), 
                                     tmpVS->m_compileVertexShader->GetBufferPointer(),
                                     tmpVS->m_compileVertexShader->GetBufferSize(),
                                     &tmpIL->m_inputLayout);

    tmpVS->m_compileVertexShader->Release();
    if (FAILED(hr)) {
      return hr;
    }

    // Set the input layout
    m_deviceContext->IASetInputLayout(tmpIL->m_inputLayout);

    // Compile the pixel shader
    if (_pixelShader.expired()) {
      return false;
    }
    auto PSObj = _pixelShader.lock();
    auto tmpPS = reinterpret_cast<buDXPixelShader*>(PSObj.get());

    // Create the pixel shader
    hr = m_device->CreatePixelShader(tmpPS->m_compilePixelShader->GetBufferPointer(),
                                     tmpPS->m_compilePixelShader->GetBufferSize(),
                                     NULL,
                                     &tmpPS->m_pixelShader);
    tmpPS->m_compilePixelShader->Release();

    if (FAILED(hr)) {
      return hr;
    }

    // Create vertex buffer
    if (_vertexBuffer.expired()) {
      return false;
    }
    auto VBObj = _vertexBuffer.lock();
    auto tmpBV = reinterpret_cast<buDXBuffer*>(VBObj.get());

    SimpleVertex vertices[] =
    {
        buVector3F(0.0f, 0.5f, 0.5f),
        buVector3F(0.5f, -0.5f, 0.5f),
        buVector3F(-0.5f, -0.5f, 0.5f),
    };

    tmpBV->init(D3D11_USAGE_DEFAULT,
                sizeof(SimpleVertex) * 3,
                D3D11_BIND_VERTEX_BUFFER,
                0,
                0,
                1,
                sizeof(SimpleVertex), 
                0,
                vertices);

    hr = m_device->CreateBuffer(&tmpBV->m_descriptor,
                                &tmpBV->m_subresourceData,
                                &tmpBV->m_buffer);
    if (FAILED(hr)) {
      return hr;
    }

    // Set vertex buffer
    m_deviceContext->IASetVertexBuffers(tmpBV->m_startSlot,
                                        tmpBV->m_numBuffers,
                                        &tmpBV->m_buffer, 
                                        (UINT*)&tmpBV->m_stride,
                                        (UINT*)&tmpBV->m_offset);

    // Set primitive topology
    m_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    return S_OK;
  }

  bool buDXGraphicsAPI::initWindow(void* hInstance, void* _wndProc)
  {
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = reinterpret_cast<WNDPROC>(_wndProc);
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = reinterpret_cast<HINSTANCE>(hInstance);
    wcex.hIcon = LoadIcon(reinterpret_cast<HINSTANCE>(hInstance), (LPCTSTR)IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "TutorialWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);
    if (!RegisterClassEx(&wcex))
      return E_FAIL;

    // Create window
    g_hInst = hInstance;
    RECT rc = { 0, 0, 640, 480 };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    g_hWnd = CreateWindow("TutorialWindowClass", "Buzzshock Engine",
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, reinterpret_cast<HINSTANCE>(hInstance),
      NULL);
    if (!g_hWnd)
      return E_FAIL;

    ShowWindow(g_hWnd, SW_SHOW);

    return S_OK;
  }

  void buDXGraphicsAPI::cleanUp()
  {
    SAFE_RELEASE(m_deviceContext);
    //SAFE_RELEASE(g_pVertexBuffer);
    //SAFE_RELEASE(g_pVertexLayout);
    ///SAFE_RELEASE(g_pVertexShader);
    //SAFE_RELEASE(g_pPixelShader);
    //SAFE_RELEASE(m_renderTargetView);
    SAFE_RELEASE(m_device);
    SAFE_RELEASE(m_swapchain);
  }

  void buDXGraphicsAPI::render(WeakSPtr<buCoreRenderTargetView> _renderTargetView,
                               WeakSPtr<buCoreVertexShader> _vertexShader,
                               WeakSPtr<buCorePixelShader> _pixelShader)
  {
    // Clear the back buffer 
    float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red,green,blue,alpha
    if (_renderTargetView.expired()) {
      return;
    }
    auto RTVObj = _renderTargetView.lock();
    auto tmpRTV = reinterpret_cast<buDXRenderTargetView*>(RTVObj.get());
    m_deviceContext->ClearRenderTargetView(tmpRTV->m_renderTargetView, ClearColor);

    // Render a triangle
    if (_vertexShader.expired()) {
      return;
    }
    auto VSObj = _vertexShader.lock();
    auto tmpVS = reinterpret_cast<buDXVertexShader*>(VSObj.get());
    m_deviceContext->VSSetShader(tmpVS->m_vertexShader, NULL, 0);

    if (_pixelShader.expired()) {
      return;
    }
    auto PSObj = _pixelShader.lock();
    auto tmpPS = reinterpret_cast<buDXPixelShader*>(PSObj.get());
    m_deviceContext->PSSetShader(tmpPS->m_pixelShader, NULL, 0);
    m_deviceContext->Draw(3, 0);

    // Present the information rendered to the back buffer to the front buffer (the screen)
    m_swapchain->Present(0, 0);    
  }
  
  SPtr<buCoreViewport> buDXGraphicsAPI::createViewport()
  {
    auto pviewport = std::make_shared<buDXViewport>();
    return pviewport;
    //return SPtr<buCoreViewport>();
  }

  SPtr<buCoreTexture2D> buDXGraphicsAPI::createTexture2D()
  {
    auto ptexture2D = std::make_shared<buDXTexture2D>();
    return ptexture2D;
  }

  SPtr<buCoreSwapchain> buDXGraphicsAPI::createSwapchain()
  {
    auto swapchain = std::make_shared<buDXSwapchain>();
    return swapchain;
  }

  SPtr<buCoreRenderTargetView> buDXGraphicsAPI::createRenderTargetView()
  {
    auto renderTargetView = std::make_shared<buDXRenderTargetView>();
    return renderTargetView;
  }

  SPtr<buCoreVertexShader> buDXGraphicsAPI::createVertexShader()
  {
    auto vertexShader = std::make_shared<buDXVertexShader>();
    return vertexShader;
  }

  SPtr<buCorePixelShader> buDXGraphicsAPI::createPixelShader()
  {
    auto pixelShader = std::make_shared<buDXPixelShader>();
    return pixelShader;
  }

  SPtr<buCoreInputLayout> buDXGraphicsAPI::createInputLayout()
  {
    auto inputLayout = std::make_shared<buDXInputLayout>();
    return inputLayout;
  }

  SPtr<buCoreBuffer> buDXGraphicsAPI::createBuffer()
  {
    auto buffer = std::make_shared<buDXBuffer>();
    return buffer;
  }

  LRESULT buDXGraphicsAPI::WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
  {
    switch (Msg)
    {
    default: return DefWindowProc(Hw, Msg, wParam, lParam);
    }
  }
}