class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char, int> record;
    int i, j, val, k, z;

    for( i = 0; i < 9; i++){
      for( j = 0; j < 9; j++){
        if(board[i][j] == '.') continue; 
        if(record.find(board[i][j]) != record.end()) return false;
        record[board[i][j]] = 1;
      }
      record.clear();
    

    for( j = 0; j < 9; j++){
      for( i = 0; i < 9; i++){
        if(board[i][j] == '.') continue; 
        if(record.find(board[i][j]) != record.end()) return false;
        record[board[i][j]] = 1;
      }
      record.clear();
    }

    for( i = 0; i < 9; i += 3){
      for( j= 0; j < 9; j += 3){
        
        for( k = 0; k < 3; k++){
          for( z = 0; z < 3; z++){
            val = board[i+k][j+z];
            if(val == '.') continue; 
            if(record.find(val) != record.end()) return false;
            record[val] = 1;
          }
        }
        record.clear();
      }
    }

    return true;    
  }
};
