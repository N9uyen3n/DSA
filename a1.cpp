#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Block {
    int h, L, c; // h: chiều cao khối, c: số lượng khối, L: giới hạn độ cao của khối
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<Block> blocks(n);
    int sumH = 0; // tổng chiều cao tối đa có thể có (nếu dùng hết tất cả các khối)
    for (int i = 0; i < n; i++){
        cin >> blocks[i].h >> blocks[i].L >> blocks[i].c;
        sumH += blocks[i].h * blocks[i].c;
    }
    
    // Bước 1: Sắp xếp các loại khối theo giới hạn độ cao L tăng dần
    sort(blocks.begin(), blocks.end(), [](const Block &a, const Block &b){
        return a.L < b.L;
    });
    
    // dp[x] = true nếu có thể xây được tháp có chiều cao chính xác x
    vector<bool> dp(sumH + 1, false);
    dp[0] = true;
    int ans = 0; // lưu trữ chiều cao tháp tối đa đạt được

    // Bước 2: Duyệt qua từng loại khối (đã sắp xếp theo L)
    // Với mỗi loại khối, chỉ cho phép thêm khối vào các trạng thái có chiều cao không vượt quá L (giới hạn của loại khối hiện tại)
    for (auto b : blocks){
        int h = b.h, c = b.c, L = b.L;
        // Duyệt từ L về 0 (đi ngược giúp đảm bảo không dùng cùng một khối nhiều lần trong vòng lặp)
        for (int x = L; x >= 0; x--){
            if (dp[x]){ // nếu có thể xây được tháp có chiều cao x
                // Thử thêm từ 1 đến c khối loại hiện tại, với điều kiện tổng chiều cao không vượt quá L của loại khối này
                for (int k = 1; k <= c; k++){
                    int newH = x + k * h;
                    if (newH > L) break;  // nếu vượt quá giới hạn của khối hiện tại thì dừng
                    if (newH <= sumH) {
                        dp[newH] = true;
                        ans = max(ans, newH);
                    }
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
