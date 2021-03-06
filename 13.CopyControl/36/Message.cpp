#include "Message.h"

Message::Message(const std::string &content) : contents(content)
{
	;
}

Message::Message(const Message &mes) : contents(mes.contents), folders(mes.folders)
{
	addToAllFolders();
}

Message::~Message()
{
	std::cout << "folders.size(): " << folders.size() << std::endl;
	removeFormFolders();
	std::cout << "folders.size(): " << folders.size() << std::endl;
}

Message::Message(Message &&mes) : contents(std::move(mes.contents)), folders(std::move(mes.folders))
{
	moveFolders(&mes);
}

Message& Message::operator=(const Message &mes)
{
	removeFormFolders();
	folders = mes.folders;
	contents = mes.contents;
	addToAllFolders();
	return *this;
}

Message& Message::operator=(Message &&mes)
{
	if(this != &mes)
	{
		removeFormFolders();
		contents = std::move(mes.contents);
		folders = std::move(mes.folders);
		moveFolders(&mes);
	}
	return *this;
}

void Message::moveFolders(Message *mes)
{
	for(auto folder : folders)
	{
		folder->remove(*mes);
		folder->onlySave(*this);
	}
	mes->folders.clear();
}

void swap(Message &mes1, Message &mes2)
{
	using std::swap;
	mes1.removeFormFolders();
	mes2.removeFormFolders();
	swap(mes1.folders, mes2.folders);
	swap(mes1.contents, mes2.contents);
	mes1.addToAllFolders();
	mes2.addToAllFolders();
}

void Message::save(Folder &folder)
{
	folder.save(*this);
}

void Message::remove(Folder &folder)
{
	folder.remove(*this);
}

void Message::addToAllFolders()
{
	for(auto &fold : folders)
		fold->onlySave(*this);
}

void Message::removeFormFolders()
{
	for(auto &fold : folders)
		fold->remove(*this);
}
