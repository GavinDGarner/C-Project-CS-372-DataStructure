/*
Gaivn Garner
CS 372
Statistician
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream inf;
ofstream outf;

class statistician
{
  private:
  float lowest, highest, length, last_num, sum, mean;
  public:
  statistician()
  {
    lowest = 0;
    highest = 0;
    length = 0;
    last_num = 0;
    sum = 0;
    mean = 0;
  }
  void next_number(float val)
    {
    is_first(val);
    // Test for highest and lowest values thus far
    low(val);
    high(val);

    // incriment length
    len();

    // set new last_num
    last(val);

    // compute sum
    comp_sum(val);

    // compute mean
    comp_mean();
    }

  void is_first(float val)
    {
      if (length == 0)
        {
          last_num = val;
          highest = val;
          lowest = val;
        }

    }

  void low(float val) // lower than last number
    {
    if (lowest > val)
        lowest = val; 
    }

  void high(float val) // larger than last number
    {
    if (highest < val) 
        highest = val; 
    }

  void len() // length + 1
    {length += 1;}

  void last(float val) // store val for next number comparison
    {last_num = val;}

  void comp_sum(float val)
    {sum = sum + val;}

  void comp_mean()
    {mean = sum / length;}



  void erase()
  {
    lowest = 0;
    highest = 0;
    length = 0;
    last_num = 0;
    sum = 0;
    mean = 0;
  }

  //Getters
  float get_lowest()
  {return lowest;}

  float get_highest()
  {return highest;}

  float get_last_num()
  {return last_num;}

  float get_length()
  {return length;}

  float get_sum()
  {return sum;}

  float get_mean()
  {return mean;}
};


int main() 
{
outf.open("Results.txt");
inf.open("Stat1.txt");

statistician s;
float temp; // we will read in data to this variable for simplicity's sake

// SET 1

outf << "Processing set 1...\n\n";

while (inf >> temp)
{
  s.next_number(temp);
}

outf << "Lowest number of set 1: " << s.get_lowest() << endl;
outf << "Highest number of set 1: " << s.get_highest() << endl;
outf << "Number of values in set 1: " << s.get_length() << endl;
outf << "Last number of set 1: " << s.get_last_num() << endl;
outf << "Sum of the numbers of set 1: " << s.get_sum() << endl;
outf << "Mean of the numbers of set 1: " << s.get_mean() << endl;

outf << "Erasing stored data for next set to be entered...\n";
s.erase(); // zero out data

inf.close();
inf.open("Stat2.txt");

// SET 2

outf << "\nProcessing set 2...\n\n";

while (inf >> temp)
{
  s.next_number(temp);
}

outf << "Lowest number of set 2: " << s.get_lowest() << endl;
outf << "Highest number of set 2: " << s.get_highest() << endl;
outf << "Number of values in set 2: " << s.get_length() << endl;
outf << "Last number of set 2: " << s.get_last_num() << endl;
outf << "Sum of the numbers of set 2: " << s.get_sum() << endl;
outf << "Mean of the numbers of set 2: " << s.get_mean() << endl;

outf << "Erasing stored data for next set to be entered...\n";
s.erase(); // zero out data

inf.close();
inf.open("Stat3.txt");

// SET 3

outf << "\nProcessing set 3...\n\n";

while (inf >> temp)
{
  s.next_number(temp);
}

outf << "Lowest number of set 3: " << s.get_lowest() << endl;
outf << "Highest number of set 3: " << s.get_highest() << endl;
outf << "Number of values in set 3: " << s.get_length() << endl;
outf << "Last number of set 3: " << s.get_last_num() << endl;
outf << "Sum of the numbers of set 3: " << s.get_sum() << endl;
outf << "Mean of the numbers of set 3: " << s.get_mean() << endl;

outf << "Erasing stored data for next set to be entered...\n";
s.erase(); // zero out data

inf.close();
// As requested by the HW document we will make new objects for this
//avg stat 1
inf.open("Stat1.txt");

statistician s1;

while (inf >> temp)
{
  s1.next_number(temp);
}
outf << "\nThe average of Set 1 is : "<< s1.get_mean();

inf.close();

//Sum of stat 2
inf.open("Stat2.txt");

statistician s2;

while (inf >> temp)
{
  s2.next_number(temp);
}
outf << "\nThe sum of Set 2 is : "<< s2.get_sum();

inf.close();

//Length of stat 3
inf.open("Stat3.txt");

statistician s3;

while (inf >> temp)
{
  s3.next_number(temp);
}
outf << "\nThe Number of values in Set 3 is : "<< s3.get_length();

inf.close();


// As requested by the HW doc
// largest values from the sets
outf << "\n\nThe largest number of Set 1 is : "<< s1.get_highest();
outf << "\nThe largest number of Set 2 is : "<< s2.get_highest();
outf << "\nThe largest number of Set 3 is : "<< s3.get_highest();

outf.close();
}

