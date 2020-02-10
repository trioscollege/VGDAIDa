//
//  LinkedListNode.h
//  Data Structures & AI Day 2
//
//  Created by Fernando  Restituto on 2020-02-10.
//  Copyright © 2020 Fernando Restituto. All rights reserved.
//
//  Licensed to triOS College.

#ifndef LinkedListNode_h
#define LinkedListNode_h

namespace DataStucturesAndAI {

    struct LinkedListNode {
        std::string * data = nullptr;
        LinkedListNode * nextNode = nullptr;

        LinkedListNode() {

        }
    };
}

#endif /* LinkedListNode_h */
