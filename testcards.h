// testcards.h
//Authors: Archana Neupane
//All test declarations go here

// This is not exhaustive list of tests. You can remove / edit tests if it doesn't suit your design but you should definitelty add more
// You should test all possible cornere cases of your public functions

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>

using namespace std;
void runAll();
void test_constructor();
void test_append();
void test_equal();
void test_card();
void test_member_functions(); 
void test_accessors_mutators();
/*
void test_destructor();
void test_remove();
void test_search();

*/
void test_append_empty_list(); // A test case for append
void test_append_single_element_list(); // Tests cases should be independent,
            // small, fast, orthogonal
void test_equal_empty_list();
void test_card_operator_double_equal();
void test_clear_function(); 
void test_search_function(); 
void test_card_constructor();
void test_cardList_constructor();
void test_Player_constructor();
void test_getcardName();
void test_getPointer();
void test_setcardName();
void test_setPointer();
void test_getHead();
void test_getCard();
void test_setCardPointer();
void test_getListPtr();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}
void assertEquals(Card * expected , Card * actual, string testDescription){
  if (expected == actual){
    cout << "PASSED "<< endl;
  }
  else{
    cout<< " FAILED: "<<testDescription << endl << " Expected: "<< expected<< " Actual: "<< actual <<endl;
  }
}
void assertEquals(CardList *expected, CardList *actual, string testDescription){
if(expected == actual){
   cout << "PASSED "<< endl;
  }
  else{
    cout<< " FAILED: "<<testDescription << endl << " Expected: "<< expected<< " Actual: "<< actual <<endl;
  }
}
void assertEquals(int expected, bool actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}
// You should add more assertEquals function for your classes. For example, Node/Card class

#endif
