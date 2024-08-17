#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
 * Okay, time to actually sketch out a plan for the cipher system
 *
 * Four processes:
 * One, assess the message,
 *  - what is the longest word? This is the longest any given line can be.
 *  - Divide the words into separate strings to be re-assembled
 * Two, transform all the words into their capital letter variant
 *  - Check the character, if it is lowercase, subtract 32 to make it uppercase.
 *  - lowercase is between 97 and 122 inclusive in the ASCII character set.
 * Three, combine words in sequence so that we can fill in the line
 *  - Include a garbage letter between words that will make up the same line
 * Four, add garbage letters to the series to make length
 *  - Add garbage letter at the start, and garbage letters to the end to make the full length
 *
 * Function List:
 * - Generate/pick a random character, from a list that excludes vowels.
 * - Determine a word by the spaces around it and copy it into a list / return a list of words from a string.
 *      The ASCII number for a space is '32'
 * - Determine the longest word in the message by measuring all the words found and extracted from the message.
 * - Convert all words in our list into uppercase.
 * - Build a string of words no longer than the max N characters, and return that in a new list of lines for the cipher
 * - Extend a string to the max N characters with random letters.
 *
 *
 * Extra (items outside of the current brief that I would like to experiment with):
 * - allow for user input and sanitise to remove all punctuation and numerical characters
 * - allow for input to include numerical characters, detect them and add them to the junk character system
 *      This would use something like a regular expression to add all the characters in the message to the random
 *      character selector and then pull from that while encrypting.
 */

// function 1: get/pick a random character all uppercase letters excluding vowels.
char get_random_char_excluding_vowels()
{
    const string characters_except_vowels = "BCDFGHJKLMNPQRSTVWXYZ";
    // todo: make a better random selection system.
    int i = (rand()% characters_except_vowels.length());
    return characters_except_vowels[i];
}

/*
 * adding this one in for fun. There's a way to reference the character (capital A-Z via the ASCII number)
 * todo: return a character using the numbers between 65 and 90 inclusive.
 */
char get_random_char_including_vowels()
{
    const string characters_including_vowels = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // todo: make a better random selection system.
    int i = (rand()% characters_including_vowels.length());
    return characters_including_vowels[i];
}

// function 2: create a list of words from a string
vector<string> list_of_words_from_string(string input_string)
{
    vector<string> working_list_of_words;
    
    /*
     * to keep the algorithm simple, we're going to make an assumption: the string that reaches this function
     * has been sanitized, it is a string of words separated by spaces.
     * This will allow us to iterate and find the next space in the string which is the divider between words
     * if we reach the end of the string, that is the last word.
     * We can delineate a word by taking the index after the last space we found, and the index before the next
     * space we find.
     *
     * we will need to extract the word delineated by the two index points we've found.
     * we should also check that we're not starting with a space (as it's a valid character) this would allow us to
     * start with a word at a non-zero index, and if we manage our loop correctly we can also handle double spaces
     * correctly.
     *
     * the original idea I had in mind was to use the find() and substr() functions to split substring into my word
     * list. I have found the strtok() function, which uses a pointer? that is given the function to refer to? but it
     * requires that I convert my string to a c-style string.
     *
     * I am closing for the night as this is not working, and giving me a headache instead.
     */
    

    return working_list_of_words;
}

/*
 * Handling the situation of a list of combined words that we can then scramble based on column:
 *
 * Some creative problem solving for the fact that we can't create dynamically sized arrays without some
 * really creative manipulation of the Vector and List libraries.
 * We can treat a string as a 2 dimensional array using the wonderful magic of maths.
 * Using Modulus and division, flooring the result to get the nearest integer.
 * Alternatively we could use arrays of set, anticipated sizes, and manipulate the data around that.
 * We'd need some backup for situations that result in arrays for messages with longer words and a system to pick
 * the correctly sized array for those situations.
 */


struct DictionaryEntry
{
    int key;
    string name;
};

int main(int argc, char* argv[])
{
    
    vector<DictionaryEntry> dictionaryOfSamples;
    DictionaryEntry sample;
    for (int i = 0; i < 10; i++)
    {
        sample.key = i;
        sample.name = "wordy";
        sample.name += to_string(i);
        dictionaryOfSamples.push_back(sample);
    }

    cout << "List size = "<< dictionaryOfSamples.size() << endl;
    for( int i = 0; i < dictionaryOfSamples.size() ; i++ )
    {
        cout << "Key: " << dictionaryOfSamples.at(i).key << " Name: " << dictionaryOfSamples.at(i).name << endl;
    }

    // make code to allow us to search the keys inside the dictionary and retrieve the index, and thus the values inside the dictionary for any given key.
    
    return 0;
}
