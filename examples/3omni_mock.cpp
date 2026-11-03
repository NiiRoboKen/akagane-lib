#include <Arduino.h>
#include <akagane.hpp>

using namespace Akagane;

MockMotor motor0("m0");
MockMotor motor1("m1");
MockMotor motor2("m2");

OmniWheels<3> omni_wheel{
    OmniWheel(motor0, TWO_PI * 0. / 3.),
    OmniWheel(motor1, TWO_PI * 1. / 3.),
    OmniWheel(motor2, TWO_PI * 2. / 3.)};

void setup() {
  delay(1000);
  Serial.begin(115200);
}

double degree = 0.;
double step = (360 / 8);
double radian = 0.;

void loop() {
  radian = (TWO_PI / 360.) * degree;
  int16_t x = TypeInfo<int16_t>::MAX * cos(radian);
  int16_t y = TypeInfo<int16_t>::MAX * sin(radian);
  AKAGANE_INFO("OmniWheels run. radian = %lf", degree);
  omni_wheel.move(x, y);
  degree += step;
  if (degree >= 360) {
    degree = 0;
  }
  delay(500);
}
