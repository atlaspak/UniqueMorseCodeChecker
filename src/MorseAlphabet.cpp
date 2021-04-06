#include "MorseAlphabet.h"

/*
    This array will be seeked so many times that
    it needs to be stored in a fixed array
    and preferably in the cpu cache so that 
    cache misses won't be a problem
*/
constexpr void MorseAlphabet::createAlphabet()
{
    morseArray[0] = { '.', '-', '\0', '\0' };
    morseArray[1] = { '-', '.', '.', '.' };
    morseArray[2] = { '-', '.', '-', '.' };
    morseArray[3] = { '-', '.', '.', '\0' };
    morseArray[4] = { '.', '\0', '\0', '\0' };
    morseArray[5] = { '.', '.', '-', '.' };
    morseArray[6] = { '-', '-', '.', '\0' };
    morseArray[7] = { '.', '.', '.', '.' };
    morseArray[8] = { '.', '.', '\0', '\0' };
    morseArray[9] = { '.', '-', '-', '-' };
    morseArray[10] = { '-', '.', '-', '\0' };
    morseArray[11] = { '.', '-', '.', '.' };
    morseArray[12] = { '-', '-', '\0', '\0' };
    morseArray[13] = { '-', '.', '\0', '\0' };
    morseArray[14] = { '-', '-', '-', '\0' };
    morseArray[15] = { '.', '-', '-', '.' };
    morseArray[16] = { '-', '-', '.', '-' };
    morseArray[17] = { '.', '-', '.', '\0' };
    morseArray[18] = { '.', '.', '.', '\0' };
    morseArray[19] = { '-', '\0', '\0', '\0' };
    morseArray[20] = { '.', '.', '-', '\0' };
    morseArray[21] = { '.', '.', '.', '-' };
    morseArray[22] = { '.', '-', '-', '\0' };
    morseArray[23] = { '-', '.', '.', '-' };
    morseArray[24] = { '-', '.', '-', '-' };
    morseArray[25] = { '-', '-', '.', '.' };
}

MorseAlphabet::MorseAlphabet()
{
    createAlphabet();
}

/*
    This operator helps user to only work with lower case alphabet
    index must be a char to ease the seek calculation
*/
MorseCode* MorseAlphabet::operator[](const char& index)
{
    if(index >= 'a' && index <= 'z')
    {
        return &(morseArray[index - ((int)('a'))]);
    }
    return nullptr;
}