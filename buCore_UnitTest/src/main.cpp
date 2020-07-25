/**
 * @file main.cpp
 * @version 1.0
 * @date 27/06/2020
 * @author Roberto Charreton Kaplun (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @brief File in charge of Checking the unit testing of the Core.
 */
#include <buPrerequisitesCore.h>
#include <gtest/gtest.h>
#include "buGameApp_UnitTest.h"

using namespace buEngineSDK;

buGameApp_UnitTest App;

// int
// main(int argc, char** argv) {
//   printf("Running main() from %s\n", __FILE__);
//   testing::InitGoogleTest(&argc, argv);
// 
//   try
//   {
//     App.run(); 
// 
//   }
//   catch (int e)
//   {
// 
//   }
// 
//   return RUN_ALL_TESTS();
// }

int32 main()
{
//   try
//   {
//     App.run();
//   }
//   catch (const std::exception&)
//   {
// 
//   }
  return App.run();
}
