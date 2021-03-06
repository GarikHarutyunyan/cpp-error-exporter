#include <stdio.h>
#include <tchar.h>
#include <windows.h>

using namespace std;

void error_text_output() {

    LPVOID lpMsgBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0,
        NULL
    );
    _tprintf(_T("Error is:%d-%s\n"), dw, (LPTSTR)lpMsgBuf);

    LocalFree(lpMsgBuf);
}

int _tmain(int argc, TCHAR* argv[] )
{
    for (int i = 0; i < 10;i++) {
        SetLastError(i);
        error_text_output();
    }

    return 0;
}