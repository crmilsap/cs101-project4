//
//  main.cpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "huffmanTree.hpp"

FrequenciesList readFile(string filename);

int main(int argc, const char *argv[]) {
    //checking for errors in file usage
    
    if (argc != 2) {
        cout << "Usage: ./a.out filename" << endl;
        return -1;
    }
    
    string filename = argv[1];
    FrequenciesList freqs = readFile(filename);
    
    heap tree(freqs);
    huffmanTree huff;
    huff.buildTree(tree);
    huff.writePreOrder("preorder1.txt");
    huff.writeInOrder("inorder1.txt");
    huff.encodeFile(filename);

    return 0;
}

FrequenciesList readFile(string filename) {
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "Unable to open " << filename << " for input." << endl;
    }
    FrequenciesList data;
    char c;
    while (inFile.get(c)) {
        data.increaseCount(c);
    }
    inFile.close();
    return data;
}
