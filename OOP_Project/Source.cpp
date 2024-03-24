#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class nhanvien {
private:
	int Manv, Cmt;
	string hoten, ngaysinh, diachi;
	float luongCB, phucap, thuclinh;
public:
	//xaydung phuongthuc nhap
	void nhap() {
		cin.ignore(1, '\n');
		cout << " \n\nNhap ma nhan vien: "; cin >> Manv; //fflush(stdin); //xoa bo nho dem
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " \nNhap ho ten: "; getline(cin, hoten); //fflush(stdin);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " \nNhap ngay sinh: "; getline(cin, ngaysinh); //fflush(stdin);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " \nNhap dia chi: "; getline(cin, diachi); //fflush(stdin);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " \nNhap so the CMT: "; cin >> Cmt; //fflush(stdin);
		cout << " \nNhap luong co ban: "; cin >> luongCB; //fflush(stdin);
		cout << " \nNhap phu cap: "; cin >> phucap; //fflush(stdin);
		thuclinh = luongCB + phucap;
	}
	//xay dung phuong thuc xuat
	void xuat() {
		cout << setw(10) << Manv << setw(14) << hoten << setw(14) << ngaysinh << setw(10) << diachi;
		cout << setw(12) << Cmt << setw(10) << luongCB << setw(10) << phucap << setw(11) << thuclinh;
	}
	//Lay gia tri thuoc tinh pham vi private
	int get_Manv() {
		return Manv;
	}
	int get_Cmt() {
		return Cmt;
	}
	float get_thuclinh() {
		return thuclinh;
	}
	float get_phucap() {
		return phucap;
	}
	
};
//Nhap n nhanvien
void nhapds(nhanvien nv[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhan vien thu " << i + 1 << "";
		nv[i].nhap();
	}
}
void xuat_file(nhanvien nv[], int n)
{
	//xay dung phuong thuc xuat ra file .txt danh sach nhan vien
	ofstream DSNhanVien("danhsach.txt"); // tạo file danhsach.txt 
	ifstream DSNhanVien_open;
	DSNhanVien_open.open("danhsach.txt");
	DSNhanVien << "\n Manv" << setw(14) << "Ho Ten" << setw(14) << "Ngay Sinh" << setw(10) << "Dia Chi" << setw(11);
	DSNhanVien << "CMT" << setw(10) << "LuongCB" << setw(10) << "Phu Cap" << setw(11) << "Thuc Linh" << setw(12);
	for (int i = 0; i < n; i++)
	{
		
	}
	DSNhanVien.close();
}
//Xuat n nhanvien
void xuatds(nhanvien nv[], int n) {
	cout << "\n Manv" << setw(14) << "Ho Ten" << setw(14) << "Ngay Sinh" << setw(10) << "Dia Chi" << setw(11);
	cout << "CMT" << setw(10) << "LuongCB" << setw(10) << "Phu Cap" << setw(11) << "Thuc Linh" << setw(12);

	for (int i = 0; i < n; i++) {
		nv[i].xuat();
	}
	cout << "Xuat danh sach ra file danhsach.txt...\n";
	xuat_file(nv,n);
	cout << "Xuat file thanh cong. ";
}
//Tim kiem theo ma sinh vien
void timkiemManv(nhanvien nv[], int n) {
	int ma;
	int count = 0;
	cout << " \nNhap ma nhan vien can tim: "; cin >> ma;
	for (int i = 0; i < n; i++) {
		if (nv[i].get_Manv() == ma) { //public ko get.
			nv[i].xuat();
			count++;
		}
	}
	if (count == 0) {
		cout << " \nKhong tim thay Manv can tim.";
	}
}
//Tim kiem theo chung minh thu
void timkiemCmt(nhanvien nv[], int n) {
	int cm;
	int count = 0;
	cout << " \nNhap so CMT nhan vien can tim: "; cin >> cm;
	for (int i = 0; i < n; i++) {
		if (nv[i].get_Cmt() == cm) {
			nv[i].xuat();
			count++;
		}
	}
	if (count == 0) {
		cout << " \nKhong tim thay CMT nhan vien can tim.";
	}
}
//Sap xep luong nhan vien tang dan
void sapxep(nhanvien nv[], int n) {
	nhanvien tg;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nv[i].get_thuclinh() > nv[j].get_thuclinh())
				tg = nv[i];
			nv[i] = nv[j];
			nv[j] = tg;
		}
	}
	cout << " \nSau khi sap xep: " << endl;
	xuatds(nv, n);
}
//Tinh tong luong cac nhan vien trong danh sach
void tongluong(nhanvien nv[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nv[i].get_thuclinh();
	}
	cout << " \nTong luong cua cac nhan vien trong danh sach: " << sum;
}
//Tim nhan vien thu nhap cao nhat
void thuclinhMax(nhanvien nv[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (nv[i].get_thuclinh() > max) {
			max = nv[i].get_thuclinh();
		}
	}
	cout << "Nhan vien co luong cao nhat: " << max;
	//xuatds(nv,n);
}
//Tim phu cap > 100.000 vnd.
void timphucap(nhanvien nv[], int n) {
	cout << "Nhan vien co phu cap > 100.000 vnd:";
	cout << "\n Manv" << setw(14) << "Ho Ten" << setw(14) << "Ngay Sinh" << setw(10) << "Dia Chi" << setw(11);
	cout << "CMT" << setw(10) << "LuongCB" << setw(10) << "Phu Cap" << setw(11) << "Thuc Linh" << setw(12);

	for (int i = 0; i < n; i++) {
		if (nv[i].get_phucap() > 500000) {
			nv[i].xuat();
		}
	}
}

//Xay dung menu chuc nang nhan vien
void menu(nhanvien nv[], int n) {
	int choice;
	do {
		system("cls");
		cout << "================= QUAN LY NHAN VIEN ====================\n";
		cout << "==        1.Nhap danh sach nhan vien.                 ==\n";
		cout << "==        2.Xuat danh sach nhan vien.                 ==\n";
		cout << "==        3.Tim kiem nhan vien theo Manv.             ==\n";
		cout << "==        4.Tim kiem nhan vien theo CMT.              ==\n";
		cout << "==        5.Sap xep luong nhan vien tang dan.         ==\n";
		cout << "==        6.Tinh tong luong cac nhan vien.            ==\n";
		cout << "==        7.Tim kiem nhan vien thu nhap cao nhat.     ==\n";
		cout << "==        8.Tim kiem nhan vien phu cap > 500.000.     ==\n";
		cout << "==        9.Exit                                      ==\n";
		cout << "========================================================\n";
		cout << " \t Nhap lua chon cua ban: "; cin >> choice;
		switch (choice) {
		case 1:
			//cout<<"Nhap so luong nhan vien: ";cin>>n;
			nhapds(nv, n);
			cout << endl;
			system("\npause");
			break;
		case 2:
			xuatds(nv, n);
			cout << endl;
			system("\npause");
			break;
		case 3:
			timkiemManv(nv, n);
			cout << endl;
			system("pause");
			break;
		case 4:
			timkiemCmt(nv, n);
			cout << endl;
			system("pause");
			break;
		case 5:
			sapxep(nv, n);
			cout << endl;
			system("pause");
			break;
		case 6:
			tongluong(nv, n);
			cout << endl;
			system("pause");
			break;
		case 7:
			thuclinhMax(nv, n);
			cout << endl;
			system("pause");
			break;
		case 8:
			timphucap(nv, n);
			cout << endl;
			system("pause");
			break;
		case 9:
			exit(0);
			break;
		default:
			cout << "Khong co du lieu ban nhap.";
			break;
		}
	} while (choice != 0);
}


class NguyenLieu {
public:
	string LoaiTra;
	string LoaiSua;
	int soluong; 
};
class Tra: public NguyenLieu {
public:
	string NhanHieuTra;
	
};
class BanHang {
public:
	BanHang() 
	{
		do
		{
			system("cls");
			cout << "Moi chon do uong: \n";
			cout << "1. Tra sua tran chau (15.000 dong)\n";
			cout << "2. Tra sua Thai (20.000 dong)\n";
			cout << "0. Thoat";
			cin >> LoaiMon;
			switch (LoaiMon) {
			case 1:
				cout << "So luong: ";
				cin >> SoLuongMon_TraTranChau;
			case 2:
				cout << "So luong: ";
				cin >> SoLuongMon_TraThai;
			default:
				break;
			}
		} while (LoaiMon != 0);
	}
	float TongTienThanhToan=0;
	int SoLuongMon_TraTranChau=0;
	int SoLuongMon_TraThai=0;
	int LoaiMon;
	void TinhTien();
	void InHoaDon();
};
void BanHang::TinhTien()
{
	TongTienThanhToan = 15000 * SoLuongMon_TraTranChau + 20000 * SoLuongMon_TraThai;
}
void BanHang::InHoaDon()
{
	ofstream Bill("hoadon.txt");
	Bill << "1. Tra sua tran chau" << "\t" << SoLuongMon_TraTranChau << "\t" << 15000 * SoLuongMon_TraTranChau << "\n";

	Bill.close();
}

void main()
{
	int n;
	cout << "Chao mung ban den voi phan mem quan ly ban tra sua! Xin moi nhap so nhan vien: ";
	cin >> n;
	nhanvien* nv = new nhanvien[n];
	menu(nv, n);
}