/**
 * @file Event.cpp
 * @author Jhonathan Tepan (jhonathan.tepan51@myhunter.cuny.edu)
 * @brief This file is the implementation for Event class
 * @date 2024-06-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Event.hpp"

Event::Event(){
    name_ = "Not Set Yet";
    timestamp_ = -1;
}
Event::Event(const std::string& name, const long& timestamp){
    name_ = name;
    timestamp_ = timestamp;
}
std::string Event::getName()const{
    return name_;
}
long Event::getTimestamp()const{
    return timestamp_;
}
std::vector<std::string> Event::getGuests()const{
    return guests_;
}
void Event::setName(const std::string& name){
    name_ = name;
}
bool Event::setTimestamp(const long& timestamp){
    bool set_Time_success_ = false;
    //checks to see if the timestamp is a positive value so it can be set. 
    if(timestamp > 0){
        timestamp_ = timestamp;
        set_Time_success_= true;
    }
    return set_Time_success_;
}
bool Event::setGuests(const std::vector<std::string>& guests){
    //checks to make sure the guests vector is not empty
    if( guests.size() <= 0){
        return false;
    }
    //iterate through all values to make sure it does not contain an empty string name
    for(int i = 0; i < guests.size(); i++){
        if(guests[i] == ""){
            return false;
        }
    }
    //this will only iterate when we know there are no empty strings in the 'guests' vector
    for(int i = 0; i < guests.size(); i++){
        guests_.push_back(guests[i]);
    }
    
    return true;
}
std::ostream& operator <<(std::ostream& os, const Event& event){
    os<< "Name: "+ event.getName() + "\nTime: " + event.timeToString() + "\nGuests:\n" + event.guestsToString();
    return os; 
}
std::string Event::guestsToString() const{
    std::string list_of_guests_;
    //iterate through the vector and add each name with proper spacing to the string list_of_guests_
    for(int i = 0; i < guests_.size();i++){
        list_of_guests_ += std::to_string(i) + ": " + guests_[i] +"\n";
    }
    return list_of_guests_;
}
std::istream& operator>>(std::istream& is,Event& event){
    std::string name_;
    std::getline(is , name_);
    event.addGuest(name_);
    return is;
}
bool Event::addGuest(const std::string& name){
    if( name == " ")return false;
    else{
        guests_.push_back(name);
        return true;
    }
}
bool Event::addGuest(const std::vector<std::string>& names){
    //iterate through the vector of names to see if any of them are empty.
    for(int i = 0; i < names.size(); i++){
       if(names[i] == ""){
            return false;
       }
    }
    for(int i = 0; i < names.size(); i++){
        addGuest(names[i]);
    }
    return true;
}
bool Event::removeGuest(const std::string& name){
    bool can_be_removed_ = false;
    int index_ = -1;
    for(int i = 0; i < guests_.size(); i++){
        if(guests_[i] == name){
            can_be_removed_ = true;
            index_ = i;
            break;
        }
    }
    if(index_ != -1){
        guests_.erase(guests_.begin() + index_);
    }
    return can_be_removed_;
}
bool Event::removeGuest(const size_t& id){
    bool  can_be_removed_ = false;
    if( (id < 0) || (id >= guests_.size())){
        return can_be_removed_;
    }
    else{
        can_be_removed_ =  true;
        guests_.erase(guests_.begin()+ id);
    }
    return can_be_removed_;
}
std::string Event::timeToString() const {
    // if timestamp is -1, it is not valid and is the result of default constructor
    if (timestamp_ == -1) {
        return "Not Set Yet";
    }
    struct tm* dt = localtime(&timestamp_);
    std::string time = asctime(dt);
    time.pop_back();
    return time;
}