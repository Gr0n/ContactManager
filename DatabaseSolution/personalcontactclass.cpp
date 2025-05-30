#include "personalcontactclass.h"

PersonalContact::PersonalContact() {}

PersonalContact::PersonalContact(string first_name, string last_name, string phone_number, string email, string birthday, string nickname)
{
	Contact(first_name, last_name, phone_number, email);
	this->birthday = birthday;
	nickname = nickname;
}
/// @brief sets the nickname of the personal contact.
/// @param nickname The nickname to set for the personal contact. <String>
void PersonalContact::setNickname(string nickname)
{
	this->nickname = nickname;
}
/// @brief sets the birthday of the personal contact.
/// @param birthday The birthday to set for the personal contact. <String>
void PersonalContact::setBirthday(string birthday)
{
	this->birthday = birthday;
}

/// @brief Gets the nickname of the personal contact.
string PersonalContact::getNickname() const
{
	return nickname;
}
/// @brief Gets the birthday of the personal contact.
string PersonalContact::getBirthday() const
{
	return birthday;
}
