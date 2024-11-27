void displayPetIcons() {
    int offsetX = 52; // Начальная позиция по X
    int offsetY = 0; // Начальная позиция по Y
    
    // Отображаем иконки в зависимости от активных состояний
    for (int i = currentStartIndex; i < currentStartIndex + menuCount && i < activeCount; i++) {
        for (int j = 0; j < conditionCount; j++) {
            if (activeStates[i] == petConditions[j].state) {
                oled.drawBitmap(offsetX, offsetY, petConditions[j].icon, 24, 24, BITMAP_NORMAL, BUF_ADD);
                
                // Рисуем рамку вокруг активной иконки
                //if (i == currentStartIndex) { // Здесь можно использовать currentCondition, если актуально
                //    drawFrame(offsetX, offsetY);
                //}
                
                offsetX += 25; // Сдвигаемся вправо
                if (offsetX >= ICON_WIDTH * 5) { // Если достигли конца строки
                    offsetX = 52; // Сбрасываем X
                    offsetY += 25; // Переходим на следующую строку
                }
                break; // Выходим из цикла, если иконка найдена
            }
        }
    }
//    oled.update(); // Обновляем экран
}

void scrollIcon() {
    // Сдвигаем текущий индекс для скролла
    if (currentStartIndex < activeCount - 1) {
        currentStartIndex++;
    } else {
        currentStartIndex = 0; // Зацикливаем
    }
    displayPetIcons(); // Перерисовываем иконки
}
/*
void displayPetIcons() {
  int offsetX = 52;
  int offsetY = 0;
  for (int i = currentStartIndex; i < currentStartIndex + menuCount && i < activeCount; i++) {
    for (int j = 0; j < conditionCount; j++) {
      if (activeStates[i] == petConditions[j].state) {
          oled.drawBitmap(offsetX, offsetY, petConditions[j].icon, 24, 24, BITMAP_NORMAL, BUF_ADD);
        offsetX += 25; 
          if (offsetX >= ICON_WIDTH * 5) {                // Проверяем, нужно ли перенести на следующую строку
            offsetX = 52;
            offsetY += 25;
          }
    break;                                                // Выходим из внутреннего цикла после отображения иконки
      }
    }
  }
}
*/
void scrollUp() {
    if (currentStartIndex > 0) {
        currentStartIndex--;
        displayPetIcons(); // Перерисовываем иконки
    }
}
void scrollDown() {
    if (currentStartIndex + menuCount < activeCount) {
        currentStartIndex++;
        displayPetIcons(); // Перерисовываем иконки
    }
}
void updateActiveStates(PetState newState) {
  for (int i = 0; i < activeCount; i++) {                   // Проверяем, есть ли уже это состояние
    if (activeStates[i] == newState) 
    return;                                                 // Состояние уже активно
  }
    if (activeCount < MAX_ICONS) {                          // Добавляем новое состояние, если есть место
        activeStates[activeCount++] = newState;
  }
}
void resetSpecificState(PetState stateToReset) {
  for (int i = 0; i < activeCount; i++) {
    if (activeStates[i] == stateToReset) {
      activeStates[i] = PetState::INACTIVE;                  // Устанавливаем состояние в неактивное
      activeCount--;                                         // Уменьшаем счетчик активных состояний
        for (int j = i; j < activeCount; j++) {              // Сдвигаем массив, чтобы избежать пустого места
          activeStates[j] = activeStates[j + 1];
        }
        break;                                               // Прерываем цикл, так как одно состояние было обнулено
    }
  }
}
void resetActiveStates() {
    activeCount = 0;                                         // Очищаем активные состояния
}
