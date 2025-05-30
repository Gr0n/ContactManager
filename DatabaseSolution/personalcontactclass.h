#ifndef PERSONALCONTACTCLASS_H
#define PERSONALCONTACTCLASS_H

#include "ContactClass.h"
#include <string>
using namespace std;

/// @brief Class representing a personal contact in the contact manager.
class PersonalContact : public Contact
{
private:
	/// @brief Private member variables to store additional personal contact information.
	string nickname; ///< The nickname of the personal contact.
	string birthday; ///< The birthday of the personal contact.
public:
	/// Default constructor initializes personal contact with empty strings.
    PersonalContact();
	/// @brief Parameterized constructor initializes personal contact with provided values.
	PersonalContact(string first_name, string last_name, string phone_number, string email, string birthday, string nickname);


	/// @brief sets the nickname of the personal contact.
	/// @param nickname The nickname to set for the personal contact. <String>
	void setNickname(string nickname);

	/// @brief sets the birthday of the personal contact.
	/// @param birthday The birthday to set for the personal contact. <String>
	void setBirthday(string birthday);


	/// @brief Gets the nickname of the personal contact.
	string getNickname() const;

	/// @brief Gets the birthday of the personal contact.
	string getBirthday() const;
};

#endif // PERSONALCONTACTCLASS_H
