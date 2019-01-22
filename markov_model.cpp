#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

class Sequence
{
    public:
        int AddCount();
        int GetCount() const;

    private:
        int count_ = 0;
};

class MarkovModel
{
    public:
        void InsertString();
        void CharCount(string, int);
    private:
        map<string, Sequence> character_map_;
};

int main()
{
    string fileName;
    int seed;

    cin >> fileName;
    cin >> seed;

    MarkovModel sequence_map;


    sequence_map.CharCount(fileName, seed);

}

int Sequence::GetCount() const
{
    return count_;
}

int Sequence::AddCount()
{
    count_++;
}

void MarkovModel::CharCount(string fileName, int seed)
{
    ifstream inputFile;
    inputFile.open(fileName.c_str());
    int numSequences = 0;

    for(string line; getline(inputFile, line);)
    {
        for(int i = 0; i < line.length(); i++)
        {
            string window = "";

            for(int j = i; j < (i + seed); j++)
            {
                window += line[j];
            }

            if(character_map_.count(window) == 0)
            {
                Sequence read_window;

                read_window.AddCount();
                character_map_.insert({window, read_window});

            } else {
                character_map_[window].AddCount();
            }

            numSequences++;

            cout << window << endl;

        }
    }

    //char currSeed = character_map_[window].GetCount();

    /*for(int = i; i < numSequences; i++)
      {
      }
      */

    for(auto const& pair : character_map_)
    {
        cout << pair.first << ": " << pair.second.GetCount() << endl;
    }


    int max_count = 0;
    string first_seed;

    for(auto i = character_map_.cbegin(); i != character_map_.cend(); i++)
    {
        if(i -> second.GetCount() > max_count)
        {
            max_count = i -> second.GetCount();
            first_seed = i -> first;
        }
    }

    cout << "FIRST SEED: " << first_seed;
}

void MarkovModel::InsertString()
{
}

