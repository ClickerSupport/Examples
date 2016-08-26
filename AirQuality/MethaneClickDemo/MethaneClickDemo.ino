/* Methane Click Demo
 * 
 * Reads the analog MQ-4 value and calculates the PPM of Methane
 * 
 * You need to know the "clean air" resistance of the MQ-4 sensor
 * to calibrate the readings. Also the reistance of the "load"
 * resistor. This is adjustable between 470 and 10470 ohms.
 */

const uint8_t pin = PIN_C2_AN;    // Pin to read the value from
const uint32_t RL = 5000 + 470;  // Load resistance value
const uint32_t R0 = 10000;       // Clean air resistance
void setup()
{
  Serial.begin(115200);
}

void loop()
{
    float v = analogRead(pin) / 1024.0 * 3.3;
    float RS = (RL * 5) / v;
    float ppm = 1021 * pow(RS / R0, -2.7887);
    Serial.print("Methane: ");
    Serial.print(ppm);
    Serial.println(" ppm");
    delay(200);
}

