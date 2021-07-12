#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

ofstream outf;

typedef int ArrayType;

// #21 Number of Digits in a number
int NumOfDig(int n) {
  if (n < 0)
    return NumOfDig(-n); // get a positive number

  if (n < 10)
    return 1;
   //else loop
  return NumOfDig(n/10) + 1;
}

// #23 Print a number backwards
void NumBackwards(int n) {
  if (n == 0)
    return;
  //else
  outf << n%10;
  NumBackwards(n/10);

  return;
}

// #27 Reverse the entries in an array
void ReverseArray(ArrayType a[], int first, int last) {
  ArrayType temp;
  if (first == last) {
    return;
  }
  if (first > last)
    return;
  //else
  temp = a[first];
  a[first] = a[last];
  a[last] = temp;
  ReverseArray(a, first + 1, last - 1);
  return;
}

// #28 Sum of all contents in an array
int SumArray(ArrayType a[], int n) {
  if (n < 0)
   return 0;
  //else
  return a[n-1] + SumArray(a, n-1);
}

// #29 Prints the location of an element in an array
int location(ArrayType a[], int first, int last, ArrayType elm) {
  if (first > last)
    return 0;

  if (a[last] == elm) {
    return last + 1;
  }
  if (a[first] == elm) {
    return first + 1;
  }
  //else
  return location(a, first, last - 1, elm);
}

// #33 GCD of two numbers
int GCD(int n1, int n2) {
  int q, r;
  q = n1 / n2;
  r = n1 % n2;
  if (r == 0)
    return n2;
  //else 
  return GCD(n2,r);
}

// HailStones Formula
int Hail(int n) {
  if (n==1)
    return 0;
  if (n < 0)
    return Hail(-n);
  //else
  if (n%2 == 0)
    return Hail(n/2) + 1;
  else
    return Hail(n*3+1) + 1;
}

// Sumover Function
double SumOver(unsigned int n) {
  if (n == 0)
    return 0;
  //else
  return 1/n + SumOver(n-1);
}

  // Fill an array recursively 1 to 35
void FillArrayF(int n, ArrayType a[]) {
  if (n < 0)
    return;
  //else
  FillArrayF(n-1, a);
  a[n] = n+1;
  return;
}

  // Fill an array recursively 1 to 35
void FillArrayB(int n, ArrayType a[], int size) {
  if (n < 0)
    return;
  //else
  a[n] = size - n;
  FillArrayB(n-1, a, size);
  return;
}
 // Fill an array from the middle
void FillArrayMid(int n, int first, int last, ArrayType a[]){
  if (n==0)
    return;
  //else
  if (n%2 == 0) {
    a[last] = n;
    FillArrayMid(n-1, first, last-1, a);
  }
  if (n%2 != 0) {
    a[first] = n;
    FillArrayMid(n-1, first+1, last, a);
  }
  return;
}

// Converts a string to an integer number
int StringToNum(string str, int n, int size){
  if (n==0)
    return 0;
  //else
  str[n-1] = str[n-1] - '0';
  return StringToNum(str, n-1, size) + str[n-1]*pow(10, size-n);
}

void RunFromDucks(int time, float Delta, float Total){
  if (Delta <= 0)
    return;
  
  outf << setw(10) << right << time << setw(20) << right << Delta << setw(20) << right << Total << endl;

  RunFromDucks(time + 4, Delta - 0.013, Total + Delta);
  return;
}

void BigToSmall(char a[], int n, int c){
  if (c==26)
    return;
  //else
  if (n==0){
    for(int i=1; i<c+1; i++){
    a[i] = 'a' + (c-i);
      }
    for(int i=0; i<c; i++){
      outf << a[c-i];
      }
    for(int i=2; i<c+1; i++){
      outf << a[i];
      }
    outf << endl;
    BigToSmall(a, n, c+1);
    return;
  }

  if (n > 26)
    return;
  //also else
  for(int i=1; i<n+1; i++){
    a[i] = 'a' + (n-i);
  }
  for(int i=0; i<n; i++){
    outf << a[n-i];
  }
  for(int i=2; i<n+1; i++){
    outf << a[i];
  }
  outf << endl;
  BigToSmall(a, n-1, c);
  return;
}

void SmallToBig(char a[], int n, int c){
  if (n==0)
    return;
  if (n > 26)
    return;
  //else

 if(c==26){
    for(int i=1; i<n+1; i++){
      a[i] = 'a' + (n-i);
    }
    for(int i=0; i<n; i++){
      outf << a[n-i];
    }
    for(int i=2; i<n+1; i++){
      outf << a[i];
    }
    outf << endl;
    SmallToBig(a, n-1, c);
    return;
  }

    //also else
    for(int i=1; i<c+1; i++){
    a[i] = 'a' + (c-i);
      }
    for(int i=0; i<c; i++){
      outf << a[c-i];
      }
    for(int i=2; i<c+1; i++){
      outf << a[i];
      }
    outf << endl;
    SmallToBig(a, n, c+1);
    return; 
}

void Hanoi(int n, char source, char dest, char spare ){ 
  if (n == 1) { 
    cout << "Move disk 1 from rod " << source <<  " to rod " << dest << endl; 
    return; 
  } 
  Hanoi(n - 1, source, spare, dest); 
    cout << "Move disk " << n << " from rod " << source << " to rod " << dest << endl; 
  Hanoi(n - 1, spare, dest, source);  
}


// gonna redo my braces for this pgm
int main() {
  outf.open("Result.txt");

  // #21 Number of Digits in a number
  outf << "# 21 Number of digits in a number: ";
  outf << NumOfDig(3987) << endl << endl;

  // #23 Print a number backwards
  outf << "# 23 Prints a number backwards: " ;
  NumBackwards(3987);
  outf << endl << endl;

  // #27 Reverse the entries in an array
  // Create and populate an array
  outf << "#27 Reverses the contents of the array:\n";
    int size = 10;
    ArrayType ary[size];
  for (int i=0; i<size; i++) {
    ary[i] = i;
    outf << ary[i];
  }
  outf << endl;
  ReverseArray(ary, 0, size - 1);
  for (int i=0; i<size; i++) {
    outf << ary[i];
  }
  outf << endl << endl;

  // #28 Prints the Sum  of the contents of an array
  outf << "#28 Prints the Sum of the contents of the array: " << SumArray(ary, size);
  outf << endl << endl;

  // #29 Prints the location of an element in an array
  outf << "#29 Prints the location of an element searched for in an array: POS: " <<  location(ary, 0, size, 3);
  outf << endl << endl;
  
  // #33 GCD of two numbers
  outf << "#33 GCD of two numbers: 96 and 72: " << GCD(96,72);
  outf << endl << endl;

  // HailStones
  outf << "Hail Formula using 2 numbers 1779 and 116670. 1779: " << Hail(1779) << " iterations. 116670: " << Hail(116670) << " iterations." << endl << endl;

  //SumOver
  outf << "SumOver Function Given 4 as input: " <<  SumOver (4);
  outf << endl << endl;

  // Fill an array recursively 1 to 35
  // make an array of size 35
  ArrayType bry[35];
  FillArrayF(35, bry);
  outf << "Createing an array of size 35 recursively:\n";
  for (int i=0; i<35; i++){
    outf << bry[i] << " ";
  }
  outf << "\n\n";

  // Fill an array recursively 35 to 1
    outf << "Createing an array of size 35 recursively and filling it with numbers 35 to 1:\n";
  FillArrayB(35, bry , 35);
  for (int i=0; i<35; i++){
    outf << bry[i] << " ";
  } 
  outf << "\n\n";

  // function to fill an array of size 19 with values from the middle
  ArrayType cry[19];
  outf << "Fill an array of size 19 with values from the middle:\n";
  FillArrayMid(19, 0, 18, cry);
  for (int i=0; i<19; i++){
    outf << cry[i] << " ";
  }

  // Converting a string to an integer number
  outf << "Converting a string to an integer number:\n";
  string str = "17689375";
  outf << str << " -> " << StringToNum(str, str.size(), str.size()) << endl;
  str = "745433";
  outf << str << " -> " << StringToNum(str, str.size(), str.size()) << endl << endl;

  // Running Table
  outf << setw(10) << right << "Minutes " << setw(20) << right << "4 min Distance" << setw(20) << right << "Total Distance  \n";
  outf << fixed << setprecision(3);
  RunFromDucks(4, 0.73, 0.73);
  outf << endl << endl;
  
  // Kissing Triangle
  outf << "Kissing Triagles:\n";
  char dry[51];
  BigToSmall(dry, 26, 0);
  outf << "\n\n";

  outf << "Now the other way:\n";
  SmallToBig(dry, 26, 0);
  outf << "\n\n\n\n";

  outf << "Now for the Tower of Hanoi: \n";
  char ch = 'A', cj = 'B', ck = 'C';
  clock_t clok;
  clok = clock();
  //Hanoi(100, ch, cj, ck);
/*   clok = clock() - clok;
  float t = clok;
  outf << fixed << setprecision(100);
  outf << "The computer took " << (t/1000) << " seconds to complete the tower\n"; */
  outf << "\nSadly I use an online IDE so I cannot maintain a solid internet conection long enough to run the Hanoi function at 100, however lets have some fun guesstimating how long it takes.\n";
  outf << "Lets assume the computer can perform roughly 2.64 billion disk moves per second (roughly 60% of my computers processing power), It would take my computer with that processing power nearly 152,261,124,399 Centuries to compile the tower fo Hanoi at 100 disks. Yikes\n";
  outf << "If you made 1 move per second it would take 40,196,936,841,331,472,432,000 years to solve this puzzle. Double Yikes" << endl;


  outf.close();
  return 0;
}