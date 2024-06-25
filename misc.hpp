#ifndef misc_hpp
#define misc_hpp
#include <string>
#include <iostream>
using namespace std;

class misc
{
    int count_down = 5;

public:

    void payment();
    void wrongInput();
    bool check_number(string&);


};

#endif // misc_hpp
