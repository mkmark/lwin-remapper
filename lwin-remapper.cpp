// #include <iostream>
#include <Windows.h>

DWORD lastPressVkCode;

HHOOK keyboardHook = NULL;
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode == HC_ACTION) {
    KBDLLHOOKSTRUCT* kbStruct = (KBDLLHOOKSTRUCT*)lParam;
    if (wParam == WM_KEYDOWN) {
      // std::cout << "Key Pressed: " << kbStruct->vkCode << std::endl;
      lastPressVkCode = kbStruct->vkCode;
    }
    else if (kbStruct->vkCode == VK_LWIN && lastPressVkCode == VK_LWIN) {
      keybd_event(VK_F23, 0, 0, 0);
      keybd_event(VK_F23, 0, KEYEVENTF_KEYUP, 0);
    }
  }
  return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

int main(){
  keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0);

  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  UnhookWindowsHookEx(keyboardHook);
  return 0;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  main();
}
