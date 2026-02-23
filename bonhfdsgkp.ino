#include <ESP32Servo.h>

// ===== PIN LDR =====
#define LDR_KIRI   32   // LDR1
#define LDR_KANAN  33   // LDR2
#define LDR_ATAS   34   // LDR3
#define LDR_BAWAH  35   // LDR4

// ===== PIN SERVO =====
#define SERVO_H 25   // sumbu X (kanan - kiri)
#define SERVO_V 26   // sumbu Y (atas - bawah)

Servo servoH;
Servo servoV;

int posH = 90;   // posisi awal horizontal
int posV = 90;   // posisi awal vertikal

void setup() {
  Serial.begin(115200);

  pinMode(LDR_KIRI, INPUT);
  pinMode(LDR_KANAN, INPUT);
  pinMode(LDR_ATAS, INPUT);
  pinMode(LDR_BAWAH, INPUT);

  servoH.attach(SERVO_H);
  servoV.attach(SERVO_V);

  servoH.write(posH);
  servoV.write(posV);

  Serial.println("=== Solar Tracker 2 Axis (Digital LDR) ===");
}

void loop() {

  // ---- BACA LDR ----
  int kiri  = digitalRead(LDR_KIRI);
  int kanan = digitalRead(LDR_KANAN);
  int atas  = digitalRead(LDR_ATAS);
  int bawah = digitalRead(LDR_BAWAH);

  // =================================================
  // SERVO HORIZONTAL (KANAN - KIRI) | SUMBU X
  // =================================================
  if (kiri == kanan && kiri == 1) {
    posH = 90;   // kembali ke posisi awal
    Serial.println("Horizontal seimbang → kembali tengah");
  }
  else if (kiri > kanan) {
    posH += 8;
    Serial.println("Horizontal → KIRI");
  }
  else if (kanan > kiri) {
    posH -= 8;
    Serial.println("Horizontal → KANAN");
  }

  // =================================================
  // SERVO VERTIKAL (ATAS - BAWAH) | SUMBU Y
  // =================================================
  if (atas == bawah && atas == 1) {
    posV = 90;   // kembali ke posisi awal
    Serial.println("Vertikal seimbang → kembali tengah");
  }
  if (bawah == atas && bawah == 1) {
    posV = 90;   // kembali ke posisi awal
    Serial.println("Vertikal seimbang → kembali tengah");
  }
  else if (atas > bawah) {
    posV += 8;
    Serial.println("Vertikal → ATAS");
  }
  else if (bawah > atas) {
    posV -= 8;
    Serial.println("Vertikal → BAWAH");
  }

  // ---- BATAS SUDUT ----
  posH = constrain(posH, 0, 180);
  posV = constrain(posV, 0, 180);

  // ---- GERAKKAN SERVO ----
  servoH.write(posH);
  servoV.write(posV);

  // ---- MONITOR ----
  Serial.print("H: ");
  Serial.print(posH);
  Serial.print(" | V: ");
  Serial.println(posV);

  delay(200);
}
