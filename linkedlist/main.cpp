//
//  main.cpp
//  linkedlist

#include <iostream>
#include "Classes.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkedList* ll = new LinkedList(1);
    ll->append(2);
    ll->prepend(-1);
    
    cout << "get: " << ll->get(1)->value << endl;
    ll->set(1, 3);
    cout << "get: " << ll->get(1)->value << endl;
    
    ll->shift();
    ll->print();
    ll->pop();
    ll->print();
    ll->shift();
    ll->print();
    
    delete ll;
    return 0;
}
