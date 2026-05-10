C++ Digital Clock Project
This project implements a customizable digital clock in C++ that runs in the console. It evolved from a simple version to a more advanced, object-oriented one with enhanced features like color, positioning, and a 12-hour format with AM/PM.

Project Evolution
Initial Console Version: A basic implementation using windows.h and ctime, featuring an infinite loop, screen clearing (system("cls")), HH:MM:SS format, and a 1-second delay (Sleep(1000)).
Advanced Object-Oriented Version: Introduced a DigitalClock class for better organization and features. This version utilizes gotoXY for precise cursor positioning (avoiding screen flicker), console colors (SetConsoleTextAttribute), a blinking colon, 12-hour format with AM/PM, and ASCII art framing. It also incorporates the name “Mohandes Kian” and a coder emoji (👨‍💻).
Key Features
Real-time Clock Display: Shows current Hour, Minute, and Second.
12-Hour Format with AM/PM: Easily switchable and displayed.
Console Positioning: Uses gotoXY to update the time in place, preventing screen flickering.
Color Customization: Implemented SetConsoleTextAttribute for text coloring.
Blinking Colon: Adds a dynamic visual effect to the time display.
Customizable Frame: ASCII art is used to create a decorative border around the clock.
Personalization: Includes the name “Mohandes Kian”.
Cross-Platform Considerations: Addressed potential character encoding issues for console display, especially with non-ASCII characters (like Persian).
