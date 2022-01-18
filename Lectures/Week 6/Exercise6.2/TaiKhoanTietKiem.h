#ifndef _TAIKHOANTIETKIEM_H
#define _TAIKHOANTIETKIEM_H

#include "TaiKhoan.h"
#include <cmath>

class TaiKhoanTietKiem : public TaiKhoan {
private:
    int m_kyHanGui; //tinh bang nam

    float m_laiSuat; // lai suat tinh theo nam

    int m_soThangDaGui;

public:
    void napTien(float soTien) {
        int soDuHienTai = baoSoDu();

        int tienLai = soDuHienTai * pow((1 + m_laiSuat), (m_soThangDaGui / 12) + (m_soThangDaGui % 12));

        TaiKhoan::napTien(soTien + tienLai);

        m_soThangDaGui = 0;
    }

    bool rutTien(float soTien) {
        int soDuHienTai = baoSoDu();

        int tienLai = soDuHienTai * pow((1 + m_laiSuat), (m_soThangDaGui / 12) + (m_soThangDaGui % 12));

        TaiKhoan::napTien(tienLai);

        if (TaiKhoan::rutTien(soTien)) {
            m_soThangDaGui = 0;

            return true;
        }

        return false;
    }

    void tangSoThangDaGui(int soThang) {
        if (soThang > 0) {
            m_soThangDaGui += soThang;
        }
    }
};

#endif