#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Sequence
{
    public:
        void CharCount();
        int GetCount() const;

    private:
        int count_ = 0;
};

class MarkovModel
{
    public:
        void InsertString();

    private:
        map<string, Sequence> character_map_;
};

int main()
{
    string fileName;
    cin >> fileName;

    MarkovModel line_map;

    int i;
    string line;

    for(line = "", i = 0; getline(inputFile, line); i++)
    {
        characterCount[i] = line_map.CharCount();
    }

}

void Sequence::CharCount(filename, MarkovModel)
{
    ifstream inputFile;
    Sequence map_count_;

    for(string line; getline(inputFile, line);)
    {
        for(int i = 0; i < line.length(); i++)
        {
            if(!character_map_.count(i))
            {
                count_ = 1;
            }
            else
            {
                count_ = character_map_.find(line[i]) + 1;
            }

            character_map_.insert({line[i], map_count_});
        }
    }
}

int Sequence::GetCount() const
{

}

void MarkovModel::InsertString()
{
    for(int i = 0; i < 
    character_map_.insert()
}
