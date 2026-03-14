#include <iostream>
#include <algorithm>
using namespace std;

struct arr
{
    int n, a[100];              // mảng a có 100 phần tử cố định  
};

istream& operator >> (istream& in, arr &t)
{
    in>>t.n;                    // nhập số lượng phần tử của mảng
    for(int i=0; i<t.n; ++i)
    {
        in>>t.a[i];
    }
    return in;
}

ostream& operator << (ostream& out, arr t)  // toán tử xuất hong cần tham chiếu &
{
    for(int i=0; i<t.n; ++i)
    {
        out<<t.a[i]<<" ";
    }
    return out;
}

arr operator + (arr h, arr k)
{
    arr res;
    res.n = max(h.n, k.n);      // ở đây phải khai báo thêm thư viện thuật toán algorithm để dùng hàm max nhe
    for(int i=0; i<res.n; ++i)
    {
        res.a[i] = 0;           // Khởi tạo phần tử thứ i = 0 để xún dưới cộng
        if (i < h.n) 
            res.a[i] += h.a[i]; // Nếu mảng h còn phần tử thì cộng vào
        if (i < k.n) 
            res.a[i] += k.a[i]; // Nếu mảng k còn phần tử thì cộng vào
    }
    return res;
}

int main()
{
    arr t, h;
    cin>>t>>h;
    cout<<t+h;
    return 0;
}
