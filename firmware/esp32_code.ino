#include <BluetoothSerial.h>
#include <WiFi.h>

// -------- Pin Configuration --------
const int CURRENT_PIN = 26;    // ACS712 output
const int VOLTAGE_PIN = 27;    // ZMPT101B output
const int RELAY_PIN   = 25;    // Relay control pin

// -------- Thresholds --------
const float CURRENT_THRESHOLD = 12.0;   // Amps (adjustable)

// -------- Objects --------
BluetoothSerial SerialBT;

// -------- Setup --------
void setup() {
  Serial.begin(115200);
  SerialBT.begin("PowerGrid_Device");   // Bluetooth device name

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);        // Relay ON (normal state)

  WiFi.mode(WIFI_OFF);                  // Disable WiFi (power saving)

  Serial.println("PowerGrid Solutions Initialized");
  SerialBT.println("System Active");
}

// -------- Main Loop --------
void loop() {

  // Read raw ADC values
  int currentRaw = analogRead(CURRENT_PIN);
  int voltageRaw = analogRead(VOLTAGE_PIN);

  // Convert ADC values
  float current = ((currentRaw - 2048) * 5.0) / 2048.0;   // ACS712 approx
  float voltage = (voltageRaw * 5.0) / 4095.0;            // ZMPT101B approx

  // Debug output
  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A | Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // -------- Fault Detection --------
  if (current > CURRENT_THRESHOLD) {

    // Trip relay
    digitalWrite(RELAY_PIN, LOW);   // Cut power

    // Alert message
    String alertMessage = "ALERT: High current detected!\n"
                          "Current: " + String(current) + " A\n"
                          "Status: Circuit isolated";

    Serial.println(alertMessage);
    SerialBT.println(alertMessage);

    delay(6000);  // Cooldown before next alert
  }
  else {

    // Normal operation data
    SerialBT.print("Current: ");
    SerialBT.print(current);
    SerialBT.print(" A | Voltage: ");
    SerialBT.print(voltage);
    SerialBT.println(" V");

    digitalWrite(RELAY_PIN, HIGH);  // Ensure relay ON
  }

  delay(1000); // Sampling delay
}
