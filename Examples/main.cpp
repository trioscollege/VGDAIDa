//
//  main.cpp
//  Data Structures & AI Day 2
//
//  Created by Fernando  Restituto on 2020-02-10.
//  Copyright © 2020 Fernando Restituto. All rights reserved.
//
//  Licensed to triOS College.

#include <iostream>

#include "LinkedListNode.h"

using namespace DataStucturesAndAI;

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    
    
    
        
    //Assemble our linked list

    LinkedListNode n1;
    n1.data = new std::string("first");

    LinkedListNode n2;
    n2.data = new std::string("second");
    n1.nextNode = &n2;

    LinkedListNode n3;
    n3.data = new std::string("third");
    n2.nextNode = &n3;

    LinkedListNode n4;
    n4.data = new std::string("fourth");
    n3.nextNode = &n4;

    LinkedListNode n5;
    n5.data = new std::string("fiveded");
    n4.nextNode = &n5;
    
    
    
    
    
    // Create the headNode pointer
    LinkedListNode * headNode = &n1;
    
    
    
    
    
    // Traversing through our linked list
    LinkedListNode * currentNode = headNode;

    while(currentNode != nullptr) {
        std::cout << *currentNode->data + "\n";
        currentNode = currentNode->nextNode;
    }
    
    
    
    
    
    //Assembling a linked list, without maintain direct variable access to each element

    LinkedListNode * newNode = new LinkedListNode();
    newNode->data = new std::string("sixer");
    n5.nextNode = newNode;
    
    
    
    
    LinkedListNode * lastNode = newNode;
    
    
    
    
    newNode = new LinkedListNode();
    newNode->data = new std::string("sevenith");
    lastNode->nextNode = newNode;
    lastNode = newNode;

    newNode = new LinkedListNode();
    newNode->data = new std::string("eighth");
    lastNode->nextNode = newNode;
    lastNode = newNode;

    newNode = new LinkedListNode();
    newNode->data = new std::string("nineth");
    lastNode->nextNode = newNode;
    lastNode = newNode;
    
    
    //Verify that the above elements have been added
    std::cout << "---Verifying Elements Added---\n";
    currentNode = headNode;
    
    while(currentNode != nullptr) {
        std::cout << *currentNode->data + "\n";
        currentNode = currentNode->nextNode;
    }
    
    
    
    //Adding an element to the begining of a linked list
    
    newNode = new LinkedListNode();
    newNode->data = new std::string("Newly Added Frist Node");
    newNode->nextNode = headNode;
    headNode = newNode;
    
    //Verify that the above code worked
    std::cout << "---Verifying Node Added To Start---\n";
    
    currentNode = headNode;
    
    while(currentNode != nullptr)
    {
        std::cout << *currentNode->data + "\n";
        currentNode = currentNode->nextNode;
    }
    
    std::cout << "------\n";
    
    
    
    

    // Delete an element from the start of a Linked List

    LinkedListNode * secondNode = headNode->nextNode;
    delete (headNode);
    headNode = secondNode;

    //Verify that the above code worked
    std::cout << "---Verifying Node Removed From Start---\n";
    currentNode = headNode;

    while(currentNode != nullptr) {
        std::cout << *currentNode->data + "\n";
        currentNode = currentNode->nextNode;
    }

    std::cout << "------\n";





    // Removing an element from the end of a Linked List

    currentNode = headNode;
    LinkedListNode * prevNode = nullptr;

    while(currentNode->nextNode != nullptr) {
        prevNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    if(prevNode != nullptr) {
        delete (prevNode->nextNode);
        prevNode->nextNode = nullptr;
    }

    // Verify
    std::cout << "---Verifying Node Removed From End---\n";

    currentNode = headNode;

    while(currentNode != nullptr) {
        std::cout << *currentNode->data + "\n";
        currentNode = currentNode->nextNode;
    }

    std::cout << "------\n";






    //add a new element after the 5th element
    newNode = new LinkedListNode();
    newNode->data = new std::string("new node data");

    prevNode = nullptr;

    currentNode = headNode;

    int i = 0;
    while(currentNode != nullptr) {
        if(i == 5) {
            newNode->nextNode = currentNode;
            prevNode->nextNode = newNode;

            currentNode = nullptr;
        } else {
            prevNode = currentNode;
            currentNode = currentNode->nextNode;
        }

        i++;
    }

    //Verify that the above code worked
    std::cout << "---Verifying Node was Added After the Fifth---\n";

    currentNode = headNode;

    while(currentNode != nullptr) {
        std::cout << *currentNode->data + "\n";
        currentNode = currentNode->nextNode;
    }

    std::cout << "------\n";






    //remove our newly added element

    prevNode = nullptr;

    currentNode = headNode;

    i = 0;
    while (currentNode != nullptr && currentNode != nullptr) {

        if(i == 5) {
            prevNode->nextNode = currentNode->nextNode;
            delete (currentNode);
            currentNode = nullptr;
        } else {
            prevNode = currentNode;
            currentNode = currentNode->nextNode;
        }

        i++;
    }

    //Verify that the above code worked
    std::cout << "---Verifying New Node Was Deleted---\n";

    currentNode = headNode;

    while(currentNode != nullptr) {
        std::cout << *currentNode->data + "\n";
        currentNode = currentNode->nextNode;
    }

    std::cout << "------\n";


    
    
    
    
    return 0;
}
