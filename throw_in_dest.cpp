#include <iostream>

struct A{
	A(){
		std::cout << "call A constructor" << std::endl;
	}
	~A(){
		std::cout << "call A destructor" << std::endl;
		throw "Object is deleted";
	}
};

int main()
{
	A* ptr = new A;
	try
	{
		delete ptr;
		std::cout << "Succesfully deleted ptr!" << std::endl;
	}
	catch(const char* c)
	{
		std::cerr << "Error: " << c << std::endl;
	}
	

	return 0;
}