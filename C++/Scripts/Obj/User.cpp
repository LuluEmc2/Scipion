#include <string>
#include <iostream>
using namespace std;

#include "User.hpp"

User::User(string _name, string _password)
{
    name = _name;
    password = _password;
}

string User::get_name() const
{
    return name;
}
string User::get_password() const
{
    return password;
}

void User::set_name(string _name)
{
    name = _name;
}
void User::set_password(string _password)
{
    password = _password;
}
void User::set_all(string _name, string _password)
{
    name = _name;
    password = _password;
}

ostream& operator<<(ostream& stream, User const& user)
{
    stream << user.get_name() << "\n   Password : " << user.get_password() << "\n";
    return(stream);
}