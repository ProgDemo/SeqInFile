#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <sstream>

class Student {

    private:
        std::string name;
        std::string neptun;
        std::string results;
    public:
        Student(std::string name = "", std::string neptun = "", std::string results = ""):
            name(name), neptun(neptun), results(results) {}

        std::string getName() const { return name; }
        std::string getNeptun() const { return neptun; }
        std::string getResults() const { return results; }

        void setName(const std::string& name) { this->name = name; }
        void setNeptun(const std::string& neptun) { this->neptun = neptun; }
        void setResults(const std::string& results) { this->results = results; }

        std::string toString() const;
        friend std::ostream& operator <<(std::ostream& out, const Student& student);
};

#endif // STUDENT_H_INCLUDED
