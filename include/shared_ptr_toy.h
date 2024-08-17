#pragma once

#include <iostream>
#include <string>
#include <toy.h>

// The class is a smart pointer to a toy
class Shared_ptr_toy {
private:
   Toy *toy;
   int *count;

   /*!
   * @brief The method of copying the toy.
   * @param inToy a copyable toy.
   */
   void copy(const Shared_ptr_toy& inToy);
public:
    // constructor
   
   /*!
   * @brief The default toy constructor.
   */
   Shared_ptr_toy();
   /*!
   * @brief A toy constructor with a given name.
   * @param inName the name of the toy.
   */
   Shared_ptr_toy(const std::string& inName);
   /*!
   * @brief A constructor with object copying.
   * @param inToy the object of the toy.
   */
   Shared_ptr_toy(const Shared_ptr_toy& inToy);

   // destructor
   
   /*!
   * @brief The destructor of the toy with the correction of the reference counter.
   */
   ~Shared_ptr_toy();

   // getter
   
   /*!
   * @brief The method of getting the name of the toy.
   * @return Returns the name of the toy.
   */
   std::string getToyName() const;

   // methods
   
   /*!
   * @brief Reset the link counter.
   */
   void reset();
   /*!
   * @brief Getting a toy.
   * @return Returns a pointer to Toy.
   */
   Toy* get() const;
   /*!
   * @brief Getting the number of links to the toy.
   * @return Returns the number of references to the Toy object.
   */
   int use_count() const;

   // overloading operations

   /*!
   * @brief Overloading of the "equals" operator.
   * @param inToyRight the right operand of the "equals" operator.
   * @return Returns a pointer to a smart pointer.
   */
   Shared_ptr_toy& operator =(Shared_ptr_toy& toyRight);
};

// service function

/*!
* @brief The smart pointer assembly service function.
* @param inName the name of the toy.
* @return Returns the smart pointer object.
*/
Shared_ptr_toy make_shared_toy(std::string inName);
