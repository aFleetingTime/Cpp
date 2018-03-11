#pragma once
#include <string>
#include <set>
#include <iostream>

class Message;

class Folder
{
public:
	Folder() = default;
	Folder(const Folder &);
	~Folder();
	Folder& operator=(const Folder &);

	void save(Message &);
	void remove(Message &);
	void onlySave(Message &);

	std::ostream& readMessage(std::ostream &);

private:
	std::set<Message*> messages;

	void addToAllMessages();
	void removeFormMessages();
};
