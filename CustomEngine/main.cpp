/*#include <D3D11.h>

#include <iostream>

int main(int argc, char **argv)
{
	std::cout<<"Testing this?"<<"\n";
	int x;
	std::cin>> x;
	return 0;
}
*/

//#define WIN32_LEAN_AND_MEAN				//Exclude rarely used stuff from Windows header
#include <Windows.h>

//C RunTime Header Files
//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
//#include <tchar.h>



//Temp Stub Not used, stored for later implementation
/*LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	return DefWindowProc(hwnd, message, wparam, lparam);
}*/


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	//Letting compiler know these parameters are unused
	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(cmdLine);

	//===== Window Initialization =====

	WNDCLASSEX wndClass = {0};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = DefWindowProc;
	wndClass.hInstance = hInstance;
	//wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ERROR));
	
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName="GameWindowClass";

	if(!RegisterClassEx(&wndClass))
		return -100;

	RECT rc = {0,0,640,480};
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	
	HWND hwnd = CreateWindowA("GameWindowClass","WIP Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance, NULL);

	
	if(!hwnd)
		return -200;

	ShowWindow(hwnd, cmdShow);

	//===== Game Initialize =====
	
	MSG msg = {0};

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//Update / Draw here
		}
	}
	
	//===== Game Shutdown =====

	

	//return static_cast<int>(msg.wParam);
	return 0;
}