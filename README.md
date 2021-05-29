# Student registration system



## Overview :blush:
This Project was created for building a Login System. The system is useful for storing students' information.
The system has privilege to create, delete, update and store students' information.
Also, that it keeps information as records in *.csv file.<br/>
There are separated files one to store data and another to store usernames and passwords.



## Getting Started

### Prerequisites
* CMake 3.16 or higher<br>
    * To Compiling and Build Executable Files. OR <a href="#manually">(Build manually)</a> <br>
    * *install [CMake](https://cmake.org/download/)*


### Compiling

1. Make Directory for cmake-build
    ```
   mkdir build
   ```
2. Use CMakeLists.txt at Source Directory
    ```
   cmake ..
   ```
3. Build Executable files
    ```
   make
   ```
4. In Source Directory you will find LoginSystem Project to RUN IT....!



<!-- USAGE EXAMPLES -->

## Usage

### You can create your own dataset OR use demo.csv in _libs_ directory to demonstration purposes 

> Note: You can find username and password of Admin in 
> the first record in ${dataset_name}Pass.csv file
* Example
```json
<<------ Glad To See Again, How`s Your Day ^o^ ------>>
For first time You`ll be admin So...
Enter existence DataBase Name OR create new one: demo
And Admin`s User Name: 5amisi
Enter Admin password: Jo1
        
Choose Mood...1:Admin  2:Student  9:Exit $ 1
ReEnter Admin Password(or n|N)to Exit: Jo1
        
Enter A Number to Choose An Operation:
	1 $Create A New Record.
	2 $Update An Existence Record
	3 $Delete An Existence Record.
 	4 $Show An Existence Record.
	0 $$ShutDown The System.$$
---------------------------------------------------

Selection:    $ 4
Student`s ID will be Showed OR -1 to ShowAll: -1
ID: 1001 |Name: Mohammed El-kha |Age: 25 |Department: Engineer |GPA: 4.5
ID: 1002 |Name: Ahmed Maged     |Age: 88 |Department: Art      |GPA: 2.3
ID: 1003 |Name: Osama Magdi     |Age: 12 |Department: Doctor   |GPA: 1.2
ID: 1004 |Name: Kaseem Waleed   |Age: 25 |Department: CS       |GPA: 2.5
ID: 1005 |Name: Ahmed Hossam    |Age: 30 |Department: Architec |GPA: 3.6
ID: 1006 |Name: Tara Emaad      |Age: 35 |Department: Radio    |GPA: 2.3
Choose Mood...1:Admin  2:Student  9:Exit $ 9

```

## Build Manually
* Generate object files
```shell
$ g++ -c main.cpp -Isrc -o main.o
$ g++ -c src/User.cpp -Isrc -o User.o
$ g++ -c src/Dataset.cpp -Isrc -o Dataset.o
```
* linke object files to build executable binary
```shell
$ g++ main.o User.o Dataset.o -o LoginSystem
```
* RUN Final Executable file
```shell
$ ./LoginSystem
```

## Contributing :heart:
Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any
contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b my_new_branch`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin my_new_branch`)
5. Open a Pull Request


## Acknowledgements

* [CMake Documentation](https://cmake.org/documentation/)
* [MakeFile Manual](https://www.gnu.org/software/make/manual/make.html)
