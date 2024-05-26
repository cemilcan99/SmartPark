#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change the HEX address if needed
Servo myservo1;

int IR1 = 2;
int IR2 = 4;
int Slot = 4;           // Enter Total number of parking Slots
int flag1 = 0;
int flag2 = 0;

void setup() {
  lcd.init();  // Initialize the LCD
  lcd.backlight();
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  myservo1.attach(7);
  myservo1.write(100); // Initially servo closed
  lcd.setCursor(0, 0);
  lcd.print("     ARDUINO    ");
  lcd.setCursor(0, 1);
  lcd.print("  Parking System ");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (digitalRead(IR1) == LOW && flag1 == 0) {
    if (Slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo1.write(0);  // Open the gate
        Slot = Slot - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print(" PARK ALANI DOLU ");
      lcd.setCursor(0, 1);
      lcd.print("  Parking Full  ");
      delay(3000);
      lcd.clear();
    }
  }

  if (digitalRead(IR2) == LOW && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo1.write(0);  // Open the gate
      Slot = Slot + 1;
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo1.write(100); // Close the gate
    flag1 = 0;
    flag2 = 0;
  }

  lcd.setCursor(0, 0);
  lcd.print("   HOSGELDINIZ!    ");
  lcd.setCursor(0, 1);
  lcd.print("  BOS PARK: ");
  lcd.print(Slot);
}
