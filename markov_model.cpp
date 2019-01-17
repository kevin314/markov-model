#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>

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

    Sequence read_window();

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

            cout << window << endl;

        }
    }

    for(auto const& pair : character_map_)
    {
        cout << pair.first << ": " << pair.second.GetCount() << endl;
    }
}

void MarkovModel::InsertString()
{
}

/*if(!character_map_.count(j))
{
	read_window.SetCount()count_ = 1;
}
else
{
	read_window.SetCount()count_ = character_map_.find(line[j]) + 1;
}
*/
