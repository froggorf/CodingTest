#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int Answer = 0;
    
    while(true){
        std::vector<std::vector<bool>> Deleted(m, std::vector<bool>(n, false));
        bool bIsDeleted = false;
        // 제거할거를 찾아 메모한다.
        for(int x = 0; x < m-1; ++x){
            for(int y = 0; y < n-1; ++y){
                if(board[x][y] == '@'){
                    continue;
                }
                
                // 2x2로 같다면
                if(board[x][y] == board[x][y+1] 
                   && board[x][y] == board[x][y+1] 
                   && board[x][y] == board[x+1][y] 
                   && board[x][y] == board[x+1][y+1] )
                {
                    Deleted[x][y] = true;
                    Deleted[x+1][y] = true;
                    Deleted[x][y+1] = true;
                    Deleted[x+1][y+1] = true;
                    bIsDeleted = true;
                }
            }
            
            
        }
        
        if(!bIsDeleted){
            break;
        }
        
        // 제거할 애를 제거한다.
        for(int x = 0; x < m; ++x){
            for(int y = 0; y < n; ++y){
                if(Deleted[x][y]){
                    board[x][y] = '@';
                    ++Answer;
                }        
            }
        }
        
        // 스택에다가 순서대로 담은다음에
        std::vector<std::stack<char>> S(n);
        for(int x = 0; x < m; ++x){
            for(int y = 0; y < n; ++y){
                if(board[x][y] != '@'){
                    S[y].emplace(board[x][y]);
                }
            }
        }
        
        // 재배치한다.
        for(int x = m-1; x >= 0; --x){
            for(int y = 0; y < n; ++y){
                if(S[y].empty()){
                    board[x][y] = '@';
                }
                else{
                    board[x][y] = S[y].top();
                    S[y].pop();
                }
            }
        }
        
    }
    
    return Answer;
}