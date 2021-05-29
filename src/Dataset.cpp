#include "Dataset.h"

using namespace __input;

/**
 *  @brief receive input from std::cin
 *  @param s  std::string variable to receive input
 *  @return received input, OR leave default if no input
 */
void __input::inputString(std::string &s) {
    std::string line = "", temp;

    getline(std::cin, line);
    std::stringstream str(line);

    str >> line;
    while (str >> temp) {
        line += " " + temp;
    }
    if (!line.empty())
        s = line;
}

/**
 * @brief receive input form std::cin
 * @param n  int variable to receive input
 * @return received input, OR leave default if no input
 */
void __input::inputNumber(int &n) {
    int temp = -1;

    std::string s;
    getline(std::cin, s);
    std::stringstream str(s);
    str >> temp;
    if (temp > -1) n = temp;
}

/**
 * @brief receive input form std::cin
 * @param f  float variable to receive input
 * @return received input, OR leave default if no input
 */
void __input::inputNumber(float &f) {
    float temp = -1.0;

    std::string s;
    getline(std::cin, s);
    std::stringstream str(s);
    str >> temp;

    if (temp > -1.0) f = temp;
}


/*Dataset CLASS IMPLEMENTATION */

Dataset::Dataset(std::string fileName, std::string username)
        : Admin(username) {

    std::fstream fdata, fpass;
    try {

        this->filePathData = "libs" + slash + fileName + ".csv";
        this->filePathPass = "libs" + slash + fileName + "Pass.csv";

        if (std::filesystem::exists(this->filePathData)
            || std::filesystem::exists(this->filePathPass)) {
            fpass.open(this->filePathPass, std::ios::in);
            std::string preline, line;

            getline(fpass, line);
            auto comma = line.find(',');
            std::string preAdmin = line.substr(0, comma);
            std::string prePass = line.substr(2 + comma);

            if (preAdmin != this->username || prePass != this->password) {
                throw 0;
            }


            while (!fpass.eof()) {
                preline = line;
                getline(fpass, line);
            }
            this->lastID = std::stoi(preline.substr(0, preline.find(',')));
            fdata.close();


            fdata.open(this->filePathData, std::ios::out | std::ios::app);
            fpass.open(this->filePathPass, std::ios::out | std::ios::app);
        } else {
            fdata.open(this->filePathData, std::ios::out);
            fpass.open(this->filePathPass, std::ios::out);
            fpass << this->username << ", " << this->password << std::endl;
        }


        if (!fdata.is_open() || !fpass.is_open()) {
            throw "Error opening A file..!!!";
        }

    } catch (int x) {
        std::cout << "User Name OR Password doesn't match existence file" << std::endl;
        exit(0);
    } catch (char const *e) {
        std::cout << e << std::endl;
    } catch (...) {
        std::cout << "Error has been occurred" << std::endl;
    }
    fdata.close();
    fpass.close();

}


void Dataset::creatRecord() {
    auto *stu = new Student(++lastID);
    std::fstream file;

    try {
        file.open(this->filePathPass, std::ios::out | std::ios::app);
        if (!file.is_open()) throw "Error has been occurred when signup user & password";

        file << stu->username << ", " << stu->password << std::endl;
        file.close();

        file.open(this->filePathData, std::ios::out | std::ios::app);
        if (!file.is_open()) throw "Error has been occurred when creating a new Record";

        std::string line = creatRecord(stu->ID, stu->name, stu->age, stu->dep, stu->GPA);
        file << line << std::endl;

        file.close();
    } catch (char const *e) {
        std::cout << e << std::endl;
        return;
    } catch (...) {
        std::cout << "Error has been occurred" << std::endl;
    }
    std::cout << "The Record has been created successfully" << std::endl;
}


std::string Dataset::creatRecord(int id, std::string name, int age, std::string dep, float gpa) {
    std::stringstream str;
    str << id << ", " << name << ", " << age << ", " << dep << ", " << gpa;
    return str.str();
}


std::string Dataset::readRecord(int id) {

    std::string line = "NULL";
    std::fstream file;
    try {
        file.open(this->filePathData, std::ios::in);
        if (!file.is_open())
            throw "Error has been occurred when trying access to dataset";

        while (getline(file, line)) {

            auto it = line.find(',');
            if (it == std::string::npos)
                throw "Error has been occurred when try to read data";

            int lookingId = std::stoi(line.substr(0, it));
            if (lookingId == id) {
                file.close();
                return line;
            }
        }

        //Fail
        throw "Can't find A record match ID you have entered";
    } catch (char const *e) {
        std::cout << e << std::endl;
    } catch (...) {
        std::cout << "Error has been occurred" << std::endl;
    }

    file.close();

    //Fail
    line.clear();
    return line;
}


void Dataset::deleteRecord(int id) {


    std::string rec = readRecord(id);

    if (rec.empty()) {
        std::cout << "Record not found" << std::endl;
        return;
    }

    try {
        std::fstream file, temp;

        std::string tempfile = "libs" + slash + "temp.csv";
        temp.open(tempfile, std::ios::out);
        file.open(this->filePathData, std::ios::in);

        if (!temp.is_open() || !file.is_open())
            throw "Error has been occurred when access to dataset";

        std::string line;
        while (getline(file, line)) {

            auto it = line.find(',');
            if (it == std::string::npos)
                throw "Error has been occurred when try to read data";

            int lookingId = std::stoi(line.substr(0, it));
            if (lookingId == id)
                break;

            temp << line << std::endl;
        }

        //Speed UP, we don't need to check the remaining of file
        while (getline(file, line)) {
            temp << line << std::endl;
        }

        std::remove(&*(this->filePathData.begin()));
        std::rename(&*(tempfile.begin()), &*(this->filePathData.begin()));

    } catch (char const *e) {
        std::cout << e << std::endl;
    } catch (...) {
        std::cout << "Error has been occurred" << std::endl;
    }

    std::cout << "The Record has been deleted" << std::endl;

}


void Dataset::updateRecord(int id) {

    std::string rec = readRecord(id);

    if (rec.empty()) {
        std::cout << "Record not found" << std::endl;
        return;
    }

    try {
        std::fstream file, temp;
        std::string tempfile = "libs" + slash + "temp.csv";

        temp.open(tempfile, std::ios::out);
        file.open(this->filePathData, std::ios::in);

        if (!temp.is_open() || !file.is_open())
            throw "Error has been occurred when access to dataset";

        std::string line;
        while (getline(file, line)) {

            auto it = line.find(',');
            if (it == std::string::npos)
                throw "Error has been occurred when try to read data";

            int lookingId = std::stoi(line.substr(0, it));
            if (lookingId == id) {
                Student *stu = new Student();

                stu->csvToStudent(line);
                this->editStudent(*stu);

                line = creatRecord(stu->ID, stu->name, stu->age, stu->dep, stu->GPA);
            }

            temp << line << std::endl;
        }

        //Speed UP, we don't need to check the remaining of file
        while (getline(file, line)) {
            temp << line << std::endl;
        }

        std::remove(&*(this->filePathData.begin()));
        std::rename(&*(tempfile.begin()), &*(this->filePathData.begin()));
        if (!std::filesystem::exists(this->filePathData))throw "Error has been occurred";

    } catch (char const *e) {
        std::cout << e << std::endl;
    } catch (...) {
        std::cout << "Error has been occurred" << std::endl;
    }

    std::cout << "The Record has been updated" << std::endl;

}


void Dataset::showRecord(int user, int id) {//0 as Admin, 1 as Student

    std::fstream file;

    if (user == 0 && id == -1) {

        try {
            file.open(this->filePathData, std::ios::in);
            if (!file.is_open())
                throw "Error has been occurred when access to dataset";

            Student *stu = new Student();
            std::string line;
            while (getline(file, line)) {

                auto it = line.find(',');
                if (it == std::string::npos)
                    throw "Error has been occurred when try to read data";

                stu->csvToStudent(line);
                stu->displayRecord();

            }
            file.close();
        } catch (char const *e) {
            std::cout << e << std::endl;
        } catch (...) {
            std::cout << "Error has been occurred" << std::endl;
        }


        return;
    }

    std::string rec = readRecord(id);
    if (rec.empty()) return;
    Student *stu = new Student();
    stu->csvToStudent(rec);

    if (user == 0) {
        stu->displayRecord();
        return;
    }

    try {
        file.open(this->filePathPass, std::ios::in);

        if (!file.is_open())
            throw "Error has been occurred when access to dataset";

        std::string line;
        getline(file, line); //Exculed Admin's Password from searching
        while (getline(file, line)) {

            auto it = line.find(',');
            if (it == std::string::npos)
                throw "Error has been occurred when try to read data";

            int username = std::stoi(line.substr(0, it));
            if (username == stu->ID) {
                it += 2;
                stu->password = line.substr(it);
                std::cout << "Enter your Password to see your data:";
                std::cout.flush();
                std::string temp;
                __input::inputString(temp);

                if (temp == stu->password) {
                    stu->displayRecord();
                } else {
                    std::cout << "The password you have entered is incorrect..." << std::endl;
                }
                break;
            }
        }
    } catch (char const *e) {
        std::cout << e << std::endl;
    } catch (...) {
        std::cout << "Error has been occurred" << std::endl;
    }

    file.close();
}
