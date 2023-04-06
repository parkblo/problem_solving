#include <string>
#include <vector>

using namespace std;

int ret = 0;

void dfs(vector<int> numbers, int count, int curr, int target)
{
    if (count == numbers.size()) {
        if (curr == target) ret++;
        return;
    }
    
    dfs(numbers,count+1, curr+numbers[count], target);
    dfs(numbers,count+1, curr-numbers[count], target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers,0,0,target);
    
    answer = ret;
    return answer;
}
