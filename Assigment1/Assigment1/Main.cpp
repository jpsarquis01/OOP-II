#include <iostream>
#include <time.h>
#include <list>
#include "Restaurant.h"
#include "Person.h"
#include "Group.h"

std::list<Person> CreateRandomGroup(int size)
{
    std::list<Person> clients;
    std::string names[] = { "Chanti", "Grevin", "Arthur", "Alfred", "Emir" };

    //Adds random number to the names
    for (int i = 0; i < size; i++)
    {
        std::string name = names[rand() % 5] + std::to_string(rand() % 100); 
        clients.push_back(Person(name));
    }
    return clients;
}

int main()
{
    srand(time(NULL));

    Restaurant restaurant(5); //() is for how many tables

    std::cout << "Welcome to the Yakitori, enjoy the service.\n";
    std::cout << "-------------------------------------\n\n";

    //test group
    for (int i = 0; i < 8; i++) // 8 groups more than available tables(5)
    {
        int groupSize = rand() % 4 + 1; // 1-4 people per group
        std::list<Person> clients = CreateRandomGroup(groupSize);
        restaurant.AddGroup(clients);
    }

    restaurant.Run(50); // () Frames runned

    return 0;
}
