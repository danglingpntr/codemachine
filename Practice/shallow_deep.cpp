#include <cassert>
#include <iostream>
using namespace std;
class Fraction
{
public:
	int *m_ptr;
	int m_denominator;	
    // Default constructor
    Fraction(int val=0, int denominator=1):  m_denominator(denominator)
    { 
        *m_ptr=val;
		assert(denominator != 0);
    }

	// Copy constructor
	Fraction(const Fraction& copy) :m_denominator(copy.m_denominator)
	{
		m_ptr = new int;
		*m_ptr=*copy.m_ptr; 
		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

};


int main()
{
    Fraction fiveThirds(2);
	Fraction Thirds=fiveThirds;
	*Thirds.m_ptr=10;
	cout << *fiveThirds.m_ptr<<endl;
	cout << *Thirds.m_ptr<<endl;

    return 0;
}