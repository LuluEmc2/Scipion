#include <string>
#include <iostream>
#include <vector>
#include "../Func/Style.hpp"
#include "User.hpp"
using namespace std;

#include "Device.hpp"

const char* os_string[] = {
    "Windows 98",
    "Windows XP",
    "Windows Vista",
    "Windows Server 2008",
    "Windows 7",
    "Windows 8",
    "Windows Server 2012",
    "Windows 10",
    "Windows Server 2016",
    "Windows Server 2019",
    "Windows Server 2022",
    "Windows 11",

    "Debian",
    "Knoppix",
    "Ubuntu",
    "Linux Mint",
    "Slackware",
    "openSUSE",
    "Red Hat",
    "Red Hat Enterprise",
    "Fedora",
    "Gentoo",
    "Chromium OS",
    "Arch Linux",
    "Manjaro",

    "Mac OS X Server 1",
    "Mac OS X 10",
    "OS X 10",
    "macOS 10",
    "macOS 11",
    "macOS 12",
    "macOS 13",
    "macOS 14",

    "Android 1",
    "Android 2",
    "Android 3",
    "Android 4",
    "Android 5",
    "Android 6",
    "Android 7",
    "Android 8",
    "Android 9",
    "Android 10",
    "Android 11",
    "Android 12",
    "Android 13",
    "Android 14"
};

const char* osToStr(OS os) {
    if (os >= 0 && os < sizeof(os_string) / sizeof(os_string[0])) {
        return os_string[os];
    }
    else 
    {
        return "OS error";
    }
}

Device::Device(string _ip, OS _os, vector<User> const& _users, vector<string> _apps)
{
    ip = _ip;
    os = _os;
    users = _users;
    current_user = -1;
    apps = _apps;
    current_state = On;
}
Device::Device()
{
    ip = "0.0.0.0";
    os = Windows_98;
    users = vector<User>();
    current_user = -1;
    apps = vector<string>();
    current_state = On;
}

vector<User> Device::get_users() const
{
    if(current_state == Destroyed)
    {
        cout << "Device destroyed";
        return vector<User>();
    }
    return users;
}
string Device::get_ip() const
{
    if(current_state == Destroyed)
    {
        cout << "Device destroyed";
        return string();
    }
    return ip;
}
OS Device::get_os() const
{
    if(current_state == Destroyed)
    {
        cout << "Device destroyed";
        return Windows_98;
    }
    return os;
}
State Device::get_state() const
{
    return current_state;
}
int Device::get_current_user() const
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return -1;
    }
    return current_user;
}
std::string Device::get_current_user_password() const
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return string();
    }
    if(current_user == - 1)
    {
        return "";
    }

    return users[current_user].get_password();
}
std::string Device::get_current_user_name() const
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return string();
    }
    if(current_user == - 1)
    {
        return "";
    }

    return users[current_user].get_name();
}
std::vector<std::string> Device::get_apps() const
{
    if(current_state == Destroyed)
    {
        cout << "Device destroyed";
        return vector<string>();
    }
    return apps;
}

void Device::add_user(User _user)
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return;
    }

    users.push_back(_user);
}
int Device::remove_user(int i)
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return -1;
    }

    if(i >= users.size())
    {
        return -1;
    }
    users.erase(users.begin()+i);
    return 0;
}
void Device::power_up()
{
    if(current_state == Destroyed)
    {
        cout << "Device destroyed";
        return;
    }

    cout << "Device powering up ";
    rotating_loading_bar(100, 5);
    cout << "Device on\n\n";

    current_state = On;
}
void Device::shut_down()
{
    if(current_state == Destroyed)
    {
        cout << "Device destroyed";
        return;
    }
    
    cout << "Device shutting down ";
    rotating_loading_bar(100, 5);
    cout << "Device off\n\n";

    current_state = Off;
}
void Device::destroy()
{
    if(current_state == Destroyed)
    {
        cout << "Device already destroyed";
        return;
    }

    cout << "Destroying device ";
    rotating_loading_bar(100, 10);
    cout << "Device destroyed or off\n\n";

    current_state = Destroyed;
}
void Device::set_current_user()
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return;
    }

    cout << "Choose user (0 - " << users.size() - 1 << ") : ";

    cin.clear();
    int user;
    if(!(cin >> user))
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Connection to user ";
    rotating_loading_bar(100, 3);

    if(user < 0 || user >= users.size())
    {
        cout << "Invalid user : " << user << endl;
        return;
    }
    else
    {
        current_user = user;
    }

    cout << "Successfully connected to " << users[current_user].get_name();
}
void Device::add_app()
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return;
    }
    cout << "Choose application : ";
    string app;
    cin >> app;
    cout << "\nSearching " << app;
    rotating_loading_bar(100, 3);
    cout << app << " found" << endl;

    cout << "Downloading " << app;
    progressing_loading_bar(500, 5);

    cout << "Installing " << app;
    rotating_loading_bar(100, 15);

    cout << app << " installed";

    apps.push_back(app);
}
void Device::delete_app()
{
    if(current_state == Destroyed || current_state == Off)
    {
        cout << "Device destroyed or off";
        return;
    }
    cout << "Choose application (0 - " << apps.size() - 1 << "): ";
    string app;
    cin >> app;
    cout << "\nSearching " << app;
    rotating_loading_bar(100, 3);
    cout << app << " found" << endl;

    cout << "Uninstalling " << app;
    rotating_loading_bar(100, 15);

    cout << app << " uninstalled";

    apps.erase(apps.begin()+atoi(app.c_str()));
}

ostream& operator<<(ostream& stream, Device const& device)
{
    stream << "Device : " << device.get_ip() << endl;

    stream << "OS : " << osToStr(device.get_os()) << endl << endl;

    stream << "Users : \n";

    vector<User> users = device.get_users();
    for(int i = 0; i < users.size(); i++)
    {
        stream << "\n" << i << ") " << users[i];
    }


    stream << "Apps : \n";
    for(int i = 0; i < device.get_apps().size(); i++)
    {
        stream << "\n" << i << ") " << device.get_apps()[i];
    }

    stream << endl;

    if(device.get_current_user() != -1)
    {
        stream << "Current user : " << device.get_users()[device.get_current_user()].get_name() << endl << endl;
    }

    return stream;
}