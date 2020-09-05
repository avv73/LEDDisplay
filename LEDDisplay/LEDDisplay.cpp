/*
  LEDDisplay.cpp - Library for controlling 4bit seven segment LED Display
  Created by Aleksandar V. , September, 2020
  Released under GNU General Public License
*/
#include <Arduino.h>
#include <LEDDisplay.h>
#define SEGMENT_PINS_LENGTH 7
#define DIGIT_COUNT 4

LEDDisplay::LEDDisplay(int* segmentPins, int* digitSelectPins, int decimalPointPin) {
	// Assign each attribute to parameter passed
	// segmentPins sequence - {A,B,C,D,E,F,G}
	// digitSelectPins sequence - {Digit1, Digit2, Digit3, Digit4}
	
	this->segmentPins = segmentPins;
	this->digitSelectPins = digitSelectPins;
	this->decimalPointPin = decimalPointPin;
	
	// Sets all pins to output
	setupPins();
}

void LEDDisplay::setupPins() {
	pinMode(decimalPointPin, OUTPUT);
	
	for (int i = 0; i < SEGMENT_PINS_LENGTH; i++) {
		pinMode(segmentPins[i], OUTPUT);
	}
	
	for (int i = 0; i < DIGIT_COUNT; i++) {
		pinMode(digitSelectPins[i], OUTPUT);
	}
}

void LEDDisplay::clear() {
	// Clears the display 
	
	for (int i = 0; i < SEGMENT_PINS_LENGTH; i++) {
		digitalWrite(segmentPins[i], LOW);
	}
	
	for (int i = 0; i < DIGIT_COUNT; i++) {
		digitalWrite(digitSelectPins[i], HIGH);
	}
	
	digitalWrite(decimalPointPin, LOW);
}

void LEDDisplay::activateSegments(int number) {
	// Activates segments according to the number passed (in range 0 to 9), assumes segments are set to LOW
	
	if (number == 0) {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (number == 1) {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
	}
	else if (number == 2) {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[3], HIGH);
	}
	else if (number == 3) {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
	}
	else if (number == 4) {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (number == 5) {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
	}
	else if (number == 6) {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
	}
	else if (number == 7) {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
	}
	else if (number == 8) {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (number == 9) {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
}

void LEDDisplay::activateSegments(char ch) {
	// Activates segments according to char passed, not every ASCII symbol
	// is representable in 7 segment - in such case the method doesn't return anything
	// Assumes segments are set to LOW
	
	if (isDigit(ch)) {
		activateSegments((int)(ch - '0'));
	}
	else if (ch == 'a' || ch == 'A') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'b' || ch == 'B') {
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'c' || ch == 'C') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == 'd' || ch == 'D') {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'e' || ch == 'E') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'f' || ch == 'F') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'g' || ch == 'G') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == 'h' || ch == 'H') {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'i' || ch == 'I') {
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == 'j' || ch == 'J') {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
	}
	else if (ch == 'l' || ch == 'L') {
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == 'n' || ch == 'N') {
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'o' || ch == 'O') {
		activateSegments(0);
	}
	else if (ch == 'p' || ch == 'P') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'q' || ch == 'Q') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'r' || ch == 'R') {
		digitalWrite(segmentPins[6], HIGH);
		digitalWrite(segmentPins[4], HIGH);
	}
	else if (ch == 's' || ch == 'S') {
		activateSegments(5);
	}
	else if (ch == 't' || ch == 'T') {
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == 'u' || ch == 'U') {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == 'y' || ch == 'Y') {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[5], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == '_') {
		digitalWrite(segmentPins[3], HIGH);
	}
	else if (ch == '-') {
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == '=') {
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
	else if (ch == '\"') {
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == '\'') {
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == '(' || ch == '[') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[3], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[5], HIGH);
	}
	else if (ch == ')' || ch == ']') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[2], HIGH);
		digitalWrite(segmentPins[3], HIGH);
	}
	else if (ch == '?') {
		digitalWrite(segmentPins[0], HIGH);
		digitalWrite(segmentPins[1], HIGH);
		digitalWrite(segmentPins[4], HIGH);
		digitalWrite(segmentPins[6], HIGH);
	}
}

void LEDDisplay::display(int number) {
	// Displays a number in range 0 to 9999.
	
	display(number, new bool[4] {false, false, false, false});
}

void LEDDisplay::display(int number, bool* decimalPointFlags) {
	// Displays a number in range 0 to 9999 and sets decimal point at each flag that equals true. Each digit is represented by the index
	// of the flag in the array. For example decimalPointFlags[1] is the flag for digit 2.
	// On a N digit number, only N decimal points can be shown.
	
	if (number < 0 || number > 9999) {
		return;
	}
  
	clear();
  
	int firstDigit = number % 10;
	number /= 10;
	int secondDigit = number % 10;
	number /= 10;
	int thirdDigit = number % 10;
	number /= 10;
	int fourthDigit = number % 10;
  
	activateSegments(firstDigit);
	if (decimalPointFlags[0]) {
		digitalWrite(decimalPointPin, HIGH);
	}
	digitalWrite(digitSelectPins[3], LOW);
	delay(5);
  
	clear();
  
	if (secondDigit == 0 && thirdDigit == 0 && fourthDigit == 0) {
		// Do not display number with leading zeros
		return;
	}
  
	activateSegments(secondDigit);
	if (decimalPointFlags[1]) {
		digitalWrite(decimalPointPin, HIGH);
	}
	digitalWrite(digitSelectPins[2], LOW);
	delay(5);
  
	clear();
  
	if (thirdDigit == 0 && fourthDigit == 0) {
		return;
	}
  
	activateSegments(thirdDigit);
	if (decimalPointFlags[2]) {
		digitalWrite(decimalPointPin, HIGH);
	}
	digitalWrite(digitSelectPins[1], LOW);
	delay(5);
  
	clear();
  
	if (fourthDigit == 0) {
		return;
	}
  
	activateSegments(fourthDigit);
	if (decimalPointFlags[3]) {
		digitalWrite(decimalPointPin, HIGH);
	}
	digitalWrite(digitSelectPins[0], LOW);
	delay(5);
  
}