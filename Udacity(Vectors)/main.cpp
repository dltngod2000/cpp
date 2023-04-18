// Goal: pracitce constructing vectors
// and their iterators
// Call the vector vFloat
// Call the iterator it

// TODO: Add the necessary libraries
#include "main.hpp"

int main()
{
    // TODO: create a vector of floats
    std::vector<float> vFloat;
    std::cout << "vFloat has " << vFloat.size() << " elements\n";

    std::cout << "\n\nAdding 10 elements to the vector\n";

    // TODO: assign the value 8.8 to 10 elements of the vector
    vFloat.assign(10, 8.8);
    std::cout << "vFloat has " << vFloat.size() << " elements\n";

    // TODO: Complete the Print function in main.hpp
    //  Call the function here to print out each element of vFloat

    printVector(vFloat);

    /***************************************************/
    // creating a vector of integers
    std::vector<int> vectorInts;
    // creating an iterator for the vector
    std::vector<int>::iterator it;

    vectorInts.push_back(0);
    vectorInts.push_back(1);
    vectorInts.push_back(2);
    vectorInts.push_back(3);
    vectorInts.push_back(4);
    vectorInts.push_back(5);
    vectorInts.push_back(6);
    vectorInts.push_back(7);

    std::cout << "\nvectorInts has " << vectorInts.size() << " elements\n";

    // printing the contents of vectorInts
    std::cout << "VectorInts has these elements:\n";
    for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
        std::cout << *it << " ";

    // pop the last element off the vector
    vectorInts.pop_back();
    std::cout << "\n\nAfter pop_back(), the vector has these elements:\n";
    for (it = vectorInts.begin(); it != vectorInts.end(); ++it)
        std::cout << *it << " ";

    // pop_back does not return the element that was removed.
    // For example, the line of code below will return an error.
    int a;
    // a = vectorInts.pop_back(); //this line does not compile

    return 0;
}