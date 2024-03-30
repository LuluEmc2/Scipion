#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include "Reading.hpp"
using namespace std;

#include "App.hpp"

vector<string> set_adobe_suit(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/adobe_suit.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}
vector<string> set_cao(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/cao.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}
vector<string> set_office_suit(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/office_suit.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}
vector<string> set_other(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/other.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}
vector<string> set_prog(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/prog.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}
vector<string> set_streaming(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/streaming.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}
vector<string> set_video_games(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/video_games.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}
vector<string> set_web_browser(int min, int max)
{
    default_random_engine rand_eng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distrib {min, max};
    int app_nb = distrib(rand_eng);

    string app = "./Files/Apps/web_browsers.txt";

    vector<string> apps;

    for(int i = 0; i < app_nb; i++)
    {
        string x = random_line(app);
        if(find(apps.begin(), apps.end(), x) == apps.end())
        {
            apps.push_back(x);
        }
    }

    return apps;
}