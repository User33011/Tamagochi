void tama_loop() {
    // Считываем сенсоры
    sensor_read();  
    
    // Уменьшаем каждый из показателей
    tama.sleep--;
    tama.food--;
    tama.water--;
    tama.game--;
    tama.shit--;
    tama.day++;
    // Возраст
    if (tama.day >= 365) {
      tama.age++;
      tama.day = 0;
      }
    // Защита от отрицательных значений
    if (tama.sleep <= 0) tama.sleep = 0; 
    if (tama.food <= 0) tama.food = 0; 
    if (tama.water <= 0) tama.water = 0; 
    if (tama.game <= 0) tama.game = 0; 
    if (tama.shit <= 0) tama.shit = 0;
    // Защита от превышения
    if (tama.sleep >= 99) tama.sleep = 99; 
    if (tama.food >= 99) tama.food = 99; 
    if (tama.water >= 99) tama.water = 99; 
    if (tama.game >= 99) tama.game = 99; 
    if (tama.shit >= 99) tama.shit = 99;
    // Рассчитываем коэффициент счастья
    // Уменьшение счастья из-за нехватки еды, воды и сна
    tama.happiness -= (tama.food < 50) > 0 ? 2 : 0;   // Уменьшение из-за еды
    tama.happiness -= (tama.shit < 50) > 0 ? 3 : 0;   // Уменьшение из-за туалета
    tama.happiness -= (tama.water < 50) > 0 ? 2 : 0;  // Уменьшение из-за воды
    tama.happiness -= (tama.sleep < 50) > 0 ? 3 : 0;  // Уменьшение из-за сна
    tama.happiness -= (tama.game < 50) > 0 ? 1 : 0;   // Уменьшение из-за игры
    tama.happiness -= (tama.health < 50) > 0 ? 3 : 0; // Уменьшение из-за здоровья

    if (tama.happiness <= 0) tama.happiness = 0;
    if (tama.happiness >= 99) tama.happiness = 99;

    // Проверка состояния питомца
    if (tama.sleep == 0 && !tama.SleepFlag) {
        tama.SleepFlag = true;
        tama.state = ST_SLEEPING; // Если нет очков сна
    } else if (tama.happiness >= 80) {
        tama.state = ST_HAPPY;    // Питомец счастлив
    } else if (tama.happiness < 50 || tama.health < 50) {
        tama.state = ST_SAD;      // Питомец грустит
    } else {
        tama.state = ST_OK;       // Питомец в норме
    }

    // Логика изменения здоровья
    tama.health -= (tama.food < 30) > 0 ? 2 : 0;  // Уменьшение из-за еды
    tama.health -= (tama.shit < 30) > 0 ? 3 : 0;  // Уменьшение из-за туалета
    tama.health -= (tama.water < 30) > 0 ? 2 : 0; // Уменьшение из-за воды
    tama.health -= (tama.sleep < 30) > 0 ? 3 : 0; // Уменьшение из-за сна

    if (tama.health >= 99) tama.health = 99; 
    if (tama.health <= 0) tama.health = 0; 
    
 /*   if (ST_SLEEPING) {
        tama.sleep ++;    // Добавление очков сна
    }
    */
    if (tama.SleepFlag && tama.sleep >= 30) {
        tama.SleepFlag = false;    // Сняли флаг сна
    }
    if (tama.shit < 40 && !tama.ShitFlag){ 
      updateActiveStates(SHIT);
      tama.ShitFlag = true;
    } 
    if (tama.shit >= 95 && tama.ShitFlag){
      resetSpecificState(SHIT);
    }

    if (tama.food < 40){ 
      updateActiveStates(HUNGRY);
    } else {
      resetSpecificState(HUNGRY);
    }
  
    if (tama.water < 40){ 
      updateActiveStates(THIRSTY);
    } else {
      resetSpecificState(THIRSTY);
    }

    if (tama.sleep < 20){ 
      updateActiveStates(SLEEPY);
    } else {
      resetSpecificState(SLEEPY);
    }

    if (tama.health < 40){ 
      updateActiveStates(HEALTH);
    } else {
      resetSpecificState(HEALTH);
    }

    if (tama.game < 20){ 
      updateActiveStates(PLAY);
    } else {
      resetSpecificState(PLAY);
    }
}
