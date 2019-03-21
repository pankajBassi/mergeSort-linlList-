/*
* CPSC 2150 Assignment 6 Polynomial Calculations.
* Student Last Name: BASSI
* Student First Name: PANKAJ
* Student Number: 100292175
* This program Reads in a polynomial store it as a Linked List, Sort it and diffrentiate it.
*/

#include "Polynomial.h"
#include <sstream>
#include <iostream>

//Method to make a polynomial.
void makePolynomial(Polynomial& P,std::string str){
   int i=0;
   while(str.at(i) == ' ') i++;
   int numOfTerms = (str.at(i)-48);
   while(i < numOfTerms){
      std::string terms;
      getline(std::cin,terms);
      P.addTerm(terms);
      i++;
   }
}

//Method for printing two polynomials.
void printPolynomials(Polynomial P1, Polynomial P2){
   std::cout<<"=============================================\n";
   std::cout<<"unsorted\n";
   std::cout<<"poly1: "<<P1<<"\n";
   std::cout<<"poly2: "<<P2<<"\n";
   std::cout<<"sorted\n";
   P1.mergeSort();
   std::cout<<"a: "<< P1 <<"\n";
   P2.mergeSort();
   std::cout<<"b: "<< P2 <<"\n";
   Polynomial add = P1 + P2;
   std::cout<<"a + b: "<< add << "\n";
   Polynomial P1X= P1.diffretianteWRX();
   std::cout<<"da/dx: "<<P1X<<"\n";
   Polynomial P1Y= P1.diffretianteWRY();
   std::cout<<"da/dy: " << P1Y <<"\n";
   Polynomial P2X= P2.diffretianteWRX();
   std::cout<<"db/dx: "<< P2X <<"\n";
   Polynomial P2Y= P2.diffretianteWRY();
   std::cout<<"db/dy: "<< P2Y <<"\n";
   std::cout<<"=============================================\n";
}

int main() {
   std::string str;
   
   //Keep taking input until the end of a file.
   while(getline(std::cin, str)){
      Polynomial P1;
      makePolynomial(P1,str);
      getline(std::cin, str);
      Polynomial P2;
      makePolynomial(P2,str);
      printPolynomials(P1, P2);
   }
}