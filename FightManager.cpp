/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 04 Space Wars
Date Last Modified: 02/13/2017
File Summary:
------------------------------------------*/
#include "FightManager.h"

//-----------------------------------------------------------------------------
//                                                                           //
//     CONSTRUCTOR                                                           //
//                                                                           //
//-----------------------------------------------------------------------------
FightManager::FightManager(std::string filename)
{
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open())
  {
    shipList = new LinkedList<SpaceShip*>;//startrek = new LinkedList<StarTrek>;
    std::string line;


    while(!inFile.eof())
    {

      std::string univ = "";
      std::string pilot = "";
      std::string captain = "";
      std::string atkpwr = "";
      std::string crew = "";
      std::string maxhull = "";
      std::string shield = "";
      std::string lw = "";

      //std::cout << "Repeat " << test << std::endl;

      std::getline(inFile, univ, ',');
      if(univ == "StarWars")
      {
        std::getline(inFile, pilot, ',');
        std::getline(inFile, atkpwr, ',');
        std::getline(inFile, maxhull, ',');
        std::getline(inFile, shield, ',');
        std::getline(inFile, lw);

        //Debug
        //std::cout << "Made a StarWars\n";
        //std::cout << univ << " " << pilot << " " << atkpwr << " " << maxhull << " " << shield << " " << lw <<std::endl;

        SpaceShip* newStarWars = new StarWars(univ, pilot, std::stoi(atkpwr), std::stoi(maxhull), std::stoi(shield), lw);

        shipList->addBack(newStarWars);
      }

      if(univ == "StarTrek")
      {
        std::getline(inFile, captain, ',');
        std::getline(inFile, atkpwr, ',');
        std::getline(inFile, crew, ',');
        std::getline(inFile, maxhull, ',');
        std::getline(inFile, shield);

        //Debug
        //std::cout << "Made a StarTrek\n";
        //std::cout << univ << " " << captain << " " << atkpwr << " " << crew << " " << maxhull << " " << shield << std::endl;

        SpaceShip* newStarTrek = new StarTrek(univ, captain, std::stoi(atkpwr), std::stoi(crew), std::stoi(maxhull), std::stoi(shield));

        shipList->addBack(newStarTrek);

      }

    }
    std::cout << "Battle commencing...\n";
    std::cout << "3..\n";
    std::cout << "2..\n";
    std::cout << "1..\n";

    inFile.close();

  }

  //Debug
  /*for(int i = 1; i <= shipList->getLength(); i++)
  {
    std::cout << shipList->getEntry(i)->status();
  }*/
}

//-----------------------------------------------------------------------------
//                                                                           //
//     DESTRUCTOR                                                            //
//                                                                           //
//-----------------------------------------------------------------------------
FightManager::~FightManager()
{
  //Delete Objects inside of node

  delete shipList;
  std::cout << "We have won the battle.\n";
  std::cout << m_winner << '\n';
}

//-----------------------------------------------------------------------------
//                                                                           //
//     STAR WARS ATTACK                                                      //
//                                                                           //
//-----------------------------------------------------------------------------
int FightManager::starAtk()
{
  for(int i = 1; i <= shipList->getLength(); i++)
  {
      if(shipList->getEntry(i)->universe() == "StarTrek")
      {
        return(i);
      }
  }
  return(0);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     STAR TREK ATTACK                                                      //
//                                                                           //
//-----------------------------------------------------------------------------
int FightManager::trekAtk()
{
  for(int i = 1; i <= shipList->getLength(); i++)
  {
      if(shipList->getEntry(i)->universe() == "StarWars")
      {
        return(i);
      }
  }
  return(0);
}

//-----------------------------------------------------------------------------
//                                                                           //
//     RUN                                                                   //
//                                                                           //
//-----------------------------------------------------------------------------
void FightManager::run()
{
  int SW = 0;
  int ST = 0;

  //int test = 1;

  //---------------------------------
  //Keep Track of amount of each ship
  for(int i = 1; i <= shipList->getLength(); i++)
  {
    if(shipList->getEntry(i)->universe() == "StarWars")
    {
      SW = SW + 1;
    }
    else
    {
      ST = ST + 1;
    }
  }
  //--------------------------------


//--------------------------------
//     Ship Battle
//--------------------------------
  while(shipList->getLength() > 1)
  {
    // If there are both ships in list
    while(SW != 0 && ST != 0)
    {
      /*for(int i = 1; i <= shipList->getLength(); i++)
      {
        std::cout << shipList->getEntry(i)->status();
      }
      std::cout << '\n';*/


      for(int i = 1; i <= shipList->getLength(); i++)
      {
        if(shipList->getEntry(i)->universe() == "StarWars")
        {
          if(shipList->getEntry(starAtk())->takeDamage(shipList->getEntry(i)->attackPower()))
          {
            shipList->removeAt(starAtk());
            ST--;
          }
        }
        //Star Trek Attack
        else
        {
          try
          {
            if(shipList->getEntry(trekAtk())->takeDamage(shipList->getEntry(i)->attackPower()))
            {
              shipList->removeAt(trekAtk());
              SW--;
            }
          }
          catch(std::invalid_argument e)
          {
            //do nothing
          }

        }
        //std::cout << "Both: " << shipList->getLength() << '\n';
      }

      //Print Status
      for(int i = 1; i <= shipList->getLength(); i++)
      {
        std::cout << shipList->getEntry(i)->status();
      }
      std::cout << '\n';
    }
    //std::cout << "Test\n";

  // If there are only StarWars
    while(SW > 1)
    {
      for(int i = 1; i <= shipList->getLength(); i++)
      {
        std::cout << shipList->getEntry(i)->status();
      }
      std::cout << '\n';

      for(int i = 1; i <= shipList->getLength(); i++)
      {
        if(i == 1)
        {
          if(shipList->getEntry(2)->takeDamage(shipList->getEntry(1)->attackPower()))
          {
            shipList->removeAt(2);
            SW--;
          }
        }
        else
        {
          if(shipList->getEntry(1)->takeDamage(shipList->getEntry(i)->attackPower()))
          {
            shipList->removeAt(1);
            SW--;
          }
        }
        //std::cout << "StarWars: " << shipList->getLength() << '\n';
      }

      for(int i = 1; i <= shipList->getLength(); i++)
      {
        std::cout << shipList->getEntry(i)->status();
      }
      std::cout << '\n';

    }


  // If there are only StarTrek
    while(ST > 1)
    {


      for(int i = 1; i <= shipList->getLength(); i++)
      {
        //std::cout << "Test\n";
        if(i == 1)
        {
          if(shipList->getEntry(2)->takeDamage(shipList->getEntry(1)->attackPower()))
          {
            shipList->removeAt(2);
            ST--;
          }
        }
        else
        {
          if(shipList->getEntry(1)->takeDamage(shipList->getEntry(i)->attackPower()))
          {
            shipList->removeAt(1);
            ST--;
          }
        }
        //std::cout << "StarTrek: " << shipList->getLength() << '\n';
      }
      for(int i = 1; i <= shipList->getLength(); i++)
      {
        std::cout << shipList->getEntry(i)->status();
      }
      std::cout << '\n';
    }
  }

//--------------------------------
//--------------------------------
//--------------------------------


  //Prints who is victorious!
  if(SW == 0)
  {
    m_winner = "StarTrek Wins!\n";
  }
  else
  {
    m_winner = "StarWars Wins!\n";
  }


}














//Space
