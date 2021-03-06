#include "BaseApp.h"

namespace buEngineSDK {

  int32 BaseApp::run()
  {
    // Create Window
    m_windowName = "Buzz shock Engine";
    m_screenWidth = 640;
    m_screenHeight = 480;
    createWindow();
    // Create systems
    initSystems();

    
    // Sends message onCreate method
    onCreate();

    // Main loop
    MSG msg = { nullptr };
    while (WM_QUIT != msg.message) {
      if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
      else {
        // Update the game time
        static float t = 0.0f;
        //if (g_driverType == D3D_DRIVER_TYPE_REFERENCE) {
        //  t += (float)3.1415926535f * 0.0125f;
        //}
        //else {
        //}
          static uint32 dwTimeStart = 0;
          uint32 dwTimeCur = GetTickCount();
          if (dwTimeStart == 0)
            dwTimeStart = dwTimeCur;
          t = (dwTimeCur - dwTimeStart) / 1000.0f;
        // Update game logic
        update(t);
        // Render frame
        render();
      }
    }

    // Destroy systems
    onDestroy();

    // Destroy all systems
    destroySystems();

    return 0;
  }

  void BaseApp::initSystems()
  {
    if (m_directXPlug.loadPluggin("buDX_APId.dll")) {
      auto createGraphicsAPI = reinterpret_cast<fnGraphicsAPIProt>(
        m_directXPlug.getProcedureByName("createGraphicAPI"));

      buCoreGraphicsAPI::startUp();
      buCoreGraphicsAPI* graphicAPI = createGraphicsAPI();
      g_graphicsAPI().setObject(graphicAPI);
      m_graphicsAPI = &g_graphicsAPI();
      m_graphicsAPI->initialize(m_window, m_screenWidth, m_screenHeight);
    }
  }

  bool BaseApp::createWindow()
  {
    auto hInstance = reinterpret_cast<HINSTANCE>(GetModuleHandle(nullptr));

    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = handelWindowEvent;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "TutorialWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);
    if (!RegisterClassEx(&wcex))
      return false;

    // Create window
    //m_instance = hInstance;
    RECT rc = { 0, 0, m_screenWidth, m_screenHeight };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    
    HWND hWd;
    hWd = CreateWindow("TutorialWindowClass",
                          "Buzz shock Engine",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT, 
                          rc.right - rc.left,
                          rc.bottom - rc.top, 
                          nullptr,
                          nullptr,
                          hInstance,
                          nullptr);
    if (!hWd)
      return false;

    ShowWindow(hWd, SW_SHOW);

    RECT clientRect;
    GetClientRect(hWd, &clientRect);

    m_screenWidth =  clientRect.right - clientRect.left;
    m_screenHeight = clientRect.bottom - clientRect.top;

    m_window = reinterpret_cast<void*>(hWd);

    return true;
  }

  void BaseApp::update(float _deltaTime = 0)
  {
    onUpdate(_deltaTime);
  }

  void BaseApp::render()
  {
    onRender();    
  }
  
  LRESULT BaseApp::handelWindowEvent(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
  {
    /*auto pThis = (BaseApp*)GetWindowLongPtr(Hw, GWLP_USERDATA);
    if (pThis != NULL) {
      return pThis->CustomDialogProcInstance(Hw, Msg, wParam, lParam);*/
    return DefWindowProc(Hw, Msg, wParam, lParam);
  }
  //LRESULT BaseApp::CustomDialogProcInstance(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
  //{
  //  PAINTSTRUCT ps;
  //  HDC hdc;
  //  /*if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
  //  {
  //    return true;
  //  }*/
  //  switch (Msg)
  //  {
  //  case WM_PAINT:
  //    hdc = BeginPaint(Hw, &ps);
  //    EndPaint(Hw, &ps);
  //    break;

  //  case WM_DESTROY:
  //    PostQuitMessage(0);
  //    break;
  //  case WM_SIZE:
  //  default:
  //    return DefWindowProc(Hw, Msg, wParam, lParam);
  //  }

  //  return 0;
  //}
}