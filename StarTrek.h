/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary:
------------------------------------------*/
#ifndef STARTREK_H
#define STARTREK_H
#include "SpaceShip.h"

class StarTrek : public SpaceShip
{
private:
  std::string m_univ;
  std::string m_captain;
  int m_currhull;
  int m_atkpwr;
  int m_crew;
  int m_maxhull;
  int m_shield;

public:
  StarTrek(std::string univ, std::string captain, int atkpwr, int crew, int maxhull, int shield);
  ~StarTrek();
  int attackPower() const;
  int currentHull() const;
  int maxHull() const;
  bool takeDamage(int amount);
  bool shields();
  std::string universe() const;
  std::string status() const;
};
#endif
