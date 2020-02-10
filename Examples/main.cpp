//
//  main.cpp
//  Data Structures & AI Day 4
//
//  Created by Fernando  Restituto on 2020-02-10.
//  Copyright © 2020 Fernando Restituto. All rights reserved.
//

#include <iostream>

#include <stack>

#include <queue>

#include <deque>

#include "CircularList.h"
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    
    
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "--Print Each Top Element & Then Remove It --\n";

    while (!s.empty()) {
        cout << '\t' << s.top() << "\n";
        s.pop();
    }
    
    
    
    
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "--Print Front Element & Then Remove It --\n";

    while (!q.empty()) {
        cout << q.front() << "\n";
        q.pop();
    }
    
    
    
    
    cout << "--Now Using Deque--\n";

    deque <int> d;

    cout << "--Adding Elements to Front of Deque--\n";

    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_front(4);

    cout << "--Printing elements from front and then pop them--\n";

    while (!d.empty()) {
        cout << d.front() << "\n";
        d.pop_front();
    }
    
    
    
    cout << "--Adding Elements to Back of Deque--\n";

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    cout << "--Printing elements from front and then pop them--\n";

    while (!d.empty()) {
        cout << d.front() << "\n";
        d.pop_front();
    }
    
    
    
    
    cout << "--Adding Elements to Back of Deque--\n";

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    cout << "--Printing elements from front and then pop them--\n";

    while (!d.empty()) {
        cout << d.front() << "\n";
        d.pop_front();
    }
    
    
    
    
    cout << "--Adding Elements to Front of Deque--\n";

    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_front(4);

    cout << "--Printing elements from back and then pop them--\n";

    while (!d.empty()) {
        cout << d.back() << "\n";
        d.pop_back();
    }
    
    
    
    
    
    CircularList<string> sentence;

    sentence.push_back("All");
    sentence.push_back("work");
    sentence.push_back("and");
    sentence.push_back("no");
    sentence.push_back("play");
    sentence.push_back("makes");
    sentence.push_back("Jack");
    sentence.push_back("a");
    sentence.push_back("dull");
    sentence.push_back("boy");

    CircularList<string>::Iterator word = sentence.begin();

    while (true) {
        cout << *word << " ";
        ++word;
    }
    
    
    
    
    
    return 0;
}
