#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int h, c, l; // h: chiều cao khối, c: số lượng khối, l: giới hạn độ cao
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, sumH = 0, maxHeight = 0;
    cin >> k;
    
    vector<Block> blocks(k);
    
    for (int i = 0; i < k; ++i) {
        cin >> blocks[i].h >> blocks[i].l >> blocks[i].c;
        sumH += blocks[i].h * blocks[i].c;
    }

    // Sắp xếp các khối theo giới hạn độ cao l tăng dần
    sort(blocks.begin(), blocks.end(), [](const Block &a, const Block &b) {
        return a.l < b.l;
    });

    vector<bool> dp(sumH + 1, false);
    dp[0] = true;

    for (auto b : blocks) {
        int d = b.h, e = b.c, f = b.l;
        
        for (int i = f; i >= 0; i--) {
            if (dp[i]) {
                for (int k = 1; k <= e; ++k) { // Chỉ sử dụng tối đa e khối
                    int newH = i + k * d;
                    if (newH > f) break;
                    if (newH <= sumH) {
                        dp[newH] = true;
                        maxHeight = max(maxHeight, newH);
                    }
                }
            }
        }
    }

    cout << maxHeight << "\n";
    return 0;
}
