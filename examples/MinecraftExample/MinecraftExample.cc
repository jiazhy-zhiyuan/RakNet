#include <iostream>
#include <sstream>
#include "RakPeerInterface.h"
#include "RakSleep.h"

#define MAX_CONNECTIONS 1

int main() {
  RakNet::RakPeerInterface *server = RakNet::RakPeerInterface::GetInstance();
  server->SetTimeoutTime(30000, RakNet::UNASSIGNED_SYSTEM_ADDRESS);

  RakNet::SocketDescriptor socketDescriptor;
  socketDescriptor.port = 19132;
  socketDescriptor.socketFamily = AF_INET;

  bool b = server->Startup(MAX_CONNECTIONS, &socketDescriptor, 1) == RakNet::RAKNET_STARTED;
  if(b) std::cout << "Server has started\n";

  server->SetMaximumIncomingConnections(MAX_CONNECTIONS);
  server->SetOccasionalPing(true);
  server->SetUnreliableTimeout(1000);

  std::stringstream ss;
  ss << "MCPE;A Minecraft: PE Server;201 201;1.2.10;0;";
  ss << MAX_CONNECTIONS;

  server->SetOfflinePingResponse(ss.str().c_str(), ss.str().size());

  while(true) RakSleep(30);
}
