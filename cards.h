//cards.h
//Archana Neupane
//All class declarations go here
#include <string>
#include <fstream>
using namespace std; 
#ifndef CARDS_H
#define CARDS_H
class Card {

public:
Card(string c = ""); //constructor
//accessors
string getcardName() const;
Card* getPointer() const; 
//mutators
void setPointer(Card* p);
void setCardName(string c);
//member function
bool operator==(const Card &source);

private:
string cardName;
Card *next;
};

class CardList {

public:
CardList();
~CardList();
//accessor
Card * getHead() const; 
Card * getCard() const; 
//mutator
void setCardPointer(Card* q);
//non member function
friend ostream& operator<<(ostream &out, CardList &target);
//member functions
void append(Card &c);
bool searchHelper(Card* c, Card* tmp) const; 
bool search(Card *c);
void clear(Card* p); 

private: 
Card *head; //points to first card
Card *r; // pointer to iterate through cardList 
};

class Player{

public: 
//constructor
Player(CardList &c);
//accessor
CardList * getListPtr() const; 

private: 
CardList * cp;
};  
#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
