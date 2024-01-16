void setup() {
    pinMode(14, INPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.print("模拟量值为：");
    Serial.println(analogRead(14));
    delay(200);
}
