//menerima
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Atur alamat I2C dan ukuran LCD (16 kolom x 2 baris)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ganti 0x27 jika alamat I2C beda

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LoRa penerima");

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
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String message = "";
    while (LoRa.available()) {
      message += (char)LoRa.read();
    }

    int rssi = LoRa.packetRssi();

    // Tampilkan di Serial Monitor
    Serial.print("pesan: ");
    Serial.println(message);
    Serial.print("sinyal: ");
    Serial.println(rssi);

    // Tampilkan di LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("pesan: ");
    lcd.print(message);
    lcd.setCursor(0, 1);
    lcd.print("sinyal: ");
    lcd.print(rssi);
    delay(2000);
  }
}

//================================================================

// #include <SPI.h>
// #include <LoRa.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);
// unsigned long counter = 0;

// void setup() {
//   Serial.begin(9600);

//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("LoRa Sender");

//   if (!LoRa.begin(433E6)) {
//     Serial.println("LoRa init failed!");
//     lcd.setCursor(0, 1);
//     lcd.print("Init Failed!");
//     while (1);
//   }

//   delay(2000);
//   lcd.clear();
// }

// void loop() {
//   String message = "Hello World";
//   counter++;

//   LoRa.beginPacket();
//   LoRa.print(message);
//   LoRa.endPacket();

//   Serial.println("mengirim: " + message);

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("mengirim:");
//   lcd.print(message);
//   lcd.setCursor(0, 1);
//   lcd.print("pesan dikirim: ");
//   lcd.print(counter);

//   delay(2000);
// }
