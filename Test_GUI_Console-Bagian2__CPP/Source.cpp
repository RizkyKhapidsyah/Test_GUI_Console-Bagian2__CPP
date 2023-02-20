#include <Windows.h>
#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main() {
    // Daftarkan kelas window
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"ConsoleButton";

    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        L"ConsoleButton",               // Window class
        L"Console Button",              // Window text
        WS_VISIBLE | WS_SYSMENU,        // Window style

        // Size and position
        100, 100, 200, 100,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    // Run the message loop
    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// The window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
        // Create the command button
        CreateWindow(
            L"BUTTON",                  // Button class
            L"Tekan Saya!",                // Button text
            WS_VISIBLE | WS_CHILD,      // Button style
            50, 25, 100, 25,            // Position and size
            hwnd,                       // Parent window
            NULL,                       // No menu
            GetModuleHandle(NULL),      // Instance handle
            NULL                        // No additional data
        );
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == BN_CLICKED){ // Check if the button was clicked
            std::cout << "Aduh, saya ditekan!" << std::endl;
        }

        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}