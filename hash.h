#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        int current = 4;
        HASH_INDEX_T wValues[5] = {0};
        int i = k.length() -1;
        while (i >= 0) {
            HASH_INDEX_T base = 1;
            int count = 0;
            while(count < 6 && i>=0){
                wValues[current] += letterDigitToNumber(k[i]) * base;
                base *= 36;
                count ++;
                --i;
            }
            --current;
        }
        HASH_INDEX_T value = rValues[0]*wValues[0] +rValues[1]*wValues[1]+ rValues[2]*wValues[2] +rValues[3]*wValues[3] +rValues[4]*wValues[4];
        return value;

    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        if(isdigit(letter)){
            HASH_INDEX_T integer = int(letter) - 22;
            return integer;
        }
        else{
            char temp = tolower(letter);
            HASH_INDEX_T integer = int(temp) - 97;
            return integer;
        }
      
  
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
