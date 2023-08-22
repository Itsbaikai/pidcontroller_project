void PID_Control() {
  float target_speed = 100; // 目标速度
  float current_speed = 0; // 当前速度
  float error = 0; // 误差
  float previous_error = 0; // 上一次的误差
  float integral = 0; // 积分项
  float derivative = 0; // 微分项
  float Kp = 0.5; // 比例系数
  float Ki = 0.2; // 积分系数
  float Kd = 0.1; // 微分系数

  while (1) {
    current_speed = GetPulse(); // 通过定时器获取当前速度
    error = target_speed - current_speed; // 计算误差

    integral += error; // 累计误差
    derivative = error - previous_error; // 计算微分项

    float output = Kp * error + Ki * integral + Kd * derivative; // 计算输出值

    // 使用PWM输出信号控制电机转速
    // 根据output来调整占空比，实现缓慢提高PWM信号的占空比
    // 从而使电机的速度缓慢地提升上去

    previous_error = error; // 更新上一次的误差值
  }
}
