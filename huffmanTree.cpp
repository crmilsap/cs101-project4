//
//  huffmanTree.cpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#include "huffmanTree.hpp"

void huffmanTree::buildTree(heap minTree) {
    node *node1 = new node;
    node *node2 = new node;
    while (minTree.getSize() > 1) {
        node *internal = new node;
        
        node1 = minTree.remove();
        node2 = minTree.remove();
        internal->setInternalNode(*node1, *node2);
        minTree.add(internal);
        
        internal->setLChild(node1); internal->setRChild(node2);
    }
    if (minTree.getSize() == 0) {
        root->setInternalNode(*node1, *node2);
        root->setLChild(node1); root->setRChild(node2);
    }
    else if(minTree.getSize() == 1) {
        root = minTree.remove();
        
        root->setLChild(node1);
        root->setRChild(node2);
    }
    encode(root);
}

void huffmanTree::writeInOrder(string filename) {
    ofstream outFS;
    outFS.open(filename);
    if (!outFS.is_open()) {
        cout << "Unable to open inorder1.txt for writing." << endl;
        return;
    }
   printInOrder(root, &outFS);
}

void huffmanTree::printInOrder(node *temp, ofstream *out) {
    if (temp == nullptr) return;
    printInOrder(temp->getLChild(), out);
    *out << *temp << endl;
    printInOrder(temp->getRChild(), out);
}

void huffmanTree::writePreOrder(string filename) {
    ofstream outFS;
    outFS.open(filename);
    if (!outFS.is_open()) {
        cout << "Unable to open preorder1.txt for writing." << endl;
        return;
    }
    
    printPreOrder(root, &outFS);
}
void huffmanTree::printPreOrder(node *temp, ofstream *out) {
    if (temp == nullptr) return;
    *out << *temp << endl;
    printPreOrder(temp->getLChild(), out);
    printPreOrder(temp->getRChild(), out);
}

void huffmanTree::encode(node *root, string encoding) {
    if (root == nullptr) return;
    if (root->getID() < 129) {// is a leaf
        codeArr[root->getID()] = encoding;
        encoding.clear();
    }
    encode(root->getLChild(), encoding + "0");
    encode(root->getRChild(), encoding + "1");
}

void huffmanTree::encodeFile(string filename) {
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "Unable to open file for reading." << endl;
        return;
    }
    
    ofstream outFS;
    outFS.open("code1.txt");
    if (!outFS.is_open()) {
        cout << "Unable to open code1.txt for writing." << endl;
        return;
    }
    
    char c,x;
    string temp;
    int bitCount = 0;
    
    while(inFile.get(c)) {
        x = c;
        temp = codeArr[int(x)];
        bitCount += temp.length();
        for (unsigned int i = 0; i < temp.size(); i++) {
            outFS << temp[i];
        }
    }
    cout << "Phase 1 code length: " << bitCount << " bits" << endl;
    outFS.close();
}

