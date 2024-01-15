int val;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    val = Serial.read();
    if (val == 'R') {
        Serial.println("Hello World! - v2"); // 在串口上？显示
    }
}
