#include "jakeIO.h"

void OpeningStatement();

int main() {
    bool done(false);

    const char* openFileName;
    char fileNameBuffer[BUF_SIZE];
    bool loadedFile(false);

    while(!done){
        OpeningStatement();
        char c = getUserAction();



        switch(c) {
            case 'l' : {
                printString("Enter name of the file you are loading");
                openFileName = read(fileNameBuffer, BUF_SIZE);
                loadedFile = true;

                //do I need to do this?
                std::ofstream out("temp.txt", std::ofstream::out | std::ofstream::trunc);
                out.close();

                break;
            }
            case 's': {
                //overwrite file name
                printString("Enter name you wish to save the file as");
                break;
            }
            case 'a': {
                char nameBuffer[BUF_SIZE], valueBuffer[BUF_SIZE];
                const char* name, *value;

                printString("Enter a name");
                name = read(nameBuffer, BUF_SIZE);

                printString("Enter a value");
                value = read(valueBuffer, BUF_SIZE);


                //Not needed, 
                // if(loadedFile) {
                //     printString("File detected");
                //     writeData(name, value, openFileName);
                // } else {
                //     printString("No file detected");
                //    writeData(name, value);
                // }
                break;
            }
            case 'q': {
                std::ofstream out("temp.txt", std::ofstream::out | std::ofstream::trunc);
                out.close();
                done = true;
                break;
            }
        }
    }
    return 0;
}

void OpeningStatement() {
	printString("(l)oad (s)ave (a)dd (q)uit or (p)rint?");
}
