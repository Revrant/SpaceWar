/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary:
------------------------------------------*/
#include "StarWars.h"
//-----------------------------------------------------------------------------
//                                                                           //
//     CONSTRUCTOR                                                           //
//                                                                           //
//-----------------------------------------------------------------------------
StarWars::StarWars(std::string univ, std::string pilot, int atkpwr, int maxhull, int shield, std::string lw)
{
  m_univ = univ;
  m_pilot = pilot;
  m_atkpwr = atkpwr;
  m_maxhull = maxhull;
  m_shield = shield;
  m_lw = lw;
  m_currhull = maxhull;
}

//-----------------------------------------------------------------------------
//                                                                           //
//     DESTRUCTOR                                                            //
//                                                                           //
//-----------------------------------------------------------------------------
StarWars::~StarWars()
{
  std::cout << "The final message from " << m_pilot << ": " << m_lw << '\n';
}

//-----------------------------------------------------------------------------
//                                                                           //
//     ATTACK POWER                                                          //
//                                                                           //
//-----------------------------------------------------------------------------
int StarWars::attackPower() const
{
  return(m_atkpwr);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     CURRENT HULL                                                          //
//                                                                           //
//-----------------------------------------------------------------------------
int StarWars::currentHull() const
{
  return(m_currhull);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     MAX HULL                                                              //
//                                                                           //
//-----------------------------------------------------------------------------
int StarWars::maxHull() const
{
  return(m_maxhull);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     TAKE DAMAGE                                                           //
//                                                                           //
//-----------------------------------------------------------------------------
bool StarWars::takeDamage(int amount)
{
  if(shields())
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
bool StarWars::shields()
{
  if(m_shield == 0)
  {
    return(false);
  }
  else
  {
    return(true);
  }
}

//-----------------------------------------------------------------------------
//                                                                           //
//     UNIVERSE                                                              //
//                                                                           //
//-----------------------------------------------------------------------------
std::string StarWars::universe() const
{
  return(m_univ);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     STATUS                                                                //
//                                                                           //
//-----------------------------------------------------------------------------
std::string StarWars::status() const
{
  std::string status = m_pilot + "'s ship has " + std::to_string(m_currhull) + " out of " + std::to_string(m_maxhull) + " remaining.\n";
  return(status);
}










//Free Space
