void eatPet() {
  oled.clear();
  button.timer = millis();
  tama.food = tama.food + 30;
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Кушаем");
    oled.update();
    if (millis() - button.timer > 2000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void drink() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Пьём");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void bullShit() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Сраньё");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void ventilation() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Вентилятор");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void medical() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Лечим");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void goSleep() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Спим");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void perhead() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Греем");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void playGame() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Играем");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}