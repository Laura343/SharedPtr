#include <iostream>
#include "sharedptr.h"
int main()
{
    SharedPtr<int> ptr1(new int(42));
    SharedPtr<int> ptr2 = ptr1;

    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;

    *ptr1 = 10;

    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;

    return 0;
}