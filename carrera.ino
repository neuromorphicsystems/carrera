constexpr uint8_t PWM_PIN = 3;

void setup() {
    pinMode(PWM_PIN, OUTPUT);
    TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS20);
    OCR2B = 0xff;
    Serial.begin(115200);
}

void loop() {
    if (Serial.available() > 0) {
        const uint8_t speed = static_cast<uint8_t>(Serial.read());
        OCR2B = 0xff - speed;
    }
}
