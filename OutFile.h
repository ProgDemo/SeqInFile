#ifndef OUTFILE_H_INCLUDED
#define OUTFILE_H_INCLUDED

#include <fstream>
#include <sstream>
#include "Student.h"

class OutFile {

    private:
        std::string fileName;
        std::ofstream file;

    public:
        enum OutFileExceptions {PermissionException};
        OutFile(const std::string& fileName): fileName(fileName) {}
        void init();
        void printLine(const Student& student);
        ~OutFile() { file.close(); }

};

#endif // OUTFILE_H_INCLUDED
