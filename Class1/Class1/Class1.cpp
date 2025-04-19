#include <iostream>

class Car
{
public:
    virtual void move()
    {
        position++;
    }

    void ToString()
    {
        std::cout << "BMW moved position" << position << "\n";
    }

private:
    int position = 0;
    int fuel = 0;
};

class Sedan
{
    void move()                           
    {                                     
        if (turbo)                        
        {                                 
            position + 10;                
        }                                 
        else                              
        {                                 
            std::cout << "No turbo";      
        }                                 
    }                                     
                                          
private:                                  
    int position = 0;
    bool turbo = true;
};

int main()
{
    Car bmw;

    bmw.ToString();
    bmw.move();
    bmw.ToString();

    Sedan myCar;


}

