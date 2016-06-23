#ifndef CONSOLE_SAVED_DATA_H
#define CONSOLE_SAVED_DATA_H
#include <iostream>
#include <string>
#include <vector>

class console_saved_data{

public:
    console_saved_data();
    ~console_saved_data();
    console_saved_data(const console_saved_data & _source);
    console_saved_data & operator=(const console_saved_data & _source);

    std::vector<std::string> get_driveA();
    std::vector<std::string> get_driveB();
    std::vector<std::string> get_backupDrive();

private:

    std::vector<std::string> _driveA;
    std::vector<std::string> _driveB;
    std::vector<std::string> _backupDrive;

};
#endif
