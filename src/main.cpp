#include <iostream>

#include "encoder.h"
#include "bitstream_reader.h"

int main()
{
    std::string file = "C:\\Users\\Shevchenko\\Desktop\\test.bin";

    Encoder::EncodeFile(file);

    BitStreamReader in("output.huff");
    auto bits = in.Read();

    uint16_t x = 10;
    std::cout << sizeof(x) << std::endl;

    std::cout << "Bits count - " << bits.size() << std::endl;
    int cnt = 0;
    int buffer = 0;
    for(auto bit : bits)
    {
//        std::cout << bit;

        buffer |= (bit << (7 - cnt));

        cnt += 1;
        if(cnt == 8)
        {
            cnt = 0;
            std::cout << buffer << ' ';
            buffer = 0;
        }
    }
}
