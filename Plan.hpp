/**
 * @file Plan.hpp
 * @author Jhonathan Tepan (jhonathan.tepan51@myhunter.cuny.edu)
 * @brief This file is the interface for Plan class which is also a template class
 * @date 2024-06-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PLAN_H_
#define PLAN_H_

#include <iostream>

template<class T>
class Plan{
    private:
        //data members  
        int capacity_;
        int items_;
        T *tasks_;
    public:
        //constructor
        Plan(); 

        //destructor 
        ~Plan();

        /**
         * @brief Copy Construct a new Plan object
         * 
         * @param other this is used to make the current plan obejct a copy of the 'other' Plan object 
         */
        Plan(const Plan& other);

        /**
         * @brief copy assignment operator
         * 
         * @param other this is also a Plan object that will be used to add the same properties as the 'other' Plan to this Plan object
         * @return Plan<T>& it will have the same data as the 'other' Plan object
         */
        Plan<T>& operator=(const Plan<T>& other);

        /**
         * @brief move Constructer 
         * 
         * @param other this will be used to make this Plan object mimic that data of the 'other' Plan object
         */
        Plan(Plan<T>&& other);

        /**
         * @brief this is the move assignment operator
         * 
         * @param other another Plan object whose data we will be using 
         * @return Plan<T>& it will now return the plan object as a new version that incorporates the 'other' Plan object
         */
        Plan<T>& operator=(Plan&& other);

        /**
        * @brief Add an event to the Plan
        *
        * @param event The event to be added to the Plan
        * @post If the array is full , the capacity of the array will be
        doubled and the event will be added
        */
        void addEvent ( const T & event ) ;
        /**
        * @brief Remove an event from the plan
        *
        * @param event The event to be removed
        * @return true if the event is in the array and is successfully
        removed
        * @return false if the event is not in the array and can ’t be
        removed
        * @post If the event exists in the Plan , it will be removed while
        retaining the order
        */
        bool removeEvent ( const T & event ) ;
        /**
        * @brief Get the pointer to the Plan array
        *
        * @return T* Pointer to the dynamically allocated array where Plan
        is stored
        */
        T * getEvents () const ;
        /**
        * @brief Get the size of the Plan
        *
        * @return int Number of events in the plan
        5
        */
        int getSize () const ;
        /**
        * @brief Get the capacity of the Plan array
        *
        * @return int The maximum number of items that can be stored in the
        currently allocated Plan array
        */
        int getCapacity () const ;
        /**
        * @brief Get the index of the object
        *
        * @param event Object whose index is being queried
        * @return int Index of the object if it exists , -1 otherwise
        */
        int getIndexOf ( const T& event ) ;

};
#include "Plan.cpp"
#endif //PLAN_H_