/*
  LEDDisplay.h - Library for controlling 4bit seven segment LED Display
  Created by Aleksandar V. , September, 2020
  Released under GNU General Public License
*/
#include <Arduino.h>

class LEDDisplay {
public:
	LEDDisplay(int segmentPins[], int digitSelectPins[], int decimalPointPin);
	
	void display(String textToDisplay);
    	void display(String textToDisplay, bool decimalPointFlags[]);
    	void display(char textToDisplay[]);
    	void display(char textToDisplay[], bool decimalPointFlags[]);
    	void display(int number);
    	void display(int number, bool decimalPointFlags[]);
	
    	void clear();
private:
	int* segmentPins;
	int* digitSelectPins;
	int decimalPointPin;
	
	void setupPins();
	void activateSegments(int number);
	void activateSegments(char chr);
};
