#include <Arduino.h>
#include <akagane.hpp>

using namespace Akagane;

const uint32_t DELAY_MS = 100;

Pid::Config config{
    .kp = 0.1,
    .ki = 0.01,
    .kd = 0.005,
    .i_term_min = -255.0,
    .i_term_max = 255.0,
    .output_min = -255.0,
    .output_max = 255.0};
Pid pid(config);

double target = 5000.;
double current = 0.;

double mock_linear_motor(double duty, double dt) {
  constexpr double MAX_SPEED = 2.5;
  constexpr double TAU_ACCEL = 0.5;
  constexpr double TAU_FRICTION = 0.7;
  static double position = 0.0;
  static double velocity = 0.0;
  duty = clamp(duty, -255.0, 255.0);
  const double target_velocity = MAX_SPEED * duty / 255.0;
  const double tau = (duty == 0.0) ? TAU_FRICTION : TAU_ACCEL;
  const double alpha = 1.0 - std::exp(-dt / tau);
  velocity += alpha * (target_velocity - velocity);
  position += velocity * dt;
  if (std::abs(velocity) < 0.001) {
    velocity = 0.0;
  }
  return position;
}

void setup() {
  Serial.begin(115200);
  pid.set_target(target);
}

void loop() {
  int16_t duty = pid.update(current, DELAY_MS);
  current = mock_linear_motor(duty, DELAY_MS);
  AKAGANE_INFO("target: %lf, current: %lf, duty: %d", target, current, duty);
  delay(DELAY_MS);
}
