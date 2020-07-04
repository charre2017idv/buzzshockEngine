#include "buDXGraphicsAPI.h"

namespace buEngineSDK {
  buDXGraphicsAPI::~buDXGraphicsAPI()
  {
  }
  void buDXGraphicsAPI::testFunc()
  {
    std::cout << "TestFunc in DX API" << std::endl;
  }
  
  SPtr<buCoreViewport> buDXGraphicsAPI::createViewport()
  {
//     auto pviewport = std::make_shared<buDXViewport>();
//     return pviewport;
    return SPtr<buCoreViewport>();
  }
}