//
//  FreqList.hpp
//  project4
//
//  Created by Cory Milsap on 4/14/19.
//  Copyright © 2019 Cory Milsap. All rights reserved.
//

#ifndef FreqList_hpp
#define FreqList_hpp

#include <iostream>

class FrequenciesList {
public:
    void initArray();
    void increaseCount(char c) { freqList[int(c)]++; }
    void decreaseCount(char c) { freqList[int(c)]--; }
    int countAtIndex(int i) {
        if (i == 10) return freqList[i] - 1;
        else return freqList[i];
    }
    void showFreq();
    FrequenciesList& operator=(const FrequenciesList& src) { // assignment operator
        for (int i = 0; i < 128; i++) freqList[i] = src.freqList[i];
        return *this;
    }
private:
    int freqList[128] = {0}; // for all characters from ASCII value 32 - 127
};

#endif /* FreqList_hpp */
