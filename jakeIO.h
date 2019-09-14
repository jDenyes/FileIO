#include <fstream>
#define BUF_SIZE 50

void printChar(char);
void printString(const char*);
char inputChar();
char getUserAction();
const char* read(char*, int);
int str2int(const char*);
void writeData(const char*, const char*);
void writeData(const char*, const char*, const char*);
void writeString(std::ofstream*, const char*);
