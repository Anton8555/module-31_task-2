#pragma once

#include <iostream>
#include <string>

// toy class
class Toy {
private:
   std::string name;  // the name of the toy

public:
    // constructor
   Toy(const std::string& inName);

   // destructor
   ~Toy();

   // getter
   std::string getName() const;
};
