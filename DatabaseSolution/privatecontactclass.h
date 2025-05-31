#ifndef PRIVATECONTACTCLASS_H
#define PRIVATECONTACTCLASS_H

#include "ContactClass.h"
#include <string>
#include "DatabaseSolution_global.h"
/// @brief Class representing a private contact in the contact manager.
/// This class inherits from the Contact class and adds a company name attribute.
class DATABASESOLUTION_EXPORT PrivateContact : public Contact
{
private:
    /// @brief Private member variables to store additional contact information.
    string company_name;

public:
    /// @brief Default constructor initializes private contact with empty strings.
    PrivateContact();


    /// @brief Parameterized constructor initializes private contact with provided values.
    /// @param first_name The first name of the contact.
    /// @param last_name The last name of the contact.
    /// @param phone_number The phone number of the contact.
    /// @param email The email address of the contact.
    /// @param company_name The company name associated with the contact.
    PrivateContact(string first_name, string last_name, string phone_number, string email, string company_name);

    /// @brief Sets the company name of the private contact.
    /// @param company_name The company name to set for the private contact.
    void setCompanyName(string company_name);

    /// @brief Gets the company name of the private contact.
    /// @return The company name of the private contact as a string.
    string getCompanyName() const;


};

#endif // PRIVATECONTACTCLASS_H
