#include <iostream>
using namespace std;

class SmartPtr {
  public:
	int* ptr; // Actual pointer
	
	explicit SmartPtr(int* p = NULL) { ptr = p; }

	~SmartPtr() { delete (ptr); }

	int& operator*() { return *ptr; }
};

int main()
{
	SmartPtr ptr1(new int());
	*ptr1.ptr = 20;
	cout << *ptr1;

	return 0;
}
 