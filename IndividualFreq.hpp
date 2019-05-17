//
//  IndividualFreq.hpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#ifndef IndividualFreq_hpp
#define IndividualFreq_hpp

#include <iostream>
#include "FreqList.hpp"
using namespace std;
class node {
public:
    void setNode(int i, FrequenciesList list);
    void setInternalNode(node node1, node node2);
    void setLChild(node *child) { LChild = child; }
    void setRChild(node *child) { RChild = child; }
    node *getLChild() { return LChild; }
    node *getRChild() { return RChild; }
    int getFreq() { return freq; }
    char getChar() { return c; }
    int getID() { return id; }
    void setID(int i) { id = i; }
    friend ostream &operator<<(ostream &output, const node& src) {
        if (src.id > 129)
            output << "i" << src.id;
        else
            output << "s" << src.id;
        return output;
    }
private:
    char c; int freq, id;

    node *LChild, *RChild;
};
class nodeList {
public:
    nodeList() { // constructor
        size = 0; capacity = 2;
        a = new node*[capacity];
        for (int i = 0; i < capacity; i++) a[i] = new node;
    }
    nodeList(int capacity) {
        
    }
    ~nodeList() { //destructor
        for (int i = 0; i < size; i++)
            delete a[i];
        delete a;
    }
    nodeList& operator=(const nodeList& src) { // assignment operator
        size = src.size; capacity = src.capacity;
        a = new node*[src.size];
        for (int i = 0; i < size; i++) a[i] = src.a[i];
        return *this;
    }
    nodeList(const nodeList& src) {
        *this = src;
    }
    node*& operator[](int i) {
        return *(a+i);
    }
    void addNode(node *newNode);
    node *remove();
    int getSize() { return size; }
private:
    node **a;
    int size, capacity;
    int counter = 130;
};
#endif /* IndividualFreq_hpp */
/*
IndividualFreq();
IndividualFreq(char ch);
IndividualFreq(IndividualFreq node1, IndividualFreq node2);
void addCount() { count++; }
void initCharacter(int i);
int getCount() { return count; }
char getChar() { return c; }
void setlChild(IndividualFreq node) { lChild = &node; }
void setrChild(IndividualFreq node) { rChild = &node; }
IndividualFreq *getlChild() { return lChild; }
IndividualFreq *getrChild() { return rChild; }
*/
