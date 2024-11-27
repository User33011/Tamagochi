void sensor_read() {

  int t = 0;
  int h = 0;
  dht11.readTemperatureHumidity(t, h);
  int l = analogRead(SENSOR_LIGHT) / 4;
  int aR = analogRead(VOLTAGE);     // Считываем значение с аналогового входа
  float V_ref = 5.0;                // Опорное напряжение для Arduino
  float v = (aR / 1024.0) * V_ref;  // Рассчитываем напряжение

  sensor.temperat = t;
  sensor.humidity = h;
  sensor.light = l;
  sensor.voltage = v;

}