# Huffman File Compressor

A file compression tool based on **Huffman Coding Algorithm**. It efficiently reduces file size while ensuring lossless decompression.
This tool is very effective for text-based files, but has minimal impact on already compressed files.

## Features
- **Lossless compression** using Huffman coding.
- **Support for popular file types** (text, binary, etc.).
- **Fast encoding & decoding** optimized with a bit-stream writer and reader.

## How It Works
1. Reads the file and calculates the frequency of each byte.
2. Builds a Huffman Tree based on byte frequencies.
3. Encodes the file by replacing bytes with their Huffman codes.
4. Stores the Huffman tree and encoded data in a compressed file.
5. For decompression, reconstructs the tree and decodes the original file.

| File Type  | Original Size | Compressed Size | Compression Ratio |
|------------|--------------|----------------|------------------|
| **Text File** | 112 KB  | 61.8 KB  | **45% reduction** |
| **CSV Data File**   | 7.07 MB  |3.31 MB  | **54% reduction** |
