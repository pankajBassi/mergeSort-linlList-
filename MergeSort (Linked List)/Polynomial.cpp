/*
* CPSC 2150 Assignment 6 Polynomial Calculations.
* Student Last Name: BASSI
* Student First Name: PANKAJ
* Student Number: 100292175
* This program Reads in a polynomial store it as a Linked List, Sort it and diffrentiate it.
*/

#include "Polynomial.h"
#include <iostream>
#include <sstream>

//Constructor.
Polynomial::Polynomial(){
   poly = nullptr;
}

//Adding the terms to list.
Polynomial::Node* Polynomial::cons(Term* term){
   return new Node{term, poly};
}

//Making a new term from the string entered.
void Polynomial::addTerm(std::string str){
   int i=0;
   int k=0;
   int Coeff,degX,degY;
   int length = str.size();
   
   while(i<(length) ){
   
      if(str.at(i) == ' ') { i++; continue; }
      
      if(str.at(i) == '-') {
         i++;
               
         if( isDigit( str.at( i ) ) ) {
         std::stringstream num;
         
         while ( i < (length) && (str.at( i ) != ' ') ){
            num << str.at(i);
            ++i;
         }
         
         if( k==0 ) { num >> Coeff; Coeff = (Coeff*-1); k++; }
         else if (k == 1) { num >> degX; k++; }
         else { num >> degY; }
         }
      }
      
      if( isDigit( str.at( i ) ) ) {
         std::stringstream num;
         
         while ( i < (length) && (str.at( i ) != ' ') ){
            num << str.at(i);
            ++i;
         }
         
         if( k==0 ) { num >> Coeff; k++; }
         else if (k == 1) { num >> degX; k++; }
         else { num >> degY; }
      }
   }
   
   Term* term = new Term{Coeff,degX,degY};
   term->setExp(str);
   
   poly = cons(term);
}

//Printing the polynomial Just a helper method.
void Polynomial::printPolynomial(){
   while( poly != nullptr ){
      Term* current = poly->term;
      std::cout << current->getCoeff() <<":" << current->getDegX() <<":" <<current->getDegY() << ",";
      poly = poly->next;
   }
}

//Input : this function takes in the polynomial object and the output object.
//Outout: this function just prints out all the values in a polynomial.
std::ostream& operator<<(std::ostream& output,const Polynomial& P){
    Polynomial::Node *pr = P.poly;
    if(pr==nullptr){
        std::cout<<"0";
    }
    
    while(pr!=nullptr){
        int coeff = pr->term->getCoeff();
        int degX = pr->term->getDegX();
        int degY = pr->term->getDegY();
       
        if(coeff==0){
            std::cout<<"";
        }
        
        else if(coeff>0){
           std::cout<<"+"<<coeff;
           std::cout<<"x"<<"^"<<degX;
           std::cout<<"y"<<"^"<<degY;
        }
        
        else if(coeff<0){
           std::cout<<coeff;
           std::cout<<"x"<<"^"<<degX;
           std::cout<<"y"<<"^"<<degY;
        }
        
        std::cout<<" ";
        
        pr=pr->next;
    }
    return output;
}

//Differtiating with respect to x.
Polynomial Polynomial::diffretianteWRX(){
      Polynomial res;
   Node* pr = poly;
   
   while(pr!=nullptr){
      int coeff = pr->term->getCoeff();
      int degX = pr->term->getDegX();
      int degY = pr->term->getDegY();
      coeff = coeff*degX;
      degX = degX-1;
      
      if(coeff!=0){
         Term* term = new Term{coeff,degX,degY};
         res.poly = res.cons(term);
      }
      pr=pr->next;
   }
   res.poly = res.reverse(res.poly);
   
   return res;
}

//Differtiating with respect to Y.
Polynomial Polynomial::diffretianteWRY(){
   Polynomial res;
   Node* pr = poly;
   
   while(pr!=nullptr){
      int coeff = pr->term->getCoeff();
      int degX = pr->term->getDegX();
      int degY = pr->term->getDegY();
      coeff = coeff*degY;
      degY = degY-1;
      
      if(coeff!=0){
         Term* term = new Term{coeff,degX,degY};
         res.poly = res.cons(term);
      }
      pr=pr->next;
   }
   res.poly = res.reverse(res.poly);
   
   return res;
}

//Doing the mergeSort.
void Polynomial::mergeSort(){
   mergeSort(poly);
}

//mergeSort overloaded method.
void Polynomial::mergeSort(Node*& list){
   Node* head = list;
   Node* a;
   Node* b;
   
   if( head == nullptr || head->next == nullptr) return;
   
   splitList(head, a, b);
   
   mergeSort(a);
   mergeSort(b);
   list = merge(a,b);
}

//Method to split the list.
void Polynomial::splitList(Node* head, Node*& a, Node*& b) {
   Node* front;
   Node* back;
   
   if( head==nullptr || head->next == nullptr ){
      front = head;
      back = nullptr;
   }
   
   else{
      front = head;
      back = head->next;
      
      while(back != nullptr){
         back = back->next;
         if(back != nullptr){
            front = front->next;
            back = back->next;
         }
      }
      
      Node* temp = head;
      Node* temp2 = temp;
      
      while(temp != front){
         temp = temp->next;
      }
      front = temp->next;
      temp->next = nullptr;
      
      a = temp2;
      b = front;
   }
}

//Method to merge two lists based on thier degrees destructively.
Polynomial::Node* Polynomial::merge(Node* a, Node* b){
   Node* endList = nullptr;
   
   if(a == nullptr){
      return b;
   }
   
   if(b == nullptr) return a;
   
   //if degree of x of term a is greater than degree of x of term b, then return 'a' otherwise return 'b'
   if(a->term->getDegX() > b->term->getDegX()){
      endList = a;
      endList->next = merge(a->next,b);
   }
   else if(a->term->getDegX() < b->term->getDegX()){
      endList = b;
      endList->next = merge(a,b->next);
   }
   //if x degree of both terms are same, we make comparison on the basis of degree of y
   else{
      if(a->term->getDegY() > b->term->getDegY()){
         endList = a;
         endList->next = merge(a->next,b);
      }
      else{
         endList = b;
         endList->next = merge(a,b->next);
      }
   }
    
   return endList;
}

//Input : a first polynomial,b second Polynomial.
//Output: this function adds a and b using merge algorithm and return a new Polynomial.
const Polynomial operator +(const Polynomial& a, const Polynomial& b){
   Polynomial res;//This will be the resulting polynomial.
   Polynomial::Node* p = a.poly;
   Polynomial::Node* q = b.poly;
    
   while ( (p != nullptr) && (q != nullptr) ) {
      
      if (p->term->getDegX() > q->term->getDegX()) {
         res.addTerm(p->term->getExp());
         p = p->next;
      }
      else if (p->term->getDegX() < q->term->getDegX()) {
         res.addTerm(q->term->getExp());
         q = q->next;
      }
      else {
         if (p->term->getDegY() > q->term->getDegY()) {
            res.addTerm(p->term->getExp());
            p = p->next;
         }
         else {
            res.addTerm(q->term->getExp());
            q = q->next;
         }
      }
   }
   
   while (p != nullptr) {
      res.addTerm(p->term->getExp());
      p = p->next;
   }
   while (q != nullptr) {
      res.addTerm(q->term->getExp());
      q = q->next;
   }
   
   res.poly = res.reverse(res.poly);
   
   return res;
}

//Helper method to reverse the linked list
Polynomial::Node* Polynomial::reverse(Node * p) {
   Node *q, *t;
   if ( (p == nullptr) || (p->next == nullptr) ) 
      return p;
   q = p->next;
   p->next = nullptr;
   while( q != nullptr ) {
      t = q->next;
      q->next = p;
      p = q;
      q = t;
   }
   return p;
}

//Method to check if the current character is the digit.
bool Polynomial::isDigit( char ch ){
   
   if ( (ch-48) >= 0 && (int)(ch-48) <=9 ) return true;
   
   return false;
}

//~ void Polynomial::copyList(Node* q){
   //~ Node* temp = q;
   //~ while( temp != nullptr ){
      //~ poly = cons(q->term);
      //~ temp = temp->next;
   //~ }
   //~ poly = reverse(poly);
//~ }

//~ // copy constructor
//~ Polynomial::Polynomial(const Polynomial& other) {
   //~ poly = nullptr;
   //~ copyList(other.poly);
//~ }

//~ void Polynomial::deleteList(){
   //~ //delete all nodes(terms)
   //~ while(poly!=nullptr){
      //~ Node* discard = poly;
      //~ Term* discardTerm = discard->term;
      //~ poly = poly->next;
      //~ delete discard;
      //~ delete discardTerm;
   //~ }
//~ }

//~ // destructor
//~ Polynomial::~Polynomial() {
   //~ deleteList();
   //~ poly=nullptr;
//~ }

//~ // overload the assignment operator
//~ Polynomial& Polynomial::operator = (const Polynomial& other){
   //~ deleteList();
   //~ Polynomial res;
   //~ res.copyList(other.poly);
   //~ return res;   
//~ }

