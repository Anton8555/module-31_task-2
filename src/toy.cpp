#include "toy.h"

/*!
* @brief A constructor for creating a toy with a given name.
* @param inName the name of the toy.
*/
Toy::Toy(const std::string& inName): name(inName) { }

/*!
* @brief The destructor of the toy with the output of its name for control.
*/
Toy::~Toy()
{
    std::cout << "Toy " << name << " was dropped " << std::endl;
}

/*!
* @brief The method of getting the name of the toy.
*/
std::string Toy::getName() const
{
    return name;
}