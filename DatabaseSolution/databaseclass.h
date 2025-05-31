#ifndef DATABASECLASS_H
#define DATABASECLASS_H

#include "PrivateContactClass.h"
#include "personalcontactclass.h"
#include <string>
#include <vector>
#include "DatabaseSolution_global.h"

using namespace std;

class DATABASESOLUTION_EXPORT Database
{
public:
    Database();
    vector<PrivateContact> private_contacts; ///< Vector to store all contacts.
    vector<PersonalContact> personal_contacts; ///< Vector to store all contacts.
    /// @brief Adds a contact to the database.
    /// @param contact The contact to be added to the database.
    void addContact(PrivateContact contact);
    void addContact(PersonalContact contact);

    /// @brief Removes a contact from the database by index.
    void removeContact(int type, int index);

    /// @brief Saves the contacts to a file.
    void save_to_file();

    /// @brief Loads contacts from a file.
    void load_from_file(string filename);

    /// @brief Displays all contacts in the database.
    void displayContacts() const;
};

#endif // DATABASECLASS_H
