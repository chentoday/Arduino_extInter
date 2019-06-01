# Arduino_extInter

## 功能
使用外部中断控制 LED

## 代码
```C++
#include "Arduino.h"
volatile boolean RunBuzzer = true;
const int led = 18;
const int button = 35;

// 中断函数
void warning()
{

  RunBuzzer = !RunBuzzer;
}

void setup()
{
  // 初始化外部中断、pin
  // 当按键按下时，引脚 34 输入的电平由高变低,触发中断函数warning
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  attachInterrupt(button, warning, FALLING);
}

void loop()
{
  if (RunBuzzer)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}

```