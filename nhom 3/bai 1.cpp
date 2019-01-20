#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;
void DocFile();
void GhiFile();
void Xuat();
void Lietke();
void Timkiem();
void Them();
void ChinhSua();
void Xoa();
struct Contact {
		char ten[20];
		bool gioitinh;
		char sdt[11],email[20],diachi[50];
};
vector <Contact> DanhBa;
vector <Contact> DB;
void GhiFile()
{
	FILE *f = fopen("input.dat","wb");
	for(int i=0;i<DanhBa.size();i++)
		fwrite(&DanhBa[i],sizeof(Contact),1,f);
	fclose(f);
}
void Xuat(Contact c)
{
	cout<<c.ten<<"\t"<<c.gioitinh<<"\t"<<c.diachi<<"\t"<<c.email<<"\t"<<c.sdt<<endl;
}
void Them() 
{
	Contact ct;
	strcpy(ct.ten,"tien");
	ct.gioitinh=0;
	strcpy(ct.email,"tien@gmail.com");
	strcpy(ct.diachi,"viet nam");
	strcpy(ct.sdt,"0123456789");
	DanhBa.push_back(ct);
	strcpy(ct.ten,"nguoiyeucuatui");
	ct.gioitinh=0;
	strcpy(ct.email,"pequynh@gmail.com");
	strcpy(ct.diachi,"di xa roi chua co ve toi");
	strcpy(ct.sdt,"123456");
	DanhBa.push_back(ct);
	strcpy(ct.ten,"pe le van dat");
	ct.gioitinh=1;
	strcpy(ct.email,"levandat@gmail.com");
	strcpy(ct.diachi,"quan cam");
	strcpy(ct.sdt,"55555");
		DanhBa.push_back(ct);
	strcpy(ct.ten,"pe ngoc");
		ct.gioitinh=1;
	strcpy(ct.email,"pengoc@gmail.com");
	strcpy(ct.diachi,"quan cam tp sai gon");
	strcpy(ct.sdt,"1234567");
	DanhBa.push_back(ct);	
}
void DocFile()
{
	FILE *f = fopen("input.dat","rb");
	for(int i=0;i<DanhBa.size();i++)
		{
			Contact c;
			fread(&c,sizeof(c),1,f);
			DB.push_back(c);
		}
	fclose(f);
}
void LietKe()
{
	for(int i=0;i<DanhBa.size();i++)
		{
			Xuat(DanhBa[i]);
		}
}
void ChinhSua(char tt[])
{
	for(int i=0;i<DanhBa.size();i++)
		if(strcmp(DB[i].sdt,tt)==0)
			strcpy(DB[i].ten,"pengoc123");
}
void Xoa(char t[])
{
	for(int i=0;i<DB.size();i++)
		{
			if(strcmp(DB[i].ten,t)==0)
				DB.erase(DB.begin()+i);
		}
}
Contact TimKiem(char t[])
{
	for(int i=0;i<DB.size();i++)
			if(strcmp(DB[i].ten,t)==0)
				return DB[i];
}
int main (){	
	Them();
	LietKe();
	GhiFile();
	DocFile();
			ChinhSua("1234567");//chinh sua ten theo so dien thoai
	cout<<"sau khi chinh sua "<<endl;
	Xoa("tien");
	cout<<"sau khi xoa "<<endl;
		for(int i=0;i<DB.size();i++)
		{
			Xuat(DB[i]);
		}
	Contact c=	TimKiem("le van dat");
	cout<<"hien thi Contact sau khi tiem kiem "<<endl;
	Xuat(c);	

}
