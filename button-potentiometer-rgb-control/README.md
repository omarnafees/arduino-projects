# Button Potentiometer RGB Control

A button and potentiometer are used to control an RGB LED. The RGB LED stays off until the button is pressed, then the potentiometer controls its color.

## How It Works

When the button is not pressed, the RGB LED remains off. When the button is pressed, the potentiometer value is divided into ranges that control the RGB LED's color as the potentiometer is turned.

## What I Used

* Arduino Uno
* Push button
* Potentiometer
* RGB LED
* Resistors
* Breadboard
* Jumper wires

## What I Learned

* Using `INPUT_PULLUP`
* Using `map()` to convert input ranges
* Dividing an input range using multiple `else if` conditions
* Creating smooth RGB color transitions
* Controlling RGB channels independently

## Project Video

[ Click here to watch the project in action](https://www.youtube.com/watch?v=p-wNrhv2z0c)
