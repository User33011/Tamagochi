/*___________________________________________________________________________
  |Эта функция использовалась ранее, в качестве обработчика нажатия кнопок. |
  |Впоследствии я от нее отказался, но не стал удалять из проекта.          |                                                                |
  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

void button_loop(){
  button.flag = false;
  button.A = digitalRead(BUTTON_A);
  button.B = digitalRead(BUTTON_B);
  button.C = digitalRead(BUTTON_C);
  button.D = digitalRead(BUTTON_D);
  
  if (!button.A && !button.flag && millis() - button.timer > 100) {
    button.flag = true;
    button.timer = millis();
    oled.clear();
    debug();
  }
  else if (!button.B && !button.flag && millis() - button.timer > 100) {
    button.flag = true;
    button.timer = millis();
    oled.clear();
  }
  else if (!button.C && !button.flag && millis() - button.timer > 100) {
    button.flag = true;
    button.timer = millis();
    oled.clear();
    bot_loop();
  }
  else if (!button.D && !button.flag && millis() - button.timer > 100) {
    button.flag = true;
    button.timer = millis();
    updateActiveStates(HUNGRY);
    updateActiveStates(SLEEPY);
    updateActiveStates(HEALTH);
    updateActiveStates(SHIT);
    updateActiveStates(THIRSTY);
    updateActiveStates(PLAY);
  }
  else {
    button.flag = false;
    button.timer = millis();
    }
}
        if (!button.A && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();break;
            selectedRow = max(0, selectedRow - 1);
            currentCondition = (currentCondition - 4 + NUM_PET_CONDITIONS) % NUM_PET_CONDITIONS;
            // Переход вниз по строкам.
        } else if (!button.B && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();
            selectedRow = min((NUM_PET_CONDITIONS / 4) - 1, selectedRow + 1);
            currentCondition = (currentCondition + 4) % NUM_PET_CONDITIONS;
            // Влево.
        } else if (!button.C && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();
            currentCondition = (currentCondition + 1) % NUM_PET_CONDITIONS;
             // Вправо.
        } else if (!button.D && !button.flag && millis() - button.timer > 100) {
            button.flag = true;
            button.timer = millis();
            currentCondition = (currentCondition - 1 + NUM_PET_CONDITIONS) % NUM_PET_CONDITIONS;
    //        bot_loop(); // Вызов функции выбора иконки.
    //        break; // Завершить цикл после выбора.
            // Выход.
        } else {
            button.flag = false; // Сброс флага при отсутствии нажатий.
            button.timer = millis();
        }
*/