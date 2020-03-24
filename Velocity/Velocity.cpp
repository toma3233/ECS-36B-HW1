// Velocity class
// Implementing the provided interface (Velocity.h)

//Name: Tom Abraham
//Student ID: 917096660

#include "Velocity.h"
#include<iostream>
using namespace std;

// Velocity default constructor which sets velocity to 0
Velocity::Velocity(){
    v = 0;
};

// Velocity method "accelerate" that increases that velocity
void Velocity::accelerate(int dv)
{
    // Utilizes helper method "set" to add parameter value to current velocity
    set(dv);

}

// Velocity helper method "set" that adds parameter value to current velocity 
void Velocity::set(int i)
{
    v += i;
    // Resets velocity to 65 if new velocity is greater than 65
    if(v > 65){
        v = 65;
    }
    // Resets velocity to -5 if new velocity is less than -5
    if(v < -5){
        v = -5;
    }
   
}

// Velocity helper method "get" that returns the current value of the velocity
int Velocity::get(){
    return v;
}

// Velocity method "print" which prints out the current velocity
void Velocity::print(){
    cout << "velocity: " << get() << endl;
}