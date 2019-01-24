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
    map<char, int> GetNextCharCount() const;
    char SetNextChar(char);

  private:
    int count_ = 0;
    map<char, int>nextchar_map_;
};

class MarkovModel
{
  public:
    void InsertString();
    void CharCount(string, int);
  private:
    map<string, Sequence> character_map_;
    string current_seed;
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
        read_window.SetNextChar(line[(2 * seed) - 1]);
        character_map_.insert({window, read_window});
      } else {
        character_map_[window].AddCount();
        character_map_[window].SetNextChar(line[(2 * seed) - 1]);
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
  for(auto i = character_map_.cbegin(); i != character_map_.cend(); i++)
  {
    cout << i -> first << ": " << i -> second.GetCount() << endl;

    for(auto j = i -> second.GetNextCharCount().cbegin();
        j != i -> second.GetNextCharCount().cend(); j++)
    {
      cout << "Next char: " << j -> first << " Next char count: " <<
      j -> second << endl;
    }
  }

  /*for(auto const& pair : character_map_)
  {
    cout << pair.first << ": " << pair.second.GetCount() << endl;
  }
  */

  int max_count = 0;

  for(auto i = character_map_.cbegin(); i != character_map_.cend(); i++)
  {
    if(i -> second.GetCount() > max_count)
    {
      max_count = i -> second.GetCount();
      current_seed = i -> first;
    }
  }

  cout << "FIRST SEED: " << current_seed;

}

void MarkovModel::InsertString()
{
}

int Sequence::GetCount() const
{
  return count_;
}

int Sequence::AddCount()
{
  count_++;
}

map<char, int> Sequence::GetNextCharCount() const
{
  return nextchar_map_;
}

char Sequence::SetNextChar(char next_char)
{
  if(nextchar_map_.count(next_char) == 0)
  {
    int char_count = 1;
    nextchar_map_.insert({next_char, char_count});
  } else {
    nextchar_map_[next_char]++;
  }
}
