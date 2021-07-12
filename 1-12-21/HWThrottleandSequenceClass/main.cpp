#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outf;

class Throttle
{
  private:
    int position, top_position;



  public:
  // Constructors
    Throttle()
    {
      position = 0;
      top_position = 0;
    }
    Throttle(int x, int y)
    {
      top_position = x;
      position = y;
    }
    // Manipulation and Testing
    void shift(int newpos)
    {
      position = position + newpos; //Shifting

      if (position > top_position) // cant exceed maximum
          position = top_position;

      if (position < 0) // cant be less than 0
          position = 0;
    }

    void shut_off()
    {
      position = 0;
    }

    bool is_on() const
    {
      return (flow() > 0);
    }

    float flow() const
    {
      float fuel;
      fuel = static_cast<float> (position) / static_cast<float> (top_position);
      return fuel;
    }

    //Getters
    int get_pos()
    {return position;}

    int get_top_pos()
    {return top_position;}

};

int main() 
{
  outf.open("Results.txt");

  Throttle car(6, 0);
  Throttle truck(30, 0);
  Throttle shuttle(20, 6);

  if (shuttle.is_on()) // if its on then we want them off
      outf << "Beginning procedures for turning main shuttle engines off.\n";
  while (shuttle.is_on()) // if its still on, we are not done turning them off
  {
    outf << "Current throttle position: " << shuttle.get_pos() << endl;
    outf << "Current flow ratio: " << shuttle.flow() << endl;
    outf << "Lowering throttle position by 1..." << endl;
    shuttle.shift(-1);    
  } 
    outf << "\nThis shuttle's engines are no longer recieving fuel.\n";

  outf << "\nAttempting to push throttle on the truck past its limitations.\n";

  truck.shift(68);
  outf << "After attempting to shift 68 positions, the current throttle position is: " << truck.get_pos() << "\n";
  outf << "This should be equivalent to the maximum throttle position: " << truck.get_top_pos() << "\n";
  outf << "Now attempting the same procedure, but reversed by 68 positions.\n";
  truck.shift(-68);
  outf << "After attempting to shift 68 positions, the current throttle position is: " << truck.get_pos() << "\n";
  outf << "This should be equivalent to the minimum throttle position: 0\n";

  // lets turn the car off, but first on
  car.shift(4);
  outf << "\nThe car has arrived at its destination and should be turned off. Currently it's throttle in in position: " << car.get_pos() << "\n";
  car.shut_off();
  outf << "After running the shut off procedure the car's current throttle position is: " << car.get_pos() << "\n";

}

  