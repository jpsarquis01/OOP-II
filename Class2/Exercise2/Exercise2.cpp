#include <iostream>
#include <list>
#include <time.h>

int main()
{
	std::list<int> myList = { 1, 2, 3, 4, 5 , 6, 7, 8, 9, 10};
	std::cout << "OG list: \n";
	for (int& val : myList)
	{
		std::cout << val << "\n";
	}

	std::cout << "\n";
	myList.remove(myList.back());
	std::cout << "Removed last element\n";
	myList.remove(myList.front());
	std::cout << "Removed first element\n";
	myList.push_back(rand() % 100);
	std::cout << "Added random num to the back\n";
	myList.push_front(rand() % 100);
	std::cout << "Added random num to the front\n";
	myList.push_back(rand() % 100);
	std::cout << "Added random num to the back\n";
	myList.push_front(rand() % 100);
	std::cout << "Added random num to the front\n";
	myList.push_back(rand() % 100);
	std::cout << "Added random num to the back\n\n";

	std::cout << "New list: \n";
	for (int& val : myList)
	{
		std::cout << val << "\n";
	}
	
	std::cout << "\n";

	std::cout << "The first element is: " << myList.front() << "\n";
	std::cout << "The last element is: " << myList.back() << "\n";
}


