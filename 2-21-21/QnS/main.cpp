/*
Gavin Garner
CS372
Queue and Stack
 PGM
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

ofstream outf;
ifstream inf;
//defining data types
typedef unsigned long size_t; // Compiler threw a fit about unsigned int so now its long

// Constants
const int CAPACITY = 300;

//Classes
template<typename ElementType>
class List
  {
  private:
    int pos;
    int used;
    ElementType myary[CAPACITY];
  public:
    //Constructors
    
    List()
    {
      pos = 0; used = 0; 
    }

    
    List(List &T)
    {
      pos = T.getPos();
      used = T.size();
      for (int i = 0; i < CAPACITY; i++)// would use i < used, but I want the other elements to be initialized to zero
        {myary[i] = T.myary[i];}    
    }

    //Methods
    bool empty() // returns true if list is empty
    {
      if (used == 0)
        return true;
      return false;
    }

    void first()// places pos at beginning of list
    {pos = 0;}
    
    void last() // places pos at end of list
    {
      if(used != 0)
        pos = (used - 1);
    } // if used is 0 there is no list so last DNE

    void prev() // moving pos 1 back in the list
    {
      if (pos > 0)
        pos--;
    }

    void next() // moving pos 1 further into the list
    {
      if (pos < (used - 1))
        pos++;
    }

    
    void insertBefore(ElementType x) //inserting an element behind pos
    {
      if (used < CAPACITY)
      {
        used++;
        if (used > 1)
        {
          for (int i = (used - 1); i >= pos; i--)
          {
            myary[i] = myary[i-1];
          }
        }
        myary[pos] = x; // an empty element is now inserted technically behind the value pos was pointing to
      }
    }

    
    void insertAfter(ElementType x) //inserting an element behind pos
    {
      if (used < CAPACITY)
      {
      used++;
      if (used > 1)
      {
        for (int i = (used - 1); i > pos; i--)
        {
          myary[i] = myary[i-1];
        }
      }

      if(used > 1) // of the 2 identical elements move to the one after the other
        pos++;
      
      myary[pos] = x; // an empty element is now inserted technically behind the value pos was pointing to
      }
    }



    void erase()//erases the element at pos
    { 
      if(used > 1)
      {
        for (int i = pos; i < used; i++)
        {
          myary[i] = myary[i+1];
        }
      }
      if(used > 0)
        {used--;}
    }

    void clear() // clears the entire list
    {
      pos = 0; used = 0; 
      for (int i = 0; i < CAPACITY; i++)
        myary[i] = 0;    
    }

    //Getters and Setters
    
    int getPos()
    {return pos;}
    
    void setPos(int i)
    {
      if (used > i && i >= 0)
      {pos = i;}
    }

    int size() const // returns # of elements in array
    {return used;} // used is the number of elements

    
    ElementType getElement()
    {
      if (used > 0)
        return myary[pos];
    }

    
    void replace(ElementType y)
    {myary[pos] = y;}

    //Overloading Operators
    
    bool operator==(List<ElementType> &T)
    {
      if (used != T.size()) // false if they arnt same size
        return false;

      for(int i = 0; i < used; i++)
        {
          if (myary[i] != T.myary[i])
            return false;
        }
        
      return true;
    }

    
    bool operator!=(List<ElementType> &T)
    {
      if (*this == T)
        return false;
      return true;
    }

    
    List<ElementType> operator+(List<ElementType> &T) //adding the elements from 2 lists
    {
      
      if(used > T.size())
        {
          List temp(T);
          for(int i = 0; i < T.size(); i++)
            {
              temp.myary[i] = myary[i] + temp.myary[i]; 
            }
          return temp;
        }
      if(used < T.size())
        {
          List temp(T);
          for(int i = 0; i < used; i++)
            {
              temp.myary[i] = myary[i] + temp.myary[i]; 
            }
          return temp;
        }
      if(used == T.size() && used != 0)
        {
          List temp(T);
          for(int i = 0; i < T.size(); i++)
            {
              temp.myary[i] = myary[i] + temp.myary[i]; 
            }
          return temp;
        }
    }

    
    List<ElementType> operator=( List<ElementType> &T)
      {
        List temp(T);
        if(T.size() == 0 || used == 0)
          return temp;
        
        if(used > T.size())
        {
          for(int i = 0; i < T.size(); i++)
          {
            myary[i] = T.myary[i];
          }
        }
        
        if(used < T.size())
        {
          for(int i = 0; i < used; i++)
          {
            myary[i] = T.myary[i];
          }
        }
        
        if(used == T.size())
        {
          for(int i = 0; i < used; i++)
          {
            myary[i] = T.myary[i];
          }
        }      
      }// Replace A with B

    
    List<ElementType> operator+=(List<ElementType> &T)
      {
        List temp(T);
        
        if(T.size() == 0 || used == 0)
          return temp;
        
        if(used > T.size())
        {
          for(int i = 0; i < T.size(); i++)
          {
            temp.myary[i] = myary[i] + T.myary[i];
          }
          return temp;
        }
        
        if(used < T.size())
        {
          for(int i = 0; i < used; i++)
          {
            temp.myary[i] = myary[i] + T.myary[i];
          }
          return temp;
        }
        
        if(used == T.size())
        {
          for(int i = 0; i < used; i++)
          {
            temp.myary[i] = myary[i] + T.myary[i];
          }
          return temp;
        }
        return temp;
      }

        // OVERLOAD <<
    friend ostream& operator<<(ostream& outf, List<ElementType> &T)
    {
      T.setPos(0);
      for (int i = 0; i < T.size(); i++)
      {
        outf << T.getElement() << " ";
        T.next();
      }
      return outf;
    }

  };

template<typename ElementType>
class Stack

  {
    private:
      List<ElementType> s1;
    public:
      void push(ElementType i)
      {     
        s1.insertAfter(i);
        s1.last();
      }

      void pop()
      {
        s1.last();
        s1.erase();
        s1.last();
      }

      ElementType Top()
      {
        s1.last();
        return s1.getElement();
      }

      void Printall()
        {
          cout << s1; 
          outf << s1; 
        }
  };

template<typename ElementType>
class Queue
  {
    private:
      List<ElementType> myQ;
      int back = 0;
      int front = 0; // front of line

    public:
      Queue()
        {
          back = 0; front = 0;
        }
      void enqueue(ElementType v)
        {
          if (myQ.size() == CAPACITY) // if list full do nothing
            return;
          myQ.last();
          myQ.insertAfter(v);
          myQ.last(); // ensure its in the last pos

          back = myQ.getPos(); // back of line established

          // Queue has moved so we move with it
          myQ.first();
          front = myQ.getPos();
          return;
        }

      void dequeue()
        {
          if (myQ.size() == 0) // if no list do nothing
            return;
          myQ.first();
          myQ.erase();
          myQ.first(); // ensure we are in first pos

          front = myQ.getPos(); // front of the line reestablished

          // Queue has moved so we move with it
          myQ.last();
          back = myQ.getPos();
        }
      
      bool empty()
        {
          if (myQ.size() == 0)
            return true;
          return false;
        }

      bool full()
        {
          if ((back + 1) == front)
            return true;
          return false;
        }

      int size()
        {
          return back;
        }

      //Getters and Setters
      int get_back()
      {return back;}

      int get_front()
      {return front;}

      ElementType get_front_val()
      {
        myQ.first();
        return myQ.getElement();
      }

      ElementType get_back_val()
      {
        myQ.last();
        return myQ.getElement();
      }

     void Printall()
        {
          cout << myQ;
          outf << myQ;
        }

  };

//Functions
template<typename ElementType>
void Decrypt(Queue<ElementType> &Q1 , Stack<ElementType> S1)
  {
    int syze = Q1.size() + 1;
    for (int i = 0; i < (syze/2); i++)
     {
      // Throw 1st element to Stack Then dequeue that element from queue
      S1.push(Q1.get_front_val());
      Q1.dequeue();
      // Enqueue Next Element to get it to back of queue then dequeue it
      Q1.enqueue(Q1.get_front_val());
      Q1.dequeue();
     }

    S1.Printall();
    Q1.Printall();
  }

int main() 
{
  outf.open("Results.txt");
  inf.open("QStkInput.txt");
  Queue<string> Q;
  Stack<string> S;
  string temp; // IMPORTANT! change this when you change the type declatrations for the class objects above They Must Match
  while(inf >> temp)
    {
      Q.enqueue(temp);
    } 

    Decrypt(Q, S);



  inf.close();
  outf.close();
}

