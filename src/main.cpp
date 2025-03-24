#include <iostream>

#include "bit_stream.h"

int main()
{

    BitStream str("C:\\Users\\Shevchenko\\Desktop\\test.bin", "test.bin");

    auto bits = str.Read();

    for(int i = 0; i < bits.size(); ++i)
    {
        std::cout << bits[i];
    }
}
