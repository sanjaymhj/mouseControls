#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT move_cursorTo(int x,int y);
void DLL_EXPORT click_Left_down(int x, int y);
void DLL_EXPORT click_Left_up(int x, int y);
void DLL_EXPORT click_Right_down(int x, int y);
void DLL_EXPORT click_Right_up(int x, int y);


#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
