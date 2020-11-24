#include "dumpCorrection.hpp"

char* ReadFile(const char* path, uint32_t& fileLength)
{
    std::fstream File;
    File.open(path);

    uint32_t byteCounter = 0;
    
    char* Buffer = new  char [MAX_BUFFER_SIZE] {0};
    char* BuffPtr = Buffer;

    while (File.getline(BuffPtr, STRING_LENGTH, '\n'))
    {  
        BuffPtr += STRING_LENGTH;
        byteCounter++;
    }

    fileLength = byteCounter;
    return Buffer;
}

void FilterTextFile(const char* pathBin, const char* pathTxt)
{
     uint32_t byteCounter = 0;
    uint8_t reverseCounter = 15;

    uint8_t Data = 0;

    FILE* out;
    out = fopen(pathBin, "wb+"); 

    char* Buffer = ReadFile(pathTxt, byteCounter);
    char* BuffPtr = Buffer;

    std::cout << std::dec << byteCounter << std::endl;

    for (uint32_t i = 0; i < byteCounter; i++)
    {
        Data = std::stoi(BuffPtr, 0, 16);
        if (Data == 0x0F && reverseCounter > 15)
        {
            reverseCounter = 0;
        }
        else
        {
            fwrite(&Data, 1, 1, out); 
            reverseCounter++;
        }
        BuffPtr += STRING_LENGTH;
    }

    fclose(out);
}

void TxtIntoBin(const char* pathBin ,const char* pathTxt)
{
    uint32_t BufferLength = 0;
    char* Buffer = ReadFile(pathTxt, BufferLength);
    char* BuffPtr = Buffer;

    FILE* out;
    out = fopen(pathBin, "wb+"); 

    for (uint32_t i = 0; i < BufferLength; i++)
    {
        uint8_t temp = std::stoi(BuffPtr, 0, 16);
        fwrite(&temp, 1, 1, out); 

        BuffPtr += STRING_LENGTH;
    }

    fclose(out);
}