/**
 * @file buPlugger.h
 * @version 1.0
 * @date 12/06/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief Class in charge of providing a plug in from a dll. 
 * @bug None.
 */
#pragma once

#include "buPrerequisitesUtil.h"

#if BU_PLATFORM == BU_PLATFORM_WIN32
#include <Windows.h>
#endif

namespace buEngineSDK {
  class buPluggin
  {
  public:
    /**
     * @brief Default constructor
     */
    buPluggin() = default;

    /**
     * @brief Destructor
     */
    ~buPluggin();

    /**
     * @brief Method in charge of initialize a plug in from a extern dll.
     * @param LPCSTR _dllName DLL name.
     * @return Boolean value to check if the initialization of the plug in
     * was correct.
     * @bug None.
     */
    bool
    createPluggin(const String& _dllName);

    void* 
    getProcedureByName(const String& _name);

    /**
     * @brief 
     * @param 
     * @return 
     * @bug 
     */
    void
    destroy();

  public:
    void* m_instance;
  };

  buPluggin::~buPluggin() { }

  inline bool buPluggin::createPluggin(const String& _dllName)
  {
    m_instance = LoadLibraryExA(
      _dllName.c_str(),
      nullptr,
      LOAD_WITH_ALTERED_SEARCH_PATH);

    // Check that the instances isnt null
    if (!m_instance) {
      destroy();
      return false;
    }

    

    return true;
  }


  inline void* buPluggin::getProcedureByName(const String& _name)
  {
    auto createFunction = GetProcAddress(reinterpret_cast<HINSTANCE>(m_instance),
                                         _name.c_str());

    if (!createFunction) {
      std::cout << "auto createFunction not Initialized!" << std::endl;
     // return ;
    }

    return createFunction;
  }

  inline void buPluggin::destroy()
  {
    // Realese the library.
    FreeLibrary((reinterpret_cast<HINSTANCE>(m_instance)));
  }
};