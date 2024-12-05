
void bot_loop() {
  uint16_t btnB = 0, btnC = 0, btnD = 0;
  while(true) {
  if (!digitalRead(BUTTON_B))
	btnB++;
    else
	btnB = 0;
  if (!digitalRead(BUTTON_C))
	btnC++;
    else
	btnC = 0;
  if (!digitalRead(BUTTON_D))
	btnD++;
    else
	btnD = 0;

  if (btnB > 5000) {
    executeSelectedOption(selectedIndex);
    btnB = 0;
  } else if (btnC > 5000) {
    selectedIndex--;
            if (selectedIndex < 0) {
                selectedIndex = menuCount - 1; // Зацикливаем вниз
            }        
    showMenu(selectedIndex);
    btnC = 0;

  } else if (btnD > 5000) {
    selectedIndex++;
            if (selectedIndex >= menuCount) {
                selectedIndex = 0; // Зацикливаем вверх
            }
    showMenu(selectedIndex);
    btnD = 0;
  }
}
}

void showMenu(int index) {
    oled.clear(); // Очистка дисплея
    // Отображаем пункты меню
    int startIndex = index < 6 ? 0 : index - 5; // Начальный индекс для отображения пунктов меню
    int endIndex = min(startIndex + 6, menuCount); // Конечный индекс для отображения пунктов меню
    
    for (int i = startIndex; i < endIndex; i++) {
        if (i == index) {
            oled.setScale(1);
            // Отображение выбранного элемента с символами '>' и '<'
            oled.setCursor(0, (i - startIndex) + 1); // Установить курсор в начале строки
            oled.invertText(1);
            oled.print(menuItems[i]);
            oled.invertText(0);
        } else {
            oled.setCursor(0, (i - startIndex) + 1); // Установить курсор в начале строки
            oled.print(menuItems[i]);
        }
    }
    oled.update(); // Обновление дисплея
}

void executeSelectedOption(int index) {
    switch (index) {
        case 0:
            indikat();
            break;
        case 1:
            debug();
            break;
        case 2:
            status_loop();
            break;
        case 3:
            displayTime();
            break;
        case 4:
            tama_draw();
            break;
        case 5:
            byte_draw();
            break;
        default:
            bot_loop();
            break;
    }
    showMenu(selectedIndex); // Вернуться к меню
}
