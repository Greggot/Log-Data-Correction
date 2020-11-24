#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>

#define MAX_BUFFER_SIZE 0xFFFF
#define STRING_LENGTH 3

char* ReadFile(const char* path, uint32_t& fileLength);
void FilterTextFile(const char* pathBin, const char* pathTxt);
void TxtIntoBin(const char* pathBin ,const char* pathTxt);