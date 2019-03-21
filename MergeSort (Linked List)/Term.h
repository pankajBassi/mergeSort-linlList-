#ifndef TERM_H
#define TERM_H
/*
* CPSC 2150 Assignment 6 Polynomial Calculations.
* Student Last Name: BASSI
* Student First Name: PANKAJ
* Student Number: 100292175
* This program Reads in a polynomil store it as a Linked List, Sort it and diffrentiate it.
*/

#include <string>

class Term{
   public:
      //Constructor for a term.
      Term();
      //Constructor with its values.
      Term(int Coeff, int degX, int degY);
      
      //String expression entered.
      std::string exp;
      //To get the degree of x
      int getDegX();
      //To get the degree of y
      int getDegY();
      // To get the coefeccient.
      int getCoeff();
      //To get the string expression enter.
      std::string getExp();
   
      //BELOW are the methods to set all the values to a term.
      void setDegX(int degX);
      void setDegY(int degY);
      void setCoeff(int Coeff);
      void setExp(std::string exp);
   
   private:
      int coeff;
      int deg_x;
      int deg_y;
};
#endif