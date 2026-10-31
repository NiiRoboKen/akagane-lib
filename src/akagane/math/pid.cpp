#include "pid.hpp"
#include "math.hpp"

namespace Akagane {

Pid::Pid(Pid::Config config) : config(config), target(0.), pre_error(0.), i_term(0.) {}

void Pid::set_target(double target) {
  this->target = target;
}

double Pid::get_target() {
  return this->target;
}

double Pid::update(double value, double dt) {
  double error = this->target - value;
  double p_term = this->config.kp * error;
  this->i_term = this->config.ki * clamp(
                                       this->i_term + (error + this->pre_error) * dt / 2.,
                                       this->config.i_term_min,
                                       this->config.i_term_max);
  double d_term = this->config.kd * (error - this->pre_error) / dt;
  this->pre_error = error;
  return clamp(p_term + i_term + d_term, this->config.output_min, this->config.output_max);
}

}; // namespace Akagane
