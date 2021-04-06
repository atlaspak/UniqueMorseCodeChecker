#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include "MorseAlphabet.h"
#include <string>

class Solution 
{
private:
    MorseAlphabet morseAlphabet;
    bool compareStrings(const std::string& word1, const std::string& word2);
public:    
    int uniqueMorseRepresentations(std::vector<std::string>& words);
};

#endif //SOLUTION_H