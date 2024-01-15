const float JUMP = 1.0594631;
const float EPS = 1e-6;
const float C4 = 261.626;
using i32 = int32_t;
i32 READ_VAL = 0;
const i32 TWO_TIGERS[] = {
    41, 99, 42, 99, 43, 99, 41, 99, //
    41, 99, 42, 99, 43, 99, 41, 99, //
    43, 99, 44, 99, 45, 99, 99, 0, //
    43, 99, 44, 99, 45, 99, 99, 0, //
    45, 46, 45, 44, 43, 99, 41, 0, //
    45, 46, 45, 44, 43, 99, 41, 0, //
    42, 99, 35, 99, 41, 99, 99, 0, //
    42, 99, 35, 99, 41, 99, 99, 0, //
};
float FREQUENCIES[100] = { 0.0 };
i32 NOTE_LENGTH_US[100];

void generate_frequencies() {
    FREQUENCIES[41] = C4;
    for (i32 group = 5; group <= 7; group++) {
        FREQUENCIES[group * 10 + 1] = FREQUENCIES[(group - 1) * 10 + 1] * 2;
    }
    for (i32 group = 4; group >= 1; group--) {
        FREQUENCIES[group * 10 + 1] = FREQUENCIES[(group + 1) * 10 + 1] / 2;
    }
    for (i32 group = 1; group <= 7; group++) {
        for (i32 i = 2; i <= 7; i++) {
            FREQUENCIES[group * 10 + i] = FREQUENCIES[group * 10 + i - 1] * JUMP;
        }
    }
    for (i32 i = 0; i < 100; i++) {
        if (FREQUENCIES[i] > EPS)
            NOTE_LENGTH_US[i] = round(1e6 / FREQUENCIES[i]);
    }
}

void play_note(i32 note, i32 note_us) {
    if (note == 0) {
        delayMicroseconds(note_us);
        return;
    }
    // delay(3000);
    i32 note_length_us = NOTE_LENGTH_US[note];
    i32 note_cnt = note_us / note_length_us;
    i32 note_rest = note_us % note_length_us;
    char msg[100];
    sprintf(msg, "%d %d %d %d", note_us, note, note_length_us, note_cnt);
    if (READ_VAL == 'R') {
        Serial.println(msg);
    }
    for (i32 i = 0; i < note_cnt; i++) {
        digitalWrite(2, HIGH);
        delayMicroseconds(note_length_us / 2);
        digitalWrite(2, LOW);
        delayMicroseconds((note_length_us + 1) / 2);
    }
    delayMicroseconds(note_rest);
}

void play_sequences(i32 seq[], i32 len, i32 note_ms) {
    const i32 note_us = note_ms * 1000;
    i32 last_note = 0;
    for (i32 i = 0; i < len; i++) {
        bool to_pause = !(i != len - 1 && seq[i + 1] == 99);
        i32 play_us = to_pause ? note_us : note_us / 8 * 7;
        i32 pause_us = note_us - play_us;
        i32 note_to_play = seq[i] == 99 ? last_note : seq[i];
        if (seq[i] != 99) {
            last_note = seq[i];
        }
        play_note(note_to_play, play_us);
        delayMicroseconds(pause_us);
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    generate_frequencies();
}

void loop() {
    READ_VAL = Serial.read();
    if (READ_VAL == 'R') {
        char msg[100];
        sprintf(msg, "%d", NOTE_LENGTH_US[41]);
        Serial.println(msg);
    }
    // play_sequences(TWO_TIGERS, sizeof(TWO_TIGERS) / sizeof(i32), 500);
}
