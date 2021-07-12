/*
Gaivn Garner
CS 372
Quadratic Expression
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

ofstream outf;
ifstream inf;

class quadratic
{
  private:
    float a, b, c, real0, real1, real2, real3;
  public:
    quadratic(float x, float y, float z)
      {
        a = x;
        b = y;
        c = z;
        real0 = 0;
        real1 = 1;
        real2 = 2;
        real3 = 3;
      }
    
    float real_roots()
      {
      // a = b = c = 0 all numbers are real roots
      if(a == 0 && b == 0 && c == 0) 
        return real3;

      // a = b = 0 and c !=0  no numbers are real roots
      if(a == 0 && b == 0 && c != 0)
        return real0;

      // a = 0, b != 0 then 1 real root
      if (a == 0 && b !=0)
        return real1;
      
      // a !=0, b^2 < 4ac then no real roots
      if (a != 0 && (pow(b, 2.0) < (4 * a * c)))
        return real0;

      // a !=0, b^2 = 4ac then 1 real roots
      if (a != 0 && (pow(b, 2.0) == (4 * a * c)))
        return real1;

      // a !=0, b^2 > 4ac then 2 real roots
      if (a != 0 && (pow(b, 2.0) > (4 * a * c)))
        return real2;   

      return real0;
      }

    float low_root()
      {
        if(real_roots() == 3)
        {;
          return real0;
        }
        if(real_roots() == 0)
        {
          return real0;
        }
        if(real_roots() > 0)
        {
          float root_low;
          root_low = ((-b - sqrt((pow(b, 2.0)-(4 * a * c)))) / (2 * a));
          return root_low;
        }
        return real0;
      }
    float high_root()
      {
        if(real_roots() == 3)
        {
          return real0;
        }
        if(real_roots() == 0)
        {
          return real0;
        }
        if(real_roots() > 0)
        {
          float root_high;
          root_high = ((-b + sqrt((pow(b, 2.0)-(4 * a * c)))) / (2 * a));
          return root_high;
        }
        return real0;
      }

};

int main() 
{
  outf.open("Results.txt");
  inf.open("Numbers.txt");
  float x, y, z;
  while(inf >> x)
  {    
    inf >> y; 
    inf >> z;
    quadratic eq(x, y, z);
    
    outf << "\nFor the coefficients: " << x << ", " << y << ",  and " << z << " there exist " << eq.real_roots() << " real roots for the equation.\n";

    if (eq.real_roots() == 1)
      {
        outf << "The real root is " << eq.high_root() << endl;
      }

    if (eq.real_roots() == 2)
      {
        outf << "The real roots are " << eq.high_root() << " and " << eq.low_root() << endl;
      }
    
    if (eq.real_roots() == 3)
      {
        outf << "The real roots are " << eq.high_root() << " and " << eq.low_root() << endl;
      }
  }
  inf.close();
  outf.close();
}