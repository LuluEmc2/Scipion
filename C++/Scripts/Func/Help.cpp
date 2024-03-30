#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

#include "Help.hpp"

void general_help()
{
    cout << "- device : Device functions, modify the physical state of the device\n\n";
    this_thread::sleep_for(100ms);

    cout << "- target : Target functions, change current device\n\n";
    this_thread::sleep_for(100ms);
    
    cout << "- app : App functions, all functions about applications installed on the device\n\n";
    this_thread::sleep_for(100ms);
    
    cout << "Other functions :\n";
    cout << "exit : stop the hacking program\n";
    cout << "help : returnd all the functions of the program  (help.module gives informations about the module)\n\n";
    this_thread::sleep_for(100ms);
}

void device_help()
{
    cout << "device.get_current_user : returns the current user's (needs target)\n";
    cout << "device.get_apps : returns the current device apps list (needs target)\n";
    cout << "device.get : returns the current device (needs target)\n";
    cout << "device.destroy : destroys the device hacked (needs target)\n";
    cout << "device.power_up : turns the device on (needs target)\n";
    cout << "device.shut_down : turns the device off (needs target)\n";
    cout << "device.set_current_user : change the current user of the device (needs target)\n\n";
}

void target_help()
{
    cout << "target.set : change the target\n\n";
}

void app_help()
{
    cout << "app.install : installs the app choosen  (needs target)\n";
    cout << "app.uninstall : uninstalls the app choosen  (needs target)\n";
}