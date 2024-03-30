#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Obj/User.hpp"
#include "Obj/Device.hpp"
#include "Func/Help.hpp"
#include "Func/Target.hpp"
using namespace std;

#include "Funcs.hpp"

Device func(Device device)
{

    cout << device.get_ip() << ">";

    string cmd = "";
    cin >> cmd;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    stringstream cmd_stream(cmd);

    string lib, funct;

    getline(cmd_stream, lib, '.');
    getline(cmd_stream, funct, '.');

    cout << endl;

    if(lib == "device")
    {
        if(funct == "get_current_user")
        {
            device_get_current_user(device);
        }
        else if(funct == "get_apps")
        {
            device_get_apps(device);
        }
        else if(funct == "get")
        {
            device_get(device);
        }
        else if(funct == "destroy")
        {
            return device_destroy(device);
        }
        else if(funct == "shut_down")
        {
            return device_shut_down(device);
        }
        else if(funct == "power_up")
        {
            return device_power_up(device);
        }
        else if(funct == "set_current_user")
        {
            return device_set_current_user(device);
        }
        else
        {
            cout << "Unknown function\n\n";
            return device;
        }
    }
    else if(lib == "target")
    {
        if(funct == "set")
        {
            return target_set();
        }
    }
    else if(lib == "app")
    {
        if(funct == "install")
        {
            return app_install(device);
        }
        else if(funct == "uninstall")
        {
            return app_uninstall(device);
        }
        else
        {
            cout << "Unknown function\n\n";
            return device;
        }
    }
    else
    {
        if(lib == "exit" && funct == "")
        {
            return Device("0", Windows_98, vector<User>(), vector<string>());
        }
        else if(lib == "help")
        {
            if(funct == "")
            {
                general_help();
            }
            else if(funct == "device")
            {
                device_help();
            }
            else if(funct == "target")
            {
                target_help();
            }
            else if(funct == "app")
            {
                app_help();
            }
            else
            {
                cout << "Unknown function\n\n";
                return device;
            }
        }
        else
        {
            cout << "Unknown function\n\n";
            return device;
        }
    }

    return device;
}

void device_get_current_user(Device device)
{
    cout << "Current user : " << device.get_current_user() << endl << endl;
}
void device_get_apps(Device device)
{
    cout << "Apps : ";
    
    for(int i = 0; i < device.get_apps().size(); i++)
    {
        cout << "\n" << i << ") " << device.get_apps()[i];
    }

    cout << endl << endl;
}
void device_get(Device device)
{
    cout << device << endl;
}
Device device_destroy(Device device)
{
    device.destroy();
    cout << endl;
    return device;
}
Device device_power_up(Device device)
{
    device.power_up();
    cout << endl;
    return device;
}
Device device_shut_down(Device device)
{
    device.shut_down();
    cout << endl;
    return device;
}
Device device_set_current_user(Device device)
{
    device.set_current_user();
    cout << endl << endl;
    return device;
}

Device target_set()
{
    return set_target();
}

Device app_install(Device device)
{
    device.add_app();
    cout << endl;
    return device;
}
Device app_uninstall(Device device)
{
    device.delete_app();
    cout << endl;
    return device;
}