void byte_draw() {
    oled.clear(); // Очистка OLED экрана
    int coord_X = 0;
    int coord_Y = 0;

    // Цикл по всем строкам (блокам по 8 пикселей высотой)
    for (int i = 0; i < SCREEN_HEIGHT / 8; i++) {
        coord_Y = i * 8; // Позиционируем Y координату

        // Цикл по всем колонкам
        for (coord_X = 0; coord_X < SCREEN_WIDTH; coord_X += 8) {
            // Отрисовка байтовых данных
            oled.setCursorXY(coord_X, coord_Y); 
            oled.drawByte(0b10011001); 
            oled.drawByte(0b10111101);
            oled.drawByte(0b01011010); 
            oled.drawByte(0b01111110);
            oled.drawByte(0b01000010); 
            oled.drawByte(0b00111100);
            oled.drawByte(0b11011011); 
            oled.drawByte(0b10000001);  
        }
    }
    oled.update(); // Обновляем экран после отрисовки
    if(lifetimer >= 4000){
      lifetimer = 0;
      bot_loop();
      } else {
        byte_draw();
      }

}