#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;
const int MAX_ORDER = 1000;
void MainMenu(int& nhanvien_num, int& nguyenlieu_num, int& monuong_num);
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
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " \nNhap luong co ban: "; cin >> luongCB; //fflush(stdin);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " \nNhap phu cap: "; cin >> phucap; //fflush(stdin);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	string get_HoTen() {
		return hoten;
	}
	string get_DOB() {
		return ngaysinh;
	}
	string get_adr() {
		return diachi;
	}
	float get_luong() {
		return luongCB;
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
	
}
//Xuat n nhanvien
void xuatds(nhanvien nv[], int n) {
	cout << "\n Manv" << setw(14) << "Ho Ten" << setw(14) << "Ngay Sinh" << setw(10) << "Dia Chi" << setw(11);
	cout << "CMT" << setw(10) << "LuongCB" << setw(10) << "Phu Cap" << setw(11) << "Thuc Linh" << setw(12)<<"\n";

	for (int i = 0; i < n; i++) {
		nv[i].xuat();
		cout << "\n";
	}
	xuat_file(nv,n);
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			break;
		default:
			cout << "Khong co du lieu ban nhap.";
			break;
		}
	} while (choice != 9);
}

class NguyenLieu {
public:
	string ten;
	int soLuong;

	void nhap() {
		cin.ignore(1, '\n');
		cout << "Ten nguyen lieu: ";
		getline(cin, ten);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "So luong nguyen lieu: ";
		cin >> soLuong;
	}

	void xuat() {
		cout << "Nguyen lieu " << ten << ": so luong " << soLuong << endl;
	}

	static void baoCaoTinhTrangNguyenLieu(NguyenLieu NL[], int n) {
		cout << "Bao cao tinh trang nguyen lieu:" << endl;
		for (int i = 0; i < n; ++i) {
			cout << NL[i].ten << ": " << NL[i].soLuong << endl;
		}
	}

	static void ghiNhanNLHet(NguyenLieu NL) {
		cout << "Nguyen lieu het trong kho: " << NL.ten << endl;
	}
};

bool kiemTraNL(NguyenLieu NL[], int n) {
	for (int i = 0; i < n; ++i) {
		if (NL[i].soLuong > 0) {
			return false;
		}
	}
	return true;
}

void themNguyenLieu(NguyenLieu NL[], int& n) {
	/*int soLuong;
	cout << "Nhap so luong nguyen lieu can them: ";
	cin >> soLuong;*/
	for (int i = 0; i < n; i++) {
		NL[i].nhap();
		//n++;
	}
}

void xoaNguyenLieu(NguyenLieu NL[], int& n) {
	int vt;
	cout << "Nhap vi tri can xoa: ";
	cin >> vt;
	for (int i = vt; i < n - 1; ++i) {
		NL[i] = NL[i + 1];
	}
	n--;
}

void kiemTraMonHet(NguyenLieu NL[], int n) {
	for (int i = 0; i < n; ++i) {
		if (NL[i].soLuong == 0) {
			NguyenLieu::ghiNhanNLHet(NL[i]);
		}
	}
}

class MonDoUong {
public:
	string ten;
	float gia;

	void nhap() {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ten mon: ";
		getline(cin, ten);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Gia mon: ";
		cin >> gia;
	}

	void xuat() {
		cout << "Ten Mon: " << ten << "  Gia mon: " << gia << endl;
	}
};

void themMonMenu(MonDoUong DoUong[], int& m) {
	/*int soLuong;
	cout << "Nhap so luong mon can them: ";
	cin >> soLuong;*/
	for (int i = 0; i < m; ++i) {
		DoUong[i].nhap();
		//m++;
	}
}

void xoaMonMenu(MonDoUong DoUong[], int& m) {
	int vt;
	cout << "Nhap vi tri can xoa: ";
	cin >> vt;
	for (int i = vt; i < m - 1; ++i) {
		DoUong[i] = DoUong[i + 1];
	}
	m--;
}

void inMenu(MonDoUong DoUong[], int m) {
	cout << "Menu:" << endl;
	for (int i = 0; i < m; ++i) {
		cout << i << ". ";
		DoUong[i].xuat();
	}
}

void quanLy(NguyenLieu NL[], int& n, MonDoUong DoUong[], int& m) {
	int dem;
	do {
		system("cls"); //xoa man hinh
		cout << "0. Thoat" << endl;
		cout << "1. Nguyen Vat Lieu" << endl;
		cout << "   1.A) Them nguyen vat lieu" << endl;
		cout << "   1.B) Xuat bang nguyen vat lieu" << endl;
		cout << "   1.C) Xoa nguyen vat lieu" << endl;
		cout << "   1.D) Kiem tra mon het trong kho" << endl;
		cout << "2. Menu" << endl;
		cout << "   2.A) Them mon menu" << endl;
		cout << "   2.B) Xoa mon trong menu" << endl;
		cout << "   2.C) In menu" << endl;
		cout << "____________________________________________" << endl;
		cout << "Nhap chuc nang: ";
		cin >> dem;
		switch (dem) {
		case 1:
			cout << "1) Them nguyen vat lieu " << endl;
			cout << "2) Xuat bang nguyen vat lieu" << endl;
			cout << "3) Xoa nguyen vat lieu" << endl;
			cout << "4) Kiem tra mon het trong kho" << endl;
			cout << "__________________________________" << endl;
			cout << "Nhap chuc nang: ";
			cin >> dem;
			switch (dem) {
			case 1:
				/*cout << "Moi ban nhap so luong nguyen lieu muon them vao: ";
				cin >> n;*/
				cin.ignore(1, '\n');
				themNguyenLieu(NL, n);
				break;
			case 2:
				cin.ignore(1, '\n');
				NguyenLieu::baoCaoTinhTrangNguyenLieu(NL, n);
				system("pause");
				break;
			case 3:
				cin.ignore(1, '\n');
				xoaNguyenLieu(NL, n);
				break;
			case 4:
				cin.ignore(1, '\n');
				kiemTraMonHet(NL, n);
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "1) Them mon menu" << endl;
			cout << "2) Xoa mon trong menu" << endl;
			cout << "3) In menu" << endl;
			cout << "______________________" << endl;
			cout << "Nhap chuc nang: ";
			cin >> dem;
			switch (dem) {
			case 1:
				/*cout << "Moi ban nhap so luong mon do uong muon them vao: ";
				cin >> m;*/
				cin.ignore(1, '\n');
				themMonMenu(DoUong, m);
				break;
			case 2:
				cin.ignore(1, '\n');
				xoaMonMenu(DoUong, m);
				break;
			case 3:
				cin.ignore(1, '\n');
				inMenu(DoUong, m);
				system("pause");
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	} while (dem != 0);
}
class BanHang
{
public:
	int soluongmon;
	int price;
	void Selection_num()
	{
		cout << "Moi ban chon so luong mon do uong: ";
		cin >> soluongmon;
	}
	
};
void LuaChonMon(MonDoUong douong[], BanHang bh[], int m)
{
	bh[m].Selection_num();
	cout << "\n";
	cout << "Ban lua chon "<<bh[m].soluongmon<< " mon " << douong[m].ten << " voi gia tien: " << douong[m].gia*bh[m].soluongmon << "\n";
}
float ThanhToan(MonDoUong douong[], BanHang bh[], int m)
{
	float price;
	price = (float)bh[m].soluongmon * douong[m].gia;
	//cout << price;
	return price;
}
void InHoaDon(MonDoUong douong[], BanHang bh[], int m, float price[])
{
	ofstream hoadon_file("hoadon.txt");
	float tongtien = 0;
	for (int i = 0; i < m; i++)
	{
		tongtien = tongtien + price[i];
	}
	cout << "Hoa don thanh toan: \n";
	cout << "Ten do uong\tSo luong\tGia\n";
	for (int i = 0; i < m; i++)
	{
		cout << i + 1 << ". ";
		cout << douong[i].ten << "\t" << bh[i].soluongmon << "\t" << price[i];
		cout << "\n";
	}
	cout << "Tong tien can thanh toan: " << tongtien << "\n";
	cout << "Cam on quy khach! Hen gap lai";
	if (hoadon_file.is_open()) //Ham kiem tra file mo hay khong
	{
		cout << "\nMo file thanh cong. Dang thuc hien xuat hoa don vao file hoadon.txt";
		hoadon_file << "Hoa don thanh toan: \n";
		hoadon_file << "Ten do uong\t\So luong\tGia\n";
		for (int i = 0; i < m; i++)
		{
			hoadon_file << i + 1 << ". ";
			hoadon_file << douong[i].ten << "\t" << bh[i].soluongmon << "\t" << price[i];
			hoadon_file << "\n";
		}
		hoadon_file << "Tong tien can thanh toan: " << tongtien << "\n";
		hoadon_file << "Cam on quy khach! Hen gap lai";
	}
	else cout << "Loi khi mo file hoadon.txt";

}
void MainMenu(int& nhanvien_num, int& nguyenlieu_num, int& monuong_num)
{
	int choice = 0;
	do {
		system("cls");
		cout << "Xin chao mung ban da den voi phan mem quan ly quan tra sua! \nLua chon cac chuc nang bang cach bam (1-3) tren ban phim";
		cout << "\n1. Quan ly nhan vien";
		cout << "\n2. Phan loai nguyen lieu, tao menu";
		cout << "\n3. Ban hang";
		cout << "\n0. Thoat chuong trinh";
		cout << "\nMoi ban nhap so luong mon an muon them vao: ";
		cin >> monuong_num;
		cin.ignore(1, '\n');
		MonDoUong* DoUong = new MonDoUong[monuong_num];
		cout << "\nBan chon chuc nang bang cach bam (1-3) tren ban phim: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Nhap so nhan vien cua quan: ";
			cin >> nhanvien_num;
			nhanvien* nv = new nhanvien[nhanvien_num];
			menu(nv, nhanvien_num);
			break;
		}
		case 2:
		{
			cout << "\nMoi ban nhap so luong nguyen lieu muon them vao: ";
			cin >> nguyenlieu_num;
			NguyenLieu* NL = new NguyenLieu[nguyenlieu_num];
			quanLy(NL, nguyenlieu_num, DoUong, monuong_num);
			//delete[] NL;
			//delete[] DoUong;
			//break;
		}
		case 3:
			char choice_new;
			int* loaimon_store = new int[MAX_ORDER];
			int loaimon = 0;
			int loaimon_store_num = 0;
			float* price = new float[MAX_ORDER];
			BanHang * bh = new BanHang[monuong_num];
			cout << "Moi ban chon do uong trong menu duoi day: \n";
			inMenu(DoUong, monuong_num);
			cout << "\nBam (0-" << monuong_num-1 << ") de lua chon mon uong";
			cin >> loaimon;
			loaimon_store[0] = loaimon;
			LuaChonMon(DoUong, bh, loaimon);
			cout << "Ban muon goi them mon nua khong? Bam Y de dong y.";
			cin >> choice_new;
			while (choice_new == 'Y')
			{
				inMenu(DoUong, monuong_num);
				cout << "\nBam (0-" << monuong_num << ") de lua chon mon uong";
				cin >> loaimon;
				loaimon_store_num++;
				loaimon_store[loaimon_store_num] = loaimon;
				LuaChonMon(DoUong, bh, loaimon);
				cout << "Ban muon goi them mon nua khong? Bam Y de dong y.";
				cin >> choice_new;
			}
			if (loaimon_store_num != 0)
			{
				//float tt = ThanhToan(DoUong, bh, loaimon_store[loaimon_store_num]);
				for (int i = 0; i < loaimon_store_num + 1; i++)
				{
					float tt = ThanhToan(DoUong, bh, loaimon_store[i]);
					price[i] = tt;
				}
			}
			InHoaDon(DoUong, bh, loaimon_store_num + 1, price);
			system("pause");
			break;
		}
	} while (choice != 0);
}

void main()
{
	/*int n;
	cout << "Chao mung ban den voi phan mem quan ly ban tra sua! Xin moi nhap so nhan vien: ";
	cin >> n;
	nhanvien* nv = new nhanvien[n];
	menu(nv, n);*/
	/*int n = 3;
	int m = 3;*/
	/*int n=0;
	int m=0;
	cout << "Moi ban nhap so luong nguyen lieu muon them vao: ";
	cin >> n;
	cout << "Moi ban nhap so luong mon an muon them vao: ";
	cin >> m;
	cin.ignore(1, '\n');
	NguyenLieu* NL = new NguyenLieu[n];
	MonDoUong* DoUong = new MonDoUong[m];
	quanLy(NL, n, DoUong, m);
	delete[] NL;
	delete[] DoUong;*/
	int n = 0;
	int m = 0;
	int nv = 0;
	MainMenu(nv, n, m);
}