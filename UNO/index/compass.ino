int compass(int i, int turn) {
  // i - compass current value
  // turn - new turn direction
  // 1 - North
  // 2 - East
  // 3 - West
  // 4 - South
  // turn 1 = left
  // turn 2 = right
  switch (turn) {
    case 1:
      switch (i) {
        case 1:
          i = 3;
          break;
        case 2:
          i = 1;
          break;
        case 3:
          i = 4;
          break;
        case 4:
          i = 2;
          break;
      }
      break;
    case 2:
      switch (i) {
        case 1:
          i = 2;
          break;
        case 2:
          i = 4;
          break;
        case 3:
          i = 1;
          break;
        case 4:
          i = 3;
          break;
      }
      break;
  }
  return i;
}

