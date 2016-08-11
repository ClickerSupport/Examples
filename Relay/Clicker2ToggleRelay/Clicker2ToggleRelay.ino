/*
 * Toggle the relays on the Relay Click board using the two buttons
 * on the Clicker 2 PIC32MX board
 *
 * Place the relay board into MBUS port 1 (left-hand).
 */

const int RelayOne = PIN_C1_PWM; // Click 1, PWM
const int RelayTwo = PIN_C1_CS;  // Click 1, CS

const int ButtonOne = PIN_BTN2;  // Right-hand button
const int ButtonTwo = PIN_BTN1;  // Left-hand button

void setup() {
    pinMode(RelayOne, OUTPUT);
    pinMode(RelayTwo, OUTPUT);
    digitalWrite(RelayOne, LOW);
    digitalWrite(RelayTwo, LOW);

    pinMode(ButtonOne, INPUT);
    pinMode(ButtonTwo, INPUT);
}

void loop() {
    static bool relayOneState = LOW;
    static bool relayTwoState = LOW;
    static bool buttonOneState = HIGH;
    static bool buttonTwoState = HIGH;

    bool buttonOneValue = digitalRead(ButtonOne);
    bool buttonTwoValue = digitalRead(ButtonTwo);

    if (buttonOneValue != buttonOneState) {
        buttonOneState = buttonOneValue;
        if (buttonOneValue == LOW) {
            relayOneState = !relayOneState;
            digitalWrite(RelayOne, relayOneState);
        }
    }

    if (buttonTwoValue != buttonTwoState) {
        buttonTwoState = buttonTwoValue;
        if (buttonTwoValue == LOW) {
            relayTwoState = !relayTwoState;
            digitalWrite(RelayTwo, relayTwoState);
        }
    }
}
