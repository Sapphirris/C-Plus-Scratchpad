#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

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

    
    return 0;
}
