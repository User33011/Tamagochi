void status_loop() {
while(true){
  const int btnA = digitalRead(BUTTON_A);

  oled.clear();

  oled.setCursor(0, 0);
  oled.print("Голод");
  oled.setCursor(0, 1);
  oled.print("Жажда");
  oled.setCursor(0, 2);
  oled.print("Игра");
  oled.setCursor(0, 3);
  oled.print("Сон");
  oled.setCursor(0, 4);
  oled.print("Лоток");
  oled.setCursor(0, 5);
  oled.print("Здоровье");
  oled.setCursor(0, 6);
  oled.print(" ");

  if(tama.food < 10){
    oled.setCursor(50, 0);
    oled.print(tama.food);
    oled.setCursor(55, 0);
    oled.print(" ");
  } else {
  oled.setCursor(50, 0);
  oled.print(tama.food); 
  }

  if(tama.water < 10){
    oled.setCursor(50, 1);
    oled.print(tama.water);
    oled.setCursor(55, 1);
    oled.print(" ");
  } else {
  oled.setCursor(50, 1);
  oled.print(tama.water); 
  }

  if(tama.game < 10){
    oled.setCursor(50, 2);
    oled.print(tama.game);
    oled.setCursor(55, 2);
    oled.print(" ");
  } else {
  oled.setCursor(50, 2);
  oled.print(tama.game); 
  }

  if(tama.sleep < 10){
    oled.setCursor(50, 3);
    oled.print(tama.sleep);
    oled.setCursor(55, 3);
    oled.print(" ");
  } else {
  oled.setCursor(50, 3);
  oled.print(tama.sleep); 
  }

  if(tama.shit < 10){
    oled.setCursor(50, 4);
    oled.print(tama.shit);
    oled.setCursor(55, 4);
    oled.print(" ");
  } else {
  oled.setCursor(50, 4);
  oled.print(tama.shit); 
  }

  if(tama.health < 10){
    oled.setCursor(50, 5);
    oled.print(tama.health);
    oled.setCursor(55, 5);
    oled.print(" ");
  } else {
  oled.setCursor(50, 5);
  oled.print(tama.health); 
  }

  if(tama.happiness < 10){
    oled.setCursor(50, 6);
    oled.print(tama.happiness);
    oled.setCursor(55, 6);
    oled.print(" ");
  } else {
  oled.setCursor(50, 6);
  oled.print(tama.happiness); 
  }
  
  oled.update();
  if(lifetimer >= 10000){
    lifetimer = 0;
    tama_loop();
  } 
  if (!btnA) break;
}
}
