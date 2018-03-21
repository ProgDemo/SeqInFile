#include "Student.h"

std::string Student::toString() const {
    std::stringstream tmp;
    tmp << name << ", " << "(" << neptun << "), " << results;
    return tmp.str();
}

std::ostream& operator <<(std::ostream& out, const Student& student) {
    out << student.toString();
    return out;
}
