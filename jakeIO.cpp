#include "jakeIO.h"
#include <conio.h>

char getUserAction() {
	char c;
	do {
		c = _getch();
	} while (c != 'l' && c != 'p' && c != 'a' && c != 's' && c != 'q');
	return c;
}

void printChar(char c) {
    _putch(c);
}

void printString(const char* c) {
    for (const char* s = c; *s != 0; s++) {
		printChar(*s);
	}
	printChar('\n');
}

char inputChar() {
    char c = _getch();
    printChar(c);
    return c;
}

const char* read(char* buf, int maxSize) {
	const char* s = buf;
	char* end = buf + maxSize;
	for (char c = inputChar(); c != 13 && (buf + 1 < end); c = inputChar(), buf++) {
		*buf = c;
	}
	*buf = 0;
	printChar('\n');
	return s;
}

int str2int(const char* s) {
	const char* p = s;
	for (; *p >= '0' && *p <= '9'; p++);
	p--;

	int sum(0);
	int place(1);

	for (; p >= s; p--) {
		if (*p >= '0' && *p <= '9')	{
			sum += (*p - '0') * place;
			place *= 10;
		} else {
			return -1;
		}
	}
	return sum;
}

void writeData(const char* name, const char* value) {
    std::ofstream out("temp.txt", std::ofstream::out | std::ofstream::app);

    writeString(&out, name);
    writeString(&out, ": ");
    writeString(&out, value);
    out.put('\n');

    out.close();
}

void writeData(const char* name, const char* value, const char* fileName) {
    std::ofstream out(fileName, std::ofstream::out | std::ofstream::app);

    if(out.is_open()){
        printString("file is good");
    } else {
        printString("not good");
    }

    writeString(&out, name);
    writeString(&out, ": ");
    writeString(&out, value);
    out.put('\n');

    out.close();
}

void writeString(std::ofstream* out, const char* name) {
    for(const char *c = name; *c != 0; c++ ) {
        out->put(*c);
    }
}