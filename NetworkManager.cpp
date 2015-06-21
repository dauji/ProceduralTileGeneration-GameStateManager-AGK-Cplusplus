#include<iostream>
#include "NetworkManager.h"
#include "template.h"

NetworkManager * NetworkManager::netManager = NULL;

NetworkManager * NetworkManager::Instance()
{
	if (!netManager)
		netManager = new NetworkManager;

	return netManager;
}

int NetworkManager::HostNetwork(std::string netName, std::string hostName, int port)
{
	int networdID__;
	const char * netName__ = netName.c_str();
	const char * hostName__ = hostName.c_str();
	networdID__ = agk::HostNetwork(netName__, hostName__, port);
	return networdID__;
}

int NetworkManager::JoinNetwork(std::string netName, std::string clientName)
{
	int networdID__;
	const char * netName__ = netName.c_str();
	const char * clientName__ = clientName.c_str();
	networdID__ = agk::JoinNetwork(netName__, clientName__);
	return networdID__;
}

bool NetworkManager::IsNetworkActive(int netID)
{
	switch (agk::IsNetworkActive(netID))
	{
	case 0: return false; break;
	case 1: return true;  break;
	}
}

void NetworkManager::CreateSendNetworkMessageINT(int num, int message, int netID, int num_clients)
{
	message = agk::CreateNetworkMessage();
	agk::AddNetworkMessageInteger(message, num);
	agk::SendNetworkMessage(netID, num_clients, message);
	
}

NetworkManager::NetworkManager()
{

}