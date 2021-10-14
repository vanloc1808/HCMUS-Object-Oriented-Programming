#include <iostream>
#include <vector>

using namespace std;

class HocSinh {
private:
    char* m_hoTen;
    float m_diemVan;
    float m_diemToan;

public:
    float tinhDTB() {
        return (this->m_diemToan + m_diemVan) / 2;
    }

    int xepLoai() {
        if (this->tinhDTB() >= 8) {
            return 1;
        }
        return 0;
    }

    void xuat() {
        cout << this->m_hoTen << " " << this->m_diemToan << " " << this->m_diemVan << "\n";
    }
};

class BangDiem {
private:
    vector<HocSinh> m_danhSach;

public:
    vector<HocSinh> xuatdsHSG() {
        vector<HocSinh> ans;
        for (int i = 0; i < this->m_danhSach.size(); i++) {
            if (this->m_danhSach[i].xepLoai() == 1) {
                ans.push_back(this->m_danhSach[i]);
            }
        }

        return ans;
    }

};