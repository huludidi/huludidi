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
	cout<<"<"<<this->name<<">���������"<<this->staynumber<<endl;
	while(1){
		cout<<"��������Ҫȡ����������";cin>>number;
		if(number>this->staynumber){cout<<"�������������,���������룡"<<endl;n=0;}
		else{
			this->staynumber=this->staynumber-number;
			this->outnumber=this->outnumber+number;
			cout<<"������ȡ��ʱ��(��2020.05.05)��";
			cin>>time;
			this->outtime.assign(time);break;
		}
	}
}
void change(Warehouse *p,string c) 
{
	if(c=="���")
	{
		int number;
		cout<<"ԭ��ţ�"<<p->num<<endl;
		cout<<"�±�ţ�";cin>>number;
		p->num=number;
	}
	else if(c=="����")
	{
		string n;
		cout<<"ԭ���ƣ�"<<p->name<<endl;
		cout<<"�����ƣ�";cin>>n;
		p->name.assign(n);
	}
	else if(c=="����")
	{
		int pr;
		cout<<"ԭ���ۣ�"<<p->price<<endl;
		cout<<"�µ��ۣ�";cin>>pr;
		p->price=pr;
	}
	else if(c=="�������")
	{
		int nu;
		cout<<"ԭ������"<<p->innumber<<endl;
		cout<<"��������";cin>>nu;
		p->innumber=nu;
	}
	else if(c=="�������")
	{
		int nu;
		cout<<"ԭ������"<<p->staynumber<<endl;
		cout<<"��������";cin>>nu;
		p->staynumber=nu;
	}
	else if(c=="��������")
	{
		int nu;
		cout<<"ԭ������"<<p->outnumber<<endl;
		cout<<"��������";cin>>nu;
		p->outnumber=nu;
	}
	else if(c=="������")
	{
		string k;
		cout<<"ԭ�����ˣ�"<<p->keeper<<endl;
		cout<<"�±����ˣ�";cin>>k;
		p->keeper.assign(k);
	}
	else if(c=="����ʱ��")
	{
		string t;
		cout<<"ԭʱ�䣺"<<p->intime<<endl;
		cout<<"��ʱ�䣺";cin>>t;
		p->intime.assign(t);
	}
	else if(c=="����ʱ��")
	{
		string t;
		cout<<"ԭʱ�䣺"<<p->outtime<<endl;
		cout<<"��ʱ�䣺";cin>>t;
		p->outtime.assign(t);
	}
	else if(c=="��ע")
	{
		string n;
		cout<<"ԭ��ע��"<<p->note<<endl;
		cout<<"�±�ע��";cin>>n;
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
	cout<<"********************************************|����Ӳ�����Ϣ|********************************************"<<endl;
	cout<<"********************************************|����-1����¼��|********************************************"<<endl;
	cout<<"����¼���š����ơ����ۡ����������������������������������ˡ��������ڡ��������ںͱ�ע"<<endl;
	head=p=create();
	while(k)
	{
		cout<<"������Ҫ���еĲ���(֧�������ȡ����ɾ������ѯ���޸ġ��������)"<<endl;
		cin>>c;
		if(c=="��ѯ"||c=="chaxun"){
			cout<<"��������Ҫ��ѯ�ı��(-1��������)��";
			nhead=np=crea();
			cout<<left<<setw(11)<<"���"<<left<<setw(11)<<"����"<<left<<setw(11)<<"����"<<left<<setw(11)<<"�������"<<left<<setw(11)<<"�������"<<left<<setw(11)
				<<"��������"<<left<<setw(11)<<"������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��ע"<<endl;
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
				cout<<"**************************************|��Ŵ�������������|**************************************"<<endl;
			np=nhead->next;
			while(np)
			{
				delete nhead;
				nhead=np;np=np->next;
			}delete nhead;
			p=head;
		}
		else if(c=="���"||c=="tianhuo")
		{
			cout<<"������¼���š����ơ����ۡ����������������������������������ˡ�����ʱ�䡢����ʱ��ͱ�ע"<<endl;
			cout<<"*********************************************|����-1����¼��|*******************************************"<<endl;
			q=create();
			while(p->next)
			{
				p=p->next;
			}
			p->next=q;
			p=head;
			cout<<left<<setw(11)<<"���"<<left<<setw(11)<<"����"<<left<<setw(11)<<"����"<<left<<setw(11)<<"�������"<<left<<setw(11)<<"�������"<<left<<setw(11)
				<<"��������"<<left<<setw(11)<<"������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��ע"<<endl;
			while(p)
			{
				p->show();
				p=p->next;
			}
			p=head;
		}
		else if(c=="�޸�"||c=="xiugai")
		{
			cout<<"��������Ҫ�޸ĵĲ��ϵı��(-1��������)��";
			nhead=np=crea();
			while(np&&p)
			{
				if(p->getnum()==np->n)
				{
					cout<<"�����޸ĵ�<"<<p->getname()<<">������(��š����ơ����ۡ����������������������������������ˡ�����ʱ�䡢����ʱ��ͱ�ע)"<<endl;
					cin>>c;
					change(p,c);np=np->next;p=head;
					k=0;
				}
				else
					p=p->next;
			}
			if(!p&&np)
			{
				cout<<"*****************************************|��Ŵ�������������|*****************************************"<<endl;}
			else{
				cout<<"**********************************************|�޸ĳɹ�|************************************************"<<endl;
				cout<<left<<setw(11)<<"���"<<left<<setw(11)<<"����"<<left<<setw(11)<<"����"<<left<<setw(11)<<"�������"<<left<<setw(11)<<"�������"<<left<<setw(11)
					<<"��������"<<left<<setw(11)<<"������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��ע"<<endl;
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
		else if(c=="ȡ��"||c=="quhuo")
		{
			cout<<"��������ȡ����ı��(-1��������)��";nhead=np=crea();
			while(p&&np)
			{
				if(p->getnum()==np->n)
				{
					p->getout();
					cout<<"<"<<p->getname()<<">���п�棺"<<p->getstay()<<endl;
					k=0;np=np->next;p=head;
				}
				else
					p=p->next;
			}
			if(!p&&np)
			{
				cout<<"*****************************************|��Ŵ�������������|*****************************************"<<endl;}
			np=nhead->next;
			while(np)
			{
				delete nhead;
				nhead=np;np=np->next;
			}delete nhead;
			p=head;
		}
		else if(c=="ɾ��"||c=="shanhuo")
		{
			cout<<"��������ɾ���Ļ���ı��(-1��������)��";nhead=np=crea();p=head->next;q=head;
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
				cout<<"*****************************************|��Ŵ�������������|*****************************************"<<endl;}
			else
			cout<<"**********************************************|ɾ���ɹ�|************************************************"<<endl;
			np=nhead->next;
			while(np)
			{
				delete nhead;
				nhead=np;np=np->next;
			}delete nhead;
			p=head;
		}
		else if(c=="�������"||c=="shuchusuoyou")
		{
			cout<<left<<setw(11)<<"���"<<left<<setw(11)<<"����"<<left<<setw(11)<<"����"<<left<<setw(11)<<"�������"<<left<<setw(11)<<"�������"<<left<<setw(11)
				<<"��������"<<left<<setw(11)<<"������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��ע"<<endl;
			while(p)
			{
				p->show();
				p=p->next;
			}
			k=0;
			p=head;
		}
		cout<<"*************************************|����1��������������0�˳�����|*************************************"<<endl;
		cin>>k;
	}
	ofstream outfile;
	outfile.open("1.txt",ios::out);
	p=head;
	outfile<<left<<setw(11)<<"���"<<left<<setw(11)<<"����"<<left<<setw(11)<<"����"<<left<<setw(11)<<"�������"<<left<<setw(11)<<"�������"<<left<<setw(11)
		<<"��������"<<left<<setw(11)<<"������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��������"<<left<<setw(11)<<"��ע"<<endl;
	while(p)
	{
		outfile<<left<<setw(11)<<p->getnum()<<left<<setw(11)<<p->getname()<<left<<setw(11)<<p->getp()<<left<<setw(11)<<p->getinn()<<left<<setw(11)<<p->getstay()
			<<left<<setw(11)<<p->getoun()<<left<<setw(11)<<p->getk()<<left<<setw(11)<<p->getit()<<left<<setw(11)<<p->getot()<<left<<setw(11)<<p->getno()<<endl;
		p=p->next;
	}
	outfile.close();
	return 0;
}