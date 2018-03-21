#include "InFile.h"

void InFile::init() {

    file.open(fileName.c_str());
    if (file.fail()) {
        status = ABNORM;
        throw FileNotFoundException;
    }
}

bool InFile::defaultCheck(const std::string& line) {
    return true;
}

void InFile::checkLine(const std::stringstream& line, const std::string& str, bool (*check)(const std::string&)) const {
    if (line.fail()) {
        throw FileFormatException;
    }

    if (!check(str)) {
        throw SemanticException;
    }
}

void InFile::setCurrent(const std::string& name, const std::string& neptun, const std::string& results) {
    current.setName(name);
    current.setNeptun(neptun);
    current.setResults(results);
}

void InFile::read() {
    std::string tmp;
    std::stringstream line;

    getline(file, tmp);
    if (!file.fail()) {
        status = NORM;
        line << tmp;

        std::string name;
        std::string neptun;
        std::string results;

        getline(line, name, delimiter);
        checkLine(line, name, defaultCheck);

        getline(line, neptun, delimiter);
        checkLine(line, neptun, defaultCheck);

        line >> results;
        checkLine(line, results, defaultCheck);

        setCurrent(name, neptun, results);

    } else {
        status = ABNORM;
    }
}
