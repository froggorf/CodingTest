#include <string>
#include <vector>

using namespace std;

std::vector<std::vector<int>> Matrix;
int Rotate(const std::vector<int>& Query){
    int x1 = Query[0];
    int y1 = Query[1];
    int x2 = Query[2];
    int y2 = Query[3];
    x1-=1;
    y1-=1;
    x2-=1;
    y2-=1;
    
    int x1y1Value = Matrix[x1][y1];
    int MinValue = x1y1Value;
    // 왼쪽라인부터 쭉 옮기고
    {
        for(int x = x1; x < x2; ++x){
            Matrix[x][y1] = Matrix[x+1][y1];
            MinValue = std::min(MinValue, Matrix[x][y1]);
        }
    }
    
    // 아래라인 쭉 옮기고
    {
        for(int y = y1; y < y2; ++y){
            Matrix[x2][y] = Matrix[x2][y+1];
            MinValue = std::min(MinValue, Matrix[x2][y]);
        }
    }
    
    // 오른쪽 라인 쭉 옮기고
    {
        for(int x = x2; x > x1; --x){
            Matrix[x][y2] = Matrix[x-1][y2];
            MinValue = std::min(MinValue, Matrix[x][y2]);
        }
    }
    
    // 위쪽 라인 쭉 옮기는데, 1칸 적게 옮겨야함
    {
        for(int y = y2; y > y1+1; --y){
            Matrix[x1][y] = Matrix[x1][y-1];
            MinValue = std::min(MinValue, Matrix[x1][y]);
        }
    }
    
    Matrix[x1][y1+1] = x1y1Value;
    
    return MinValue;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    // 시뮬레이션인데..
    // 1회 회전당 row*2번, col*2번 발생함
    // 그럼 1회 회전당 최대 400번의 작업이 발생하는데
    // 쿼리가 10000회이므로 4'000'000, 즉 시간안에 도달함
    // 이건 그냥 해도 되는 시뮬레이션임
    Matrix = std::vector<std::vector<int>>(rows, std::vector<int>(columns));
    int Num = 1;
    for(int x = 0; x < rows; ++x){
        for(int y = 0; y < columns; ++y){
            Matrix[x][y] = Num++;
        }
    }
    
    vector<int> answer;
    answer.reserve(queries.size());
    for(const std::vector<int>& Query : queries){
        answer.emplace_back(Rotate(Query));
    }
    
    return answer;
}