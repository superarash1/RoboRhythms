// Global Variables
#define BUZZER_PIN 25          // GPIO pin connected to the passive buzzer
int TEMPO = 96;               // Tempo in beats per minute (BPM)

// Note Frequencies (in Hz)
// Lower octave (3)
const int NOTE_C3 = 131;
const int NOTE_CS3 = 139;
const int NOTE_D3 = 147;
const int NOTE_DS3 = 156;
const int NOTE_Eb3 = 156;
const int NOTE_E3 = 165;
const int NOTE_F3 = 175;
const int NOTE_FS3 = 185;
const int NOTE_G3 = 196;
const int NOTE_GS3 = 208;
const int NOTE_A3 = 220;
const int NOTE_AS3 = 233;
const int NOTE_Bb3 = 233;
const int NOTE_B3 = 247;

// Middle octave (4)
const int NOTE_C4 = 262;
const int NOTE_CS4 = 277;
const int NOTE_D4 = 294;
const int NOTE_DS4 = 311;
const int NOTE_Eb4 = 311;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_FS4 = 370;
const int NOTE_G4 = 392;
const int NOTE_GS4 = 415;
const int NOTE_A4 = 440;
const int NOTE_AS4 = 466;
const int NOTE_Bb4 = 466;
const int NOTE_B4 = 494;

// Higher octave (5)
const int NOTE_C5 = 523;
const int NOTE_CS5 = 554;
const int NOTE_D5 = 587;
const int NOTE_DS5 = 622;
const int NOTE_Eb5 = 622;
const int NOTE_E5 = 659;
const int NOTE_F5 = 698;
const int NOTE_FS5 = 740;
const int NOTE_G5 = 784;
const int NOTE_GS5 = 831;
const int NOTE_A5 = 880;
const int NOTE_AS5 = 932;
const int NOTE_Bb5 = 932;
const int NOTE_B5 = 988;
const int NOTE_C6 = 1047;

const int NOTE_CS6 = 1109;     // C#
const int NOTE_D6 = 1175;
const int NOTE_DS6 = 1245;     // D# (or Eb)
const int NOTE_E6 = 1319;
const int NOTE_F6 = 1397;
const int NOTE_FS6 = 1480;     // F#
const int NOTE_G6 = 1568;
const int NOTE_GS6 = 1661;     // G#
const int NOTE_A6 = 1760;
const int NOTE_AS6 = 1865;     // A# (or Bb)
const int NOTE_B6 = 1976;

const int NOTE_C7 = 2093;

// Special values
const int REST = 0; 

// Accent types
enum AccentType {
    NONE = 0,       // No accent
    SHORT = 1,      // Short accent (^)
    LONG = 2,       // Long accent (>)
    DETACHED = 3,   // Detached accent (.)
    LEGATO = 4      // Legato accent (-)
};

// Melody and Durations
struct Note {
    int frequency;        // Frequency of the note (or REST for silence)
    float duration;       // Duration in beats (e.g., quarter note = 1, eighth note = 0.5)
    AccentType accent;    // Type of accent applied to the note
};



// WRITE EACH NOTE IN THIS ARRAY
Note melody[] = {
    {NOTE_C5, 0.25, NONE},
}; 




int melodyLength = sizeof(melody) / sizeof(melody[0]);

// Function to play a single note or rest with accent handling
void playNote(int frequency, float duration, AccentType accent) {
    int standardPause = 50; // Standard pause between notes (ms)
    float durationMultiplier = 1.0;
    int pauseAfter = standardPause;

    if (frequency > REST) {
        // Apply appropriate modifications based on accent type
        switch (accent) {
            case SHORT:
                durationMultiplier = 0.8;          // Shorter duration for short accents
                tone(BUZZER_PIN, frequency + 10);   // Slight frequency boost for emphasis
                delay(20);                         // Brief emphasis at start
                tone(BUZZER_PIN, frequency);
                break;

            case LONG:
                durationMultiplier = 1.2;          // Extended duration for long accents
                tone(BUZZER_PIN, frequency);
                break;

            case DETACHED:
                durationMultiplier = 0.85;         // Slightly shorter duration for detached notes
                pauseAfter = 100;                  // Longer pause after detached notes
                tone(BUZZER_PIN, frequency);
                break;

            case LEGATO:
                pauseAfter = 10;                   // Minimal pause for legato notes
                tone(BUZZER_PIN, frequency);
                break;

            case NONE:
            default:
                tone(BUZZER_PIN, frequency);       // Standard playback for no accents
                break;
        }

        delay((60000 / TEMPO) * duration * durationMultiplier);   // Play note for adjusted duration
        noTone(BUZZER_PIN);                                       // Stop tone after duration
        delay(pauseAfter);                                        // Pause after note (varies by accent type)
    } else {
        delay((60000 / TEMPO) * duration);                        // Handle rests (no sound)
    }
}

// Function to play the entire melody
void playMelody(Note melody[], int length) {
    for (int i = 0; i < length; i++) {
        playNote(melody[i].frequency, melody[i].duration, melody[i].accent);
    }
}

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);   // Set buzzer pin as output
}

void loop() {
    playMelody(melody, melodyLength);   // Play the melody once
    delay(2000);                        // Pause before repeating
}
