#include <random>
#include <iostream>

int main()
{
    unsigned int semilla = 42;
    
    std::default_random_engine motor(semilla); 
    
    std::uniform_int_distribution<int> adaptador(0, 9);
    
    std::cout << "Numero aleatorio: " 
            << adaptador(motor) 
            << std::endl;
}
