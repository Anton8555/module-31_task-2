#include "shared_ptr_toy.h"

void Shared_ptr_toy::copy(const Shared_ptr_toy& inToy)
{
    // copying fields
    toy = inToy.toy;
    count = inToy.count;

    // increasing the counter of pointers to a toy
    (*count)++;
}

Shared_ptr_toy::Shared_ptr_toy()
{
    toy = nullptr;
    count = nullptr;
}

Shared_ptr_toy::Shared_ptr_toy(const std::string& inName)
{
    // creating objects
    toy = new Toy(inName);
    count = new int;

    // initial installation of the counter
    *count = 1;
}

Shared_ptr_toy::Shared_ptr_toy(const Shared_ptr_toy& inToy)
{
    copy(inToy);
}

Shared_ptr_toy::~Shared_ptr_toy()
{
    if(count != nullptr) {
        // delete the toy if no one else links to it.
        if(--(*count) == 0) {
            reset();
        }
    }
}

std::string Shared_ptr_toy::getToyName() const
{
    if(toy == nullptr) {
        return "Nothing";
    }
    else
    {
        return toy->getName();
    }
}

void Shared_ptr_toy::reset()
{
    if(count != nullptr) {
        delete toy;
        delete count;
    
        toy = nullptr;
        count = nullptr;
    }
}

Toy* Shared_ptr_toy::get() const
{
    return toy;
}

int Shared_ptr_toy::use_count() const
{
    if(count == nullptr)
        return 0;
    else
        return *count;
}

Shared_ptr_toy& Shared_ptr_toy::operator =(Shared_ptr_toy& inToyRight)
{
    // If the copied object contains a reference to the same Toy object as the current one,
    // then nothing needs to be done — the current object already contains a reference to the desired Toy.
    if(this->toy == inToyRight.toy) {
        return *this;
    }

    // otherwise, decrement the link counter and delete the toy if it is not referenced
    if(*count > 0) {
        (*count)--;
    }
    if(*count == 0) {
        delete toy;
        delete count;
    }

    // copying
    copy(inToyRight);

    return *this;
}

Shared_ptr_toy make_shared_toy(std::string inName)
{
    return Shared_ptr_toy(inName);
}
