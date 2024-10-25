/**
 * @file main.cpp
 * @author Jhonathan Tepan (jhonathan.tepan51@myhunter.cuny.edu)
 * @brief An example main file testing the functions from the `Event` class and the 'Plan' class
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include "Event.hpp"
#include "Plan.hpp"
#include <utility>

int main(){

  Event beach_party;
  Event pool_party = Event("Jhonathan's Pool Party", 3422522);
  std::string name_of_event = pool_party.getName();
  long time_of_event = pool_party.getTimestamp();
  beach_party.setName("Rockaway beach party");
  beach_party.setTimestamp(42982498);
  std::vector<std::string> invitees = {
    "Luis",
    "Jorge",
    "Brandon",
    "Ed",
    "Abeedah",
    "Brian"
  };
  beach_party.setGuests(invitees);

  bool set_ = pool_party.addGuest("Cris");
   std::vector<std::string> invitees_for_pool = {
    "Gary",
    "Steven",
    "Milo",
    "Mathew",
    "Leo",
    "Feid"
  };
  pool_party.addGuest(invitees_for_pool);
  std::cout<< "add a name";
  std::cin>>poolparty;

  beach_party.removeGuest("Ed");
  pool_party.removeGuest(3);

  std::cout<< beach_party<<std::endl;
  std::cout<<pool_party<<std::endl;

  std::vector<std::string> theGuests_ =  beach_party.getGuests();
  for(int i =0; i < theGuests_.size();i++){
    std::cout<< theGuests_[i]<<std::endl;
  }

  
  Plan<int> intPlan;
  intPlan.addEvent(69);
  intPlan.addEvent(45);
  intPlan.addEvent(67);
  intPlan.addEvent(89);
  intPlan.addEvent(21);
  intPlan.addEvent(42);
  intPlan.addEvent(64);
  intPlan.addEvent(24);
  intPlan.removeEvent(69);

  //this is a copy constructor 
  Plan<int> copy_intPlan = intPlan;
  copy_intPlan.addEvent(234);



  //move constructor
  Plan<int> movingPlan(std::move(intPlan));

  //copy assignment 
  intPlan = copy_intPlan;

  int theCapacity_ = intPlan.getCapacity();
  int theItems_ = intPlan.getSize();

  int *arr_of_Plan_ = new int[theItems_];

  arr_of_Plan_ = intPlan.getEvents();

  for(int i = 0; i < theItems_; i++){
    std::cout<< arr_of_Plan_[i] <<std::endl;
  } 
   
  int index_of_it = intPlan.getIndexOf(21);
  std::cout<< index_of_it <<std::endl; 

  return 0;

}