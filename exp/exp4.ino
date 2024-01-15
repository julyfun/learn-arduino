int flag = 0;
void setup() {
    pinMode(2, OUTPUT);
    pinMode(4, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(4) == LOW) {
        if (flag == 0) {
            flag = 1;
            digitalWrite(2, LOW);
        } else {
            flag = 0;
            digitalWrite(2, HIGH);
        }
        while (!digitalRead(4))
            ; // 吞噬多余输入
    }
}
