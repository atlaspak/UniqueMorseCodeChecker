#ifndef MORSE_ALPHABET_H
#define MORSE_ALPHABET_H

#define ALPHABET_LENGTH         26
#define MAX_MORSE_WORD_SIZE     4

typedef struct MorseCode
{
    char value[MAX_MORSE_WORD_SIZE]; //4: max length of a morse code
}MorseCode;

class MorseAlphabet
{
private:
    MorseCode morseArray[ALPHABET_LENGTH];
    constexpr void createAlphabet();
public:
    MorseAlphabet();
    MorseCode* operator[](const char& index);
};

#endif //MORSE_ALPHABET_H