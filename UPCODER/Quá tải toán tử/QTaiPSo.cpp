#include <bits/stdc++.h>    // Thư viện tổng trong C++, dùng khi hong nhớ từng thư viện đơn
using namespace std;

// Bé nhớ: Viết toán tử trong struct giúp giảm 1 tham số (do toán hạng trái chính là bản thân struct đang gọi), riêng toán tử nhập/xuất (>>, <<) bắt buộc phải nằm ngoài nhe.
struct ps
{
    int tu, mau; 
    // Hàm rút gọn phân số 
    ps rg()      
    {
        int uoc = __gcd(tu, mau);     // Hàm có sẵn của C++ để tìm Ước chung lớn nhất!
        tu /= uoc;
        mau /= uoc;
        // Luôn đẩy dấu trừ lên tử nếu mẫu âm (Ví dụ: 1/-2 sẽ thành -1/2) để lát nữa so sánh 2 ps hong bị sai nhe
        if(mau < 0)
        {
            tu = -tu;
            mau = -mau;
        }
        return *this;                 // Trả về chính ps này sau khi đã đc rút gọn
    }
    
    // Toán tử CỘNG: Phân số hiện tại (t, m) + Phân số a (a.t, a.m)
    ps operator + (ps a) 
    {
        ps res;
        // Công thức quy đồng cơ bản: (t1*m2 + t2*m1) / (m1*m2)
        res.tu = t*a.mau + a.tu*m;
        res.mau = m*a.mau;
        return res.rg(); // Tính xong nhớ gọi hàm rg() để rút gọn luôn trước khi trả về kết quả
    }
    
    // Toán tử BẰNG: 2 ps = nhau khi tử = tử, mẫu = mẫu (áp dụng khi cả 2 đã được rút gọn)
    bool operator == (ps a)
    {
        return t==a.tu && m==a.mau;
    }
    
    // Toán tử KHÁC: Là phủ định của toán tử BẰNG
    bool operator != (ps a)
    {
        // Bé có thể viết gọn như dưới đây để xài lại code của toán tử == ở trên
        return !(t==a.t && m==a.m);
    }
};

// BÉ LƯU Ý CHỖ NÀY: Phải có dấu '&' ở (ps &t) vì mình nhập dữ liệu xong thì ps t phải thay đổi (để lưu lại giá trị mới cất vào bộ nhớ)
istream& operator >> (istream &in, ps &t)
{
    in>>t.tu>>t.mau;
    k.rg(); // Vừa nhập xong là tự động cho rút gọn luôn nhe
    return in;
}

// Toán tử XUẤT (in ra màn hình) không làm thay đổi phân số gốc nên không cần dấu '&' cũng được nhe
ostream& operator << (ostream &out, ps t)
{
    out<<t.tu<<"/"<<t.mau;
    return out;
}

int main()
{
    ps a, b;
    cin>>a>>b;
    cout<<a+b;
    return 0;
}
