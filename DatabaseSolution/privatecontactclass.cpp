#include "privatecontactclass.h"
#include <string>

using namespace std;


PrivateContactClass::PrivateContactClass()
    : Contact(), company_name("") {}

PrivateContactClass::PrivateContactClass(string first_name, string last_name, string phone_number, string email, string company_name)
    : Contact(first_name, last_name, phone_number, email), company_name(company_name) {}

void PrivateContactClass::setCompanyName(string company_name)
{
    this->company_name = company_name;
}

string PrivateContactClass::getCompanyName() const 
{
    return company_name;
}
