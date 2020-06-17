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
  CreatePluggin(LPCSTR _dllName);

 public:
   HINSTANCE m_instance;
 };

 buPluggin::~buPluggin() { }
 
 inline bool buPluggin::CreatePluggin(LPCSTR _dllName)
 {
  m_instance = LoadLibraryExA(
  	_dllName,
  	nullptr,
  	LOAD_WITH_ALTERED_SEARCH_PATH);
  
  // Check that the instances isnt null
  if (!m_instance) {
  	return false;
  }
  
  // Realese the library.
  FreeLibrary(m_instance);
  return true;
 }
}