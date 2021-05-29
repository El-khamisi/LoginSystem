#ifndef LOGINSYSTEMOOP_DATASET_H
#define LOGINSYSTEMOOP_DATASET_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cctype>
#include <exception>
#include <vector>

#include "User.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const std::string slash="\\";
#else
static const std::string slash="/";
#endif

/**
 * @namespace __input
 * @brief Use to input strings and numbers
 * @fn inputString
 * @fn inputNumber(int)
 *
 * This namespace contains functions to receive input from user,
 * if the user doesn't enter any valid input
 * the default value of passed parameter will be the same
 */
namespace __input {

    /**
     *  @brief receive input from std::cin
     *  @param s  std::string variable to receive input
     *  @return received input, OR leave default if no input
     */
    void inputString(std::string &s);

    /**
     * @brief receive input form std::cin
     * @param n  int variable to receive input
     * @return received input, OR leave default if no input
     */
    void inputNumber(int &n);

    /**
     * @brief receive input form std::cin
     * @param f  float variable to receive input
     * @return received input, OR leave default if no input
     */
    void inputNumber(float &f);
}


/**
 * @class Dataset
 * @brief Class to manipulate dataset values. child of Admin class
 * @fn creatRecord
 * @fn ShowRecord
 * @fn deleteRecord
 * @fn updateRecord
 */
class Dataset : public Admin {
protected:
    std::string filePathData;
    std::string filePathPass;
    int lastID = 1000;
public:
    /**
     * @brief Default constructor to search about existence data file of create new one
     * @param fileName  dataset file name
     * @param username  username of admin of dataset
     */
    Dataset(std::string fileName, std::string username);

    /**
     * @brief This function creates new record and store it in csv file
     */
    void creatRecord();

    /**
     * @brief This function creates a line of record from parameters
     * @param id  ID of student
     * @param name  Name of student
     * @param age  Age of student
     * @param dep  Department of student
     * @param gpa  GPA of student
     * @return std::string line record of record was built
     */
    std::string creatRecord(int id, std::string name, int age, std::string dep, float gpa);

    /**
     * @brief trays to a read record form dataset
     * @param id  int of Student ID will be read from dataset
     * @return record in csv form, OR empty line if didn't find
     */
    std::string readRecord(int id);


    /**
     * @brief trays to a delete record from dataset
     * @param id   ID of student will be deleted
     */
    void deleteRecord(int id);

    /**
     * @brief trays to update a record from dataset
     * @param id  ID of student will be updated
     */
    void updateRecord(int id);

    /**
     * @brief display a record from csv
     * @param user  mode of calling
     *        0 as admin user
     *        otherwise as regular student
     * @param id  ID of Student will be showed
     */
    void showRecord(int user, int id);
};


#endif //LOGINSYSTEMOOP_DATASET_H
