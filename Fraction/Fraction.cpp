// Fraction class
// Implementing the fraction interface (Fraction.h)

//Name: Tom Abraham
//Student ID: 917096660

#include "Fraction.h"
#include<stdexcept>
#include<iostream>
using std::invalid_argument;

Fraction hi(1,1); // Global variable used to hold temporary fraction values

// Parameter constructor that takes in a numerator and denominator value 
Fraction::Fraction(int a, int b){
    // Initializes numerator and denominator values 
    num = a;
    den = b;
};

// Default constructor
Fraction::Fraction(){
    // Automatically initializes numerator and denominator to 1
    num = 1;
    den = 1;
};

// finds greatest common denominator of two numbers 
int find_gcd(int n1, int n2) 
{
  int gcd, remainder;

  // Euclid's algorithm 
  remainder = n1 % n2; 
  while ( remainder != 0 )
  {
    n1 = n2;
    n2 = remainder; 
    remainder = n1 % n2; 
  } 
  gcd = n2; 

  return gcd;
}

// Method to reduce a fraction 
void reduce_fraction(int *nump,  int *denomp) 
{
  int gcd;   
  gcd = find_gcd(*nump, *denomp);
  *nump = *nump / gcd;
  *denomp = *denomp / gcd;
}

// Method to overload ">>" operator
std::istream& operator >> (std::istream &in, Fraction &f){
    // uses input stream to initialize the numerator and denominator of Fraction f
    char slash = '/';
    in >> f.num;
    in >> slash;
    in >> f.den;

    return(in);

}
// Method to overload "<<" operator
std::ostream& operator << (std::ostream &out,  Fraction &f){
    // If numerator is 0 or denominator is 1, print the numerator
    if (f.num == 0 || f.den == 1){
        out << f.num;
    }
    // If denominator is negative, transfer negative sign to numerator and print fraction
    else if(f.den < 0){
        out << -f.num;
        out << '/';
        out << -f.den;
    }
    // Otherwise print fraction normally
    else{
        out << f.num;
        out << '/';
        out << f.den; 
    }
    

    return(out);
    
}

// Method to overload "=" operator
Fraction& Fraction::operator = (const Fraction &rhs){
    // Initializes numerator and denominator of fraction
    this->num = rhs.num;
    this->den = rhs.den;

    return(*this);
}

// Method to overload "+" operator
Fraction& Fraction::operator + (const Fraction &rhs){
    // Uses algorithm to add fraction
    hi.num = (this->num * rhs.den) + (this->den * rhs.num);
    hi.den = this->den * rhs.den; 

    // Throw exception if denominator of a fraction is 0
    if(hi.den == 0){
        throw invalid_argument("zero denominator");  
    }
    
    // Calls helper method to reduce the fraction
    reduce_fraction(&(hi.num), &(hi.den));

    return(hi);

}

// Method to overload "-" operator
Fraction& Fraction::operator - (const Fraction &rhs){
    // Uses algorithm to subtract fraction
    hi.num = (this->num * rhs.den) - (this->den * rhs.num);
    hi.den = this->den * rhs.den; 
    
    // Throw exception if denominator of a fraction is 0
    if(hi.den == 0){
        throw invalid_argument("zero denominator");  
    }
    
    // Calls helper method to reduce the fraction
    reduce_fraction(&(hi.num), &(hi.den));

    return(hi);
}

// Helper method that returns the numerator of the fraction
int Fraction::getNum() const
{

    int x = this->num;
    int y = 1;
    const Fraction frac(x,y);
    return frac.num;
}

// Helper method that returns the denominator of the fraction
int Fraction::getDen() const
{
    int z = this->den;
    int a = 1;
    const Fraction frc(a,z);
    return frc.den;
}







    


