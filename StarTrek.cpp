/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary:
------------------------------------------*/
#include "StarTrek.h"
//-----------------------------------------------------------------------------
//                                                                           //
//     CONSTRUCTOR                                                           //
//                                                                           //
//-----------------------------------------------------------------------------
StarTrek::StarTrek(std::string univ, std::string captain, int atkpwr, int crew, int maxhull, int shield)
{
  m_univ = univ;
  m_captain = captain;
  m_atkpwr = atkpwr;
  m_crew = crew;
  m_maxhull = maxhull;
  m_shield = shield;
  m_currhull = maxhull;
}

//-----------------------------------------------------------------------------
//                                                                           //
//      DESTRUCTOR                                                           //
//                                                                           //
//-----------------------------------------------------------------------------
StarTrek::~StarTrek()
{
  std::cout << "The final message from " << m_captain << ": My greatest honor was being the captain for "<< m_crew <<" crew members." << '\n';
}

//-----------------------------------------------------------------------------
//                                                                           //
//     ATTACK POWER                                                          //
//                                                                           //
//-----------------------------------------------------------------------------
int StarTrek::attackPower() const
{
  return(m_atkpwr);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     CURRENT HULL                                                          //
//                                                                           //
//-----------------------------------------------------------------------------
int StarTrek::currentHull() const
{
  return(m_currhull);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     MAX HULL                                                              //
//                                                                           //
//-----------------------------------------------------------------------------
int StarTrek::maxHull() const
{
  return(m_maxhull);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     TAKE DAMAGE                                                           //
//                                                                           //
//-----------------------------------------------------------------------------
bool StarTrek::takeDamage(int amount)
{
  if(m_shield == 1)
  {
    m_currhull -= (amount / 2);
  }
  else
  {
    m_currhull -= amount;
  }

  if(m_currhull <= 0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

//-----------------------------------------------------------------------------
//                                                                           //
//     SHIELDS                                                               //
//                                                                           //
//-----------------------------------------------------------------------------
bool StarTrek::shields()
{
  return(m_shield);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     UNIVERSE                                                              //
//                                                                           //
//-----------------------------------------------------------------------------
std::string StarTrek::universe() const
{
  return(m_univ);
}

//-----------------------------------------------------------------------------
//                                                                           //
//      STATUS                                                               //
//                                                                           //
//-----------------------------------------------------------------------------
std::string StarTrek::status() const
{
  std::string status = m_captain + "'s ship holding " + std::to_string(m_crew) + " crew members has " + std::to_string(m_currhull) + " out of " + std::to_string(m_maxhull) + " remaining.\n";
  return(status);
}









//Free Space
