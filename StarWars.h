/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary:
------------------------------------------*/
#ifndef STARWARS_H
#define STARWARS_H
#include "SpaceShip.h"

class StarWars : public SpaceShip
{
private:
  std::string m_pilot;
  std::string m_lw;
  std::string m_univ;
  int m_currhull;
  int m_shield;
  int m_atkpwr;
  int m_maxhull;

public:
  StarWars(std::string univ, std::string pilot, int atkpwr, int maxhull, int shield, std::string lw);
  ~StarWars();
  int attackPower() const;
  int currentHull() const;
  int maxHull() const;
  bool takeDamage(int amount);
  bool shields();
  std::string universe() const;
  std::string status() const;
};
#endif
