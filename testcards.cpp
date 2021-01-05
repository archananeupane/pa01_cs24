//testcards.cpp
//Archana Neupane
// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_append();
  test_equal();
  test_card();
  test_member_functions();
  test_accessors_mutators();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  END_TEST("test_equal");
}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  END_TEST("test_card");
}

void test_member_functions(){
  START_TEST("test_member_functions");
  test_clear_function();
  test_search_function();
  test_card_constructor();
  test_cardList_constructor();
  test_Player_constructor();
  END_TEST("test_member_functions");
}
void test_accessors_mutators(){
  START_TEST("test_accessors_mutators");
  test_getcardName();
  test_getPointer();
  test_setcardName();
  test_setPointer();
  test_getHead();
  test_getCard();
  test_setCardPointer();
  test_getListPtr();
  END_TEST("test_accessors_mutators");
}

void test_append_empty_list(){ 
  string testname = "case 0: append card k 7 to empty cardList";
  CardList c1;
  Card c("k 7");
  c1.append(c);
  assertEquals("k 7",  c1.getHead()->getcardName(), testname);
// A test case for append single card node to LinkedList
}

void test_append_single_element_list(){ 
  string testname="case 1: append card t 9 to cardList c1 with existing card k 7";
  int count = 0;
  CardList c1;
  Card c("k 7");
  Card d("t 9");
  c1.append(c);
  c1.append(d);
  Card* n = c1.getHead();
  while(n){
    count++;
    n = n->getPointer();
  }
  assertEquals(2, count, testname);
}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  CardList l1, l2;
  assertEquals(l1.getHead(),l2.getHead(),testname);
}

void test_card_operator_double_equal(){
  string testname = " double equal operator overloaded";
  Card c("a 5");
  Card d("a 5");
  assertEquals(1, (c == d), testname);
}

void test_clear_function(){
string testname = "clear only card in cardList";
CardList c1,c2; 
Card c("t 9");
c1.append(c);
c1.clear(c1.getHead());
assertEquals(c2.getHead(), c1.getHead(), testname);
}

void test_search_function(){
string testname = "search function check";
CardList c1,c2;
Card card1("a 5");
Card card2(" y 7");
Card card3("a 5");
Card card4("h 8");
c1.append(card1);
c1.append(card2);
c2.append(card3);
c2.append(card4);
assertEquals(1, c2.search(c1.getHead()), testname); 
}

void test_card_constructor(){
  string testname="check card constructor";
  Card c;
  assertEquals("", c.getcardName(), testname);
}

void test_cardList_constructor(){
  string testname= "check cardList constructor";
  CardList c1;
  assertEquals(c1.getHead(), c1.getCard(), testname);
}

void test_Player_constructor(){
  string testname = "check Player constructor";
  CardList c1;
  Player Jenny(c1);
  assertEquals(&c1, Jenny.getListPtr(), testname);
}

void test_getcardName(){
  string testname = "check card c's name is h k";
  Card c("h k");
  assertEquals("h k", c.getcardName(), testname);
}
void test_getPointer(){
  string testname = "check card c's next address is nullptr";
  Card c("y 7");
  assertEquals(nullptr, c.getPointer(), testname);
} 
void test_setcardName(){
  string testname = "check that card c's name is set to t 9";
  Card c;
  c.setCardName("t 9");
  assertEquals("t 9", c.getcardName(), testname);
}
void test_setPointer(){
  string testname = "check that card c1's next address is set to the address of card c2";
  Card c1("t 8");
  Card c2("a 9");
  c1.setPointer(&c2);
  assertEquals(&c2, c1.getPointer(), testname);
}
void test_getHead(){
  string testname = "check that the head card's name is a 3";
  CardList c1;
  Card c("a 3");
  c1.append(c);
  assertEquals("a 3", c1.getHead()->getcardName(), testname);
}
void test_getCard(){
  string testname="check that card1's name is outputted";
  CardList c1;
  Card card1("a 5");
  Card card2("b 7");
  c1.append(card1);
  c1.append(card2);
  assertEquals("a 5", c1.getCard()->getcardName(), testname);
}
void test_setCardPointer(){
  string testname="check that second card2's name b 7 get output after moving pointer";
  CardList c1;
  Card card1("a 5");
  Card card2("b 7");
  c1.append(card1);
  c1.append(card2);
  c1.setCardPointer(c1.getCard()->getPointer());
  assertEquals("b 7", c1.getCard()->getcardName(), testname);
}
void test_getListPtr(){
  string testname = "check that access to card in cardlist is successful with getListPtr";
  CardList c1;
  Card card1("p 1");
  c1.append(card1);
  Player Jasmine(c1);
  assertEquals("p 1",Jasmine.getListPtr()->getCard()->getcardName(), testname);
}




