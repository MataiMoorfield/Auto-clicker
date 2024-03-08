#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

void clickMouse() {
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(input));
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(input));
}

int main() {
    clickMouse();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() < 1100) { // Change 1.1 seconds for depending CPS test
        clickMouse();
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }

    return 0;
}
