// Cho một dãy các kí tự đại diện cho các công việc mà máy tính phải làm ( các kí tự này là các chữ cái in hoa từ A
//  đến Z)
// . Các chữ cái khác nhau đại diện cho các công việc khác nhau, các công việc có thể được hoàn thành dưới bất kì thứ tự nào. Mỗi giây, máy tính có thể hoàn thành xong một công việc. Hai công việc giống nhau phải được thực hiện tại 2 thời điểm cách nhau ít nhất là n
// . Tính thời gian ít nhất để máy tính có thể hoàn thành hết các công việc.

// Ví dụ: Có 4
//  công việc ('A','A','B',B') và n=3
// . Máy tính cần 5
//  giây để hoàn thành công việc này : A−>B−>nghỉ−>A−>B
// .

// Đầu vào
// Đầu vào từ bàn phím gốm 2
//  dòng. Dòng đầu tiên chứa 2 số nguyên m,n
// . Dòng thứ hai chứa m
//  kí tự đại diện cho m
//  công việc. (m≤105,n≤100)
// .

// Đầu ra
// In ra màn hình thời gian ít nhất để máy tính hoàn thành hết các công việc.


// thao khao solution tai https://leetcode.com/problems/task-scheduler/description/

#include<iostream>
#include <math.h>

using namespace std;


int main(){
    int m, n;
    cin >> m >> n;

    string s;
    cin >> s;

    n = n-1;

    //asdasd
    int counter[26] = {0};
    int vmax = 0;
    int maxCount = 0;

    for(int i=0; i<m; i++) {
        counter[s[i] - 'A']++;
        if(vmax == counter[s[i] - 'A']) {
            maxCount++;
        }
        else if(vmax < counter[s[i] - 'A']) {
            vmax = counter[s[i] - 'A'];
            maxCount = 1;
        }
    }


    int partCount = vmax - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = m - vmax * maxCount;
    int idles = std::max(0, emptySlots - availableTasks);

    cout << m + idles;

}
