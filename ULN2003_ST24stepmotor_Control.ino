#define IN1 16
#define IN2 17
#define IN3 18
#define IN4 19

int delayTime = 5;     // 每半步延遲(ms)
int stepsPerRev = 4096;  // 半步模式下一圈=96步

// 半步驅動序列，共8步
int stepSeq[8][4] = {
  {1, 0, 0, 1},
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1}
};

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(115200);
  Serial.println("ST-24 360° CW & CCW test");
}

void loop() {
  Serial.println("Clockwise 360° ...");
  rotateSteps(stepsPerRev, true);   // 正轉 360°
  delay(1000);

  Serial.println("Counter-Clockwise 360° ...");
  rotateSteps(stepsPerRev, false);  // 反轉 360°
  delay(1000);
}

void rotateSteps(int stepsCount, bool cw) {
  for (int i = 0; i < stepsCount; i++) {
    int index = cw ? i % 8 : (7 - (i % 8));
    digitalWrite(IN1, stepSeq[index][0]);
    digitalWrite(IN2, stepSeq[index][1]);
    digitalWrite(IN3, stepSeq[index][2]);
    digitalWrite(IN4, stepSeq[index][3]);
    delay(delayTime);
  }
}
