#include "Folder.h"
#include "Message.h"

Folder::Folder(const Folder &f) : messages(f.messages)
{
	addToAllMessages();
}

Folder::~Folder()
{
	std::cout << "message.size(): " << messages.size() << std::endl;
	removeFormMessages();
	std::cout << "message.size(): " << messages.size() << std::endl;
}

Folder& Folder::operator=(const Folder &fold)
{
	removeFormMessages();
	messages = fold.messages;
	addToAllMessages();
}

std::ostream& Folder::readMessage(std::ostream &out)
{
	std::size_t lineNo = 0;
	for(auto mes : messages)
		std::cout << ++lineNo << ' ' << mes->contents << '\n';
}

void Folder::save(Message &mes)
{
	mes.folders.insert(this);
	messages.insert(&mes);
}

void Folder::remove(Message &mes)
{
	mes.folders.erase(this);
	messages.erase(&mes);
	std::cout << "message.size(): " << messages.size() << std::endl;
}

void Folder::addToAllMessages()
{
	for(auto mes : messages)
		mes->folders.insert(this);
}

void Folder::removeFormMessages()
{
	for(auto mes : messages)
		mes->folders.erase(this);
}

void Folder::onlySave(Message &mes)
{
	messages.insert(&mes);
}
