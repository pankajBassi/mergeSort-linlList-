#ifndef Polynomial_H
#define Polynomial_H
/*
* CPSC 2150 Assignment 6 Polynomial Calculations.
* Student Last Name: BASSI
* Student First Name: PANKAJ
* Student Number: 100292175
* This program Reads in a polynomil store it as a Linked List, Sort it and diffrentiate it.
*/

#include <iostream>
#include "Term.h"
class Polynomial{
   
   public:
      //Constructor for term.
      Polynomial();
      //Printing the polynomial.
      void addTerm(std::string str);
      //Printing the polynomial.
      void printPolynomial();
      //Printing Output
      friend std::ostream& operator<<(std::ostream& output, const Polynomial& P);
      //Overloading + operator to add two polynomial of any kind and length
      friend const Polynomial operator +(const Polynomial& a, const Polynomial& b);
      //Merge Sort to sort a linked list.
      void mergeSort();
      //Diffrentiating with respect to X.
      Polynomial diffretianteWRX();
      //Diffrentiating with respect to Y
      Polynomial diffretianteWRY();
      //Destructor
      // ~Polynomial();
      //Copylist.
      //~ Polynomial(const Polynomial& other);
      //Overloaded Assignment Operator
      //Polynomial& operator = (const Polynomial& other);
      
   private:
      struct Node{
         Term* term;
         Node* next;
      };
      
      //Main head of the linked list.
      Node* poly;
      //Method to keep adding the term.
      Node* cons(Term* term);
      //Method to check if the character is a digit.
      bool isDigit( char ch );
      //Method to do the mergesort.
      void mergeSort(Node*& list);
      //Method to split the list into two halves.
      void splitList(Node* head, Node*& firstHalf, Node*& secondHalf);
      //Method to merge two lists.
      Node* merge(Node* firstHalf, Node* secondHalf);
      //Method to reverse a linked list.
      Node* reverse(Node * p);
      //Method to delete the list with its terms.
       //void deleteList();
      //Method to copy the linked list.
      //~ void copyList(Node* p);
};
#endif
   