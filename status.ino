static void displayValue(int value, int row) {
    oled.setCursor(50, row);
    oled.print(value);
    if (value < 10) {
        oled.setCursor(55, row);
        oled.print(" ");
    }
}
void status_loop() {
    while (true) {
        const int btnA = digitalRead(BUTTON_A);
        oled.clear();

        // Печать заголовков
        const char* titles[] = {"Голод", "Жажда", "Игра", "Сон", "Лоток", "Здоровье"};
        for (int i = 0; i < 6; i++) {
            oled.setCursor(0, i);
            oled.print(titles[i]);
        }

        // Печать значений
        displayValue(tama.food, 0);
        displayValue(tama.water, 1);
        displayValue(tama.game, 2);
        displayValue(tama.sleep, 3);
        displayValue(tama.shit, 4);
        displayValue(tama.health, 5);
        oled.update();
        // Обновление состояния раз в 2000 мс
        if (lifetimer >= 2000) {
            lifetimer = 0;
            tama_loop();
        } 
        if (!btnA) break;
    }
}
