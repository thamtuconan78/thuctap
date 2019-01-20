/*6
0	4	0	0	0	2

4	0	6	0	0	1

0	6	0	4	2	5

0	0	4	0	3	0

0	0	2	3	0	10

2	1	5	0	10	0


- Tao struct cap{dinh,tong}
- tao ra mot vector <cap> danhsach de xet trong qua trinh xu ly
- Tao mot bien chon kieu cap
- Gan cung dinh dau tien vao chon
- Xet cac dinh duoc chon
- Kiem tra xem co duong di tu dinh duoc chon toi cac dinh con lai
- Neu co duong di, gan dinh dang xet,chen trang = chen,tong + a[i][chon dinh]
  nguoc lai
  	chentong=0;
-KT lan luot cac phan tu trong vetor 
-chon ra phan tu co tong nho nhat va i = 0 dua vao ds chon.  	
*/	
#include <string.h>
#include <iostream>
#include <fstream>
  using namespace std;
  int n;
  fstream fi("dothi.txt") ;
	
  void Docfile(int a[10][10]){
  	for (int i=0;i<n;i++)
  	for(int j=0; j<n;j++)
  	fi>>a[i][j];
  	fi.close();
  	
  }
  void Xuatdothi(int a[10][10]){
  	for(int i=0;i<n;i++)
  		for(int j=0;j<n;j++)
  		cout<<a[i][j]<<" ";
  }
  void Taomoi(int a[10][10], int &n){
  	cout <<"nhap n"; cin>>n;
  	fi.open("dothi.txt",ios::out);
  	fi<<n;
  	for(int i=0;i<n;i++){
	  for(int j=0;j<n;j++){
	  
	  	cout<<"trong so"<<i<<"den"<<j<<":" ;
	  	cin>>a[i][j];
	  	fi<<a[i][j]<<" ";
	   }
	   }
	fi<<endl;  
	//////
	}
	void XuLi(int a[10][10])
{
	while(KetThuc()==1)
	{
	for(int i=0;i<DS.size();i++)
		{
			if(DS[i].Tong>a[i][chon.Dinh]+chon.Tong&&KiemTra(i))
				{
					DS[i].Tong= a[i][chon.Dinh]+chon.Tong;
					DS[i].Dinh= chon.Dinh;
				}
		}
	TimDinhChon();			
	}	
}
void XuatDS()
{
	for(int i=0;i<DS.size();i++)
		cout<<i<<"\t"<<DS[i].Dinh<<"\t"<<DS[i].Tong<<endl;
}
	///////
  }
int main(){
	int a[10][10];
	Docfile(a[10][10]);
}

