const int LED = 2;
const int LIGHT_R = 14;
int VAL;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(LIGHT_R, INPUT);
    Serial.begin(9600);
}

void loop() {
    VAL = analogRead(LIGHT_R);
    Serial.println(VAL);
    Serial.println("HIGH: ");
    Serial.println(HIGH);
    delay(1000);
    if (VAL > 300) {
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }
}
