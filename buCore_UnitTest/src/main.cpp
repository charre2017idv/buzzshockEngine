/**
 * @file main.cpp
 * @version 1.0
 * @date 27/06/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief File in charge of Checking the unit testing of the Core.
 */
#include <buPrerequisitesCore.h>
#include <buPluggin.h>
#include <buCoreGraphicsAPI.h>
#include <gtest/gtest.h>

using namespace buEngineSDK;

int
main(int argc, char** argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
 /**
  * @brief 
  * @param 
  * @return 
  * @bug 
  */
 TEST(buCore, FuncTest) {
   // ARRANGE
   buPluggin plug;

   // ACT
   

   if (plug.createPluggin("buDX_APId.dll")) {
     //using fnProt = buCoreGraphicsAPI * (*)();

     auto createGraphicsAPI = reinterpret_cast<fnGraphicsAPIProt>(plug.getProcedureByName("createGraphicAPI"));

     buCoreGraphicsAPI::startUp();
     buCoreGraphicsAPI* graphicAPI = createGraphicsAPI();
     g_graphicsAPI().setObject(graphicAPI);
     buCoreGraphicsAPI::instance().testFunc();
     buCoreGraphicsAPI::shutDown();
     //delete graphicAPI;
     plug.destroy();
   }
   else {
     std::cout << "Plugin not found!" << std::endl;
   }
   



   // ASSERT
   ASSERT_EQ(plug.createPluggin("buDX_APId.dll"), true);

 }