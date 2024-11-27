
void bot_loop() {
  while (true) {
  sensor_read();
  button.A = digitalRead(BUTTON_A);
  button.B = digitalRead(BUTTON_B);
  button.C = digitalRead(BUTTON_C);
  button.D = digitalRead(BUTTON_D);

    // Обработка кнопок

    if (!button.C && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            selectedIndex--;
            if (selectedIndex < 0) {
                selectedIndex = menuCount - 1; // Зацикливаем вниз
            }
            button.timer = millis();
            showMenu(selectedIndex); // Перерисовываем меню
    }

    else if (!button.D && !button.flag && millis() - button.timer > 100) { // Кнопка "вниз"
            button.flag = true;
            selectedIndex++;
            if (selectedIndex >= menuCount) {
                selectedIndex = 0; // Зацикливаем вверх
            }
            button.timer = millis();
            showMenu(selectedIndex); // Перерисовываем меню
        }

    else if (!button.B && !button.flag && millis() - button.timer > 100) { // Кнопка "выбор"
            button.flag = true;
            button.timer = millis();
            executeSelectedOption(selectedIndex); // Выполняем выбранное действие
            
        }
    else if (!button.A && !button.flag && millis() - button.timer > 100) { // Кнопка "выбор"
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
           // oled.print(">");
            oled.invertText(1);
            oled.print(menuItems[i]);
            oled.invertText(0);
           // oled.print("<");
        } else {
            oled.setCursor(0, (i - startIndex) + 1); // Установить курсор в начале строки
            oled.print(menuItems[i]);
        }
    }
    // Рисуем полосу прокрутки
    oled.update(); // Обновление дисплея
}

void executeSelectedOption(int index) {
    switch (index) {
        case 0:
            indikat();
            break;
        case 1:
            lifetimer = 0;
            debug();
            break;
        case 2:
            game_setup();
            break;
        case 3:
            displayTime();
            break;
        case 4:
            tama_draw();
            break;
        case 5:
            lifetimer = 0;
            byte_draw();
            break;
        default:
            bot_loop();
            break;
    }
    showMenu(selectedIndex); // Вернуться к меню
}