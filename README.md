# Uno-LCD-Terminal
An LCD terminal that is controllable over serial!

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
