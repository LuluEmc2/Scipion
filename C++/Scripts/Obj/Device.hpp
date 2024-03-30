#ifndef __DEVICE_DEF__
#define __DEVICE_DEF__

#include <string>
#include <iostream>
#include <vector>
#include "../Func/Style.hpp"
#include "User.hpp"

enum State
{
    Destroyed = -1,
    Off = 0,
    On = 1
};

enum OS
{
    Windows_98,
    Windows_XP,
    Windows_Vista,
    Windows_Srv_2008,
    Windows_7,
    Windows_8,
    Windows_Srv_2012,
    Windows_10,
    Windows_Srv_2016,
    Windows_Srv_2019,
    Windows_Srv_2022,
    Windows_11,

    Debian,
    Knoppix,
    Ubuntu,
    Linux_Mint,
    Slackware,
    openSUSE,
    Red_Hat,
    Red_Hat_Enterprise,
    Fedora,
    Gentoo,
    Chromium_OS,
    Arch_Linux,
    Manjaro,

    Mac_OS_X_Srv_1,
    Mac_OS_X_10,
    OS_X_10,
    macOS_10,
    macOS_11,
    macOS_12,
    macOS_13,
    macOS_14,

    Android_1,
    Android_2,
    Android_3,
    Android_4,
    Android_5,
    Android_6,
    Android_7,
    Android_8,
    Android_9,
    Android_10,
    Android_11,
    Android_12,
    Android_13,
    Android_14
};

class Device
{
    public:
        Device(std::string _ip, OS _os, std::vector<User> const& _users, std::vector<std::string> _apps);
        Device();

        std::vector<User> get_users() const;
        std::string get_ip() const;
        OS get_os() const;
        State get_state() const;
        int get_current_user() const;
        std::string get_current_user_password() const;
        std::string get_current_user_name() const;
        std::vector<std::string> get_apps() const;

        void add_user(User _user);
        int remove_user(int i);
        void power_up();
        void shut_down();
        void destroy();
        void set_current_user();
        void add_app();
        void delete_app();

    private:
        std::string ip;
        std::vector<User> users;
        OS os;
        State current_state;
        int current_user;
        std::vector<std::string> apps;
};

std::ostream& operator<<(std::ostream& stream, Device const& device);

#endif