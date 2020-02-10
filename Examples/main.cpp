//
//  main.cpp
//  Data Structures & AI Day 1
//
//  Created by Fernando  Restituto on 2020-02-10.
//  Copyright © 2020 Fernando Restituto. All rights reserved.
//
//  Licensed to triOS College.

#include <iostream>

#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    // Declare and create our int array
    int arraySize = 10;
    int * data = new int[arraySize];

    // Assign values to our array
    for (int i = 0; i < arraySize; i++) {
        data[i] = i;
    }

    // Access and print each element in our array
    std::cout <<  "---Printing Array---\n";
    for (int i = 0; i < arraySize; i++) {
        std::cout <<  std::to_string(data[i]) + "\n";
    }
    
    
    
    
    
    // Investigate the memory addresses for each element in our array
    std::cout <<  "---Printing Memory Addresses For Array---\n";
    for (int i = 0; i < arraySize; i++) {
        std::cout << &data[i];
        std::cout << "\n";
    }
    
    
    
    
    arraySize = arraySize + 1;
    int * data2 = new int[arraySize];

    for (int i = 0; i < arraySize -1; i++) {
        data2[i] = data[i];
    }

    delete [] data;
    data2[arraySize-1] = 10;
    data = data2;

    std::cout <<  "---Verify Addition of Element End of Array---\n";
    for (int i = 0; i < arraySize; i++) {
        std::cout <<  std::to_string(data[i]) + "\n";
    }
    
    
    
    
    
    // Add an element to the start of our array
    arraySize = arraySize + 1;
    data2 = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        data2[i+1] = data[i];
    }

    data2[0] = -1;
    delete [] data;
    data = data2;

    std::cout <<  "---Verify Additon of Element at Start of Array---\n";

    for (int i = 0; i<arraySize; i++) {
        std::cout <<  std::to_string(data[i]) + "\n";
    }
    
    
    
    
    
    // Delete the element at the end of our array
    arraySize = arraySize - 1;
    data2 = new int[arraySize];

    for (int i = 0; i < arraySize; i++){
        data2[i] = data[i];
    }

    delete [] data;
    data = data2;

    std::cout <<  "---Verify Deletion of Element at End of Array---\n";

    for (int i = 0; i < arraySize; i++) {
        std::cout <<  std::to_string(data[i]) + "\n";
    }
    
    
    
    
    // Add an element at the 6th index of our array
    arraySize = arraySize + 1;
    int indexMod = 0;
    data2 = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        if(i == 6) {
            data2[i] = 9001;
            indexMod = 1;
        }
        data2[i + indexMod] = data[i];
    }

    delete [] data;
    data = data2;

    std::cout <<  "---Verify Addition of the Sixth Element of Array---\n";
    for (int i = 0; i < arraySize; i++) {
        std::cout <<  std::to_string(data[i]) + "\n";
    }
    
    
    
    
    std::cout <<  "---Verify Vector Code Usage---\n";
    
    vector<int> v;    // a vector of ints
    int i;

    for (i=0; i<10; i++){
        v.push_back(i);
    }

    for (i=0; i<v.size(); i++) {
        v[i] = v[i] * 2;
    }

    for (i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
        
        
    
    
    
    //SOLUTIONS TO EXCERCISES!
    
    
    
    // Delete the element at the start of our array
    arraySize = arraySize -1;
    data2 = new int[arraySize];

    for (int i = 1; i < arraySize + 1; i++) {
        data2[i-1] = data[i];
    }

    delete [] data;
    data = data2;

    std::cout <<  "---Verify Deletion of Element at Start of Array---\n";
    for (int i = 0; i < arraySize; i++) {
        std::cout <<  std::to_string(data[i]) + "\n";
    }
    
    
    
    
    
    //Delete the 6th element in our array (the one that was just added (with the value of 9001 at index 5))
    arraySize = arraySize - 1;
    indexMod = 0;
    data2 = new int[arraySize];
    for (int i = 0; i < arraySize + 1; i++) {
        if(i == 5) {
            indexMod = -1;
        } else {
            data2[i + indexMod] = data[i];
        }
    }

    delete [] data;
    data = data2;

    std::cout <<  "---Verify Deletion of the Sixth Element of Array---\n";
    for (int i = 0; i < arraySize; i++) {
        std::cout <<  std::to_string(data[i]) + "\n";
    }
        
        
    
    
    
    
    
    return 0;
    
    
}
