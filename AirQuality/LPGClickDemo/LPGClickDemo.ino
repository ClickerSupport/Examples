/* LPG Click Demo
 * 
 * Reads the analog MQ-6 value and calculates the PPM of LPG
 * 
 * You need to know the "clean air" resistance of the MQ-6 sensor
 * to calibrate the readings. Also the reistance of the "load"
 * resistor. This is adjustable between 470 and 10470 ohms.
 */

const uint8_t pin = PIN_C2_AN;    // Pin to read the value from
const uint32_t RL = 5000 + 470;   // Load resistance value
const uint32_t R0 = 10000;        // Clean air resistance
void setup()
{
  Serial.begin(115200);
}

void loop()
{
    float v = analogRead(pin) / 1024.0 * 3.3;
    float RS = (RL * 5) / v;
    float ppm =  pow((RS / R0) / 18.466, (1.0/-0.421));
    Serial.print("LPG: ");
    Serial.print(ppm);
    Serial.println(" ppm");
    delay(200);
}

