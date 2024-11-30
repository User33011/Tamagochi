void status() {
  button.flag = false;
while(true){
  button.A = digitalRead(BUTTON_A);
  button.B = digitalRead(BUTTON_B);
  button.C = digitalRead(BUTTON_C);
  button.D = digitalRead(BUTTON_D);

  if(lifetimer >= 60000){
    lifetimer = 0;
    tama_loop();
  }
  oled.clear();

  oled.setCursor(0, 0);
  oled.print("Еда");
  if(tama.food < 10){
    oled.setCursor(17, 0);
    oled.print(tama.food);
    oled.setCursor(23, 0);
    oled.print(" ");
  } else {
  oled.setCursor(17, 0);
  oled.print(tama.food); 
  }

  oled.setCursor(0, 1);
  oled.print("Вода");
  if(tama.water < 10){
    oled.setCursor(23, 1);
    oled.print(tama.water);
    oled.setCursor(28, 1);
    oled.print(" ");
  } else {
  oled.setCursor(23, 1);
  oled.print(tama.water); 
  }

  oled.setCursor(0, 2);
  oled.print("Игра");
  if(tama.game < 10){
    oled.setCursor(23, 2);
    oled.print(tama.game);
    oled.setCursor(28, 2);
    oled.print(" ");
  } else {
  oled.setCursor(23, 1);
  oled.print(tama.game); 
  }

  oled.setCursor(0, 3);
  oled.print("Сон");
  if(tama.sleep < 10){
    oled.setCursor(17, 3);
    oled.print(tama.sleep);
    oled.setCursor(23, 3);
    oled.print(" ");
  } else {
  oled.setCursor(17, 3);
  oled.print(tama.sleep); 
  }
  
  oled.setCursor(0, 4);
  oled.print("Срач");
  if(tama.shit < 10){
    oled.setCursor(23, 4);
    oled.print(tama.shit);
    oled.setCursor(28, 4);
    oled.print(" ");
  } else {
  oled.setCursor(23, 4);
  oled.print(tama.shit); 
  }

  oled.setCursor(0, 5);
  oled.print("Хилс");
  if(tama.health < 10){
    oled.setCursor(23, 5);
    oled.print(tama.health);
    oled.setCursor(28, 5);
    oled.print(" ");
  } else {
  oled.setCursor(23, 5);
  oled.print(tama.health); 
  }

  oled.update();
  if (!button.A && !button.flag && millis() - button.timer > 200) {
            button.flag = true;
            button.timer = millis();
            break;
            // Переход вниз по строкам.
  } else {
    button.flag = false;
    button.timer = millis();
  }
}
}