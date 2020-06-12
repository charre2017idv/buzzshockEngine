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
	class buPlugger
	{
	public:
		/**
		 * @brief Default constructor 
		 */
		buPlugger() = default;
		/**
		 * @brief Destructor 
		 */
		~buPlugger();
		/** 
		 * @brief Method in charge of initialize a plug in from a extern dll.
		 * @param LPCSTR _dllName DLL name.
		 * @return Boolean value to check if the initialization of the plug in 
		 * was correct.
		 * @bug None.
		 */
		bool 
		CreatPlugIn(LPCSTR _dllName);
	public:
		//String m_dllName;
	};

	buPlugger::~buPlugger()
	{
	}

	inline bool buPlugger::CreatPlugIn(LPCSTR _dllName)
	{
		HINSTANCE hInstance = LoadLibraryExA(
			_dllName,
			nullptr,
			LOAD_WITH_ALTERED_SEARCH_PATH);

		// Check that the instances isnt null
		if (!hInstance) {
			return false;
		}

		// Realese the library.
		FreeLibrary(hInstance);
		return true;
	}
}