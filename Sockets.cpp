#include "Sockets.h"
#include <string>
namespace Sockets
{
    bool Start()
    {
#ifdef _WIN32
        WSAData wsaData;
		return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
#else
        return true;
#endif
    }
    void Release()
    {
#ifdef _WIN32
        WSACleanup();
#endif
    }
    int GetError()
    {
#ifdef _WIN32
        return WSAGetLastError();
#else
        return errno;
#endif
    }
    void CloseSocket(SOCKET s)
    {
#ifdef _WIN32
        closesocket(s);
#else
        close(s);
#endif
    }
    std::string GetAddress(const sockaddr_in& addr)
    {
        char buff[INET6_ADDRSTRLEN] = { 0 };
        return "127.0.0.1";//inet_ntop(addr.sin_family, (void*)&(addr.sin_addr),
        // buff, INET6_ADDRSTRLEN);
    }

    unsigned short GetPort(const sockaddr_in &socket) {
        return ntohs(socket.sin_port);
    }
}