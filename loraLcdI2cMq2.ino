#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define GAS_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LoRa Gas");

  if (!LoRa.begin(433E6)) {
    Serial.println("gagal");
    lcd.setCursor(0, 1);
    lcd.print("LoRa gagal");
    while (1);
  }

  delay(2000);
  lcd.clear();
}

void loop() {
  int gasValue = analogRead(GAS_PIN);
  String message = "Gas: " + String(gasValue);

  // Kirim via LoRa
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  // Tampilkan di Serial & LCD
  Serial.println(message);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Value:");
  lcd.setCursor(0, 1);
  lcd.print(gasValue);

  delay(2000); // Kirim setiap 2 detik
}

//===========================================================

// #include <SPI.h>
// #include <LoRa.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup() {
//   Serial.begin(9600);

//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("LoRa Receiver");

//   if (!LoRa.begin(433E6)) {
//     Serial.println("LoRa init failed!");
//     lcd.setCursor(0, 1);
//     lcd.print("LoRa Fail");
//     while (1);
//   }

//   delay(2000);
//   lcd.clear();
// }

// void loop() {
//   int packetSize = LoRa.parsePacket();
//   if (packetSize) {
//     String message = "";
//     while (LoRa.available()) {
//       message += (char)LoRa.read();
//     }
//     int rssi = LoRa.packetRssi();

//     Serial.print("Received: ");
//     Serial.println(message);
//     Serial.print("RSSI: ");
//     Serial.println(rssi);

//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print(message);
//     lcd.setCursor(0, 1);
//     lcd.print("RSSI: ");
//     lcd.print(rssi);
//   }
// }