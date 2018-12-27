#include <iostream>
#include <stdlib.h>
using namespace std;
	struct Ngaythang{
		int ngay;
		int thang;
		int nam;
	};
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

