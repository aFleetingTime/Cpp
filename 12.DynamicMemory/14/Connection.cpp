#include <iostream>
#include <memory>
#include <cstring>

struct Destination
{
	int linkType;
	int socketType;
};

struct Connection
{
	int linkType;
	int socketType;
	int *socketFd;
	char *IP;
	int *port;
};

Connection* connect(Destination *dest, const char *IP, int port)
{ 
	size_t ipLen = strlen(IP);
	char *temp = new char[ipLen + 1]{};
	memcpy(temp, IP, ipLen);
	return new Connection { dest->linkType, dest->socketType, 
							new int(3), temp, new int(port) };
}

Destination* createDestination(int linkType, int socketType) { return new Destination { linkType, socketType }; }

void disconnect(Connection *con) 
{
	delete[] con->IP;
	delete con->socketFd, delete con->port, delete con;
}

void socket(Destination *dest, const char *IP, int port)
{
	std::shared_ptr<Connection> con(connect(dest, IP, port), disconnect);
	std::cout << "Fd: " << *con->socketFd << std::endl;
	std::cout << "IP: " << con->IP << std::endl;
	std::cout << "Port: " << *con->port << std::endl;
	std::cout << "linked type: " << con->linkType << std::endl;
	std::cout << "socket type: " << con->socketType << std::endl;
}

int main()
{
	std::shared_ptr<Destination> dest(createDestination(0, 3));
	socket(dest.get(), "127.51.96.103", 6666);
}
