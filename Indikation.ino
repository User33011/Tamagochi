void drawFrame(int x, int y) {
    oled.rect(x - 2, y - 2, x +26, y+26, OLED_STROKE);
}
void indikat() {
    const int itemCount = 8;
    while (true) {
        oled.clear();
        button.flag = false;
        button.A = digitalRead(BUTTON_A);
        button.B = digitalRead(BUTTON_B);
        button.C = digitalRead(BUTTON_C);
        button.D = digitalRead(BUTTON_D);
        
        // Навигация по иконкам
        // Переход вверх по строкам.
        if (!button.A && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();
            break;
        } else if (!button.B && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();
            SelectedOption(currentCondition);
            break;
        } else if (!button.C && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();
            currentCondition = (currentCondition + 1) % NUM_PET_CONDITIONS;
        } else if (!button.D && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();
            currentCondition = (currentCondition - 1) % NUM_PET_CONDITIONS;
            if  (currentCondition < 0) currentCondition = MAX_ICONS;
        } else {
            button.flag = false; // Сброс флага при отсутствии нажатий.
            button.timer = millis();
        }
        
        // Отрисовка иконок============================================
        for (int i = 0; i < itemCount; i++) {
            int index = i; // В данном случае просто копируем индекс, так как мы отображаем все иконки.
            int x = 5 + (i % 4) * (24 + 5); // 4 иконки по X
            int y = 5 + (i / 4) * (24 + 5); // 2 ряда по Y

            // Отображение иконки на экране.
            oled.drawBitmap(x, y, petConditions[index].icon, 24, 24, BITMAP_NORMAL, BUF_ADD);
            if (index == currentCondition) {
                drawFrame(x, y); // Рамка вокруг активного состояния.
            }
        }
        //=============================================================
        // Если это текущая иконка, отобразить рамку.
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
           playGame();
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
