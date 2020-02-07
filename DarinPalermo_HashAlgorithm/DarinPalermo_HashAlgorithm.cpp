// DarinPalermo_HashAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std;

class Contact
{
	// Variables
public:
	string contactName;		// The contact's name
	int number;				// The contact's number
};

class HashTable
{
	// Variables

	int BUCKET;				// Number of buckets
	list<Contact>* table;	// Pointer to an array contraining the buckets

public:
	HashTable(int bucket)
	{
		this->BUCKET = bucket;
		table = new list<Contact>[BUCKET];
	}

	// Maps values to key 
	int Hash(string value)
	{
		int total = 0;

		// Summing up all the ASCII values  
		// of each alphabet in the string 
		for (int i = 0; i <= value.length(); i++)
		{
			total += (int)value[i];
		}

		return (total % BUCKET);
	}

	// Inserts a contact and a number
	void Insert(string key, int value)
	{
		// Get the index from the key
		int index = Hash(key);

		// Create the new contact
		Contact contact;
		contact.contactName = key;
		contact.number = value;

		// Store it in the right table
		table[index].push_back(contact);
	}

	// Deletes a contact by name
	void DeleteItem(string key)
	{
		// Get the index of the key
		int index = Hash(key);

		// Find the key in the bucket that it was stored in
		list<Contact> ::iterator i;
		for (i = table[index].begin();
			i != table[index].end(); i++) {
			if (i->contactName == key)
				break;
		}

		// If key is found in the table, erase it
		if (i != table[index].end())
		{
			table[index].erase(i);
		}
	}

	// Returns a contact by name
	Contact Retrieve(string key)
	{
		// Get the index of the key
		int index = Hash(key);

		// Find the key in the bucket that it was stored in
		list<Contact> ::iterator i;
		for (i = table[index].begin();
			i != table[index].end(); i++) {
			if (i->contactName == key)
				break;
		}

		// If key is found in the table, erase it
		if (i != table[index].end())
		{
			return *i;
		}
		else
		{
			cout << key << " is not in the table\n";
		}
	}

	// Displays the values in the table
	void Display()
	{
		for (int i = 0; i < BUCKET; i++)
		{
			cout << i;
			for (auto x : table[i])
			{
				cout << " --> " << x.contactName << ": " << x.number;
			}
			cout << endl;
		}
	}
};

int main()
{
	HashTable hashTable(10);
	hashTable.Insert("John", 6311234567);
	hashTable.Insert("Smith", 190049037325);
	hashTable.Insert("Steve", 1987654321);
	hashTable.Insert("Jane", 5555555555);
	hashTable.Insert("Chris", 1112223333);
	hashTable.Insert("Sue", 4676941311);
	cout << "CONTACTS: \n-------------------------\n";
	hashTable.Display();
	cout << "-------------------------\n\n";

	cout << "\nSmith's number is " << hashTable.Retrieve("Smith").number << endl;

	cout << "\nRemoving John from contacts.\n\n";
	hashTable.DeleteItem("John");
	cout << "CONTACTS: \n-------------------------\n";
	hashTable.Display();
	cout << "-------------------------\n\n";
}