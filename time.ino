void displayTime() { 
  while(true){
  const int btnA = digitalRead(BUTTON_A);
  oled.clear();
  oled.setScale(1);
  oled.home();
  oled.setCursor(0, 0);
  if (rtc.getHours() < 10) {
        oled.print("0");
    }
  oled.print(rtc.getHours());
  oled.print(":");
  if (rtc.getMinutes() < 10) {
        oled.print("0");
    }
  oled.print(rtc.getMinutes());
  oled.print(":");
  if (rtc.getSeconds() < 10) {
        oled.print("0");
    }
  oled.print(rtc.getSeconds());
  oled.print(" ");
  oled.print(rtc.getDay());
  oled.print(" ");
  if (rtc.getDate() < 10) {
        oled.print("0");
    }
  oled.print(rtc.getDate());
  oled.print("/");
  if (rtc.getMonth() < 10) {
        oled.print("0");
    }
  oled.print(rtc.getMonth());
  oled.print("/");
  oled.println(rtc.getYear());
  oled.update();
  tama.timer = millis();
  while(millis() - tama.timer < 1000){
    ;
  }
  if (!btnA) break;
  }
}
