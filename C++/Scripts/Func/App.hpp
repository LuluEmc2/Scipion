#ifndef __APP_DEF__
#define __APP_DEF__

#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include "Reading.hpp"

std::vector<std::string> set_adobe_suit(int min, int max);
std::vector<std::string> set_cao(int min, int max);
std::vector<std::string> set_office_suit(int min, int max);
std::vector<std::string> set_other(int min, int max);
std::vector<std::string> set_prog(int min, int max);
std::vector<std::string> set_streaming(int min, int max);
std::vector<std::string> set_video_games(int min, int max);
std::vector<std::string> set_web_browser(int min, int max);

#endif