const int LED = 2;
void setup() {
    // put your setup code here, to run once:
    pinMode(LED, OUTPUT); // 设置数字 2 口为输出接口
}

void loop() {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(1000);
}
