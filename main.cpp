#include <iostream>
#include "InFile.h"
#include "OutFile.h"

using namespace std;

void simplePrint(string fileName) {
    InFile inFile(fileName);
    try {
        inFile.init();
        inFile.setDelimiter(';');
        inFile.first();
        while(!inFile.end()) {
            cout << inFile.getCurrent() << endl;
            inFile.next();
        }
    } catch (InFile::InFileExceptions e) {
        if (e == InFile::FileNotFoundException) {
            cerr << "File not exists!\n";
        } else if (e == InFile::FileFormatException) {
            cerr << "Invalid file format!\n";
        } else if (e == InFile::SemanticException) {
            cerr << "Semantic error in file!\n";
        }
    }
}

bool completed(string result) {
    int sum = 0;
    for (int i = 0; i < result.size(); ++i) {
        if (result[i] == '+') {
            sum++;
        } else {
            sum--;
        }
    }

    return sum >= 0;
}

void printCompleted(string fileName) {
    InFile inFile(fileName);
    try {
        inFile.init();
        inFile.setDelimiter(';');
        inFile.first();
        while(!inFile.end()) {
            if (completed(inFile.getCurrent().getResults())) {
                cout << inFile.getCurrent() << endl;
            }
            inFile.next();
        }
    } catch (InFile::InFileExceptions e) {
        if (e == InFile::FileNotFoundException) {
            cerr << "File not exists!\n";
        } else if (e == InFile::FileFormatException) {
            cerr << "Invalid file format!\n";
        } else if (e == InFile::SemanticException) {
            cerr << "Semantic error in file!\n";
        }
    }
}

void saveCompleted(string fileName, string fileToSave) {
    OutFile outFile(fileToSave);
    try {
        outFile.init();
    } catch (OutFile::OutFileExceptions e) {
        if (e == OutFile::PermissionException) {
            cerr << "Error while saving file!\n";
        }
        return;
    }

    InFile inFile(fileName);
    try {
        inFile.init();
        inFile.setDelimiter(';');
        for (inFile.first(); !inFile.end(); inFile.next()) {
            if (completed(inFile.getCurrent().getResults())) {
                outFile.printLine(inFile.getCurrent());
            }
        }
    } catch (InFile::InFileExceptions e) {
        if (e == InFile::FileNotFoundException) {
            cerr << "File not exists!\n";
        } else if (e == InFile::FileFormatException) {
            cerr << "Invalid file format!\n";
        } else if (e == InFile::SemanticException) {
            cerr << "Semantic error in file!\n";
        }
    }
}

int main() {

    //simplePrint("test.txt");
    printCompleted("test.txt");
    saveCompleted("test.txt", "out.txt");
    return 0;
}
