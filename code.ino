#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {8, 9, 10, 11}; 
byte colPins[COLS] = {A1, A2, A3, A4}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char customKey;
String password;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
}

void loop() {
  customKey = customKeypad.getKey();

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  if (customKey){
    if (customKey == '*') {
      password = "";
    } else if (customKey == '#') {
      if (password == "917309A") {
        lcd.setCursor(0, 1);
        lcd.print("Hello Ahmad");
      } else if (password == "13709B") {
        lcd.setCursor(0, 1);
        lcd.print("Hello Milena");
      } else if (password == "36690C") {
        lcd.setCursor(0, 1);
        lcd.print("Hello Ravilya");
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Unauthenticated");
      }
      delay(1000);
      lcd.clear();
      password = "";
    } else {
      password += customKey;
    }
  }
}

