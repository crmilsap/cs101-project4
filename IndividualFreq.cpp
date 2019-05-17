//
//  IndividualFreq.cpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#include "IndividualFreq.hpp"

void node::setNode(int i, FrequenciesList frequencies) {
    c = char(i);
    freq = frequencies.countAtIndex(i);
    id = i;
    LChild = nullptr; RChild = nullptr;
}
void node::setInternalNode(node node1, node node2) {
    c = 0;
    id = 130;
    freq = node1.freq + node2.freq;
}

void nodeList::addNode(node *newNode) {
    if (size == capacity) { //array is full
        capacity *= 2;
        node **temp = new node*[capacity];
        for (int j = 0; j < size; j++) temp[j] = a[j];
        delete[] a;
        a = temp;
    }
    if (newNode->getID() > 127) {
        newNode->setID(counter);
        counter++;
    }
    a[size] = newNode;
    size++;
}

node *nodeList::remove() {
    if (size == 1) { size--; return a[0]; }
    node *root = new node;
    root = a[0];
    a[0] = a[size - 1];
    size--;
    if (size == capacity/4) {
        capacity /= 2;
        node **temp = new node*[capacity];
        for (int i = 0; i < size; i++) temp[i] = a[i];
        delete[] a;
        a = temp;
    }
    return root;
}


/*
IndividualFreq::IndividualFreq() {
    c = 0;
    count = 0;
}

IndividualFreq::IndividualFreq(char ch) {
    this->c = ch;
    count = 0;
}

void IndividualFreq::initCharacter(int i) {
    c = i + 32;
}

IndividualFreq::IndividualFreq(IndividualFreq node1, IndividualFreq node2) { // used for creating internal nodes in Huffman tree
    count = node1.getCount() + node2.getCount();
    c = 0;
    lChild = &node1;
    rChild = &node2;
}
*/
