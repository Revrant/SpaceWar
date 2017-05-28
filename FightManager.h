/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary:
------------------------------------------*/
#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H
#include "StarWars.h"
#include "StarTrek.h"
#include "LinkedList.h"
#include <fstream>

class FightManager
{
private:
  LinkedList<SpaceShip*>* shipList;
  std::string m_winner;
public:
  FightManager(std::string filename);
  ~FightManager();
  int trekAtk();
  int starAtk();
  void run();
};
#endif
