/* Carbon Monoxide Click Demo
 * 
 * Reads the analog MQ-7 value and calculates the PPM of Carbon Monoxide
 * 
 * You need to know the "clean air" resistance of the MQ-7 sensor
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
    float ppm =  pow((RS / R0) / 22.07, (1.0/-0.667));
    Serial.print("Carbon Monoxide: ");
    Serial.print(ppm);
    Serial.println(" ppm");
    delay(200);
}

