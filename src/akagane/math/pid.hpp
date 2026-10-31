#pragma once

namespace Akagane {

class Pid {
public:
  struct Config {
    double kp;
    double ki;
    double kd;
    double i_term_min;
    double i_term_max;
    double output_min;
    double output_max;
  };
  Pid(Config config);
  void set_target(double target);
  double get_target();
  double update(double value, double dt);

private:
  const Config config;
  double target;
  double i_term;
  double pre_error;
};

}; // namespace Akagane
