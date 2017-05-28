/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary: Creates class interface
------------------------------------------*/
#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <iostream>
#include <string>

class SpaceShip
{
public:
  virtual ~SpaceShip() {};
  virtual int attackPower() const = 0;
  virtual int currentHull() const = 0;
  virtual int maxHull() const = 0;
  virtual bool takeDamage(int amount) = 0;
  virtual bool shields() = 0;
  virtual std::string universe() const = 0;
  virtual std::string status() const = 0;
};
#endif
