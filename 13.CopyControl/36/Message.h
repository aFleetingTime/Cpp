#pragma once
#include <iostream>
#include <string>
#include <set>
#include "Folder.h"

class Message
{
	friend class Folder;
	friend void swap(Message &, Message &);

public:
	explicit Message(const std::string &content = std::string());
	Message(const Message &);
	Message(Message &&);
	~Message();
	Message& operator=(const Message &);
	Message& operator=(Message &&);

	void save(Folder &);
	void remove(Folder &);

private:
	std::set<Folder*> folders;
	std::string contents;

	void moveFolders(Message *);
	void addToAllFolders();
	void removeFormFolders();
};
