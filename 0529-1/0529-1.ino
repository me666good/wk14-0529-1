// 定義接腳
const int sensorPin = A0; // 光敏電阻連接到類比接腳 A0
const int ledPin = 9; // LED 連接到數位接腳 D9 (支援 PWM)

void setup() {
// 初始化序列埠，方便在電腦上監看數值
Serial.begin(9600);

// 設定 LED 接腳為輸出模式
pinMode(ledPin, OUTPUT);
}

void loop() {
// 1. 讀取光敏電阻的類比數值
int sensorRead = analogRead(sensorPin);

// 2. 使用 map 函數進行數值轉換
// 【蓋住不亮模式】：
// 當數值接近 200 (手蓋住變暗) -> 輸出 0 (LED 熄滅)
// 當數值接近 600 (手放開變亮) -> 輸出 255 (LED 全亮)
int ledBar = map(sensorRead, 500, 900, 0, 255);

// 3. 安全機制：限制 ledBar 數值在 0 ~ 255 之間
ledBar = constrain(ledBar, 0, 255);

// 4. 輸出 PWM 訊號控制 LED 亮度
analogWrite(ledPin, ledBar);

// 5. 將數值回傳到電腦的序列埠監視器
Serial.print("光敏電阻值: ");
Serial.print(sensorRead);
Serial.print(" | LED 亮度值(PWM): ");
Serial.println(ledBar);

delay(30); // 讓燈光變化流暢穩定
}
