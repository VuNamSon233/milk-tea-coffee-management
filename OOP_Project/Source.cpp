#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class NhanVien {
private:
public:
	string TenNhanVien;
	int NamSinh;
	int Tuoi;
	string HinhThucLamViec; // full-time or part-time
	float HeSoLuong;
	void Nhap();
	void Xuat();
};
void NhanVien::Nhap()
{
	cout << "Ten: ";
	fflush(stdin);
	cin >> TenNhanVien;
	cout << "Xin moi nhap tuoi: ";
	cin >> Tuoi;
}
void NhanVien::Xuat()
{
	cout << TenNhanVien <<" " << Tuoi;
}
class NguyenLieu {
public:

};

void main()
{
	
	
}