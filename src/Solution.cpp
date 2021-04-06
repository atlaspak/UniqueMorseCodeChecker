#include "Solution.h"
#include <list>
#include <iostream>

/*
    Linked list is a better selection; particularly for this solution
    because object deletion is needed  and vector object delete is cost more than list
    But since vector call is a requirement we need to convert it to list first
*/
int Solution::uniqueMorseRepresentations(std::vector<std::string>& words) 
{
    std::list<std::string> uniqueList(words.begin(), words.end());
    std::list<std::string>::iterator i,j = uniqueList.begin();

    if(uniqueList.size() == 0)
    {
        return 0;
    }
    else if(uniqueList.size() == 1)
    {
        return 1;
    }
    else
    {
        i = uniqueList.begin();
        j = std::next(i);
    }

    while(j != uniqueList.end() && i != uniqueList.end())
    {
        while(j != uniqueList.end())
        {
            if(compareStrings(*i, *j))
            {
                j = uniqueList.erase(j);
            }
            else
            {
                ++j;
            }
        }
        ++i;
        j = std::next(i);
    }

    return uniqueList.size();
}


/*
    Compare string basically iterates through latin script char conversion of morse chars
    each word will be iterated char by char and actual morse chars will be reached by index
    "gin": {['g'],['i'],['n']} : {['-','-','.','\0'],['.','.','\0','\0'],['-','.','\0','\0']}
    hence morseAlphabet['g'] will return ['-','-','.','\0']
    please check MorseAlphabet class operator for the technical details
*/
bool Solution::compareStrings(const std::string& word1, const std::string& word2)
{
    bool retVal = true;
    int ix = 0, jx = 0;
    int iy = 0, jy = 0;
    while(true)
    {
        char* code1 = morseAlphabet[word1[ix]]->value;
        char* code2 = morseAlphabet[word2[jx]]->value;

        if(code1[iy] == code2[jy])
        {
            iy++;
            jy++;
        }
        else
        {
            //characters are not equal
            retVal = false;
            break;
        }

        /*
         * A morse code can 4 or less chars but storage is fixed to 
         * 4 chars hence remamining spaces filled with '\0' 
        */
        if(iy == MAX_MORSE_WORD_SIZE || code1[iy] == '\0')
        {
            ix++;
            iy = 0;
        }
        if(jy == MAX_MORSE_WORD_SIZE || code2[jy] == '\0')
        {
            jx++;
            jy = 0;
        }

        if(ix >= word1.size())
        {
            if(jx >= word2.size())
            {
                //both variables iterated nothing went wrong
                retVal = true;
            }
            else
            {
                //only one of them completed hence size does not match
                retVal = false;
            }
            break;
        }
        else if(jx >= word2.size())
        {
            //other one completed hence size does not match
            retVal = false;
            break;
        }
    }

    return retVal;
}