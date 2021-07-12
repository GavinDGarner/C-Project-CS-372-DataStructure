/*
Gavin Garner
CS 372
General List Templates
*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream outf;
ifstream inf;
//defining data types
typedef unsigned long size_t; // Compiler threw a fit about unsigned int so now its long

// Constants
const int CAPACITY = 20;

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
    for (int i = 0; i < CAPACITY; i++)
      myary[i] = 0;
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


};
  // Overload operators
    template<typename ElementType>
    ostream& operator<<(ostream& outf, List<ElementType> &T)
 {
   T.setPos(0);
   for (int i = 0; i < T.size(); i++)
   {
     outf << T.getElement() << " ";
     T.next();
   }
   return outf;
 }

int main()
  {
    outf.open("Results.txt");
  	List<int> a,b;  int endit;

	for (int i=1;i<=20;i++)
	   a.insertAfter(i);
	outf << "List a : " << endl;
    	outf << "  "  << a << endl;
	outf << "Number of elements in a - " << a.size() << endl;

	for (int i=1;i<=10;i++)
	   b.insertBefore(i);
	outf << "List b : " << endl;
    	outf << "  "  <<  b << endl;
	outf << "Number of elements in b - " << b.size() << endl;

	if ( a == b )
	    outf << "List a & b are equal" << endl;
	  else
	    outf << "List a & b are Not equal" << endl;

	a.first();
	b.first();
	outf << "First elmenet in list a & b: " << a.getElement() << ", "
				       << b.getElement() << endl;
	a.last();
	b.last();
	outf << "Last elmenet in list a & b: " << a.getElement() << ", "
				     << b.getElement() << endl;
					 
	outf << endl << endl << " Start of new stuff" << endl;

	b.clear();
	outf << "Empty List b:  " << b << endl;

	if ( a == b )
	    outf << "List a & b are equal" << endl;
	  else
	    outf << "List a & b are Not equal" << endl;

	for (int i=1;i<=10;i++)
	   b.insertBefore(i*5);
	outf << "List b : " << endl << b << endl;

	a.setPos(5);
	b.first();
	for ( int i=1; i<4; i++)
	{
	   b.replace(a.getElement());
	   a.erase();
	   b.next();
	}

	outf << "Modified Object 'a' (shorter) " << endl;
    	outf << "List a: " << a << endl;
	outf << "Modified Object 'b' " << endl;
    	outf << "List b: " << b << endl;

	for (int i=1;i<=10;i++)
	   b.insertBefore(i);
	   
	List<int> c(b);
	outf << "Copy Constructor c(b)" << endl;
    	outf << "List b : " << b << endl;
    	outf << "List c : " << c << endl;

	if ( c == b )
	    outf << "List c & b are equal" << endl;
	  else
	    outf << "List c & b are Not equal" << endl;


	List<int> e;
	e = c;
	outf << "Object 'c' assigned to Object 'e':" << endl;
    	outf << "List c : " << c << endl;
    	outf << "List e : " << e << endl;
	
	b.first();
	endit = b.size();
	for ( int i = 1; i < endit; b.next(), i++)
	{
		b.insertBefore(b.getElement()*(-1));
		b.next(); b.next();
	}
	outf << "Results after some inserts on b " << endl;
    	outf << "List b : " << b << endl;

	a.first();
	endit = a.size();
	for ( int i = 1; i < endit; a.next(), i++)
	{
		a.replace(a.getPos()+a.getElement());
		a.next();
	}
	outf << "Results after some weird stuff on list a" << endl;
    	outf << "List a : " << a << endl;

    List<int> alist;
    alist.clear();
    for (int i=1;i<=10;i++)
	   alist.insertAfter(i);
	alist.first();
	outf << "New List alist with positions above: " << endl;
    for (int i=1;i<=10;i++) {
		outf << setw(5) << alist.getPos();
		alist.next();
	}
	outf << endl;
	alist.first();
	for (int i=1;i<=10;i++) {
		outf << setw(5) << alist.getElement();
		alist.next();
	}
	outf << endl;
	
	List<int> d(alist);
	d += alist;
	
	alist.first();
	endit = alist.size();
	outf << "show 'alist' object after 'd+= alist' " << alist << endl;
	for (int i=1;i<=endit;i++) {
		outf << setw(5) << alist.getElement();
		alist.next();
	}
	
	d.first();
	endit = d.size();
	outf << "show 'd' object after 'd+= alist' " << d << endl;
	for (int i=1;i<=endit;i++) {
		outf << setw(5) << d.getElement();
		d.next();
	}
	
	outf << endl << "  check out boundary conditions" << endl;
	List<int> sq;
	outf << "number of elements in empty sq list = " << sq.size() << endl;
	sq.first();
	sq.prev();
	sq.erase();
	sq.last();
	sq.setPos(5);
	outf << "empty sq values " << sq << endl;
	sq.insertBefore(3333);
	outf << "sq values " << sq << endl;
	sq.next(); sq.next();
	outf << "sq.getElement() = " << sq.getElement() << endl;
	outf << "sq list = " << sq << endl;
  outf.close();
	return 0;
  }