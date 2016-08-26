/* Flame Click Demo
 * 
 * This sketch examines the digital input that corresponds to the threshold indication
 * set by the trimmer on the click. When the input goes HIGH a FLAME event is indicated
 * and the current analog value of the sensor is recorded. A small amount is subtracted
 * from that value to add a bit of hysteresis to prevent flapping.
 * 
 * When the input goes LOW and the analog value is BELOW the threshold calculated
 * earlier the flame is seen as extinguished.
 */

const uint8_t analog_pin = PIN_C2_AN;    // Pin to read the value from
const uint8_t digital_pin = PIN_C2_INT;   // Pin to see if the flame is detected.

bool flame = false;
int thresh = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(digital_pin, INPUT);
}

void loop()
{
    int v = analogRead(analog_pin);
    int f = digitalRead(digital_pin);
    if (f && !flame) {
        flame = true;
        Serial.println("!!! FLAME DETECTED !!!");
        thresh = v - 20;
    }

    if (!f && flame) {
        if (v < thresh) {
            flame = false;
            Serial.println("Whew. Flame extinguisged.");
        }
    }
}

