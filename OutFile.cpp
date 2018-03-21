#include "OutFile.h"

void OutFile::init() {
    file.open(fileName.c_str());
    if (file.fail()) {
        throw PermissionException;
    }
}

void OutFile::printLine(const Student& student) {
    file << student << std::endl;
}
