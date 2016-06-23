/*This small program was written by Leon Harvey to simulate a fictional data transfer between two game's console disk drives. A user simply wishes to
 transfer  data from his old drive A, and thus copy his valuable data to another drive B. He also wishes to backup his replacement drive B to a drive C -
 just for safekeeping.*/

#include <iostream>
#include <console_saved_data.h>
#include <vector>

void view_drive_A(console_saved_data & oldDrive);
void view_drive_B(console_saved_data & newDrive);
void copy_drive_A_to_drive_B(console_saved_data & oldDrive, console_saved_data & newDrive);
void create_backup(console_saved_data & newDrive);

int main()
{
    console_saved_data oldDrive;
    console_saved_data newDrive;
    int menu = 0;

    while(1){
        std::cout << "GAME CONSOLE UTILITY MENU\n\n"
                  << "View source drive A data press 1\n"
                  << "View target/replacement drive B data press 2\n"
                  << "Copy data from source drive A to target drive B press 3\n"
                  << "Create backup of data press 4\n";

        std::cin >> menu;

         switch (menu){
            case 1:{
                 //some imaginary data on the old disk drive...

                 std::cout << "[Drive A (source) data]\n\n";
                 view_drive_A(oldDrive);
                 break;
            }

            case 2:{
            //the new unused drive is initially empty. We dont want to overwrite any copied data whenever this function is called by
            //user so we use a boolean to alter the condition, if or when the option to copy has been activated.

                  std::cout << "[Drive B (target/replacement) data\n\n";
                  view_drive_B(newDrive);
                  break;
            }

            case 3:{
               std::cout << "[Copy drive A data to drive B]\n\n";
               copy_drive_A_to_drive_B(oldDrive, newDrive);
               break;
            }

            case 4:{
               std::cout << "[Create backup]\n\n";
               create_backup(newDrive);
               break;
            }
        }
    }
    return 0;
}

void view_drive_A(console_saved_data & oldDrive){
    //display the old drive data to prove the "drive" works
    for(int i = 0; i < oldDrive.get_driveA().size(); i++){
        std::cout << oldDrive.get_driveA()[i] << std::endl;
    }

    std::cout << "\n\n";
}

void view_drive_B(console_saved_data & newDrive){
    //display the current state of the new and unsused "drive" which should be initially empty
    for(int i = 0; i < newDrive.get_driveB().size(); i++){
        std::cout << newDrive.get_driveB()[i] << std::endl;
    }

    std::cout << "\n\n";

}

void copy_drive_A_to_drive_B(console_saved_data & oldDrive, console_saved_data & newDrive){
    //copy the contents of the old drive over to the new drive. This will invoke the assignment operator
    char option;

    std::cout << "WARNING you are about overwrite all data on drive B. Do you want "
                 "to continue?\n"
                 "Press Y to continue or N to abort\n\n";

    std::cin >> option;
    if(option == 'Y' || option == 'y'){
         std::cout << "Preparing to copy contents from source drive A to replacement drive B...\n"
                   << "Copying in progress..."
                   << "Done! \n\n"
                   << "Copy succesful! Updated contents of replacement drive B\n\n";

         newDrive = oldDrive;

    }

    else if(option == 'N' || option == 'n'){
        std::cout << "No changes has been made to drive B\n";
    }
}

void create_backup(console_saved_data & newDrive){
    //if the user really values his data, and wants to create a backup of his new drive with another...
    //This will invoke the copy constructor.
    std::cout  << "Creating copy to backup drive C..."
               << "Copying in progress..."
               << "Done! \n\n"
               << "Copy succesful! Updated contents of replacement backup drive C:\n\n";
    //all drives now contain the same information

    console_saved_data backupDrive = newDrive;

    std::cout << "[Backup drive C]\n\n";


    for(int i = 0; i < backupDrive.get_backupDrive().size(); i++){
        std::cout << backupDrive.get_backupDrive()[i] << std::endl;
    }
    std::cout << "\n\n";
}
