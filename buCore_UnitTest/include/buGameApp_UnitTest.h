/**
 * @file 
 * @version 
 * @date 00/00/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief 
 * @bug
 */
#pragma once
//#include <buPrerequisitesCore.h>
#include "BaseApp.h"
#include "buPrerequisitesCore.h"
#include <buCoreGraphicsAPI.h>
#include <buPluggin.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <buVector2F.h>
#include <buVector3F.h>
#include <buVector4F.h>
#include <buMatrix4x4.h>

namespace buEngineSDK {
	struct SimpleVertex
	{
		buVector3F Pos;
		buVector2F Tex;
	};

	struct CBNeverChanges
	{
		buMatrix4x4 mView;
	};

	struct CBChangeOnResize
	{
		buMatrix4x4 mProjection;
	};

	struct CBChangesEveryFrame
	{
		buMatrix4x4 mWorld;
		buVector4F vMeshColor;
	};
	class buGameApp_UnitTest : public BaseApp
	{
	public:
		/**
		 * @brief Constructor
		 */
		buGameApp_UnitTest();
		/**
		 * @brief Destructor
		 */
		~buGameApp_UnitTest();
		/** 
		 * @brief Method that allows the user to initialize the information.
		 */
		void 
		onCreate() override;

		/** 
		 * @brief Method that destroys the modules and components of the app.
		 */
		void
		onDestroy() override;

		/** 
		 * @brief Method that updates the logic information of the app.
		 */
		void
		onUpdate(float _deltaTime = 0) override;

		/** 
		 * @brief Method that draw the objects on the screen.
		 */
		void
		onRender() override;
	private: 
		/*
		 * @brief Member that will be used as a back buffer texture. 
		 */
		SPtr<buCoreTexture2D> backBuffer;

		/**
		 * @brief Member that will be used as a depth stencil texture.
		 */
		SPtr<buCoreTexture2D> depthStencil;

		/**
		 * @brief Member that creates a depth stencil view object.
		 */
		SPtr<buCoreDepthStencilView> depthStencilView;

		/**
		 * @brief Member that creates a render target view object. 
		 */
		SPtr<buCoreRenderTargetView> renderTargetView;

		/**
		 * @brief Member that creates a viewport object.
		 */
		SPtr<buCoreViewport> viewport;

		/**
		 * @brief Member that creates a vertex shader object. 
		 */
		SPtr<buCoreVertexShader> vertexShader;

		/**
		 * @brief Member that creates an input layout object. 
		 */
		SPtr<buCoreInputLayout> inputLayout;

		/**
		 * @brief Member that creates a pixel shader object. 
		 */
		SPtr<buCorePixelShader> pixelShader;

		/**
		 * @brief Member that creates a vertex buffer object.
		 */
		SPtr<buCoreBuffer> vertexBuffer;

		/**
		 * @brief Member that creates a index buffer object.
		 */
		SPtr<buCoreBuffer> indexBuffer;

		/**
		 * @brief Member that creates a texture for a mesh.
		 */
		SPtr<buCoreTexture2D> meshTexture;

		/**
		 * @brief Member that creates a sampler object. 
		 */
		SPtr<buCoreSampler> sampler;

		/**
		 * @brief Member that creates a never changes buffer. 
		 */
		SPtr<buCoreBuffer> neverChanges;

		/**
		 * @brief Member that creates a change on resize buffer.
		 */
		SPtr<buCoreBuffer> changeOnResize;

		/**
	 	 * @brief Member that creates a changes every frame object. 
		 */
		SPtr<buCoreBuffer> changeEveryFrame;

		/**
		 * @brief Member that sets the world matrix
		 */
		buMatrix4x4 m_World;

		/**
		 * @brief Member that sets the view matrix.
		 */
		buMatrix4x4 m_view;

		/**
		 * @brief Member that set the projection matrix. 
		 */
		buMatrix4x4 m_projection;
		
		/**
		 * @brief Member that sets the color of the mesh.
		 */
		buVector4F m_meshColor = buVector4F(0.7f, 0.7f, 0.7f, 1.0f);
		
		/**
		 * @brief Member that sets the clear color 
		 */
		float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; 
		
		/**
		 * @brief Tempporal data structure that sets the vertices of a cube 
		 */
		SimpleVertex mvertices[24] =
		{
				{ buVector3F(-1.0f, 1.0f, -1.0f), buVector2F(0.0f, 0.0f) },
				{ buVector3F(1.0f, 1.0f, -1.0f), buVector2F(1.0f, 0.0f) },
				{ buVector3F(1.0f, 1.0f, 1.0f), buVector2F(1.0f, 1.0f) },
				{ buVector3F(-1.0f, 1.0f, 1.0f), buVector2F(0.0f, 1.0f) },

				{ buVector3F(-1.0f, -1.0f, -1.0f), buVector2F(0.0f, 0.0f) },
				{ buVector3F(1.0f, -1.0f, -1.0f), buVector2F(1.0f, 0.0f) },
				{ buVector3F(1.0f, -1.0f, 1.0f), buVector2F(1.0f, 1.0f) },
				{ buVector3F(-1.0f, -1.0f, 1.0f), buVector2F(0.0f, 1.0f) },

				{ buVector3F(-1.0f, -1.0f, 1.0f), buVector2F(0.0f, 0.0f) },
				{ buVector3F(-1.0f, -1.0f, -1.0f), buVector2F(1.0f, 0.0f) },
				{ buVector3F(-1.0f, 1.0f, -1.0f), buVector2F(1.0f, 1.0f) },
				{ buVector3F(-1.0f, 1.0f, 1.0f), buVector2F(0.0f, 1.0f) },

				{ buVector3F(1.0f, -1.0f, 1.0f), buVector2F(0.0f, 0.0f) },
				{ buVector3F(1.0f, -1.0f, -1.0f), buVector2F(1.0f, 0.0f) },
				{ buVector3F(1.0f, 1.0f, -1.0f), buVector2F(1.0f, 1.0f) },
				{ buVector3F(1.0f, 1.0f, 1.0f), buVector2F(0.0f, 1.0f) },

				{ buVector3F(-1.0f, -1.0f, -1.0f), buVector2F(0.0f, 0.0f) },
				{ buVector3F(1.0f, -1.0f, -1.0f), buVector2F(1.0f, 0.0f) },
				{ buVector3F(1.0f, 1.0f, -1.0f), buVector2F(1.0f, 1.0f) },
				{ buVector3F(-1.0f, 1.0f, -1.0f), buVector2F(0.0f, 1.0f) },

				{ buVector3F(-1.0f, -1.0f, 1.0f), buVector2F(0.0f, 0.0f) },
				{ buVector3F(1.0f, -1.0f, 1.0f), buVector2F(1.0f, 0.0f) },
				{ buVector3F(1.0f, 1.0f, 1.0f), buVector2F(1.0f, 1.0f) },
				{ buVector3F(-1.0f, 1.0f, 1.0f), buVector2F(0.0f, 1.0f) },

    };
		/**
		 * @brief Member that stores the number of vertex of the cube. 
		 */
		int32 m_numVertices = 24;

		/**
		 * @brief Temporal data structure that sets the indeces of the cube.
		 */
		uint32 mindices[36] =
		{
				 3,1,0,
				2,1,3,

				6,4,5,
				7,4,6,

				11,9,8,
				10,9,11,

				14,12,13,
				15,12,14,

				19,17,16,
				18,17,19,

				22,20,21,
				23,20,22
		};
		/**
		 * @brief Member that store the number of indices of the cube. 
		 */
		int32 m_numIndices = 36;
	};
}
