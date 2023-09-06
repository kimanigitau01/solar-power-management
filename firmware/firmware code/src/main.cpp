#include <Arduino.h>
#include <LiquidCrystal.h>

const int solarPin = A0;
const int batteryPin = A1;
const int relayPin = 7;

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//function prototypes
float getSolarVoltage();
float getBatteryVoltage();

float solVoltage = 0.0;
float batVoltage = 0.0;

// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;
// Float for Reference Voltage
float ref_voltage = 5.0;

void setup() {
  lcd.begin(16, 2);
  pinMode(relayPin, OUTPUT); // set relay pin as output
  pinMode(5, OUTPUT); // set pin 5 as output
  lcd.setCursor(0,0);
  lcd.print("Solar Voltage");
  delay(1000);
  lcd.clear();
}

void loop() {
  float solarVoltage = getSolarVoltage();
  float batteryVoltage = getBatteryVoltage();

  lcd.setCursor(0, 0);
  lcd.print("Solar: ");
  lcd.print(solarVoltage);
  lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print("Battery: ");
  lcd.print(batteryVoltage);
  lcd.print("V");

  // Check battery voltage
  if (batteryVoltage <= 7.4) {
    digitalWrite(5, HIGH); // Set pin 5 high if voltage <= 7.4V
  } else {
    digitalWrite(5, LOW); // Set pin 5 low if voltage > 7.4V
  }

  // Control relay based on battery voltage
  if (batteryVoltage >= 13.5) {
    digitalWrite(relayPin, HIGH); // Turn off relay if voltage >= 13.5V
  } else if (batteryVoltage <= 7.5) {
    digitalWrite(relayPin, LOW); // Turn on relay if voltage < 7.5V
  }

  delay(1000);
}

float getSolarVoltage() {
  int solarAdc_value = analogRead(solarPin);
  float solarAdc_voltage = (solarAdc_value * ref_voltage) / 1024.0;
  solVoltage = solarAdc_voltage / (R2 / (R1 + R2));
  return solVoltage;
}

float getBatteryVoltage() {
  int batteryAdc_value = analogRead(batteryPin);
  float batteryAdc_voltage = (batteryAdc_value * ref_voltage) / 1024.0;
  batVoltage = batteryAdc_voltage / (R2 / (R1 + R2));
  return batVoltage;
}
