void eatPet() {
  oled.clear();
  button.timer = millis();
  while(true) {
    oled.setCursorXY(30, 30);
    oled.autoPrintln(true);
    oled.print("Кушаем");
    oled.update();
    if (millis() - button.timer > 5000){
      oled.autoPrintln(false);
      break;
    }
  }
}
void drink() {
    oled.clear();
    oled.setCursorXY(0, 0);
    oled.println("THIS SUCKS...");
    oled.update();
}
void bullShit() {
    oled.clear();
    oled.setCursorXY(0, 0);
    oled.println("THIS SUCKS...");
    oled.update();
}
void ventilation() {
    oled.clear();
    oled.setCursorXY(0, 0);
    oled.println("Feeding pet...");
    oled.update();
}
void medical() {
    oled.clear();
    oled.setCursorXY(0, 0);
    oled.println("THIS SUCKS...");
    oled.update();
}
void goSleep() {
    oled.clear();
    oled.setCursorXY(0, 0);
    oled.println("THIS SUCKS...");
    oled.update();
}
void perhead() {
    oled.clear();
    oled.setCursorXY(0, 0);
    oled.println("THIS SUCKS...");
    oled.update();
}
void playGame() {
    oled.clear();
    oled.setCursorXY(0, 0);
    oled.println("Playing game...");
    oled.update();
}
