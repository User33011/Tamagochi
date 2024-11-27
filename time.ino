void displayTime() { 
  while(true){
  button.A = digitalRead(BUTTON_A);
  oled.clear();
  oled.setScale(1);
  oled.home();
  oled.setCursor(0, 0);
  oled.print(rtc.getHours());
  oled.print(":");
  oled.print(rtc.getMinutes());
  oled.print(":");
  oled.print(rtc.getSeconds());
  oled.print(" ");
  oled.print(rtc.getDay());
  oled.print(" ");
  oled.print(rtc.getDate());
  oled.print("/");
  oled.print(rtc.getMonth());
  oled.print("/");
  oled.println(rtc.getYear());
  oled.update();
  tama.timer = millis();
  while(millis() - tama.timer < 1000){
    ;
  }
    // Обработка кнопки
    if (!button.A && !button.flag && millis() - button.timer > 100) {
      button.flag = true;
      button.timer = millis();
      break;
    }
    else {
      button.flag = false;
      button.timer = millis();
    }
  }
}