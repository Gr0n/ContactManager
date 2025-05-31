#ifndef CONTACTCLASS_H
#define CONTACTCLASS_H

#include <string>
#include "DatabaseSolution_global.h"

using namespace std;

/// @brief Class representing a contact in the contact manager.
/// This class contains attributes for first name, last name, phone number, and email.
<<<<<<< Updated upstream
class Contact {
=======
class DATABASESOLUTION_EXPORT Contact {
>>>>>>> Stashed changes

private:
    /// @brief Private member variables to store contact information.
    string first_name;
    string last_name;
    string phone_number;
    string email;
public:
    int type; ///< Type of contact (0 for personal, 1 for private)
    Contact();
    virtual ~Contact();
    /// @brief Default constructor initializes contact with empty strings.
    /// @brief Parameterized constructor initializes contact with provided values.
    /// @param first_name The first name of the contact.
    /// @param last_name The last name of the contact.
    /// @param phone_number The phone number of the contact.
    /// @param email The email address of the contact.
    Contact(string first_name, string last_name, string phone_number, string email, int type);


    /// @brief Sets the first name of the contact.
    /// @param first_name The first name to set for the contact. <String>
    virtual void setFirstName(string first_name);

    /// @brief Sets the last name of the contact.
    /// @param last_name The last name to set for the contact. <String>
    virtual void setLastName(string last_name);

    /// @brief Sets the phone number of the contact.
    /// @param phone_number The phone number to set for the contact. <String>
    virtual void setPhoneNumber(string phone_number);

    /// @brief Sets the email of the contact.
    /// @param email The email name to set for the contact. <String>
    virtual void setEmail(string email);


    /// @brief Gets the first name of the contact.
    /// @return The first name of the contact as a string.
    virtual string getFirstName() const;

    /// @brief Gets the last name of the contact.
    /// @return The last name of the contact as a string.
    virtual string getLastName() const;

    /// @brief Gets the phone number of the contact.
    /// @return The phone number of the contact as a string.
    virtual string getPhoneNumber() const;

    /// @brief Gets the email of the contact.
    /// @return The email of the contact as a string.
    virtual string getEmail() const;

    /// @brief returns the type of contact.
    /// @return The type of contact as an integer (0 for personal, 1 for private(business)).
    virtual int getType() const;
};

<<<<<<< Updated upstream
#endif // CONTACTCLASS_H
=======
#endif // CONTACTCLASS_H
>>>>>>> Stashed changes
