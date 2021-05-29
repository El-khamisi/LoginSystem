#include <iostream>
#include <fstream>
#include <filesystem>
#include <cctype>
#include <exception>
#include <vector>


#ifndef USER_H
#define USER_H

/**
 * @class User
 * @brief Base Class for User
 * @fn setPassword
 * @fn getPassword
 */
class User {
public:
    std::string username;
    std::string password;

    /**
     * @brief Default constructor to set username, password
     */
    User();

    /**
     * @brief Set values to username, password
     * @param username  Username of user
     * @param password  Password of user
     */
    User(std::string username, std::string password = "Rand-pass1234");

    /**
     * @brief virtual fn to set User password
     * @param newPassword  New password to set
     * @return 0 if Success,  1 if failed
     */
    virtual int setPassword(std::string newPassword);

    /**
     * @return this->password of user
     */
    std::string getPassword() const;

};

/**
 * @class Student
 * @brief Class Student is child of  User class
 * @fn csvToStudent
 * @fn displayRecord
 */
class Student : public User {
public:
    int ID = 0;
    std::string name = "NULL";
    int age = 0;
    std::string dep = "NULL";
    float GPA = 0;

    /**
     * @brief Default constructor to read data
     */
    Student(int ID);

    /**
     * @brief Constructor to set values for Student
     * @param name  Student name
     * @param age  Student age
     * @param dep  Student Department
     * @param gpa  Student GPA
     */
    Student(std::string name = "", int age = 0, std::string dep = "", float gpa = 0.0);

    /**
     * @brief Function to Read Student data from CSV Record
     * @param line  CSV Record
     */
    void csvToStudent(std::string line);

    /**
     * @brief Function to Display Student data
     */
    void displayRecord();
};

/**
 * @class Admin
 * @brief Class Admin is child of  User class
 * @fn setPassword
 * @fn editStudent
 */
class Admin : public User {
public:
    /**
     * @brief Default constructor receive admin username  and set admin password
     */
    Admin(std::string username);

    /**
     * @brief Override setPassword fn for set Password to admin  with special requirement
     * @param newPassword   std::string new password to set
     * @return 0 if Success,  1 if Failed
     */
    int setPassword(std::string newPassword) override;

    /**
     * @brief This Function edit Student members' values
     * @param stu  Student instance will be edited
     */
    void editStudent(Student &stu);
};


#endif //USER_H