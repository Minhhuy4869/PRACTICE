#include <iostream>
#include <algorithm>
using namespace std;

// Toán tử =, [], (), và -> BẮT BUỘC phải được khai báo ở BÊN TRONG struct nha bé

struct arr
{
    int n, a[100];
    arr& operator = (arr &t)
    {
        n = t.n; 
        for(int i=0; i<n; ++i)
        {
            a[i] = t[i];        // Copy từng phần tử
        }
        return *this;           // Trả về chính nó nhe 
    }
    int& operator [] (int idx)
    {
        return a[idx];
    }
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
        if(i < h.n) 
            res.a[i] += h.a[i]; // Nếu mảng h còn phần tử thì cộng vào
        if(i < k.n) 
            res.a[i] += k.a[i]; // Nếu mảng k còn phần tử thì cộng vào
    }
    return res;
}

bool operator == (arr t, arr h)
{
    if(t.n != h.n) 
        return false;       // Nếu lệch size thì chắc chắn khác nhau
    for(int i=0; i<t.n; ++i)
    {
        if(t.a[i] != h.a[i])
        {
            return false;   // Chỉ cần 1 phần tử khác là sai lun
        }
    }
    return true;            // Vượt qua hết vòng for nghĩa là giống nhau y đúc
}

bool operator != (arr t, arr h)
{
    return !(t == h);
}

int main()
{
    arr t, h;
    cin>>t>>h;
    if(t == h)
        cout<<"yes";
    else 
        cout<<"no";
    return 0;
}
