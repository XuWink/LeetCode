#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int l, r, k, x;
        cin >> l >> r >> k >> x;
        if (l > r || k - 1 < x) {
            std::cout << "输入错误" << std::endl;
            continue;
        }
        int start = r + 1;
        for (int i = l; i <= r; ++i) {
            if (i % k == x) {
                start = i;
                break;
            }
        }
        if (start > r) {
            std::cout << 0 << std::endl;
            continue;
        }
        int end = 0;
        for (int i = r; i >= l; --i) {
            if (i % k == x) {
                end = i;
                break;
            }
        }
        if (end == 0) {
            std::cout << 0 << std::endl;
            continue;
        }

        int count = (end - start) / k + 1;
        std::cout << count << std::endl;
    }
}

/*

输入：
3
1 5 2 1
10 20 3 2
1 114514 2 0

输出：
3
4
57257

*/