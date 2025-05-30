#include <string>

using namespace std;

class Contact {
    /// @brief Class representing a contact in the contact manager.
    /// This class contains attributes for first name, last name, phone number, and email.
private:
    /// @brief Private member variables to store contact information.
    string first_name;
    string last_name;
    string phone_number;
    string email;
public:

    Contact();

    /// @brief Default constructor initializes contact with empty strings.
    /// @brief Parameterized constructor initializes contact with provided values.
    /// @param first_name The first name of the contact.
    /// @param last_name The last name of the contact.
    /// @param phone_number The phone number of the contact.
    /// @param email The email address of the contact.
    Contact(string first_name, string last_name, string phone_number, string email);
    

    /// @brief Sets the first name of the contact.
    /// @param first_name The first name to set for the contact. <String>
    void setFirstName(string first_name);

    /// @brief Sets the last name of the contact.
    /// @param last_name The last name to set for the contact. <String>
    void setLastName(string last_name);

    /// @brief Sets the phone number of the contact.
    /// @param phone_number The phone number to set for the contact. <String>
    void setPhoneNumber(string phone_number);

    /// @brief Sets the email of the contact.
    /// @param email The email name to set for the contact. <String>
    void setEmail(string email);
    

    /// @brief Gets the first name of the contact.
    /// @return The first name of the contact as a string.
    string getFirstName() const;
    
    /// @brief Gets the last name of the contact.
    /// @return The last name of the contact as a string.
    string getLastName() const;

    /// @brief Gets the phone number of the contact.
    /// @return The phone number of the contact as a string.
    string getPhoneNumber() const;

    /// @brief Gets the email of the contact.
    /// @return The email of the contact as a string.
    string getEmail() const;
};
