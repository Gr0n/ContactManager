#include "ContactClass.h"

using namespace std;

Contact::Contact()
    : first_name(""), last_name(""), phone_number(""), email(""), type(-1) {}

Contact::~Contact(){}

Contact::Contact(string first_name, string last_name, string phone_number, string email, int type)
/// @brief Default constructor initializes contact with empty strings.
/// @brief Parameterized constructor initializes contact with provided values.
/// @param first_name The first name of the contact.
/// @param last_name The last name of the contact.
/// @param phone_number The phone number of the contact.
/// @param email The email address of the contact.
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->phone_number = phone_number;
    this->email = email;
    this->type = type;
}

void Contact::setFirstName(string first_name)
/// @brief Sets the first name of the contact.
/// @param first_name The first name to set for the contact. <String>
{
    this->first_name = first_name;
}

void Contact::setLastName(string last_name)
/// @brief Sets the last name of the contact.
/// @param last_name The last name to set for the contact. <String>
{
    this->last_name = last_name;
}

void Contact::setPhoneNumber(string phone_number)
/// @brief Sets the phone number of the contact.
/// @param phone_number The phone number to set for the contact. <String>
{
    this->phone_number = phone_number;
}

void Contact::setEmail(string email)
/// @brief Sets the email of the contact.
/// @param email The email name to set for the contact. <String>
{
    this->email = email;
}

string Contact::getFirstName() const
/// @brief Gets the first name of the contact.
/// @return The first name of the contact as a string.
{
    return first_name;
}

string Contact::getLastName() const
/// @brief Gets the last name of the contact.
/// @return The last name of the contact as a string.
{
    return last_name;
}

string Contact::getPhoneNumber() const
/// @brief Gets the phone number of the contact.
/// @return The phone number of the contact as a string.
{
    return phone_number;
}

string Contact::getEmail() const
/// @brief Gets the email of the contact.
/// @return The email of the contact as a string.
{
    return email;
}

int Contact::getType() const
{
    return type;
}

