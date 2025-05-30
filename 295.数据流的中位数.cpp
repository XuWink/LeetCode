#include <iostream>

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (que_left.empty() || num < que_left.top()) {
            que_left.push(num);
            if (que_left.size() > que_right.size() + 1) {
                que_right.push(que_left.top());
                que_left.pop();
            }
        } else {
            que_right.push(num);
            if (que_left.size() < que_right.size()) {
                que_left.push(que_right.top());
                que_right.pop();
            }
        }
    }
    
    double findMedian() {
        if (que_left.size() > que_right.size()) {
            return que_left.top();  
        }

        return (que_left.top() + que_right.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, greater<int>> que_right; //用来存放大于中位数
    priority_queue<int, vector<int>, less<int>> que_left; //用来存放小于中位数
};

/*
中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

例如 arr = [2,3,4] 的中位数是 3 。
例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
实现 MedianFinder 类:

MedianFinder() 初始化 MedianFinder 对象。

void addNum(int num) 将数据流中的整数 num 添加到数据结构中。

double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

示例 1：

输入
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
输出
[null, null, null, 1.5, null, 2.0]

*/