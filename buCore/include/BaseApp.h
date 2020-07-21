/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include "buPrerequisitesCore.h"
#include <buCoreGraphicsAPI.h>
#include <buPluggin.h>

// #include "Window.hpp"
// #include "System.hpp"
//#include "Graphics.hpp"

namespace buEngineSDK {
	class BU_CORE_EXPORT BaseApp
	{
	public:
		/**
		 * @brief Default constructor
		 */
		BaseApp() = default;
		/**
		 * @brief Destructor
		 */
		~BaseApp() {};
		/** 
		 * @brief Method in charge of initialize the main loop and systems of the 
		 * graphics.
		 * @return A integer, usually zero.
		 * @bug Error loading the texture from file.
		 */
		int32 
		run();
	protected:
		/** 
		 * @brief Method in charge of creating a virtual method that can be used in
		 * gameApp.
		 */
		virtual void 
		onCreate() {};

		/** 
		 * @brief Method in charge of destroying the game settings and members. This
		 * method can be used in the gameApp.
		 */
		virtual void
		onDestroy() {};

		/** 
		 * @brief Virtual method in charge of updating the logical information of 
		 * the game. This method can be used in the gameApp.
		 * @param _deltaTime Variable in charge of updating the game time.
		 */
		virtual void
		onUpdate(float _deltaTime = 0) { (void)_deltaTime;};

		/** 
		 * @brief Virtual method in charge of drawing on screen all the visual info.
		 * This method can be used in the gameApp.
		 */
		virtual void
		onRender() {};
	private:
		/** 
		* @brief Method in charge of creating a window in the App.
		* @return A boolean value.
		*/
		bool
		createWindow();

		/** 
		 * @brief Method the updates the logic information that the users will not 
		 * be available to modify.
		 * @param _deltaTime Variable in charge of updating the game time.
		 */
		void
		update(float _deltaTime);

		/** 
		 * @brief Method that draw the information that the user will not be
		 * available to modify.
		 */
		void 
		render();

		/**
		 * @brief Method that initialize the modules and plug-ins for the engine.
		 */
		void 
		initSystems();

		/** 
		 * @brief Method that destroys the systems of the engine.
		 */
		void 
		destroySystems() {};
		public:
		/**
		* @brief Method that set the events and messages for the game.
		*/
		static LRESULT CALLBACK
		handelWindowEvent(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam);

  protected:
		/*
		 * @brief Member in charge of getting the dll of directX.
		 */
    buPluggin m_directXPlug;

		/**
		 * @brief Member in charge of getting the dll of a external texture lib. 
		 */
    buPluggin m_devILPlug;

		/**
		 * @brief Member that sets the instance address memory that will be used in
		 * the graphics API. 
		 */
		void* m_instance;

		/**
		* @brief Member that sets the window reference.
		*/
		HWND m_window ;

		/**
		 * @brief Member in charge of setting the name of the window.
		 */
		String m_windowName;

		/**
		 * @brief Member in charge of setting the screen width of the game window.
		 */
		int32 m_screenWidth = 0;

		/**
		 * @brief Member in charge of setting the screen height of the game window.
		 */
		int32 m_screenHeight = 0;

		/**
		 * @brief Member in charge of storing the graphicsAPI context.
		 */
		buCoreGraphicsAPI* m_graphicsAPI;

	};
}
