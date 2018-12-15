#include <iostream>

int main()
{
  return [](){std::cout << "Hi\n"; return 0;}();
}
