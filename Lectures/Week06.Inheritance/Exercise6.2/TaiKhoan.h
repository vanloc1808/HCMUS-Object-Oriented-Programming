#ifndef _TAIKHOAN_H
#define _TAIKHOAN_H

class TaiKhoan{
private:
    float m_soDu;

public:
    float baoSoDu() { return m_soDu; }

    void napTien(float soTien) { m_soDu += soTien; }

    bool rutTien(float soTien) {
        if (soTien <= m_soDu) {
            m_soDu -= soTien;

            return true;
        }

        return false;
    }
};

#endif