#include <iostream>
#include <thread>
#include <chrono>
#include <ApplicationServices/ApplicationServices.h>

void clickMouse() {
    CGEventRef ourEvent = CGEventCreate(NULL);
    CGPoint point = CGEventGetLocation(ourEvent);
    CFRelease(ourEvent);

    CGEventRef click_down = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseDown,
        point,
        kCGMouseButtonLeft
    );
    CGEventRef click_up = CGEventCreateMouseEvent(
        NULL, kCGEventLeftMouseUp,
        point,
        kCGMouseButtonLeft
    );

    CGEventPost(kCGHIDEventTap, click_down);
    CGEventPost(kCGHIDEventTap, click_up);

    CFRelease(click_down);
    CFRelease(click_up);
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
