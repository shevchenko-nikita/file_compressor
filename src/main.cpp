#include <iostream>

#include "bitstream_reader.h"
#include "bitstream_writer.h"

int main()
{

//    BitStreamReader str("C:\\Users\\Shevchenko\\Desktop\\out.bin");
//
//    auto bits = str.Read();
//    int cnt = 8;
//
//    for(int i = 0; i < bits.size(); ++i)
//    {
//        std::cout << bits[i];
//
//        --cnt;
//        if(cnt == 0)
//        {
//            std::cout << ' ';
//            cnt = 8;
//        }
//    }

    BitStreamWriter writer("C:\\Users\\Shevchenko\\Desktop\\out.bin");

    std::vector<bool> bits1 = {0, 1, 0, 0, 1, 1, 1, 0};

    writer.Write(bits1);

    BitStreamReader str("C:\\Users\\Shevchenko\\Desktop\\out.bin");

    auto bits = str.Read();
    int cnt = 8;

    for(int i = 0; i < bits.size(); ++i)
    {
        std::cout << bits[i];

        --cnt;
        if(cnt == 0)
        {
            std::cout << ' ';
            cnt = 8;
        }
    }

//    BitStream
}
