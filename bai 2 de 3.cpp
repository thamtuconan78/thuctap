#include <iostream>
#include <stdlib.h>
using namespace std;
	struct Ngaythang{
		int ngay;
		int thang;
		int nam;
	};
	int thang[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int ktnhuan(int year){
	if ((year % 4 == 0 && year % 100!=0) || year % 400 == 0)
		return 1;
	else return 0;
}
void NhapNgay(Ngaythang &ngay){
	int kt;
	do{
		kt = 0;
		cout << "nhap ngay/thang/nam cach nhau 1 dau cach ' ':";
		cin >> ngay.ngay >> ngay.thang >> ngay.nam;
		if(ngay.thang==4 || ngay.thang==6 || ngay.thang== 9 || ngay.thang == 11){
			if(ngay.ngay > 30)
			kt=1;
		}
		else if(ngay.thang == 2 && ktnhuan(ngay.nam )==1) {
			if (ngay.ngay > 29 ) kt=1;
		}
		else if(ngay.thang ==2 && ktnhuan(ngay.nam)==0){
			if(ngay.ngay > 28)
			kt=1;
		}
		else if(Ngaythang.ngay >31 || Ngaythang.thang >12)
		kt=1}
		while (kt==1);
	}
date TimNgay(int x,int nam){
	ngaythang NgayCanTim;
	int i=1;
	while (x > Thang[i]){
		x-=Thang[i];
		i++;
		if (ktnhuan(nam)==1 && i==2)
			Thang[i]=29;
	}
	NgayCanTim.thang = i;
	NgayCanTim.ngay = x;
	NgayCanTim.nam = nam;
	Thang[2]=28;
	return NgayCanTim;
	
int main(){
	string st;
	cout<<" nhap du lieu";getline(cin,st);
	Ngaythang x;
	char t[4];
	t[0]=st[0];
	t[1]=st[1];
	x.ngay=atoi(t);
	t[0]=st[3];
	t[1]=st[4];
	x.thang=atoi(t);
	t[0]=st[6];
	t[1]=st[7];
	t[2]=st[8];
	t[3]=st[9];
	x.nam=atoi(t);
	
	
	cout<<x.ngay<< " "<< x.thang << " "<<x.nam;
	
}	

