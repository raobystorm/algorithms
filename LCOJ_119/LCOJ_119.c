int *getRow(int rowIndex) {
 
  rowIndex++;
  int* row = (int*)malloc(sizeof(int) * rowIndex);
  int prev1 = 1, prev2 = 1;
  for(int i = 0; i < rowIndex; i++){
 
    for(int j = i; j >= 0; j--){

      if( j == i ) row[j] = 1;
      else row[j] += row[j-1];
    }
  }
  
  return row;
}
