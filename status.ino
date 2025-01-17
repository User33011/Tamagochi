static void displayValue(int value, int row) {
    oled.setCursorXY(50, row);
    oled.print(value);
    if (value < 10) {
        oled.setCursorXY(55, row);
        oled.print(" ");
    }
}
void status_loop() {
    while (true) {
        const int btnA = digitalRead(BUTTON_A);
        oled.clear();
        oled.drawBitmap(0, 0, stats, 48, 64, BITMAP_NORMAL, BUF_ADD);
        oled.setCursorXY(64, 0);
        oled.print("Мес.");
        // Печать значений
        displayValue(tama.food, 0);
        displayValue(tama.water, 8);
        displayValue(tama.game, 16);
        displayValue(tama.sleep, 24);
        displayValue(tama.shit, 32);
        displayValue(tama.health, 40);
        displayValue(tama.happiness, 48);
        displayValue(tama.age, 56);
        oled.update();
        // Обновление состояния раз в 2000 мс
        if (lifetimer >= 2000) {
            lifetimer = 0;
            tama_loop();
        } 
        if (!btnA) break;
    }
}
