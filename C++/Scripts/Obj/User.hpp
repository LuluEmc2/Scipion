#ifndef __USER_DEF__
#define __USER_DEF__

#include <string>
#include <iostream>

class User
{
    public:
        User(std::string _name, std::string _password);

        std::string get_name() const;
        std::string get_password() const;

        void set_name(std::string _name);
        void set_password(std::string _password);
        void set_all(std::string _name, std::string _password);
    private:
        std::string name;
        std::string password;
};

std::ostream& operator<<(std::ostream& stream, User const& user);

#endif