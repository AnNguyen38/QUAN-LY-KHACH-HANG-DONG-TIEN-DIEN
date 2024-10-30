#include<bits/stdc++.h>
using namespace std;
typedef struct NgayThangNam{
	int ngay;
	int thang;
	int nam;
}NTN;

typedef struct NgayThangNam1{
	int ngay1;
	int thang1;
	int nam1;
}NTN1;
typedef struct KhachHang{
	string tinh;
	string ten;
	string huyen;
	string maKH;
	float soDien;
	float tien;
	NTN ntn;
	NTN1 ntn1; 
}KH;

int kiemTraNgayThangNam(KH a){
	if (a.ntn.ngay<0|| a.ntn.thang<0|| a.ntn.nam<0)
		return 0;
	if (a.ntn.thang>12)
		return 0;
	if (a.ntn.thang==2){
		if (a.ntn.nam%400==0 || (a.ntn.nam%4==0 && a.ntn.nam%100!=0)){
			if(a.ntn.ngay>29)
				return 0;
		}else{
			if(a.ntn.ngay>28)
				return 0;
		}
	}
	if (a.ntn.thang==1 || a.ntn.thang==3 || a.ntn.thang==5 || a.ntn.thang==7 || a.ntn.thang==8 || a.ntn.thang==10 || a.ntn.thang==12){
		if(a.ntn.ngay>31)
			return 0;
	}
	if (a.ntn.thang==4 || a.ntn.thang==6 || a.ntn.thang==9 || a.ntn.thang==11){
		if(a.ntn.ngay>30)
			return 0;
	}
	return 1;	
}
int kiemTraNgayThangNam1(KH a){
	if (a.ntn1.ngay1<0|| a.ntn1.thang1<0|| a.ntn1.nam1<0)
		return 0;
	if (a.ntn1.thang1>12)
		return 0;
	if (a.ntn1.thang1==2){
		if (a.ntn1.nam1%400==0 || (a.ntn1.nam1%4==0 && a.ntn1.nam1%100!=0)){
			if(a.ntn1.ngay1>29)
				return 0;
		}else{
			if(a.ntn1.ngay1>28)
				return 0;
		}
	}
	if (a.ntn1.thang1==1 || a.ntn1.thang1==3 || a.ntn1.thang1==5 || a.ntn1.thang1==7 || a.ntn1.thang1==8 || a.ntn1.thang1==10 || a.ntn1.thang1==12){
		if(a.ntn1.ngay1>31)
			return 0;
	}
	if (a.ntn1.thang1==4 || a.ntn1.thang1==6 || a.ntn1.thang1==9 || a.ntn1.thang1==11){
		if(a.ntn1.ngay1>30)
			return 0;
	}
	return 1;	
}
struct Node{
	KH data;
	Node *next;
};
typedef struct Node *node;

void Init(node &phead){
	phead = NULL;
}
bool empty(node &phead){
	return phead == NULL;
}
node taoNodeMoi(KH x){
	node p = new Node;
	p->next = NULL;
	p->data = x;
	return p;
}
node themVaoDau(node &phead, KH x){
	node temp = taoNodeMoi(x);
	if(phead == NULL){
		phead = temp;
	}else{
		temp->next = phead;
		phead = temp;
	}
	return phead;
}
float tinhTienDien(float a){
	float b;
	if(a>0 && a<=50) b = a*1.893;
	else if(a>50 && a<=100) b = a*1.956;
	else if(a>100 && a<=200) b = a*2.271;
	else if(a>200 && a<=300) b = a*2.860;
	else if(a>300 && a<=400) b = a*3.197;
	else if(a>400) b = a*3.302;
	return b;
} 
void NhapThongTinKhachHang(node &phead, int &n){
	
	cout<< "nhap vao so luong khach hang: ";
	cin>> n;

	ofstream file1 ("giatri.txt", ios::app);
	
	if (!file1.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }

	KH x;
	NTN y;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		cout<< "NHAP THONG TIN KHACH HANG "<< i << endl;
	
		cout<< "nhap vao tinh / thanh pho: ";
		getline(cin, x.tinh) ;
		
		cout<< "nhap vao huyen / quan: ";
		getline(cin, x.huyen);
		
		cout<< "nhap vao ten khach hang: ";
		getline(cin, x.ten);
		
		cout<< "nhap vao ma khach hang: ";
		getline(cin, x.maKH);
		
		cout<< "nhap vao so dien: ";
		cin>> x.soDien;
	
		x.tien = tinhTienDien(x.soDien);
		
		int a = 0;
			
		while(a == 0){
			
			cout<< "nhap vao ngay/thang/nam thanh toan: ";
			cin>> x.ntn.ngay >> x.ntn.thang >> x.ntn.nam;
			a = kiemTraNgayThangNam(x);
			if(a == 0) cout<< "ngay thang nam nhap khong hop le vui long nhap lai!"<< endl;
		}
		cin.ignore();
		cout<<endl;
		
		file1 << left << setw(20) << x.tinh
              << setw(17) << x.huyen
              << setw(25) << x.ten
              << setw(17) << x.maKH
              << setw(10) << x.soDien
              << setw(13) << x.tien
              << setw(0) << x.ntn.ngay << "/" << x.ntn.thang << "/" << x.ntn.nam << endl;
              
		themVaoDau(phead, x);
		
	}
					
	file1.close();	 
}
void inVaoFile(){
	ofstream file1 ("giatri.txt", ios::app);
	
	if (!file1.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    file1 << left << setw(20) << "Tinh/Thanh Pho"
          << setw(17) << "Huyen/Quan"
          << setw(25) << "Ten Khach Hang"
          << setw(17) << "Ma Khach Hang"
          << setw(10) << "So Dien"
          << setw(13) << "Tien Dien"
          << setw(15) << "Ngay Thanh Toan" << endl;
					
	file1.close();	 
}
void DocThongTinKhachHangTuFile(node &phead, string &tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    ofstream fileOut("giatri.txt", ios::app); 
    if (!fileOut.is_open()) {
        cout << "Khong the mo file giatri.txt!" << endl;
        return;
    }
    KH x;
    while (!file.eof()) {
        getline(file, x.tinh);
        getline(file, x.huyen);
        getline(file, x.ten);
        getline(file, x.maKH);
        file >> x.soDien;
        file >> x.ntn.ngay >> x.ntn.thang >> x.ntn.nam;
        file.ignore();  // B? qua kí t? xu?ng d?ng
        x.tien = tinhTienDien(x.soDien);

        themVaoDau(phead, x);
        fileOut << left << setw(20) << x.tinh
                << setw(17) << x.huyen
                << setw(25) << x.ten
                << setw(17) << x.maKH
                << setw(10) << x.soDien
                << setw(13) << x.tien
                << setw(0) << x.ntn.ngay << "/" << x.ntn.thang << "/" << x.ntn.nam << endl;
    }
	
	fileOut.close();
    file.close();
    
}
void XuatDanhSach(node phead){ // dung de xuat danh sach nhap vao
	cout << endl;
	cout<< left << "DANH SACH KHACH HANG DA NHAP VAO BAN DAU" << endl;
	cout<< setw(20) << "tinh/thanh pho"
		<< setw(17) << "huyen/quan"
		<< setw(25) << "ten khach hang"
		<< setw(17) << "ma khach hang"
		<< setw(10) << "so dien"
		<< setw(13) << "tien dien"
		<< setw(15) << "ngay thanh toan"
		<< endl; 
	cout << string(120, '-') << endl;
	for(node a = phead; a != NULL; a = a->next){
		cout<< left << setw(20) << a->data.tinh
			<< setw(17) << a->data.huyen
			<< setw(25) << a->data.ten
			<< setw(17) << a->data.maKH
			<< setw(10) << a->data.soDien
			<< setw(13) << a->data.tien
			<< setw(0) << a->data.ntn.ngay << "/"<< a->data.ntn.thang << "/"<< a->data.ntn.nam<< endl;
	}
	cout<< endl;
} 
void XuatDanhSach1(node phead){ // dung de xuat cac sap xep 
	
	cout<< left << setw(20) << "tinh/thanh pho"
		<< setw(17) << "huyen/quan"
		<< setw(25) << "ten khach hang"
		<< setw(17) << "ma khach hang"
		<< setw(10) << "so dien"
		<< setw(13) << "tien dien"
		<< setw(15) << "ngay thanh toan"
		<< endl; 
	cout << string(120, '-') << endl;
	for(node a = phead; a != NULL; a = a->next){
		cout<< left << setw(20) << a->data.tinh
			<< setw(17) << a->data.huyen
			<< setw(25) << a->data.ten
			<< setw(17) << a->data.maKH
			<< setw(10) << a->data.soDien
			<< setw(13) << a->data.tien
			<< setw(0) << a->data.ntn.ngay << "/"<< a->data.ntn.thang << "/"<< a->data.ntn.nam<< endl;
	}
	cout<< endl;
} 
void XuatDanhSach2(node a){ // dung de xuat mot khach hang khi tim kiem 
	
	cout<< left << setw(20) << a->data.tinh
			<< setw(17) << a->data.huyen
			<< setw(25) << a->data.ten
			<< setw(17) << a->data.maKH
			<< setw(10) << a->data.soDien
			<< setw(13) << a->data.tien
			<< setw(0) << a->data.ntn.ngay << "/"<< a->data.ntn.thang << "/"<< a->data.ntn.nam<< endl;
	
	cout<< endl;
} 
void XuatDanhSach3(){ // dung de xuat mot khach hang khi tim kiem 
	
	cout<<left<< setw(20) << "tinh/thanh pho"
		<< setw(17) << "huyen/quan"
		<< setw(25) << "ten khach hang"
		<< setw(17) << "ma khach hang"
		<< setw(10) << "so dien"
		<< setw(13) << "tien dien"
		<< setw(15) << "ngay thanh toan"
		<< endl; 
	cout << string(120, '-') << endl;
	cout<< endl;
} 
node SapXepTheoSoTien(node &phead) {
    for (node x1 = phead; x1 != NULL; x1 = x1->next) {
        for (node x2 = x1->next; x2 != NULL; x2 = x2->next) {
            if (x1->data.tien < x2->data.tien) {
                KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
            }
        }
    }
    return phead;
}
node SapXepTheoSoDien(node &phead) {
    for (node x1 = phead; x1 != NULL; x1 = x1->next) {
        for (node x2 = x1->next; x2 != NULL; x2 = x2->next) {
            if (x1->data.soDien < x2->data.soDien) {
                KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
            }
        }
    }
    return phead;
}

node SapXepTheoMaKhachHang(node &phead) {
    for (node x1 = phead; x1 != NULL; x1 = x1->next) {
        for (node x2 = x1->next; x2 != NULL; x2 = x2->next) {
            if (x1->data.tien < x2->data.tien) {
                KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
            }
        }
    }
    return phead;
}
node SapXepTheoTinhThanhPho(node &phead){
	for (node x1 = phead; x1 != NULL; x1 = x1->next) {
        for (node x2 = x1->next; x2 != NULL; x2 = x2->next) {
            if (x1->data.tinh > x2->data.tinh) {
                KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
            }
        }
    }
    return phead;
}
node SapXepTheoQuanHuyen(node &phead){
	for (node x1 = phead; x1 != NULL; x1 = x1->next) {
        for (node x2 = x1->next; x2 != NULL; x2 = x2->next) {
            if (x1->data.tinh > x2->data.tinh) {
                KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
            }
        }
    }
    return phead;
}
node SapXepTheoNgayThangNam(node &phead) {
    for (node x1 = phead; x1 != NULL; x1 = x1->next) {
        for (node x2 = x1->next; x2 != NULL; x2 = x2->next) {
            if (x1->data.ntn.nam < x2->data.ntn.nam) {
                KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
            }else if(x1->data.ntn.nam == x2->data.ntn.nam && x1->data.ntn.thang < x2->data.ntn.thang){
            	KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
			}else if(x1->data.ntn.nam == x2->data.ntn.nam && x1->data.ntn.thang == x2->data.ntn.thang && x1->data.ntn.ngay < x2->data.ntn.ngay){
				KH temp = x1->data;
                x1->data = x2->data;
                x2->data = temp;
			}
            
        }
    }
    return phead;
}
void TimKiemTheoTenKhachHang(node &phead){
	string tenKH;
	cin.ignore();
	cout<<"nhap vao ten khach hang can tim: ";
	getline(cin,tenKH);	
	int flag = 0;
	for(node x2 = phead; x2 != NULL; x2 = x2->next){
		if(tenKH == x2->data.ten){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		cout<<"co khach hang can tim trong danh sach!"<<endl<<endl;
		XuatDanhSach3();
	} 
	for(node x1 = phead; x1 != NULL; x1 = x1->next){
		if(tenKH == x1->data.ten){
			XuatDanhSach2(x1);
		}
	}
	if(flag == 0) cout<<"khong tim thay khach hang trong danh sach!"<< endl;
}
void TimKiemTheoTinhThanhPho(node &phead){
	string tenTinhKH;
	cin.ignore();
	cout<<"nhap vao tinh / thanh pho can tim: ";
	getline(cin,tenTinhKH);	
	int flag = 0;
	for(node x2 = phead; x2 != NULL; x2 = x2->next){
		if(tenTinhKH == x2->data.tinh){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		cout<<"co tinh / thanh pho can tim trong danh sach!"<<endl<<endl;
		XuatDanhSach3();
	} 
	for(node x1 = phead; x1 != NULL; x1 = x1->next){
		if(tenTinhKH == x1->data.tinh){
			XuatDanhSach2(x1);
		}
	}
	if(flag == 0) cout<<"khong tim thay tinh / thanh pho trong danh sach!"<< endl;
}
void TimKiemTheoQuanHuyen(node &phead){
	string tenHuyenKH;
	cin.ignore();
	cout<<"nhap vao huyen / quan can tim: ";
	getline(cin,tenHuyenKH);	
	int flag = 0;
	for(node x2 = phead; x2 != NULL; x2 = x2->next){
		if(tenHuyenKH == x2->data.huyen){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		cout<<"co huyen / quan can tim trong danh sach!"<<endl;
		XuatDanhSach3();
	} 
	for(node x1 = phead; x1 != NULL; x1 = x1->next){
		if(tenHuyenKH == x1->data.huyen){
			XuatDanhSach2(x1);
		}
	}
	if(flag == 0) cout<<"khong tim thay huyen / quan trong danh sach!"<< endl;
}
void TimKiemTheoMaKH(node &phead){
	string maKH;
	cin.ignore();
	cout<<"nhap vao ma khach hang can tim: ";
	getline(cin,maKH);	
	int flag = 0;
	for(node x2 = phead; x2 != NULL; x2 = x2->next){
		if(maKH == x2->data.maKH){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		cout<<"co ma khach hang can tim trong danh sach!"<<endl;
		XuatDanhSach3();
	} 
	for(node x1 = phead; x1 != NULL; x1 = x1->next){
		if(maKH == x1->data.maKH){
			XuatDanhSach2(x1);
		}
	}
	if(flag == 0) cout<<"khong tim thay ma khach hang trong danh sach!"<< endl;
}

void TimKiemTheoNgayThanhToan(node &phead){
	int a = 0;
	KH y;
	while(a == 0){		
		cout<< "nhap vao ngay/thang/nam can tim: ";
		cin>> y.ntn1.ngay1 >> y.ntn1.thang1 >> y.ntn1.nam1;
		a = kiemTraNgayThangNam1(y);
		if(a == 0) cout<< "ngay thang nam nhap khong hop le vui long nhap lai!"<< endl;
	} 
	int flag = 0;
	for(node x2 = phead; x2 != NULL; x2 = x2->next){
		if(y.ntn1.ngay1 == x2->data.ntn.ngay && y.ntn1.thang1 == x2->data.ntn.thang && y.ntn1.nam1 == x2->data.ntn.nam){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		cout<<"co ngay/thang/nam can can tim trong danh sach!"<<endl;
		XuatDanhSach3();
	} 
	for(node x1 = phead; x1 != NULL; x1 = x1->next){
		if(y.ntn1.ngay1 == x1->data.ntn.ngay && y.ntn1.thang1 == x1->data.ntn.thang && y.ntn1.nam1 == x1->data.ntn.nam){
			XuatDanhSach2(x1);
		}
	}
	if(flag == 0) cout<<"khong tim thay ngay/thang/nam trong danh sach!"<< endl;
}
int main(){
	int n,m;
	node phead;
	Init(phead);
	string tenDN = "nguyen van an", MK = "an03082005" ;
	string tenDn, Mk;

	while(tenDn != tenDN || Mk != MK){
	
		cout<<"Nhap Ten Dang Nhap: ";
		getline(cin,tenDn);
		cout<<"Nhap Vao Mat Khau: ";
		getline(cin,Mk);
		if(tenDn == tenDN && Mk == MK) cout<<"dang nhap thanh cong!"<<endl;
		
		while(tenDn != tenDN || Mk != MK){
			cout<< string(20, '-')<<endl;
			cout<<"ban chua co tai khoan? nhap 1 de tao tai khoan"<<endl;
			cout<<"nhap 2 de nhap lai tai khoan"<< endl;
			cout<< string(20, '-')<<endl;
			int tk;
			cout<<"nhap lua chon: ";
			cin>> tk;
			cin.ignore();
			
			if(tk == 1){
				cout<< string(20, '-')<<endl;
				cout<<"TAO TAI KHOAN"<<endl;
				cout<<"Nhap Ten Dang Nhap Tai Khoan Moi: ";
				getline(cin,tenDn);
				cout<<"Nhap Vao Mat Khau Tai Khoan Moi: ";
				getline(cin,Mk);
				cout<< endl;
				
				tenDN = tenDn;
				MK = Mk;
				break;
			}
			if(tk==2){
				break;
			}
		}
	}
	
	if(tenDn == tenDN && Mk == MK){
		cout<< string(20, '=') << setw(20) << "CHUONG TRINH QUAN LY DANH SACH KHACH HANG DONG TIEN DIEN" << string(20, '=') << endl;
		while(true){
			
			cout<< string(50, '-')<<endl;
			cout<<"0: thoat chuong trinh"<<endl;
			cout<<"1: nhap thong tin khach hang"<< endl;
			cout<< string(50, '-')<<endl;
			
			cout<< "nhap vao lua chon: ";
			cin>> m;
			cout<<endl;
			
			if(m==0) return 0;
			if(m==1){
				inVaoFile(); 
				int m1;
				while(true){
					
					cout<< string(50, '-')<<endl;
					
					cout<<"1: nhap thong tin khach hang"<<endl;
					cout<<"2: nhap thong tin khach hang tu file"<<endl;
					cout<<"3: sap xep thong tin khach hang"<<endl;
					cout<<"4: tim kiem thong tin khach hang"<<endl;
					cout<<"5: xuat danh sach khach hang da nhap"<<endl;
					cout<<"0: quay lai man hinh chinh"<<endl;
					cout<<"6: thoat chuong trinh"<<endl;
					cout<< string(50, '-')<<endl;
					
					cout<< "nhap vao lua chon: ";
					cin>> m1;
					cout<<endl;
					
					if(m1==0) break;
					if(m1==1) NhapThongTinKhachHang(phead, n);
					if(m1==2){
						int k = 0;
						string tenFile;
						ifstream file2;
						do{
							cin.ignore();
							cout<<"nhap vao duong dan den file trong thu muc: ";
							getline(cin,tenFile);
							file2.open(tenFile);
							if(file2.is_open()){
								k = 1;
								break;
							}else cout<<"Duong dan khong hop le hoac file khong ton tai. Vui long nhap lai." ;
						}while(k==0);
						
						if(k==1){
							DocThongTinKhachHangTuFile(phead, tenFile);
							cout<<"nhap thong tin khach hang tu file thanh cong"<<endl;
						}
						file2.close();
					}
					if(m1==3){
						int m2;
						while(true){
							
							cout<< string(50, '-')<<endl;
							cout<<"0: quay lai"<<endl;
							cout<<"1: sap xep thong tin khach hang theo tinh / thanh pho"<<endl;
							cout<<"2: sap xep thong tin khach hang theo huyen / quan"<<endl;
							cout<<"3: sap xep thong tin khach hang theo ma khach hang"<<endl;
							cout<<"4: sap xep thong tin khach hang theo so tien dien"<<endl;
							cout<<"5: sap xep thong tin khach hang theo so dien da dung"<<endl;
							cout<<"6: sap xep thong tin khach hang theo ngay nap tien"<<endl;
							cout<<"7: xuat danh sach da sap xep ra man hinh"<<endl;
							cout<<"8: thoat chuong trinh"<<endl;
							cout<< string(50, '-')<<endl;
							
							cout<< "nhap vao lua chon: ";
							cin>> m2;
							cout<<endl;
							
							if(m2==0) break;
							if(m2==1){
								SapXepTheoTinhThanhPho(phead);
								cout<<"sap xep thanh cong!"<<endl;	
							} 
							if(m2==2){
								SapXepTheoQuanHuyen(phead);
								cout<<"sap xep thanh cong!"<<endl;
							} 
							if(m2==3){
								SapXepTheoMaKhachHang(phead);
								cout<<"sap xep thanh cong!"<<endl;
							} 
							if(m2==4){
								SapXepTheoSoTien(phead);
								cout<<"sap xep thanh cong!"<<endl;
							} 
							if(m2==5){
								SapXepTheoSoDien(phead);
								cout<<"sap xep thanh cong!"<<endl;
							} 
							if(m2==6){
								SapXepTheoNgayThangNam(phead);
								cout<<"sap xep thanh cong!"<<endl;
							} 
							if(m2==7){
								cout<<"DANH SACH SAU KHI DUOC SAP XEP"<<endl<<endl;
								XuatDanhSach1(phead);
								
							}
							if(m2==8) return 0; 
						}
						
					}
					if(m1==4){
						while(true){
							int m3;
							
							cout<< string(50, '-')<<endl;
							cout<<"0: quay lai"<<endl;
							cout<<"1: tim kiem theo tinh / thanh pho"<<endl;
							cout<<"2: tim kiem theo huyen / quan"<<endl;
							cout<<"3: tim kiem theo ma khach hang"<<endl;
							cout<<"4: tim kiem theo ten khach hang"<<endl;
							cout<<"5: tim kiem theo ngay/ thang/nam"<<endl;
							cout<<"6: thoat chuong trinh"<<endl;
							cout<< string(50, '-')<<endl;
								
							cout<< "nhap vao lua chon: ";
							cin>> m3;
							cout<<endl;
							
							
							if(m3==0) break;
							if(m3==1) TimKiemTheoTinhThanhPho(phead);
							if(m3==2) TimKiemTheoQuanHuyen(phead);
							if(m3==3) TimKiemTheoMaKH(phead);
							if(m3==4) TimKiemTheoTenKhachHang(phead);
							if(m3==5) TimKiemTheoNgayThanhToan(phead);
							if(m3==6) return 0;
						}
						
					} 
					if(m1==5) XuatDanhSach(phead);
					if(m1==6) return 0;
				}
			}
		}
	}
		
}
