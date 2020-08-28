#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std; 

const int GRID_SIZE = 10; 

typedef struct {
    int x; 
    int y; 
    bool isHoriz; 
    int len; 
} placement; 
bool sortLongestFirst(const placement& left, const placement& right){
    if (left.len != right.len) return left.len > right.len; 
    if (left.x != right.x) return left.x < right.x; 
    return left.y < right.y; 
}

bool longfirst(const string& left, const string& right){
    return left.length() > right.length(); 
}

bool solve(const vector<vector<char> >& grid, 
    const vector<placement>& spots, 
    const vector<string>& words){

    if (words.empty() && spots.empty()){
        for(int i=0; i<GRID_SIZE; i++){
            for(int j=0; j<GRID_SIZE; j++){
                cout << grid[i][j]; 
            }
            cout << endl; 
        }
        return true; 
    }
    if (words.empty() || spots.empty()) return false; 
    if (words[0].length() != spots[0].len) return false; 
    vector<placement> spots2(spots.begin()+1, spots.end()); 
    vector<string> words2; 
    for(int i=0; i<words.size(); i++){
        const string& w = words[i]; 
        vector<vector<char> > g2 = grid; 
        int x = spots[0].x; 
        int y = spots[0].y; 
        bool valid = true; 
        for(int l = 0; l<spots[0].len; l++){
            if (g2[x][y]=='-' || g2[x][y]==w[l]){
                g2[x][y] = w[l]; 
            } else {
                valid = false; 
                break; 
            }
            if (spots[0].isHoriz) y++; 
            else x++; 
        }
        if (!valid) continue; 

        words2.clear(); 
        for(int i2=0; i2<i; i2++)              words2.push_back(words[i2]); 
        for(int i2=i+1; i2<words.size(); i2++) words2.push_back(words[i2]); 
        if (solve(g2, spots2, words2)) return true; 
    }
    return false; 
}

int main(void){
    vector<vector<char> > grid(GRID_SIZE, vector<char>(GRID_SIZE)); 
    for(int i=0; i<GRID_SIZE; i++){
        string line; 
        cin >> line; 
        for(int j=0; j<GRID_SIZE; j++){
            grid[i][j] = line[j]; 
        }
    }
    string wordline; 
    cin >> wordline; 
    vector<string> words; 
    wordline+=";"; 
    istringstream iss(wordline); 
    string item; 
    while(getline(iss, item, ';')) words.push_back(item); 

    vector<placement> spots; 
    placement empty_spot; 
    for(int i=0; i<GRID_SIZE; i++){
        int gap_start = -1; 
        int gap_len = -1; 
        for(int j=0; j<GRID_SIZE; j++){
            if (grid[i][j]=='-'){
                if (gap_start>=0) gap_len++; 
                else {
                    gap_start = j; 
                    gap_len = 1; 
                }
            } else {
                if (gap_len>1){
                    empty_spot.x = i; 
                    empty_spot.y = gap_start; 
                    empty_spot.isHoriz = true; 
                    empty_spot.len = gap_len; 
                    spots.push_back(empty_spot); 
                }
                gap_start = -1; 
                gap_len = -1; 
            }
        }
        if (gap_len>1){
            empty_spot.x = i; 
            empty_spot.y = gap_start; 
            empty_spot.isHoriz = true; 
            empty_spot.len = gap_len; 
            spots.push_back(empty_spot); 
        }
    }
    for(int j=0; j<GRID_SIZE; j++){
        int gap_start = -1; 
        int gap_len = -1; 
        for(int i=0; i<GRID_SIZE; i++){
            if (grid[i][j]=='-'){
                if (gap_start>=0) gap_len++; 
                else {
                    gap_start = i; 
                    gap_len = 1; 
                }
            } else {
                if (gap_len>1){
                    empty_spot.x = gap_start; 
                    empty_spot.y = j; 
                    empty_spot.isHoriz = false; 
                    empty_spot.len = gap_len; 
                    spots.push_back(empty_spot); 
                }
                gap_start = -1; 
                gap_len = -1; 
            }
        }
        if (gap_len>1){
            empty_spot.x = gap_start; 
            empty_spot.y = j; 
            empty_spot.isHoriz = false; 
            empty_spot.len = gap_len; 
            spots.push_back(empty_spot); 
        }
    }
    sort(spots.begin(), spots.end(), sortLongestFirst); 
    sort(words.begin(), words.end(), longfirst); 
    solve(grid, spots, words); 
    return 0; 
}
