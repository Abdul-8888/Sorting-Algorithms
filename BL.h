#include <iostream>

using namespace std;

class Organization
{
public:
    int index;
    string organization;
    string name;
    string website;
    string country;
    string description;
    string founded;
    string industry;
    int employees;

    Organization()
    {
        index = employees = 0;
        organization = name = website = country = description = founded = industry = "";
    }

};