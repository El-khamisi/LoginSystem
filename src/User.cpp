#include "User.h"
#include "Dataset.h"

using namespace __input;

/*USER CLASS IMPLEMENTATION */

User::User() {
    this->username = "userName";
    this->password = "Rand-pass1234";
}


User::User(std::string username, std::string password) {
    this->username = username;
    this->password = password;
}


int User::setPassword(std::string newPassword) {

    if (newPassword.length() < 8) {
        std::cout << "The password you have entered is incorrect." << std::endl;
        return 1;
    }

    this->password = newPassword;
    //Success
    return 0;
}


std::string User::getPassword() const {
    return this->password;
}


Student::Student(int ID)
        : User(std::to_string(ID)) {
    this->ID = ID;
    std::cout << "Enter the Name of student: ";
    inputString(this->name);
    std::cout << "Enter the Age of student: ";
    inputNumber(this->age);
    std::cout << "Enter the Department  of student: ";
    inputString(this->dep);
    std::cout << "Enter the GPA of student: ";
    inputNumber(this->GPA);
    std::cout << "Do you want set a password (default): " << this->password<<' ';
    inputString(this->password);
}


Student::Student(std::string name, int age, std::string dep, float gpa)
        : User() {
    this->name = name;
    this->age = age;
    this->dep = dep;
    this->GPA = gpa;
}


void Student::csvToStudent(std::string line) {

    try {
        std::stringstream str(line);
        std::string field;

        getline(str, field, ',');
        this->ID = std::stoi(field);
        getline(str, field, ',');
        this->name = field.substr(1);
        getline(str, field, ',');
        this->age = std::stoi(field);
        getline(str, field, ',');
        this->dep = field.substr(1);
        getline(str, field, ',');
        this->GPA = std::stof(field);
    } catch (...) {
        std::cout << "CAN'T Read data from record" << std::endl;
    }
}


void Student::displayRecord() {

    std::cout << "ID: " << ID
              << " |Name: " << std::left << std::setw(15) << name.substr(0, std::min(15, (int) name.length()))
              << " |Age: " << std::setw(2) << age
              << " |Department: " << std::left << std::setw(8) << dep.substr(0, std::min(8, (int) dep.length()))
              << " |GPA: " << std::setw(3) << GPA << std::endl;

}


/*ADMIN CLASS IMPLEMENTATION */


Admin::Admin(std::string username) {
    this->username = username;
    std::string password;

    do {
        std::cout << "Enter Admin password: ";
        inputString(password);
    } while (this->setPassword(password));

    this->password = password;
}


int Admin::setPassword(std::string newPassword) {

    bool up = 0, low = 0, dig = 0;
    for (char c:newPassword) {
        if (isupper(c))up = 1;
        if (islower(c))low = 1;
        if (isdigit(c))dig = 1;
    }
    if (!up || !low || !dig) {
        std::cout << "The password must have at least: \n"
                  << "o ONE UPPER LETTER\n"
                  << "o ONE LOWER LETTER\n"
                  << "o ONE DIGIT" << std::endl;
        return 1;
    }

    //Success
    return 0;
}


void Admin::editStudent(Student &stu) {
    std::cout << "Enter the value you want to change, OR leave it to keep old value" << std::endl;

    std::cout << "Name (" << stu.name << "): ";
    inputString(stu.name);

    std::cout << "Age (" << stu.age << "): ";
    inputNumber(stu.age);

    std::cout << "Department (" << stu.dep << "): ";
    inputString(stu.dep);

    std::cout << "GPA (" << stu.GPA << "): ";
    inputNumber(stu.GPA);

}

