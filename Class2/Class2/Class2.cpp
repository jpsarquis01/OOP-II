#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <stack>

struct node
{
	int value = 0;

	node* next = nullptr;
	node* prev = nullptr;
};

int main()
{
    //Simple arrays
	int numbers[20] = {1,2,3,4,5,6,7,8,9};
	int maxNUmbers = 21;


	//Initialize the array
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = i * 10;
	}
	//Print the array
	for (int i = 0; i < 10; i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}
	return 0;

	//Resize the array
	int* newNumbers = new int[maxNUmbers];
	delete[] newNumbers;
	newNumbers = new int[11];

	//Linked list
	node* startNode = new node();
	node* Node = startNode;
	Node->value = 0;
	for (int i = 1; i < maxNUmbers; i++)
	{
		Node->next = new node();
		Node = Node->next;
		Node->value = i + 1;
	}

	Node = startNode;
	for (int i = 0; i < 10; i++)
	{
		Node = Node->next;
	}
	node* nextNode = Node->next;
	Node->next = nextNode;

	//std::array
	std::array<int, 10> myArray = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < myArray.size(); i++)
	{
		myArray[i] = i;
		myArray.at(i) = i;
	}
	int front = myArray.front();
	int back = myArray.back();
	myArray.empty();

	//Lists
	std::list<int> myList = { 1,2,3,4,5,6,7,8,9 };
	myList.push_back(10); //Adds elements on the back
	myList.push_front(0); //Adds elements on the front
	myList.remove(5); //Removes elements
	myList.front(); //Accesses the first element
	myList.back(); //Accesses the last element
	myList.insert(myList.begin(), 3); //Inserts an element at the beginning
	myList.clear(); //Clears the list
	myList.emplace_back(); //Adds an element at the end (will call the constructor)

	for (int& val : myList)
	{
		std::cout << "Value: " << val << "\n";
	}


	//Vectors
	std::vector<int> myVector = { 1,2,3,4,5,6,7,8,9 };

	myVector.clear(); //Clears the vector
	myVector.empty(); //Checks if the vector is empty
	myVector.front(); //Accesses the first element
	myVector.back(); //Accesses the last element
	myVector[0] = 1; //Accesses element at index
	myVector.at(0) = 1; //Accesses element at index
	myVector.capacity(); //Returns the capacity of the vector
	myVector.size(); //Returns the size of the vector
	myVector.data(); //Returns a pointer to the data
	myVector.emplace_back(); //Adds an element at the end (will call the constructor)
	myVector.push_back(10); //Adds an element at the end
	myVector.pop_back(); //Removes the last element
	myVector.shrink_to_fit(); //Reduces the capacity to fit the size
	myVector.reserve(10); //Reserves space for 10 elements
	myVector.resize(10); //Resizes the vector to 10 elements

	//Stacks
	std::stack<int> myStack;




}

