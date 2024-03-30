#include <iostream>
#include <string>
#include <random>
#include <regex>
#include <vector>
#include "../Obj/Device.hpp"
#include "Reading.hpp"
#include "Style.hpp"
#include "App.hpp"
using namespace std;

#include "Target.hpp"

string maj_init(string s)
{
    string new_s = s;
    new_s[0] = toupper(new_s[0]);
    for(int  i = 1; i < new_s.size(); i++)
    {
        new_s[i] = tolower(new_s[i]);
    }
    return new_s;
}

string set_password()
{ 
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {0, 6};
    int user_name_type = distrib(rand_eng);

    string passwords = "./Files/passwords.txt";

    return random_line(passwords);
}

string set_name()
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {0, 6};
    int user_name_type = distrib(rand_eng);

    string f_names_file = "./Files/f_names.txt";
    string names_file = "./Files/names.txt";
    string users_file = "./Files/users_names.txt";

    string new_user_name = "";

    string f_name = random_line(f_names_file);

    if(f_name == "")
    {
        return "";
    }

    string name = random_line(names_file);

    if(name == "")
    {
        return "";
    }

    string user = random_line(users_file);

    if(user == "")
    {
        return "";
    }

    switch(user_name_type)
    {
        case 0 :
            new_user_name = maj_init(user);
            break;
        case 1 :
            new_user_name = maj_init(f_name);
            break;
        case 2 :
            new_user_name = maj_init(name) + " " + f_name;
            break;
        case 3 :
            new_user_name = maj_init(name) + " " + maj_init(f_name);
            break;
        case 4 :
            new_user_name = name + " " + f_name;
            break;
        case 5 :
            new_user_name = f_name;
            break;
        case 6 :
            new_user_name = user;
            break;
        default :
            return "";
            break;
    }

    return new_user_name;
}

vector<string> set_apps(OS os)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {0, 3};
    int app_type = distrib(rand_eng);

    int adobe_suit_min = 0;
    int cao_min = 0;
    int office_min = 1;
    int other_min = 1;
    int prog_min = 0;
    int streaming_min = 0;
    int videos_games_min = 0;
    int web_browser_min = 1;

    int adobe_suit_max = 0;
    int cao_max = 0;
    int office_max = 1;
    int other_max = 2;
    int prog_max = 0;
    int streaming_max = 0;
    int videos_games_max = 0;
    int web_browser_max = 1;

    switch (app_type)
    {
    case 0:
        adobe_suit_max = 1;
        office_max = 3;
        other_max = 3;
        break;
    case 1:
        adobe_suit_min = 2;
        adobe_suit_max = 5;
        cao_max = 2;
        break;
    case 2:
        other_max = 3;
        videos_games_min = 5;
        videos_games_max = 10;
        streaming_min = 1;
        streaming_max = 3;
        break;
    case 3:
        cao_min = 1;
        cao_max = 5;
        adobe_suit_min = 1;
        adobe_suit_max = 3;
        prog_min = 1;
        prog_max = 3;
        break;
    }

    switch(os)
    {
    case Android_1 | Android_2 | Android_3 | Android_4 | Android_5 | Android_6 | Android_7 | Android_8 | Android_9 | Android_10 | Android_11 | Android_12 | Android_13 | Android_14:
        adobe_suit_min = 0;
        adobe_suit_max = 0;
        cao_min = 0;
        cao_max = 0;
        prog_min = 0;
        prog_max = 0;
        streaming_max = 2;
    case Windows_Srv_2008 | Windows_Srv_2012 | Windows_Srv_2016 | Windows_Srv_2019 | Windows_Srv_2022 | Red_Hat | Red_Hat_Enterprise:
        adobe_suit_min = 0;
        adobe_suit_max = 0;
        cao_min = 0;
        cao_max = 0;
        prog_min = 1;
        prog_max = 2;
        streaming_min = 0;
        streaming_max = 0;
        office_min = 0;
        office_max = 1;
        other_min = 0;
        other_max = 0;
        videos_games_min = 0;
        videos_games_max = 1;
        web_browser_min = 0;
        web_browser_max = 1;
    }

    vector<string> apps;

    vector<string> adobe_suit = set_adobe_suit(adobe_suit_min, adobe_suit_max);
    apps.insert(apps.end(), adobe_suit.begin(), adobe_suit.end());

    vector<string> cao = set_cao(cao_min, cao_max);
    apps.insert(apps.end(), cao.begin(), cao.end());

    vector<string> office_suit = set_office_suit(office_min, office_max);
    apps.insert(apps.end(), office_suit.begin(), office_suit.end());
    
    vector<string> other = set_other(other_min, other_max);
    apps.insert(apps.end(), other.begin(), other.end());

    vector<string> prog = set_prog(prog_min, prog_max);
    apps.insert(apps.end(), prog.begin(), prog.end());

    vector<string> streaming = set_streaming(streaming_min, streaming_max);
    apps.insert(apps.end(), streaming.begin(), streaming.end());

    vector<string> video_games = set_video_games(videos_games_min, videos_games_max);
    apps.insert(apps.end(), video_games.begin(), video_games.end());

    vector<string> web_browser = set_web_browser(web_browser_min, web_browser_max);
    apps.insert(apps.end(), web_browser.begin(), web_browser.end());

    return apps;
}

Device set_target()
{
    cout << "Choose target : ";

    cin.clear();
    string ip;
    if(!(cin >> ip))
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    regex ipv4("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    regex ipv6("^([0-9A-Fa-f]{1,4}:){7}[0-9A-Fa-f]{1,4}$");

    cout << "Searching Target ";
    rotating_loading_bar(100, 5);

    if(!(regex_match(ip, ipv4) || regex_match(ip, ipv6)))
    {
        cout << "Invalid IP : " << ip << endl << endl;
        return Device("000.000.000.000", OS(0), vector<User>(), vector<string>());
    }

    cout << "Target found\n\n";

    cout << "Connection ";
    progressing_loading_bar(250, 30);

    cout << ip << " successfully connected\n\n";

    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib_user {1, 10};
    int nb_users = distrib_user(rand_eng);

    vector<User> users;

    for(int i = 0; i < nb_users; i++)
    {
        users.push_back(User(set_name(), set_password()));
    }

    uniform_int_distribution<int> distrib_os {0, 46};
    OS os = OS(distrib_os(rand_eng));

    vector<string> apps = set_apps(os);
    return Device(ip, os, users, apps);
}