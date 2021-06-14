#include "Sockets.h"
#include "Errors.h"

#include <iostream>
#include <string>
#include <thread>

int main()
{
    if (!Sockets::Start())
    {
        std::cout << "Erreur initialisation WinSock : " << Sockets::GetError();
        return -1;
    }

    SOCKET myFirstUdpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (myFirstUdpSocket == SOCKET_ERROR)
    {
        std::cout << "Erreur création socket : " << Sockets::GetError();
        return -2;
    }

    unsigned short port;
    std::cout << "Port local ? ";
    std::cin >> port;

    sockaddr_in addr;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    if (bind(myFirstUdpSocket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)))
    {
        std::cout << "Erreur bind socket : " << Sockets::GetError();
        return -3;
    }

    unsigned short portDst;
    std::cout << "Port du destinataire ? ";
    std::cin >> portDst;
    sockaddr_in to = { 0 };
    inet_pton(AF_INET, "127.0.0.1", &to.sin_addr.s_addr); // permet de convertir l'adresse string en bit
    to.sin_family = AF_INET;
    to.sin_port = htons(portDst);

    std::cout << "Entrez le texte à envoyer (vide pour quitter)> ";
    while (true)
    {
        std::string data;
        std::getline(std::cin, data);
        //std::cin >> data;
        if (data.empty())
            break;
        int ret = sendto(myFirstUdpSocket, data.data(), static_cast<int>(data.length()), 0, reinterpret_cast<const sockaddr*>(&to), sizeof(to));
        if (ret <= 0)
        {
            std::cout << "Erreur envoi de données : " << Sockets::GetError() << ". Fermeture du programme.";
            break;
        }
        char buff[1500] = { 0 };
        sockaddr_in from;
        socklen_t fromlen = sizeof(from);
        ret = recvfrom(myFirstUdpSocket, buff, 1499, 0, reinterpret_cast<sockaddr*>(&from), &fromlen);
        if (ret <= 0)
        {
            std::cout << "Erreur réception de données : " << Sockets::GetError() << ". Fermeture du programme.";
            break;
        }
        std::cout << "Recu : " << buff << " de " << Sockets::GetAddress(from) << ":" << Sockets::GetPort(from) << std::endl;
    }

    Sockets::CloseSocket(myFirstUdpSocket);
    Sockets::Release();
    return 0;
}