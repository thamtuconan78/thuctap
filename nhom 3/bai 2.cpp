#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
ifstream fi("ip.txt");
struct datetime{
		int day;
		int  month;
		int year;
};
int Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int ktnhuan(datetime x){
	if(x.year%400==0||(x.year%4==0&&x.year%100!=0))
		return 1;
	return 0;
}
void khoitao(datetime &x,string &st){
	char c[4];
		fi>>st;
		fi.close();	
	c[0]= st[0];
	c[1] = st[1];
	x.day=atoi(c);
	c[0]= st[3];
	c[1] = st[4];
	x.month=atoi(c);
	c[0]= st[6];
	c[1] =st[7];
	c[2]= st[8];
	c[3] = st[9];
	x.year=atoi(c);
}
int tinhngay(datetime n){
	int tam=0;
	for(int i=0;i<n.month;i++)
		tam+=Month[i];
	tam+=n.day;
	if(ktnhuan(n)&&n.month>2)
		tam++;
	return tam;
}
void inngay(int n,int sum){
	int i=0;
	while(sum>Month[i]){
		sum=sum-Month[i];
		i++;
	}
	cout<<sum<<" day "<<i<<" month "<<n<<" year "<<endl;
}
void congngay(datetime  n,int t){
	int sum=0;
	sum=tinhngay(n)+t;
	if(ktnhuan(n)){
			if(sum<=366){
					Month[2]=29;
					inngay(n.year,sum);
					Month[2]=28;
				}	
			else
				inngay(n.year+1,sum-366);		
		}
	else{
			if(sum<=365)
				inngay(n.year,sum);
			else{
					n.year++;
					if(ktnhuan(n)){
							Month[2]=29;
							inngay(n.year,sum-365);
							Month[2]=28;
						}
					else{
							inngay(n.year,sum-365);	
						}
				}
		}
}
void trungay(datetime n,int t)
{
	int sum = tinhngay(n);
	if(sum>t)
		{
			sum-=t;
			if(ktnhuan(n)){
					Month[2]=29;
					inngay(n.year,sum);
					Month[2]=28;
				}
			else{
					inngay(n.year,sum);	
				}
		}
	else{
			if(ktnhuan(n)){
					sum=sum-t+366;
					n.year--;
					inngay(n.year,sum);
				}
			else{
					sum=sum-t+365;
					n.year--;
					if(ktnhuan(n)){
							Month[2]=29;
							inngay(n.year,sum);
							Month[2]=28;
						}
					else{
							inngay(n.year,sum);
						}
				}
		}
}
int main(){
	fflush(stdin);
	datetime x;
	string st;
	cout<<endl;
	int a,b;
	khoitao(x,st);
	if(ktnhuan(x)) cout<<"nam nhuan "<<endl;
	else	
		cout<<"nam khong nhuan "<<endl;
	cout<<tinhngay(x)<<endl;
	cout<<"nhap so nguyen can cong";
	cin>>a;
	congngay(x,a);
	cout<<"nhap so nguyen can tru";
	cin>>b;
	trungay(x,b);
}
