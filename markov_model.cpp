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
        int AddCount() const;

    private:
        int count_ = 0;
};

class MarkovModel
{
    public:
        void InsertString();
	void CharCount(string, Sequence, int);
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

    sequence_map.CharCount(fileName, read_window, seed);

}


int Sequence::AddCount() 
{
    count_++;
}

void MarkovModel::CharCount(string fileName, Sequence read_window, int seed)
{
    ifstream inputFile;
    inputFile.open(fileName.c_str());

    for(string line; getline(inputFile, line);)
    {
        for(int i = 0; i < line.length(); i++)
        {
	    string window = "";

	    for(int j = i; j < seed; j++)
	    {
		window += line[j];
		
	    }
            
	    read_window.AddCount();
            character_map_.insert({window, read_window});
        }
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
