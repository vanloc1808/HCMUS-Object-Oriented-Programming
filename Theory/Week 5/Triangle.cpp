class Diem {
private:
    float m_X;
    float m_Y;

public: 
    Diem() {
        this->m_X = 0;
        this->m_Y = 0;
    }

    Diem (float x, float y) {
        
    }

    Diem trongTamTamGiac(Diem a, Diem b) {
        float sigmaX = this->m_X + a.m_X + b.m_X;
        float sigmaY = this->m_Y + a.m_Y + b.m_Y;

        Diem ans;
        ans.m_X = sigmaX / 3;
        ans.m_Y = sigmaY / 3;

        return ans;
    }
};

class TamGiac {
private:
    Diem m_A;
    Diem m_B;
    Diem m_C;

public:
    Diem trongTam() {
        Diem ans = m_A.trongTamTamGiac(m_B, m_C);
    }
};

int main() {
    
}