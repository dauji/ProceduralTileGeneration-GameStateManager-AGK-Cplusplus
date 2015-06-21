#ifndef _H_NETWORKMANAGER_
#define _H_NETWORKMANAGER_

#include<iostream>
#include<vector>

class NetworkManager
{
private:
	int usersID;
	std::string username;
//	std::vector<int> message;
	NetworkManager();
	static NetworkManager * netManager;
public:
	int networkID;
	int userType;
	int message; // TEMPORARY (make vector for multiple messages)
	static NetworkManager * Instance();
	int HostNetwork(std::string netName, std::string hostName, int port);
	int JoinNetwork(std::string netName, std::string clientName);
	bool IsNetworkActive(int netID);
	void CreateSendNetworkMessageINT(int num, int message, int netID, int num_clients);
};

#endif