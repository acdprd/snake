#define FIRST_SEGMENT_PIN   2
#define SEGMENT_COUNT       7
#define MIN_POS  0
#define MAX_POS  8
int startPos = 0;

/*0b
 * 0 - dot
 * 0 - mid
 * 1 - top left
 * 1 - top
 * 1 - top right
 * 1 - botttom
 * 1 - bot right
 * 1 - bot left
 */
byte numberSegments[10] = {
  0b00111111, 0b00001010, 0b01011101, 0b01011110, 0b01101010,
  0b01110110, 0b01110111, 0b00011010, 0b01111111, 0b01111110,
};

byte snakeSegments[8] = {
  0b01000000, 0b00100000, 0b00010000, 0b00001000,
  0b01000000, 0b00000001, 0b00000100, 0b00000010, 
};

void setup() {
  for (int i = 0; i < SEGMENT_COUNT; ++i)
    pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
}

void loop() {
  int mask = snakeSegments[startPos++];
  for (int i = 0; i < MAX_POS; ++i) {
    boolean enableSegment = bitRead(mask, i);
    digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
  }
  if (startPos == MAX_POS) startPos = 0;
  delay(500);
}
