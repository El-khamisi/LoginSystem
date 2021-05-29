#include <iostream>
#include <vector>
#include <filesystem>

#include "src/User.h"
#include "src/Dataset.h"

using namespace std;
using namespace __input;


int main() {

    int selection = -1;
    int tempID = -1;
    string tempPass = "";
    char tryAgain = 'Y';

    string dataSet = "dataset-1234demo", userAdmin = "userAdmin-1234demo";
    cout << "<<------ Glad To See Again, How's Your Day ^o^ ------>>\n"
         << "For first time You'll be admin So...\n"
         << "Enter existence DataBase Name OR create new one: ";
    inputString(dataSet);
    cout << "And Admin's User Name: ";
    inputString(userAdmin);

    Dataset demoset(dataSet, userAdmin);


    /**
     * Start Program
     */
    while (1) {
        selection = -1;
        tempID = -1;
        tempPass = "";
        tryAgain = 'Y';
        cout << "Choose Mood...1:Admin  2:Student  9:Exit $ ";
        inputNumber(selection);


        if (selection == 1) {   //Admin Mode
            selection = -1;

            do {
                cout << "ReEnter Admin Password(or n|N)to Exit: ";
                inputString(tempPass);
            } while (tempPass != demoset.password &&
                     (tempPass != "N" && tempPass != "n"));
            if (tempPass != demoset.password) {
                continue;
            }
            cout << "Enter A Number to Choose An Operation:\n"
                 << '\t' << "1 $Create A New Record.\n"
                 << '\t' << "2 $Update An Existence Record\n"
                 << '\t' << "3 $Delete An Existence Record.\n "
                 << '\t' << "4 $Show An Existence Record.\n"
                 << '\t' << "0 $$ShutDown The System.$$" << endl;

            cout << "Selection:    $ ";
            inputNumber(selection);

            switch (selection) {

                case 1:
                    demoset.creatRecord();
                    break;

                case 2:
                    cout << "Student's ID will be Updated: ";
                    inputNumber(tempID);
                    demoset.updateRecord(tempID);
                    break;

                case 3:
                    cout << "Student's ID will be Deleted: ";
                    inputNumber(tempID);
                    demoset.deleteRecord(tempID);
                    break;

                case 4:
                    cout << "Student's ID will be Showed OR -1 to ShowAll: ";
                    inputNumber(tempID);
                    demoset.showRecord(0, tempID);
                    break;
                case 0:
                    exit(0);
                default:
                    cout << "INCORRECT CHOSE...TRY AGAIN.." << endl;

                    break;
            }

        } else if (selection == 2) {    //Student Mode
            selection = -1;
            cout << "Enter A Number to Choose An Operation:\n"
                 << '\t' << "1 $Show your Record.\n"
                 << '\t' << "2 $Update your  Record\n"
                 << '\t' << "0 $$ShutDown The System.$$" << endl;

            cout << "Selection:    $";
            inputNumber(selection);

            switch (selection) {
                case 1:
                    cout << "Student's ID will be Showed: ";
                    inputNumber(tempID);
                    demoset.showRecord(1, tempID);
                    break;
                case 2:
                    cout << "Student's ID will be Updated: ";
                    inputNumber(tempID);
                    demoset.updateRecord(tempID);
                    break;
                case 0:
                    exit(0);
                default:
                    cout << "INCORRECT CHOSE...TRY AGAIN.." << endl;
            }

        } else if (selection == 9) {    //Exit Selection
            exit(0);
        } else {    //Default Selection
            cout << "INCORRECT CHOSE...TRY AGAIN.." << endl;
        }

    }


    return 0;
}


