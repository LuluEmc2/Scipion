#ifndef __FUNC_DEF__
#define __FUNC_DEF__

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Obj/User.hpp"
#include "Obj/Device.hpp"
#include "Func/Help.hpp"
#include "Func/Target.hpp"

Device func(Device device);

void device_get_current_user(Device device);
void device_get_apps(Device device);
void device_get(Device device);
Device device_destroy(Device device);
Device device_power_up(Device device);
Device device_shut_down(Device device);
Device device_set_current_user(Device device);

Device target_set();

Device app_install(Device device);
Device app_uninstall(Device device);

#endif