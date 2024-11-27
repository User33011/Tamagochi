void debug(){
  while(true){
  sensor_read();
  int scrollPosition = SCREEN_WIDTH;

  button.A = digitalRead(BUTTON_A);
  button.B = digitalRead(BUTTON_B);
  button.C = digitalRead(BUTTON_C);
  button.D = digitalRead(BUTTON_D);

  if(lifetimer >= 1000){
    lifetimer = 0;
    tama_loop();
  }

  oled.clear();
  displayPetIcons();
  
  oled.setScale(1);
  oled.home();
  oled.setCursor(0, 0);
  oled.print("t=");
  oled.setCursor(12, 0);
  oled.print(sensor.temperat);
  oled.setCursor(24, 0);
  oled.print("C");

  oled.setCursor(0, 1);
  oled.print("h=");
  oled.setCursor(12, 1);
  oled.print(sensor.humidity);
  oled.setCursor(24, 1);
  oled.println("%");
  
  oled.setCursor(0, 3);
  oled.print("V=");
  oled.setCursor(12, 3);
  oled.print(sensor.voltage);

  oled.setCursor(0, 2);
  oled.print("L=");
  if (sensor.light < 100) {
    oled.setCursor(12, 2);
    oled.print(sensor.light);
    oled.setCursor(23, 2);
    oled.print(" ");
  }
  if (sensor.light < 10) {
    oled.setCursor(12, 2);
    oled.print(sensor.light);
    oled.setCursor(17, 2);
    oled.print(" ");
  }
  else{
    oled.setCursor(12, 2);
    oled.print(sensor.light);
  }
  oled.setCursor(0, 4);
  oled.print("SP");
  if(tama.sleep < 10) {
    oled.setCursor(12, 4);
    oled.print(tama.sleep);
    oled.setCursor(17, 4);
    oled.print(" ");
  }
  else{
    oled.setCursor(12, 4);
    oled.print(tama.sleep);
  }
  oled.setCursor(0, 5);
  oled.print("AG");
  if(tama.food < 10){
    oled.setCursor(12, 5);
    oled.print(tama.food);
    oled.setCursor(17, 5);
    oled.print(" ");
  }
  else {
  oled.setCursor(12, 5);
  oled.print(tama.food); 
  }
  oled.setCursor(0, 6);
  oled.print("WB");
  if(tama.water < 10){
    oled.setCursor(12, 6);
    oled.print(tama.water);
    oled.setCursor(17, 6);
    oled.print(" ");
  }
  else {
  oled.setCursor(12, 6);
  oled.println(tama.water);
  }
//  display.setCursor(scrollPosition, 56);
//  display.println("Press 'button.D' to exit");

  oled.update();

/*  scrollPosition--;
    if (scrollPosition < -200) { // Убедитесь, что текст полностью прокручивается
        scrollPosition = SCREEN_WIDTH; // Сбрасываем позицию
    }
*/
  if (!button.A && !button.flag && millis() - button.timer > 100) {
    button.flag = true;
    button.timer = millis();
    digitalWrite(LASER, LOW);
    break;
  }
  else if (!button.B && !button.flag && millis() - button.timer > 100) {
    button.flag = true;
    button.timer = millis();
    digitalWrite(LASER, LOW);
  }
  else if (!button.C && !button.flag && millis() - button.timer > 1000) {
    button.flag = true;
    button.timer = millis();
    digitalWrite(LASER, LOW);
  }
  else if (!button.D && !button.flag && millis() - button.timer > 1000) {
    button.flag = true;
    button.timer = millis();
    digitalWrite(LASER, LOW);
  }
  else {
    button.flag = false;
    digitalWrite(LASER, HIGH);
  }
  }
}