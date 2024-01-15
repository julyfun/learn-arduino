void setup() {
    // put your setup code here, to run once:
    for (int i = 2; i <= 6; i++) {
        pinMode(i, OUTPUT);
    }
}

void light(int st, int ed, int step, int output, int delay_ms) {
    for (int i = st; ed >= st ? i <= ed : i >= ed; i += step) {
        digitalWrite(i, output);
        delay(delay_ms);
    }
}

void loop() {
    const int delay_ms = 40;
    light(2, 6, 1, HIGH, delay_ms);
    delay(200);
    light(6, 2, -1, LOW, delay_ms);
    delay(200);
    light(6, 2, -1, HIGH, delay_ms);
    delay(200);
    light(2, 6, 1, LOW, delay_ms);
    delay(200);
}
