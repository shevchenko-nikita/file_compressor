#include <iostream>

#include "bit_stream.h"

int main()
{

    BitStream str("C:\\Users\\Shevchenko\\Desktop\\test.bin", "test.bin");

    auto bits = str.Read();

    int bitCount = 8;
    for(int i = 0; i < bits.size(); ++i)
    {
        std::cout << bits[i];

        bitCount -= 1;
        if(bitCount == 0)
        {
            std::cout << ' ';
            bitCount = 8;
        }
    }
}
