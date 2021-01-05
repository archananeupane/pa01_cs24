//main.cpp
//Archana Neupane
#include "cards.h"
#include <iostream>                 
using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files

  // Read each file and store cards
  CardList c1; 
  while (getline (cardFile1, line) && (line.length() > 0)){ 
  Card c(line); 
  c1.append(c);
 }   
 cardFile1.close();

 CardList c2;
  while (getline (cardFile2, line) && (line.length() > 0)){
  Card d(line);
  c2.append(d);
  }
  cardFile2.close();

  // Start the game 
Player Alice(c1); //Alice has cardList c1
Player Bob(c2); //Bob has cardList c2

while((Bob.getListPtr()->getCard()->getPointer() != nullptr) && (Alice.getListPtr()->getCard()->getPointer() != nullptr)){
  //Alice's turn
  while(Bob.getListPtr()->search(Alice.getListPtr()->getCard()) != true){ //checks if Alice's card is in Bob's deck
    Alice.getListPtr()->setCardPointer(Alice.getListPtr()->getCard()->getPointer()); //moves to next card
  }

if(Bob.getListPtr()->search(Alice.getListPtr()->getCard()) == true){ 
  cout << "Alice picked matching card "<< Alice.getListPtr()->getCard()->getcardName() <<endl; 
  Bob.getListPtr()->clear(Alice.getListPtr()->getCard()); //delete matching card from
  Alice.getListPtr()->clear(Alice.getListPtr()->getCard()); //both Alice's and Bob's decks
  if(Bob.getListPtr()->getCard()==NULL){ 
    Bob.getListPtr()->setCardPointer(Bob.getListPtr()->getCard()->getPointer());
    }
    Alice.getListPtr()->setCardPointer(Alice.getListPtr()->getCard()->getPointer()); //move pointer to Alices next card
    }
  
  //Bob's turn
while(Alice.getListPtr()->search(Bob.getListPtr()->getCard())!= true){ //check if Bob's card is in Alice's deck
  Bob.getListPtr()->setCardPointer(Bob.getListPtr()->getCard()->getPointer());
  }

if(Alice.getListPtr()->search(Bob.getListPtr()->getCard())== true){
  cout << "Bob picked matching card "<< Bob.getListPtr()->getCard()->getcardName() <<endl; 
  Alice.getListPtr()->clear(Bob.getListPtr()->getCard()); //delete matching card from Bob's
  Bob.getListPtr()->clear(Bob.getListPtr()->getCard()); // and Alice's deck
  if(Alice.getListPtr()->getCard()==NULL){
    Alice.getListPtr()->setCardPointer(Alice.getListPtr()->getCard()->getPointer());
    }
  if(Bob.getListPtr()->getCard()->getPointer() != NULL){
    Bob.getListPtr()->setCardPointer(Bob.getListPtr()->getCard()->getPointer()); //move Bobs pointer to next card
    }
    } 
//for situation where matching card is last card in deck
if((Alice.getListPtr()->getCard()->getPointer() == nullptr) && (Bob.getListPtr()->search(Alice.getListPtr()->getCard())== true)){
  cout << "Alice picked matching card "<< Alice.getListPtr()->getCard()->getcardName() <<endl; 
  Bob.getListPtr()->clear(Alice.getListPtr()->getCard());
  Alice.getListPtr()->clear(Alice.getListPtr()->getCard());
  } 
}

cout << endl<< "Alice's cards:" <<endl;
cout << c1 <<endl; 
cout <<endl <<  "Bob's cards:" <<endl;
cout << c2 <<endl; 
return 0;
}
