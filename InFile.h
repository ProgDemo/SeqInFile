#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include "Student.h"
#include <string>

class InFile {

    private:
        enum Status {NORM, ABNORM};
        std::string fileName;
        std::ifstream file;
        char delimiter = ' ';
        Status status;
        Student current;

        void checkLine(const std::stringstream& line, const std::string& str, bool (*check)(const std::string&)) const;
        static bool defaultCheck(const std::string& line);
        void read();
        void setCurrent(const std::string& name, const std::string& neptun, const std::string& results);

    public:
        enum InFileExceptions {FileNotFoundException, FileFormatException, SemanticException};

        InFile(const std::string& fileName): fileName(fileName) {}
        void setDelimiter(char delimiter) { this->delimiter = delimiter; }
        void init();
        void first() {read(); }
        void next() {read(); }
        bool end() const { return status == ABNORM; }
        Student getCurrent() { return current; }
        ~InFile() { file.close(); }

};


#endif // INFILE_H_INCLUDED
