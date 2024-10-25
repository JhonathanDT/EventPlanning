/**
 * @file Event.hpp
 * @author Jhonathan Tepan (jhonathan.tepan51@myhunter.cuny.edu)
 * @brief This file is the implementation part for Plan class
 * @date 2024-06-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Plan.hpp"

template<class T>
Plan<T>::Plan(){
    capacity_ =  2;
    items_ = 0;
    tasks_ =  new T[capacity_];
} 
//destructor
template<class T>
Plan<T>::~Plan(){
    delete[] tasks_;
    tasks_ = nullptr;  
    std::cout<<"destructor was called" <<std::endl; 
} 
//copy constructor it works!!
template<class T>
Plan<T>::Plan(const Plan& other){
    items_ = other.items_;
    capacity_ = other.capacity_;
    tasks_ = new T[other.capacity_];
    for(int i = 0; i < items_; i++){
        tasks_[i] = other.tasks_[i];
    }
    std::cout<< "copy constructor was invoked" <<std::endl;
}

//copy assignment operator works fine!!
template<class T> 
Plan<T>& Plan<T>::operator=(const Plan<T>& other){
    if(this != &other){
        delete[] tasks_;
        capacity_ = other.capacity_;
        items_ = other.items_;
        tasks_ = new T[capacity_];
        for( int i = 0; i < items_; i++){
            tasks_[i] = other.tasks_[i];
        }
    }
    std::cout<< "copy assignment operator was invoked" <<std::endl;
    return *this;
}

//move constructor it works!!
template<class T>
Plan<T>::Plan(Plan<T>&& other){
    items_ =  other.items_;
    capacity_= other.capacity_;
    tasks_ = new T[capacity_];
    for(int i = 0; i < items_; i++){
        tasks_[i] = other.tasks_[i];
    }
    other.tasks_= nullptr;
    other.items_ = 0;
    other.capacity_ = 0;
    std::cout<< "move constructor was invoked" <<std::endl;
}

//move assignment operator
template<class T>
Plan<T>& Plan<T>::operator=(Plan&& other){
    if(this != &other){
        delete[] tasks_;
        capacity_=other.capacity_;
        items_ = other.items_;
        tasks_ = new T[capacity_];
        for(int i = 0; i < items_; i++){
            tasks_[i] = other.tasks_[i];
        }
    }
    std::cout<< "move assigment called"<<std::endl;
    return *this;
}

template<class T>
void Plan<T>::addEvent(const T& event){
    if(items_ == capacity_){
        capacity_ = capacity_*2;
    }
    tasks_[items_] = event;
    items_++;
}
template<class T>
bool Plan<T>::removeEvent(const T& event){
    bool removed_ = false;
    int index_of_to_be_removed_ = -1;
    //iterate throught the array to check if we have the event exists in our array.
    for(int i = 0; i < items_; i++){
        if(tasks_[i] == event){
            index_of_to_be_removed_ = i;
            removed_= true;
            break;
        }
    }
    if( index_of_to_be_removed_ != -1){
        for(int i = index_of_to_be_removed_; i < items_-1;i++){
            tasks_[i]= tasks_[i+1];
        }
        --items_;
    }  
    return removed_;
}
template<class T>
T* Plan<T>::getEvents()const{
    return tasks_;
}
template<class T>
int Plan<T>::getSize()const{
    return items_;
}
template<class T>
int Plan<T>::getCapacity()const{
    return capacity_;
}
template<class T>
int Plan<T>::getIndexOf(const T& event){
    int index_ = -1;
    for(int i = 0; i < items_; i++){
        if(tasks_[i] == event){
            index_ = i;
        }
    }
    return index_;
}
