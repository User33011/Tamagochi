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
        if (!button.A && !button.flag && millis() - button.timer > 200) {
            button.flag = true;
            button.timer = millis();
            break;
            // Переход вниз по строкам.
        } else if (!button.D && !button.flag && millis() - button.timer > 200) {
            button.flag = true;
            button.timer = millis();
            currentCondition = (currentCondition - 1) % NUM_PET_CONDITIONS;
            if(currentCondition <= 0){
              currentCondition = 0;
            }
            // Влево.
        } else if (!button.C && !button.flag && millis() - button.timer > 200) {
            button.flag = true;
            button.timer = millis();
            currentCondition = (currentCondition + 1) % NUM_PET_CONDITIONS;
             // Вправо.
        } else if (!button.B && !button.flag && millis() - button.timer > 200) {
            button.flag = true;
            button.timer = millis();
            SelectedOption(currentCondition);
            break;
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
            break;
        case 1:
            goSleep();
            break;
        case 2:
            medical();
            break;
        case 3:
            bullShit();
            break;
        case 4:
            drink();
            break;
        case 5:
            playGame();
            break;
        case 6:
            ventilation();
            break;
        case 7:
            perhead();
            break;
        default:
            break;
    }
    
}