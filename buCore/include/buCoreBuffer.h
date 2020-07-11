/*
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
#include <buPrerequisitesCore.h>

namespace buEngineSDK {
	class buCoreBuffer
	{
	public:
		/**
		 * @brief 
		 */
		buCoreBuffer() = default;
		/**
		 * @brief 
		 */
		~buCoreBuffer() {};
		/**
		 * @brief 
		 */
		virtual void
		init(uint32 Usage, uint32 ByteWidth, uint32 BindFlags,
			   uint32 CPUAccessFlags, uint32 startSlot, uint32 numBuffers,
				 uint32 stride, uint32 offset, void* bufferData) = 0;
	private:

	};
}
