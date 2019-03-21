/*
* CPSC 2150 Assignment 6 Polynomial Calculations.
* Student Last Name: BASSI
* Student First Name: PANKAJ
* Student Number: 100292175
* This program Reads in a polynomial store it as a Linked List, Sort it and diffrentiate it.
*/

#include "Term.h"
#include <string>

Term::Term(){
   coeff = 0;
   deg_x = 0;
   deg_y = 0;
}

Term::Term(int Coeff, int degX, int degY){
   coeff = Coeff;
   deg_x = degX;
   deg_y = degY;
}

int Term::getDegX(){
   return deg_x;
}
int Term::getDegY(){
   return deg_y;
}
int Term::getCoeff(){
   return coeff;
}
std::string Term::getExp(){
   return exp;
}

void Term::setDegX(int degX){
   deg_x = degX;
}
void Term::setDegY(int degY){
   deg_y = degY;
}
void Term::setCoeff(int Coeff){
   coeff = Coeff;
}

void Term::setExp(std::string ex){
   exp = ex;
}