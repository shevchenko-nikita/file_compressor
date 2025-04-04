#include <iostream>

#include "encoder.h"
#include "decoder.h"

void HandleInput(int request, std::string file)
{
    if(request == 1)
    {
        Encoder::EncodeFile(file);
    }
    else if(request == 2)
    {
        Decoder::DecodeFile(file);
    }
    else
    {
        std::cout << "Wrong request" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cerr << "Not enough arguments" << std::endl;
        return 0;
    }

    std::string file = argv[1];

    std::cout << "Choose option:\n"
                 "1) Compress file\n"
                 "2) Decompress file\n";

    int request;
    std::cin >> request;

    try
    {
        HandleInput(request, file);
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }

}
