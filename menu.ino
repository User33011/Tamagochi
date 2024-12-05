void bot_loop() {
    uint16_t btnB = 0, btnC = 0, btnD = 0;
    const uint16_t threshold = 5000; // Пороговое значение нажатий
    int lastSelectedIndex = selectedIndex; // Для сравнения состояний

    while (true) {
        // Чтение состояния кнопок
        bool buttonBPressed = !digitalRead(BUTTON_B);
        bool buttonCPressed = !digitalRead(BUTTON_C);
        bool buttonDPressed = !digitalRead(BUTTON_D);

        // Обработка нажатия кнопок
        if (buttonBPressed) {
            btnB++;
        } else {
            btnB = 0;
        }
        if (buttonCPressed) {
            btnC++;
        } else {
            btnC = 0;
        }
        if (buttonDPressed) {
            btnD++;
        } else {
            btnD = 0;
        }
        // Проверка нажатий и выполнение действий
        if (btnB > threshold) {
            executeSelectedOption(selectedIndex);
            btnB = 0; // Сбрасываем счетчик после выполнения
        } 
        if (btnC > threshold) {
            selectedIndex--;
            if (selectedIndex < 0) {
                selectedIndex = menuCount - 1; // Зацикливаем вниз
            }
            if (lastSelectedIndex != selectedIndex) {
                showMenu(selectedIndex); // Обновляем меню
                lastSelectedIndex = selectedIndex; // Обновляем индекс
            }
            btnC = 0; // Сбрасываем счетчик
        } 
        if (btnD > threshold) {
            selectedIndex++;
            if (selectedIndex >= menuCount) {
                selectedIndex = 0; // Зацикливаем вверх
            }
            if (lastSelectedIndex != selectedIndex) {
                showMenu(selectedIndex); // Обновляем меню
                lastSelectedIndex = selectedIndex; // Обновляем индекс
            }
            btnD = 0; // Сбрасываем счетчик
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
            //debug();
            break;
        case 2:
            //status_loop();
            break;
        case 3:
            displayTime();
            break;
        case 4:
            tama_draw();
            break;
        case 5:
            game_loop();
            break;
        default:
            break;
    }
    showMenu(selectedIndex); // Вернуться к меню
}
