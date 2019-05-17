//
//  heap.hpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#ifndef heap_hpp
#define heap_hpp
#include "IndividualFreq.hpp"
#include <iostream>

class heap {
public:
    heap(FrequenciesList list) {
        bottomUp(list);
    }
    
    void add(node *newNode);
    void percolateUp(int index);
    void bottomUp(FrequenciesList list);
    int getRightChildIndex(int parentIndex);
    int getLeftChildIndex(int parentIndex);
    node *remove();
    void printTree();
    int getSize() { return hArray.getSize(); }
private:
    void heapify(int index);
    nodeList hArray;
};
#endif /* heap_hpp */
