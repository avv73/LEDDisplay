# LEDDisplay
Arduino library for controlling seven segment 4 bit common anode LED display.

## Table of contents

* [Usage](#usage)
* [Methods](#methods)
* [Example](#example)
* [Sources](#sources)

## Usage

A 4 bit seven segment LED display has 12 pins - four of those are used for selecting a digit and the rest are used to light up a particular part of the segment. Each segment has a letter assigned to it, like in the image shown below.


![letters_and_segments](https://i.postimg.cc/3N4dbNFF/bb.png)


Using the library is really easy. Different manufacturers use different pin layouts for their displays - so first you need to find the correct layout for your display model. Once you know the function of each pin, you can connect them to the Arduino board and create a LEDDisplay object in this simple manner:

	#include <LEDDisplay.h>

	LEDDisplay* myDisplay;

	void setup() {
	 int segmentPins[] = {9, 7, 5, 3, 2, 8, 6};
	 int digitPins[] = {11, 10, 13, 12};
	 int decimalPoint = 4;
  
	 myDisplay = new LEDDisplay(segmentPins, digitPins, decimalPoint);
    }
    
    
The constructor has three arguments - firstly an integer array containing the pins ordered by the segment they represent in this sequence: __A,B,C,D,E,F,G__. Then another integer array containing the pins that correspond to the digits in this order: __Digit 1, Digit 2, Digit 3, Digit 4__. The last argument is the pin that activates the decimal point. 

In the example above pins 9, 7, 5, 3, 2, 8, 6 correspond respectively to segments A, B, C, D, E, F, G and pins 11, 10, 13, 12 correspond respectively to digits 1, 2, 3, 4.

Note that we use pins from the Arduino, __NOT__ from the LED display itself. The pins from the LED are connected according to the segment/digit they activate.

If you are not sure or don't know how to hook up the LED to the Arduino, you can follow the instructions [here](https://rastating.github.io/using-a-7-segment-led-display-w-arduino-uno/).


## Methods

`clear()` - Clears the display.

`display(int)` - Displays an integer in the range [0,9999], leading zeros are omitted.

`display(int, bool[4])` - Displays an integer in range [0,9999] and sets the decimal point for each flag that is true. Each element in the array represents the decimal point for the corresponding digit. For example the element with index 1 in the array represents the second digit and so on. On a integer with N digits, only N decimal points can be set.

`display(char[])` - Displays a symbol array with maximum of 4 elements. Note that not every symbol is representable in seven segment form, in such case the symbol in question is skipped.

`display(char[], bool[4])` - Displays a symbol array with maximum of 4 elements and sets the decimal point for each flag that is true. Each element in the array represents the decimal point for the corresponding digit. 

`display(String)` - Displays a string with maximum of 4 elements. Note that not every symbol is representable in seven segment form, in such case the symbol in question is skipped.

`display(String, bool[4])` - Displays a string with maximum of 4 elements and sets the decimal point for each flag that is true. Each element in the array represents the decimal point for the corresponding digit. 


## Example

The following code creates an LEDDisplay object and displays the word `play` for a brief period of time, then displays the number `7412` with decimal point set on digit 1 and 3. 

	#include <LEDDisplay.h>

	LEDDisplay* myDisplay;

	bool* arr = new bool[4] {true, false, true, false};
	int segmentPins[] = {9, 7, 5, 3, 2, 8, 6};
	int digitPins[] = {11, 10, 13, 12};

	void setup() {
	 myDisplay = new LEDDisplay(segmentPins, digitPins, 4);
	}

	void loop() {
	 for (int i = 0; i < 100; i++) {
		 myDisplay->display("play");
	 }
	 for (int i = 0; i < 100; i++) {
		 myDisplay->display(7412, arr);
	 }
    }

## Sources

This library is inspired by a similar one by [rastating](https://github.com/rastating) that you can find [here](https://github.com/rastating/LEDDisplay), but which had some limitations and I decided to write one on my own from scratch. 
