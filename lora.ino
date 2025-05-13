#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  // Pasangan 1
  LoRa.begin(433E6); // Frekuensi LoRa 433 MHz
  //Pasangan 2
  LoRa.begin(433.1E6); // 433.100 MHz

}

void loop() {
  LoRa.beginPacket();
  LoRa.print("Hello World");
  LoRa.endPacket();
  delay(1000); 
}
// pengirim
//=======================================================================

// #include <SPI.h>
// #include <LoRa.h>

// void setup() {
//   Serial.begin(9600);
//   LoRa.begin(433E6); // Frekuensi harus sama dengan pengirim
// //Pasangan 2
//   LoRa.begin(433.1E6); // 433.100 MHz
// }

// void loop() {
//   int packetSize = LoRa.parsePacket();
//   if (packetSize) {
//     while (LoRa.available()) {
//       String message = LoRa.readString();
//       Serial.println("Menerima pesan: " + message);
//     }
//   }
// }
