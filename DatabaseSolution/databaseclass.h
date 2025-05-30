#ifndef DATABASECLASS_H
#define DATABASECLASS_H

#include "ContactClass.h"
#include "PrivateContactClass.h"
#include "PersonalContactClass.h"
#include <string>
#include <vector>


using namespace std;

class Database
{
private:
	// Private member variables can be added here to store contacts, etc.
	vector<Contact> contacts; ///< Vector to store all contacts.
public:
    Database();

	/// @brief Adds a contact to the database.
	/// @param contact The contact to be added to the database.
	void addContact(Contact contact);
	void addContact(PrivateContact contact);
	void addContact(PersonalContact contact);

	/// @brief Removes a contact from the database by index.
	void removeContact(int index);
};

#endif // DATABASECLASS_H
