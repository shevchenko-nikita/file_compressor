cmake_minimum_required(VERSION 3.21)
project(file_compressor)

set(CMAKE_CXX_STANDARD 17)

add_executable(file_compressor
        src/main.cpp
        src/huffmanTree.cpp
        src/bitstream_reader.cpp
        src/bitstream_writer.cpp
        src/encoder.cpp
        src/decoder.cpp)
