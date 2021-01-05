//cards.cpp
//Authors:Archana Neupane
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>
using namespace std; 
//constructor for Card
Card :: Card(string c) {
  next = nullptr; 
  cardName = c;
}
ostream &operator<<(ostream &out, CardList &target){ //operator overload #1
Card *n = target.head;
while(n){
  out << n-> getcardName();
  if (n->getPointer()){
    out << endl;
  }
  n = n->getPointer(); 
  }
  return out; 
}

//accessors for Card
string Card :: getcardName() const{
  return cardName;
}
Card* Card:: getPointer() const {
  return next;
}
//mutator for Card
void Card :: setPointer(Card* p){
  next = p; 
}
void Card :: setCardName(string c){
  cardName = c; 
}
bool Card :: operator==(const Card &source){ //operator overload #2
  if(this->getcardName() == source.getcardName()){
    return true; 
  }
    else{
      return false; 
    }
  }
//CardList Functions
CardList :: CardList(){ //constructor
  head = nullptr; 
  r = head; 
} 
CardList :: ~CardList(){ //destructor
  Card *n = head; 
  while(n){
    n = n->getPointer();
    delete head; 
    head = n;
  }
  delete n; 
  delete head; 
  }
//accessors 
Card* CardList :: getHead() const{
return head; 
}
Card* CardList :: getCard() const{
  return r; 
}
//mutator
void CardList :: setCardPointer(Card* q){
  r = q; 
}
//member functions
void CardList :: append(Card &c){ //append
   if (head == nullptr) {
        head = new Card; 
        head -> setCardName(c.getcardName()); 
        head -> setPointer(c.getPointer());
        r = head; 
    }
    else { 
      Card * q = new Card; 
      Card *p = head; 
      q -> setCardName(c.getcardName());
      q -> setPointer(NULL);
        while(p->getPointer()!= NULL){
          p = p-> getPointer();
        }
          p -> setPointer(q); 
        }
    } 
bool CardList :: searchHelper(Card* c, Card* index) const{
  if ( index == NULL || c == NULL){
    return false;
  }
  if (index->getcardName()== c->getcardName()){ 
    return true; 
  }
  
  else {
    return searchHelper(c, index->getPointer());
  }
}
bool CardList :: search(Card *c){
  Card *tmp = this->getHead();
  return searchHelper(c, tmp);
}

void CardList:: clear(Card* p){ //delete card
  Card *tail = this -> head; 
  while(tail -> getPointer()){
  tail = tail ->getPointer();
  }
  Card *tmp = this -> head; 
  if (tmp == NULL && tail == NULL){
    return;
  }
  Card *tmp2 = NULL; 
  if (tmp->getcardName() == p->getcardName()){ //if card deleted is the head
    tmp2 = tmp; 
    tmp = tmp -> getPointer(); 
    head = head ->getPointer();
    delete tmp2;
    return; 
  }

  while(tmp->getPointer()){
    if((tmp ->getPointer()->getcardName() == p->getcardName()) && (tmp->getPointer()->getPointer() == NULL)){ // if tail
      tmp->setPointer(NULL);
      tail->setPointer(NULL);
      delete tail; 
      return;
    }
    else if(tmp->getPointer()->getcardName() == p->getcardName()){ //in middle
      tmp2 = tmp->getPointer();
      tmp->setPointer(tmp->getPointer()->getPointer());
      tmp->setPointer(tmp->getPointer()); 
      delete tmp2; 
      return;
    }
    tmp= tmp->getPointer();
   
  }
}

//Player functions
Player :: Player(CardList &c){ //constructor
  cp = &c;
}
//accessor
CardList * Player:: getListPtr() const{
return cp; 
} 