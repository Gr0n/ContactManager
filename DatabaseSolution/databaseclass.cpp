#include "DatabaseClass.h"
#include "PersonalContactClass.h"
#include "PrivateContactClass.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <QDebug>

using namespace std;

Database::Database(){}

void Database::addContact(PrivateContact contact)
{
    // Add a private contact to the database
    private_contacts.push_back(contact);

}
void Database::addContact(PersonalContact contact)
{
    // Add a personal contact to the database
    personal_contacts.push_back(contact);
}



void Database::removeContact(int type, int index)
{
    if (type == 0) // Personal contact
    {
        if (index >= 0 && index < personal_contacts.size())
        {
            personal_contacts.erase(personal_contacts.begin() + index);
        }
        else
        {
            cerr << "Invalid index for personal contact." << endl;
        }
    }
    else if (type == 1) // Private contact
    {
        if (index >= 0 && index < private_contacts.size())
        {
            private_contacts.erase(private_contacts.begin() + index);
        }
        else
        {
            cerr << "Invalid index for private contact." << endl;
        }
    }
    else
    {
        cerr << "Invalid contact type." << endl;
    }
}


void Database::save_to_file()
{
    ofstream file("contacts.txt");
    if (!file)
    {
        cerr << "Error opening file for writing." << endl;
    }
    for (const auto& contact : private_contacts)
    {
        file << "PrivateContact," << contact.getFirstName() << "," << contact.getLastName() << ","
             << contact.getPhoneNumber() << "," << contact.getEmail() << ","
             << contact.getCompanyName() << endl;
    }
    for (const auto& contact : personal_contacts)
    {
        file << "PersonalContact," << contact.getFirstName() << "," << contact.getLastName() << ","
             << contact.getPhoneNumber() << "," << contact.getEmail() << ","
             << contact.getBirthday() << "," << contact.getNickname() << endl;
    }
    file.close();
}

void Database::load_from_file(string filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        size_t pos = 0;
        string token;
        vector<string> tokens;

        while ((pos = line.find(',')) != string::npos) {
            token = line.substr(0, pos);
            tokens.push_back(token);
            line.erase(0, pos + 1);
        }
        tokens.push_back(line); // Last token

        if (tokens.size() < 5) {
            cerr << "Invalid contact format in file." << endl;
            continue;
        }

        if (tokens[0] == "PrivateContact") {
            if (tokens.size() == 6) {
                PrivateContact contact(tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]);
                addContact(contact);
            }
            else {
                cerr << "Invalid PrivateContact format." << endl;
            }
        }
        else if (tokens[0] == "PersonalContact") {
            if (tokens.size() == 7) {
                PersonalContact contact(tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6]);
                addContact(contact);
            }
            else {
                cerr << "Invalid PersonalContact format." << endl;
            }
        }
        else {
            cerr << "Unknown contact type: " << tokens[0] << endl;
        }
    }
    file.close();

    return;
}

void Database::displayContacts() const
{
    cout << "Personal Contacts:" << endl;
    for (const auto& contact : personal_contacts)
    {
        qDebug() << "Name: " << contact.getFirstName() << " " << contact.getLastName()
        << ", Phone: " << contact.getPhoneNumber()
        << ", Email: " << contact.getEmail()
        << ", Birthday: " << contact.getBirthday()
        << ", Nickname: " << contact.getNickname();
    }

    cout << "\nPrivate Contacts:" << endl;
    for (const auto& contact : private_contacts)
    {
        qDebug() << "Name: " << contact.getFirstName() << " " << contact.getLastName()
        << ", Phone: " << contact.getPhoneNumber()
        << ", Email: " << contact.getEmail()
        << ", Company: " << contact.getCompanyName();
    }
}
