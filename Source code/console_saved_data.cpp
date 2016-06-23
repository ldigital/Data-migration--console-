#include <console_saved_data.h>
#include <vector>

console_saved_data::console_saved_data():_driveA(10), _driveB(10), _backupDrive(10){

    for(std::vector<std::string>::iterator it = _driveA.begin(); it != _driveA.end(); ++it){
        *it = "[Empty slot] ";
    }

    _driveA[0] = "[Slot 1]   Mass Effect 1              10.6Bb of saved game data";
    _driveA[1] = "[Slot 2]   Gears Of War 1             13.2Gb of saved game data";
    _driveA[2] = "[Slot 3]   Resident Evil 4            11.4Gb of saved game data";
    _driveA[3] = "[Slot 4]   Super Street Fighter 4     15.1Gb of saved game data";
    _driveA[4] = "[Slot 5]   Destiny                    20.8Gb of saved game data";
    _driveA[5] = "[Slot 6]   Forza 6                    17.5Gb of saved game data";
    _driveA[6] = "[Slot 7]   Mass Effect 2              25.9Gb of saved game data";
    _driveA[7] = "[Slot 8]   Super Street Fighter 5     13.7Gb of saved game data";
    _driveA[8] = "[Slot 9]   FIFA 15                     9.2Gb of saved game data";
    _driveA[9] = "[Slot 10]  Resident Evil 5            15.7Gb of saved game data";

    for(std::vector<std::string>::iterator it = _driveB.begin(); it != _driveB.end(); ++it){
        *it = "[Empty slot] ";
    }

    for(std::vector<std::string>::iterator it = _backupDrive.begin(); it != _backupDrive.end(); ++it){
        *it = "[Empty slot] ";
    }

}
console_saved_data::~console_saved_data(){}
console_saved_data::console_saved_data(const console_saved_data & source){

    _backupDrive = source._driveB;
}

console_saved_data & console_saved_data::operator=(const console_saved_data & source){

    if(this == & source){
        return * this;
    }

    _driveB = source._driveA;

    return * this;
}

std::vector<std::string> console_saved_data::get_driveA(){
    return _driveA;
}

std::vector<std::string> console_saved_data::get_driveB(){
    return _driveB;
}

std::vector<std::string> console_saved_data::get_backupDrive(){
    return _backupDrive;
}



