#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class Warehouse
{
private:
	int num;
	string name;
	int price;
	int innumber;
	int staynumber;
	int outnumber;
	string keeper;
	string intime;
	string outtime;
	string note;
public:
	Warehouse(int num_,string name_,int price_,int in,int stay,int out,string keeper_,string itime,string otime,string note_):
	  num(num_),name(name_),price(price_),innumber(in),staynumber(stay),outnumber(out),keeper(keeper_),intime(itime),outtime(otime),note(note_){}
	  int getnum();
	  string getname(){return this->name;}
	  int getp(){return this->price;}
	  int getinn(){return this->innumber;}
	  int getoun(){return this->outnumber;}
	  string getk(){return this->keeper;}
	  string getit(){return this->intime;}
	  string getot(){return this->outtime;}
	  string getno(){return this->note;}
	  void  getout();
	  int getstay(){return this->staynumber;} 
	  void show();
	  class Warehouse *next;
	  friend void change(Warehouse *p,string c);
};
int Warehouse::getnum()
{
	return this->num;
}
void Warehouse::show()
{
	cout<<left<<setw(11)<<this->num<<left<<setw(11)<<this->name<<left<<setw(11)<<this->price<<left<<setw(11)<<this->innumber<<left<<setw(11)<<this->staynumber
		<<left<<setw(11)<<this->outnumber<<left<<setw(11)<<this->keeper<<left<<setw(11)<<this->intime<<left<<setw(11)<<this->outtime<<left<<setw(11)<<this->note<<endl;
}
void Warehouse::getout()
{
	string time;
	int number;
	int n=1;
	cout<<"<"<<this->name<<">库存数量："<<this->staynumber<<endl;
	while(1){
		cout<<"请输入需要取出的数量：";cin>>number;
		if(number>this->staynumber){cout<<"！超出库存数量,请重新输入！"<<endl;n=0;}
		else{
			this->staynumber=this->staynumber-number;
			this->outnumber=this->outnumber+number;
			cout<<"请输入取货时间(如2020.05.05)：";
			cin>>time;
			this->outtime.assign(time);break;
		}
	}
}
void change(Warehouse *p,string c) 
{
	if(c=="编号")
	{
		int number;
		cout<<"原编号："<<p->num<<endl;
		cout<<"新编号：";cin>>number;
		p->num=number;
	}
	else if(c=="名称")
	{
		string n;
		cout<<"原名称："<<p->name<<endl;
		cout<<"新名称：";cin>>n;
		p->name.assign(n);
	}
	else if(c=="单价")
	{
		int pr;
		cout<<"原单价："<<p->price<<endl;
		cout<<"新单价：";cin>>pr;
		p->price=pr;
	}
	else if(c=="入库数量")
	{
		int nu;
		cout<<"原数量："<<p->innumber<<endl;
		cout<<"新数量：";cin>>nu;
		p->innumber=nu;
	}
	else if(c=="库存数量")
	{
		int nu;
		cout<<"原数量："<<p->staynumber<<endl;
		cout<<"新数量：";cin>>nu;
		p->staynumber=nu;
	}
	else if(c=="出库数量")
	{
		int nu;
		cout<<"原数量："<<p->outnumber<<endl;
		cout<<"新数量：";cin>>nu;
		p->outnumber=nu;
	}
	else if(c=="保管人")
	{
		string k;
		cout<<"原保管人："<<p->keeper<<endl;
		cout<<"新保管人：";cin>>k;
		p->keeper.assign(k);
	}
	else if(c=="进货时间")
	{
		string t;
		cout<<"原时间："<<p->intime<<endl;
		cout<<"新时间：";cin>>t;
		p->intime.assign(t);
	}
	else if(c=="出货时间")
	{
		string t;
		cout<<"原时间："<<p->outtime<<endl;
		cout<<"新时间：";cin>>t;
		p->outtime.assign(t);
	}
	else if(c=="备注")
	{
		string n;
		cout<<"原备注："<<p->note<<endl;
		cout<<"新备注：";cin>>n;
		p->note.assign(n);
	}
}
Warehouse *create()
{
	char c;
	int num_;
	string name_;
	int price_;
	int in;
	int stay;
	int out;
	string keeper_;
	string itime;
	string otime;
	string note_;
	Warehouse *head=NULL,*p,*q;
	cin>>num_;
	if(num_){
		c=getchar();
		cin>>name_>>price_>>in>>stay>>out>>keeper_>>itime>>otime>>note_;
		p=new Warehouse(num_,name_,price_,in,stay,out,keeper_,itime,otime,note_);
		while(1)
		{
			if(!head)
			{
				head=q=p;
				head->next=NULL;
			}
			else
			{
				q->next=p;
				q=p;
				q->next=NULL;
			}
			cin>>num_;
			if(num_<0)
				break;
			c=getchar();
			cin>>name_>>price_>>in>>stay>>out>>keeper_>>itime>>otime>>note_;
			p=new Warehouse(num_,name_,price_,in,stay,out,keeper_,itime,otime,note_);
		}
	}
	return head;
}
typedef struct node
{
	int n;
	node *next;
};
node *crea()
{
	node *h=NULL,*p,*q;
	int n;
	cin>>n;
	if(n>0)
	{
		p=new node;
		p->n=n;p->next=NULL;
		while(1)
		{
			if(!h)
				h=q=p;
			else
			{
				q->next=p;q=p;
				q->next=NULL;
			}
			cin>>n;
			if(n<0)break;
			p=new node;
			p->n=n;
		}
	}
	return h;
}
int main()
{	
	Warehouse *head=NULL,*p,*q;
	node *np,*nhead=NULL;
	int k=1;
	string c;
	int number;
	cout<<"********************************************|请添加材料信息|********************************************"<<endl;
	cout<<"********************************************|输入-1结束录入|********************************************"<<endl;
	cout<<"依此录入编号、名称、单价、入库数量、库存数量、出库数量、保管人、进货日期、出货日期和备注"<<endl;
	head=p=create();
	while(k)
	{
		cout<<"请输入要进行的操作(支持添货、取货、删货、查询、修改、输出所有)"<<endl;
		cin>>c;
		if(c=="查询"||c=="chaxun"){
			cout<<"请输入需要查询的编号(-1结束输入)：";
			nhead=np=crea();
			cout<<left<<setw(11)<<"编号"<<left<<setw(11)<<"名称"<<left<<setw(11)<<"单价"<<left<<setw(11)<<"入库数量"<<left<<setw(11)<<"库存数量"<<left<<setw(11)
				<<"出库数量"<<left<<setw(11)<<"保管人"<<left<<setw(11)<<"进货日期"<<left<<setw(11)<<"出货日期"<<left<<setw(11)<<"备注"<<endl;
			p=head;
			while(np&&p)
			{
				if(p->getnum()==np->n)
				{
					p->show();
					k=0;np=np->next;p=head;
				}
				else
					p=p->next;
			}
			if(!p&&np)
				cout<<"**************************************|编号错误，请重新输入|**************************************"<<endl;
			np=nhead->next;
			while(np)
			{
				delete nhead;
				nhead=np;np=np->next;
			}delete nhead;
			p=head;
		}
		else if(c=="添货"||c=="tianhuo")
		{
			cout<<"请依此录入编号、名称、单价、入库数量、库存数量、出库数量、保管人、进货时间、出货时间和备注"<<endl;
			cout<<"*********************************************|输入-1结束录入|*******************************************"<<endl;
			q=create();
			while(p->next)
			{
				p=p->next;
			}
			p->next=q;
			p=head;
			cout<<left<<setw(11)<<"编号"<<left<<setw(11)<<"名称"<<left<<setw(11)<<"单价"<<left<<setw(11)<<"入库数量"<<left<<setw(11)<<"库存数量"<<left<<setw(11)
				<<"出库数量"<<left<<setw(11)<<"保管人"<<left<<setw(11)<<"进货日期"<<left<<setw(11)<<"出货日期"<<left<<setw(11)<<"备注"<<endl;
			while(p)
			{
				p->show();
				p=p->next;
			}
			p=head;
		}
		else if(c=="修改"||c=="xiugai")
		{
			cout<<"请输入需要修改的材料的编号(-1结束输入)：";
			nhead=np=crea();
			while(np&&p)
			{
				if(p->getnum()==np->n)
				{
					cout<<"输入修改的<"<<p->getname()<<">的类型(编号、名称、单价、入库数量、库存数量、出库数量、保管人、进货时间、出货时间和备注)"<<endl;
					cin>>c;
					change(p,c);np=np->next;p=head;
					k=0;
				}
				else
					p=p->next;
			}
			if(!p&&np)
			{
				cout<<"*****************************************|编号错误，请重新输入|*****************************************"<<endl;}
			else{
				cout<<"**********************************************|修改成功|************************************************"<<endl;
				cout<<left<<setw(11)<<"编号"<<left<<setw(11)<<"名称"<<left<<setw(11)<<"单价"<<left<<setw(11)<<"入库数量"<<left<<setw(11)<<"库存数量"<<left<<setw(11)
					<<"出库数量"<<left<<setw(11)<<"保管人"<<left<<setw(11)<<"进货日期"<<left<<setw(11)<<"出货日期"<<left<<setw(11)<<"备注"<<endl;
				p=head;np=nhead;
				while(np)
				{
					if(p->getnum()==np->n)
					{
						p->show();p=head;np=np->next;
					}
					else
						p=p->next;
				}
				np=nhead->next;
				while(np)
				{
					delete nhead;
					nhead=np;np=np->next;
				}delete nhead;}
			p=head;
		}
		else if(c=="取货"||c=="quhuo")
		{
			cout<<"请输入需取货物的编号(-1结束输入)：";nhead=np=crea();
			while(p&&np)
			{
				if(p->getnum()==np->n)
				{
					p->getout();
					cout<<"<"<<p->getname()<<">现有库存："<<p->getstay()<<endl;
					k=0;np=np->next;p=head;
				}
				else
					p=p->next;
			}
			if(!p&&np)
			{
				cout<<"*****************************************|编号错误，请重新输入|*****************************************"<<endl;}
			np=nhead->next;
			while(np)
			{
				delete nhead;
				nhead=np;np=np->next;
			}delete nhead;
			p=head;
		}
		else if(c=="删货"||c=="shanhuo")
		{
			cout<<"请输入需删除的货物的编号(-1结束输入)：";nhead=np=crea();p=head->next;q=head;
			while(p&&np)
			{
				if(head->getnum()==np->n)
				{
					head=head->next;
					np=np->next;
					delete q;p=head->next;q=head;
				}
				else if(p->getnum()==np->n)
				{
					q->next=p->next;
					delete p;p=head->next;q=head;np=np->next;
				}
				else{
					q=p;
					p=p->next;
				}
			}k=0;
			if(!p&&np)
			{
				cout<<"*****************************************|编号错误，请重新输入|*****************************************"<<endl;}
			else
			cout<<"**********************************************|删除成功|************************************************"<<endl;
			np=nhead->next;
			while(np)
			{
				delete nhead;
				nhead=np;np=np->next;
			}delete nhead;
			p=head;
		}
		else if(c=="输出所有"||c=="shuchusuoyou")
		{
			cout<<left<<setw(11)<<"编号"<<left<<setw(11)<<"名称"<<left<<setw(11)<<"单价"<<left<<setw(11)<<"入库数量"<<left<<setw(11)<<"库存数量"<<left<<setw(11)
				<<"出库数量"<<left<<setw(11)<<"保管人"<<left<<setw(11)<<"进货日期"<<left<<setw(11)<<"出货日期"<<left<<setw(11)<<"备注"<<endl;
			while(p)
			{
				p->show();
				p=p->next;
			}
			k=0;
			p=head;
		}
		cout<<"*************************************|输入1继续操作，输入0退出操作|*************************************"<<endl;
		cin>>k;
	}
	ofstream outfile;
	outfile.open("1.txt",ios::out);
	p=head;
	outfile<<left<<setw(11)<<"编号"<<left<<setw(11)<<"名称"<<left<<setw(11)<<"单价"<<left<<setw(11)<<"入库数量"<<left<<setw(11)<<"库存数量"<<left<<setw(11)
		<<"出库数量"<<left<<setw(11)<<"保管人"<<left<<setw(11)<<"进货日期"<<left<<setw(11)<<"出货日期"<<left<<setw(11)<<"备注"<<endl;
	while(p)
	{
		outfile<<left<<setw(11)<<p->getnum()<<left<<setw(11)<<p->getname()<<left<<setw(11)<<p->getp()<<left<<setw(11)<<p->getinn()<<left<<setw(11)<<p->getstay()
			<<left<<setw(11)<<p->getoun()<<left<<setw(11)<<p->getk()<<left<<setw(11)<<p->getit()<<left<<setw(11)<<p->getot()<<left<<setw(11)<<p->getno()<<endl;
		p=p->next;
	}
	outfile.close();
	return 0;
}