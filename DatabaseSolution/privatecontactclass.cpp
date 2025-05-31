#include "PrivateContactClass.h"
#include <string>

using namespace std;


PrivateContact::PrivateContact()
    : Contact("","","","",1), company_name("") {}

PrivateContact::PrivateContact(string first_name, string last_name, string phone_number, string email, string company_name)
    : Contact(first_name, last_name, phone_number, email, 1), company_name(company_name) {}

void PrivateContact::setCompanyName(string company_name)
{
    this->company_name = company_name;
}

string PrivateContact::getCompanyName() const
{
    return company_name;
}
