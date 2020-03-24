//
// Fraction.h
//
// Fraction class interface

//Name: Tom Abraham
//Student ID: 917096660


#include<iostream>
#ifndef FRACTION_H
#define FRACTION_H
class Fraction{
  private:
    int num;  //numerator of fraction
    int den;  //denominator of fraction
  public:
    Fraction(int a, int b); // Parameter constructor that accepts numerator and denominator 
    Fraction(); //Default constructor
    int getNum() const; // Helper method that returns the numerator of a fraction
    int getDen() const; // Helper method that returns the denominator of a fraction
    friend std::istream& operator >> (std::istream &in, Fraction &f); // Operator overloading of ">>"
    friend std::ostream& operator << (std::ostream &out, Fraction &f); // Operator overloading of "<<"
    Fraction& operator = (const Fraction &rhs); // Operator overloading of "="
    Fraction& operator + (const Fraction &rhs); // Operator overloading of "+"
    Fraction& operator - (const Fraction &rhs); // Operator overloading of "-"
    

  
};
#endif