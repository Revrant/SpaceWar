/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary: Validates user inputs a file
------------------------------------------*/
#include "FightManager.h"
#include <iostream>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    FightManager fight(argv[1]);
    fight.run();
  }
  return(0);
}
