#define WINVER 0x0500

#include "main.h"

#include <windows.h>
#include "iostream"
__declspec(dllexport) void move_cursorTo(int x, int y)
{
    try{
        INPUT input={};
        input.type = INPUT_MOUSE;
        input.mi.mouseData=0;
        input.mi.dx =  x*(65536/GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
        input.mi.dy =  y*(65536/GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
        input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
        SendInput(1,&input,sizeof(input));
        throw true;
    }
    catch(bool res)
    {
    //return !res;
    }
}


__declspec(dllexport) void click_Left_up(int x,int y)
{
    INPUT input={};
    input.type = INPUT_MOUSE;
    input.mi.mouseData=0;
    input.mi.dx =  x*(65536/GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
    input.mi.dy =  y*(65536/GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
    input.mi.dwFlags =  MOUSEEVENTF_LEFTUP;
    SendInput(1,&input,sizeof(input));

}
__declspec(dllexport) void click_Left_down(int x, int y)
{
    INPUT input={};
    input.type = INPUT_MOUSE;
    input.mi.mouseData=0;
    input.mi.dx =  x*(65536/GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
    input.mi.dy =  y*(65536/GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN;
    SendInput(1,&input,sizeof(input));
    //click_Left_up(x,y);
}

__declspec(dllexport) void click_Right_up(int x, int y)
{
    INPUT input={};
    input.type = INPUT_MOUSE;
    input.mi.mouseData=0;
    input.mi.dx =  x*(65536/GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
    input.mi.dy =  y*(65536/GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP;
    SendInput(1,&input,sizeof(input));
    //click_Left_up(x,y);
}

__declspec(dllexport) void click_Right_down(int x, int y)
{
    INPUT input={};
    input.type = INPUT_MOUSE;
    input.mi.mouseData=0;
    input.mi.dx =  x*(65536/GetSystemMetrics(SM_CXSCREEN));//x being coord in pixels
    input.mi.dy =  y*(65536/GetSystemMetrics(SM_CYSCREEN));//y being coord in pixels
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN;
    SendInput(1,&input,sizeof(input));
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
