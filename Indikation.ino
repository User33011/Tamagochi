void drawFrame(int x, int y) {
    oled.rect(x - 2, y - 2, x +26, y+26, OLED_STROKE);
}


void indikat() {
  const int itemCount = 8; 
  uint32_t BUTON_TIMER = millis(); 
  while (true) {
    const int btnA = digitalRead(BUTTON_A);
    const int btnB = digitalRead(BUTTON_B);
    const int btnC = digitalRead(BUTTON_C);
    const int btnD = digitalRead(BUTTON_D);
        
    if (!btnA && millis() - BUTON_TIMER > 100) {
      BUTON_TIMER = millis();
      break;
    } else if (!btnB && millis() - BUTON_TIMER > 100) {
      BUTON_TIMER = millis();
      SelectedOption(currentCondition);
    } else if (!btnC && millis() - BUTON_TIMER > 100) {
      BUTON_TIMER = millis();
      currentCondition = (currentCondition - 1) % NUM_PET_CONDITIONS;
        if  (currentCondition < 0) currentCondition = MAX_ICONS;
    } else if (!btnD && millis() - BUTON_TIMER > 100) {
      BUTON_TIMER = millis();
      currentCondition = (currentCondition + 1) % NUM_PET_CONDITIONS;
    } else {
      BUTON_TIMER = millis();
    }
    oled.clear();
    for (int i = 0; i < itemCount; i++) {
      int index = i;
      int x = 5 + (i % 4) * (24 + 5);
      int y = 5 + (i / 4) * (24 + 5);
      oled.drawBitmap(x, y, petConditions[index].icon, 24, 24, BITMAP_NORMAL, BUF_ADD);
        if (index == currentCondition) {
          drawFrame(x, y); // Рамка вокруг активного состояния.
        }
    }
    oled.update();
  }
}

void SelectedOption(int index) {
    switch (index) {
        case 0:
            eatPet();
            // Здесь может быть код для выполнения действия пункта 1
            break;
        case 1:
            goSleep();
            // Здесь может быть код для выполнения действия пункта 2
            break;
        case 2:
            game_loop();
            // Здесь может быть код для выполнения действия пункта 2
            break;
        case 3:
            drink();
            // Здесь может быть код для выполнения действия пункта 2
            break;
        case 4:
            bullShit();
            // Здесь может быть код для выполнения действия пункта 2
            break;
        case 5:
            medical();
            // Здесь может быть код для выполнения действия пункта 2
            break;
        case 6:
            perhead();
            // Здесь может быть код для выполнения действия пункта 2
            break;
        case 7:
            ventilation();
            // Здесь может быть код для выполнения действия пункта 2
            break;
        default:
            break;
    }
    indikat();
}
