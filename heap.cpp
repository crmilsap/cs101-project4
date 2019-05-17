//
//  heap.cpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#include "heap.hpp"

void heap::add(node *newNode) {
    hArray.addNode(newNode);
    int bubble = hArray.getSize() - 1;
    int parent = (bubble - 1) / 2;
    while (bubble > 0 && hArray[bubble]->getFreq() < hArray[parent]->getFreq()) {
        node *temp = new node;
        temp = hArray[bubble];
        hArray[bubble] = hArray[parent];
        hArray[parent] = temp;
        bubble = parent;
        parent = (bubble - 1) / 2;
    }
}
void heap::bottomUp(FrequenciesList list) {
    for (int i = 0; i < 128; i++) {
        if (list.countAtIndex(i) > 0) {
            node *newNode = new node;
            newNode->setNode(i, list);
            hArray.addNode(newNode);
        }
    }
    if (list.countAtIndex(10) > 1) {
        list.decreaseCount(10);
    }
    // finished adding to list, now time to heapify
    for (int i = (hArray.getSize() / 2) - 1; i >= 0; i--)
        heapify(i);
}

void heap::heapify(int index) {
    int leftChildIndex = getLeftChildIndex(index);
    int rightChildIndex = getRightChildIndex(index);
    int minIndex = index;
    
    if (leftChildIndex!= -1 && hArray[leftChildIndex]->getFreq() < hArray[minIndex]->getFreq()) {
        minIndex = leftChildIndex;
    }
    if (rightChildIndex != -1 && hArray[rightChildIndex]->getFreq() < hArray[minIndex]->getFreq()) {
        minIndex = rightChildIndex;
    }
    if (minIndex != index) {
        node *temp = new node;
        temp = hArray[index];
        hArray[index] = hArray[minIndex];
        hArray[minIndex] = temp;
        heapify(minIndex);
    }
}

int heap::getLeftChildIndex(int parentIndex) {
    int leftIndex = (2 * parentIndex) + 1;
    if (leftIndex >= hArray.getSize()) return -1;
    return leftIndex;
}

int heap::getRightChildIndex(int parentIndex) {
    int rightIndex = (2 * parentIndex) + 2;
    if (rightIndex >= hArray.getSize()) return -1;
    return rightIndex;
}

void heap::printTree() {
    for (int i = 0; i < hArray.getSize(); i++) {
        cout << hArray[i]->getFreq() << "\t" << hArray[i]->getChar() << endl;
    }
}

node *heap::remove() {
    node *min = new node;
    min = hArray.remove();
    heapify(0);
    return min;
}

