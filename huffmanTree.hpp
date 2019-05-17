//
//  huffmanTree.hpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#ifndef huffmanTree_hpp
#define huffmanTree_hpp

#include <fstream>
#include <iostream>
#include "heap.hpp"

class huffmanTree {
public:
    void buildTree(heap minTree);
    void printInOrder(node *temp, ofstream *out);
    void writeInOrder(string filename);
    void printPreOrder(node *temp, ofstream *out);
    void writePreOrder(string filename);
    void encode(node *root, string encoding = "");
    void encodeFile(string filename);
    ~huffmanTree() { delete root; }
    node *root = new node;
private:
    string codeArr[128];
};

#endif /* huffmanTree_hpp */
