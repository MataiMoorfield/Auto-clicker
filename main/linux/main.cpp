#include <iostream>
#include <thread>
#include <chrono>
#include <X11/Xlib.h>

void clickMouse() {
    Display *display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        std::cerr << "Error: Could not open display." << std::endl;
        return;
    }

    XEvent event;
    event.type = ButtonPress;
    event.xbutton.button = Button1;
    event.xbutton.same_screen = True;
    XQueryPointer(display, RootWindow(display, DefaultScreen(display)),
                  &event.xbutton.root, &event.xbutton.window,
                  &event.xbutton.x_root, &event.xbutton.y_root,
                  &event.xbutton.x, &event.xbutton.y,
                  &event.xbutton.state);
    event.xbutton.subwindow = event.xbutton.window;
    while (event.xbutton.subwindow) {
        event.xbutton.window = event.xbutton.subwindow;
        XQueryPointer(display, event.xbutton.window,
                      &event.xbutton.root, &event.xbutton.subwindow,
                      &event.xbutton.x_root, &event.xbutton.y_root,
                      &event.xbutton.x, &event.xbutton.y,
                      &event.xbutton.state);
    }
    event.xbutton.state |= Button1Mask;
    XSendEvent(display, PointerWindow, True, 0xfff, &event);
    XFlush(display);

    event.type = ButtonRelease;
    event.xbutton.state &= ~Button1Mask;
    XSendEvent(display, PointerWindow, True, 0xfff, &event);
    XFlush(display);

    XCloseDisplay(display);
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
