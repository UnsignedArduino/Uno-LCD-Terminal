# Uno-LCD-Terminal
An LCD terminal that is controllable over serial! Should theoretically work on any Arduino board at least as powerful as an Arduino Uno, but only tested on such.

Designed to be used with my companion software [Uno LCD Terminal Daemon](https://github.com/UnsignedArduino/Uno-LCD-Terminal-Daemon). (some terribly written Python scripts)

## Hardware

### Hardware needed

- Arduino Uno (or other Arduino board of similar form factor)
- [Adafruit RGB LCD Shield Kit w/ 16x2 Character Display](https://www.adafruit.com/product/716)

### Assembly

Really couldn't get much easier, just plug the shield into the Arduino. 

## Software

### Uploading

1. Clone this repo. 
2. Open in your IDE for PlatformIO.
3. Change the [`upload_port`](https://github.com/UnsignedArduino/Uno-LCD-Terminal/blob/main/platformio.ini#L15) in [`platformio.ini`](https://github.com/UnsignedArduino/Uno-LCD-Terminal/blob/main/platformio.ini) to match the Arduino Uno's serial port.
5. Upload to your Arduino Uno. (Make sure it's plugged in!)

## Serial protocol

| Command | Sub command | Parameters        | Notes                                                           |
|---------|-------------|-------------------|-----------------------------------------------------------------|
| `r`     | None        | None              | Clears the display, resets the cursor position to (0, 0).       |
| `d`     | None        | None              | Clears the display.                                             |
| `h`     | None        | None              | Resets the cursor position to (0, 0).                           |
| `c`     | `c`         | `int`             | Sets the column.                                                |
|         | `r`         | `int`             | Sets the row.                                                   |
| `a`     | `w`         | None              | Prints the number of columns and ends with a newline.           |
|         | `h`         | None              | Prints the number of rows and ends with a newline.              |
|         | `c`         | None              | Prints 1 or 0 if there is "color" backlight support.            |
| `p`     | None        | stream of `char`s | Send a bunch of characters to print, and finish with a newline. |
| `b`     | `o`         | None              | Turns the backlight off.                                        |
|         | `r`         | None              | Sets the backlight to red.                                      |
|         | `y`         | None              | Sets the backlight to yellow.                                   |
|         | `g`         | None              | Sets the backlight to green.                                    |
|         | `t`         | None              | Sets the backlight to teal.                                     |
|         | `b`         | None              | Sets the backlight to blue.                                     |
|         | `v`         | None              | Sets the backlight to violet.                                   |
|         | `w`         | None              | Sets the backlight to white.                                    |
