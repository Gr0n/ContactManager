#include "databaseclass.h"
#include "PersonalContactClass.h"

using namespace std;
Database::Database() {}

void Database::addContact(Contact contact)
{
	// Add the contact to the contacts vector
	contacts.push_back(contact);
}
void Database::addContact(PersonalContact contact)
{
	// Add the personal contact to the contacts vector
	contacts.push_back(contact);
}
void Database::addContact(PrivateContact contact)
{
	// Add the private contact to the contacts vector
	contacts.push_back(contact);
}

void Database::removeContact(int index)
{
	if (index >= 0 && index < contacts.size())
	{
		// Remove the contact at the specified index
		contacts.erase(contacts.begin() + index);
	}
	else
	{
		// Handle invalid index case (optional)
		throw out_of_range("Index out of range");
	}
}
