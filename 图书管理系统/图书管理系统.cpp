#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int bookTotal = 0;                         //������� 
int thesisTotal = 0;                      //�������� 
int total = 0;                           // �û����� 

//һ�����������

//**********************************ͼ����********************************////////////////////////////////////////////////////////////////////////////////////////////////



class Book{
	public:
		int get_ID()             //get ͼ��ĸ������� 
		{
			return ID;
		}
		char *get_ISBN()
		{
			return ISBN;
		}
		char *get_Name()
		{
			return Name;
		}
		char *get_Pubh()
		{
			return Pubh;
		}
		char *get_Author()
		{
			return Author;
		}
		char *get_Spot()
		{
			return Spot;
		}
		char *get_Preserver()
		{
			return Preserver;
		}
		int get_State()
		{
			return State;
		}
		void set_ID(int n_id)                 //set ͼ��ĸ������� 
		{
			ID = n_id;
		}
		void set_ISBN(char n_isbn[])
		{
			strcpy(ISBN,n_isbn);
		}
		void set_Name(char n_name[])
		{
			strcpy(Name,n_name);
		}
		void set_Pubh(char n_pubh[])
		{
			strcpy(Pubh,n_pubh);
		}
		void set_Author(char n_author[])
		{
			strcpy(Author,n_author);
		}
		void set_Spot(char n_spot[])
		{
			strcpy(Spot,n_spot);
		}
		void set_Preserver(char n_preserver[])
		{
			strcpy(Preserver,n_preserver);
		}
		void set_State(int n_state)
		{
			State = n_state;
		}
	private:
		int ID;                      //��� 
		char ISBN[20];               //ISBN 
		char Name[20];               //���� 
		char Pubh[20];               //������ 
		char Author[20];             //���� 
		char Spot[20];               //���λ�� 
		char Preserver[20];          //������ 
		int State;                   //״̬ ��1���ڿ⣻ 0���ڽ裻 2����ɾ����ɾ����ǣ� 
};
Book book[10000];



//************************������*******************************************/////////////////////////////////////////////////////



class Thesis
{
	public:
		int get_id()           // get���ĵĸ������� 
		{
			return id;
		}
		char *get_title()
		{
			return title;
		}
		char *get_author()
		{
			return author;
		}
		char *get_perio()
		{
			return perio;
		}
		char *get_time()
		{
			return time;
		}
		char *get_spot()
		{
			return spot;
		}
		char *get_otherdec()
		{
			return otherdec;
		}
		void set_id(int t_id)            //set���ĵĸ������� 
		{
			id = t_id;
		}
		void set_title(char t_title[])
		{
			strcpy(title,t_title);
		}
		void set_author(char t_author[])
		{
			strcpy(author,t_author);
		}
		void set_perio(char t_perio[])
		{
			strcpy(perio,t_perio);
		}
		void set_time(char t_time[])
		{
			strcpy(time,t_time);
		}
		void set_spot(char t_spot[])
		{
			strcpy(spot,t_spot);
		}
		void set_otherdec(char t_otherdec[])
		{
			strcpy(otherdec,t_otherdec);
		}
	private:
		int id;                          //��� 
		char title[20];                  //���� 
		char author[20];                 //���� 
		char perio[20];                  //���� 
		char time[20];                   //ʱ�� 
		char spot[20];                   //���λ�� 
		char otherdec[20];               //��ע 
};
Thesis thesis[10000];



//******************************ͼ�������***************************������ͬ,��������Ĺ���ʵ�ֺ�����ûд�꣩//////////////////////////////////////////////////////////// 



class adminB:public Book, Thesis
{
	public:
		adminB()                                  //���캯���������ļ���ʼ�� 
		{
			Book n_b;
			fstream file("D:\\data.txt",ios::in);
			while(1)
			{
				file.read((char*)&n_b,sizeof(n_b));
				if(file == NULL) break;
				bookTotal++;
				book[bookTotal] = n_b;
			}
			file.close(); 
		}
		void Search(int d);
		void Search(char d[]);
		void Input();
		void Update();
		void Delete();
		void View();
		~adminB()                          //�������������ڽ���ʱ�������ĸĶ�д���ļ��� 
		{
			fstream file("D:\\data.txt",ios::out);
			for(int i = 1; i <= bookTotal; i++)
			{
				if(book[i].get_State() != 2)
				{
					file.write(reinterpret_cast<char*>(&book[i]),sizeof(book[i]));
				}
			}
			file.close();
		}
		 
};    


void adminB::Search(int d){                        //����Ų���ͼ�� 
	int i;
	for(i = 1; i <= bookTotal; i++){
		if(book[i].get_ID() == d){
			if(book[i].get_State() == 1){
				cout<<book[i].get_ID()<<" "<<book[i].get_ISBN()<<" "<<book[i].get_Name()<<" "<<book[i].get_Pubh()<<" "<<book[i].get_Author()<<" "<<book[i].get_Spot()<<" "<<book[i].get_Preserver()<<" "<<book[i].get_State()<<endl;
				return;
			}
			else if(book[i].get_State() == 0){
				cout<<"ͼ���ڽ�"<<endl; 
				return;
			}
			else if(book[i].get_State() == 2){
				cout<<"ͼ����ɾ��"<<endl;
				return;
			}
			break;
		}
	}
	if(i == bookTotal+1){
		cout<<"δ�ҵ����飡"<<endl; 
		return;
	}
}

                                                                
void adminB::Search(char d[]){                   //�����Ʋ���ͼ�� 
	int i;
	for(i = 1; i <= bookTotal; i++){
		if(strcmp(book[i].get_Name(),d) == 0){
			if(book[i].get_State() == 1){
				cout<<book[i].get_ID()<<" "<<book[i].get_ISBN()<<" "<<book[i].get_Name()<<" "<<book[i].get_Pubh()<<" "<<book[i].get_Author()<<" "<<book[i].get_Spot()<<" "<<book[i].get_Preserver()<<" "<<book[i].get_State()<<endl;
			}
			else if(book[i].get_State() == 0){
				cout<<"ͼ���ڽ�"<<endl;
			}
			else if(book[i].get_State() == 2){
				cout<<"ͼ����ɾ��"<<endl;
			}
			break;
		}
	}
	if(i == bookTotal+1){
		cout<<"δ�ҵ����飡"<<endl; 
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////


void adminB::Input(){                              //¼����ͼ������� 
	cout<<"¼��ͼ����Ϣ����1"<<endl;
	cout<<"¼��������Ϣ����2"<<endl;
	int num6;
	cin>>num6;
	if(num6 == 1){
		bookTotal++; 
		cout<<"��������"<<endl;
		int n_id;
		cin>>n_id;
		book[bookTotal].set_ID(n_id);
		cout<<"������ISBN"<<endl;
		char n_isbn[20];
		cin>>n_isbn;
		book[bookTotal].set_ISBN(n_isbn);
		cout<<"����������"<<endl;
		char n_name[20];
		cin>>n_name;
		book[bookTotal].set_Name(n_name);
		cout<<"�����������"<<endl;
		char n_pubh[20];
		cin>>n_pubh;
		book[bookTotal].set_Pubh(n_pubh);
		cout<<"����������"<<endl;
		char n_author[20];
		cin>>n_author;
		book[bookTotal].set_Author(n_author);
		cout<<"��������λ��"<<endl;
		char n_spot[20];
		cin>>n_spot;
		book[bookTotal].set_Spot(n_spot);
		cout<<"�����뱣����"<<endl;
		char n_preserver[20];
		cin>>n_preserver;
		book[bookTotal].set_Preserver(n_preserver);
		int n_state = 1;
		book[bookTotal].set_State(n_state); 
	}
	//else if(num6 == 2)                  

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void adminB::Update(){                                            //����ͼ����Ϣ 
	cout<<"������Ҫ���ĵ�ͼ�����ƣ�"<<endl;
	char b_name[20];
	cin>>b_name;
	int k;
	for(int i = 1; i <= bookTotal; i++){
		if(strcmp(book[i].get_Name(),b_name) == 0){
			k = i;	
		}
	}
	cout<<"�������޸ĺ��ͼ�����ƣ�"<<endl;
	char u_name[20];
	cin>>u_name;
	book[k].set_Name(u_name);
	cout<<"�������޸ĺ��ͼ��ISBN��"<<endl;
	char u_isbn[20];
	cin>>u_isbn;
	book[k].set_ISBN(u_isbn);
	cout<<"�������޸ĺ��ͼ������磺"<<endl;
	char u_pubh[20];
	cin>>u_pubh;
	book[k].set_Pubh(u_pubh);
	cout<<"�������޸ĺ�����ߣ�"<<endl;
	char u_author[20];
	cin>>u_author;
	book[k].set_Author(u_author);
	cout<<"�������޸ĺ�Ĵ��λ�ã�"<<endl;
	char u_spot[20];
	cin>>u_spot;
	book[k].set_Spot(u_spot);
	cout<<"�������޸ĺ�ı����ߣ�"<<endl;
	char u_preserver[20];
	cin>>u_preserver;
	book[k].set_Preserver(u_preserver);
	cout<<"�������޸ĺ���ڿ�״̬���ڿ�����1����������0"<<endl; 
	int u_state;
	cin>>u_state;
	book[k].set_State(u_state); 
}


///////////////////////////////////////////////////////////////////////////////////////


void adminB::Delete(){                       //ɾ��ͼ����Ϣ 
	cout<<"������Ҫɾ����ͼ�����ƣ�"<<endl;
	char d_name[20];
	cin>>d_name;
	for(int i = 1; i <= bookTotal; i++){
		if(strcmp(book[i].get_Name(),d_name) == 0){
			int s = 2;
			book[i].set_State(s);
		}
		break;
	}
	bookTotal--;
}


//////////////////////////////////////////////////////////////////////////////


void adminB::View()                                  //����Ԥ��ͼ�飬���庯��ʵ�ֲ����� 
{
	cout<<"��������������Ԥ����ͼ�����ƣ�"<<endl;
	char Ronline[20];
	cin>>Ronline;
	ifstream in("D:\\ͼ������.txt");
	for(string str; getline(in,str);)
	{
		cout<<str<<endl;
	}
	return;
} 


//***************************�û���***********************************************//////////////////////////////////////////////////////


class User{
	public:
		char *get_uname()                            //get�û��ĸ������� 
		{
			return uname;
		}
		int get_username()
		{
			return username;
		}
		char *get_password()
		{
			return password;
		}
		int get_tag()
		{
			return tag;
		}
		void set_uname(char n_uname[])               //set�û��ĸ������� 
		{
			strcpy(uname,n_uname);
		}
		void set_username(int n_username)
		{
			username = n_username;
		}
		void set_password(char n_password[])
		{
			strcpy(password,n_password);
		}
		void set_tag(int n_tag)
		{
			tag = n_tag;
		}
		void Bbook();  
		void Rbook(); 
	 	//int PIN(char Password[]);                                 
	private:
		char uname[20];                  //���� 
		int username;                    //�û��� 
		char password[20];               //���� 
		int tag;                         //ɾ����� 
};
User user[10000];



////////////////////////////////////////////////////////////////////



void User::Bbook()                                  //���� 
{
	cout<<"��������Ҫ���ͼ�����ƣ�"<<endl;
	char w_book[20];
	cin>>w_book;
	int k;
	int s1 = 0;
	for(k = 1; k <= bookTotal; k++)
	{
		if(strcmp(book[k].get_Name(),w_book) == 0)
		{
			if(book[k].get_State() == 1){
				book[k].set_State(s1);
				cout<<"���ĳɹ���"<<endl;
				bookTotal -= 1;
				break;
			}
			else
			{
				cout<<"�����ڽ�"<<endl;
				break; 
			}
		}
	}
	if(k == bookTotal+1)
	{
		cout<<"δ�ҵ����飡"<<endl; 
	}
}

/////////////////////////////////////////////////////////////////

void User::Rbook()                                   //���� 
{
	cout<<"��������Ҫ�黹��ͼ�����ƣ�"<<endl;
	char r_book[20];
	cin>>r_book;
	int k1;
	int s2 = 1;
	for(k1 = 1; k1 <= bookTotal; k1++)
	{
		if(strcmp(book[k1].get_Name(),r_book) == 0)
		{
			if(book[k1].get_State() != 2){
				book[k1].set_State(s2);
				cout<<"����ɹ���"<<endl;
				bookTotal += 1;
				break;
			}
		}
	}
	if(k1 == bookTotal+1)
	{
		cout<<"δ�ҵ����飡"<<endl; 
	}
}


//******************************�û�������*********************************/////////////////////////////////////////////////////////


class accountMA : public User
{
	public:
		accountMA()                          //���캯���������û���Ϣ��ʼ�� 
		{
			User n_R;
			fstream file("D:\\readerdata.txt",ios::in);
			while(1)
			{
				file.read((char*)&n_R,sizeof(n_R));
				if(file == NULL) break;
				total++;
				user[total] = n_R;
			}
			file.close(); 
		}
		void add_user();
		void update_user();
		void delete_user();
		~accountMA()                            //�������������Ķ�����Ϣд���ļ� 
		{
			fstream file("D:\\readerdata.txt",ios::out);
			for(int i = 1; i <= total; i++)
			{
				if(user[i].get_tag() == 1)
				{
					file.write(reinterpret_cast<char*>(&user[i]),sizeof(user[i]));
				}
			}
			file.close();
		}
}; 


/////////////////////////////////////////////////////////////////////////////////////////


void accountMA::add_user()                 //����û� 
{
	total += 1;
	int s5 = 1;
	user[total].set_tag(s5); 
	cout<<"������������"<<endl;
	char n_uname[20];
	cin>>n_uname;
	user[total].set_uname(n_uname);
	cout<<"�������û�����"<<endl;
	int n_username;
	cin>>n_username;
	user[total].set_username(n_username);
	cout<<"���������룺"<<endl;
	char n_password[20];
	cin>>n_password;
	user[total].set_password(n_password);
	cout<<endl;
}


/////////////////////////////////////////////////////////////////////////////////////////


void accountMA::update_user()                //�����û���Ϣ 
{
	cout<<"������Ҫ���ĵ��û�������"<<endl;
	char b_uname[20];
	cin>>b_uname;
	int k5;
	for(int i = 1; i <= total; i++){
		if(strcmp(user[i].get_uname(),b_uname) == 0){
			k5 = i;	
		}
	}
	cout<<"�������޸ĺ���û�����"<<endl;
	int u_username;
	cin>>u_username;
	user[k5].set_username(u_username);
	cout<<"�������޸ĺ�����룺"<<endl;
	char u_password[20];
	cin>>u_password;
	user[k5].set_password(u_password);
	
}


///////////////////////////////////////////////////////////////////////////////////////////


void accountMA::delete_user()                               //ע���û� 
{
	cout<<"������Ҫɾ�����û�������"<<endl;
	char d_uname[20];
	cin>>d_uname;
	for(int i = 1; i <= total; i++){
		if(strcmp(user[i].get_uname(),d_uname) == 0){
			int s3 = 0;
			user[i].set_tag(s3);
		}
		break;
	}
	total--;
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




int main()
{
	here:
	cout<<"--------------------��ӭʹ��ͼ�����ϵͳ��---------------------"<<endl; 
	cout<<endl;
	cout<<"-----------------------���ߵ�½����1---------------------------"<<endl;
	cout<<endl;
	cout<<"-----------------------����Ա��½����2-------------------------"<<endl; 
	cout<<endl;
	cout<<"-----------------------�˳�����0-------------------------------"<<endl; 
	Book *tebook;
	adminB teadminB;
	User *teuser;
	accountMA teaccountMA;
	int num1;
	cin>>num1;
	switch(num1){
		case 1:
		{
			cout<<"----------�����û���(ѧ��)��"<<endl;
			long sid;
			char mima[20];
			cin>>sid;		
			if((sid >= 1000000000)&&(sid <= 9999999999))
			{
				cout<<"----------�������룺"<<endl;
				cin>>mima;
				for(int i = 1; i <= total; i++)
				{
					if(sid == user[i].get_username())
					{
						if(strcmp(mima,user[i].get_password()) == 0)
						{
							cout<<"-----------------------��½�ɹ���-----------------------"<<endl;
							cout<<"----------ͼ���������1"<<endl; 
							cout<<"----------ͼ���������2"<<endl;
							cout<<"----------ͼ��黹����3"<<endl;
							cout<<"----------�����������4"<<endl;
							int num2;
							cin>>num2;
							switch(num2)
							{
								case 1:
								{
									cout<<"----------��Ų�������1��"<<endl;
									cout<<"----------������������2��"<<endl;
									int num3;
									cin>>num3;
									switch(num3)
									{
										case 1:
										{
											cout<<"----------����ͼ���ţ�"<<endl;
											int d;
											cin>>d;
											teadminB.Search(d);
											break;
										}	
										case 2:
										{
											cout<<"----------����ͼ�����ƣ�"<<endl;
											char d[20];
											cin>>d[20];
											teadminB.Search(d);
											break;
										}
									} 	
									break;
								} 
								case 2:
								{
									teuser->Bbook();
									break;
								} 
								case 3:
								{
									teuser->Rbook();
									break;
								}
							}
							cout<<"----------��������������1"<<endl;
							cout<<"----------�˳�����2"<<endl;
							int num9;
							cin>>num9;
							switch(num9)
							{
								case 1: goto here;
								case 2: return 0;	
							} 
						}
						else
						{
							cout<<"-----------------------������󣬵�¼ʧ�ܣ�-----------------------"<<endl;
							return 0;
						}
					}
				}
			} 
			else
			{
				cout<<"-----------------------���˺Ų����ڣ�-----------------------"<<endl;
				return 0;
			}
		}

		case 0:
		{
			break;
			return 0;
		}
		case 2:
		{
			cout<<"----------���������Ա���룺"<<endl;
			long mimaM;
			cin>>mimaM;
			if(mimaM == 2017202057)
			{
				cout<<"-----------------------��½�ɹ���-----------------------"<<endl;
				cout<<"----------ͼ���������1"<<endl;
				cout<<"----------ͼ��¼������2"<<endl;
				cout<<"----------ͼ���������3"<<endl;
				cout<<"----------ͼ��ɾ������4"<<endl;
				cout<<"----------��Ӷ�������5"<<endl;
				cout<<"----------���¶�������6"<<endl;
				cout<<"----------ɾ����������7"<<endl;
				int num4;
				cin>>num4;
				switch(num4)
				{
					case 1:
					{
						cout<<"----------��Ų�������1��"<<endl;
						cout<<"----------������������2��"<<endl;
						int num5;
						cin>>num5;
						switch(num5)
						{
							case 1:
							{
								cout<<"----------����ͼ���ţ�"<<endl;
								int d1;
								cin>>d1;
								teadminB.Search(d1);
								break;
							}
							case 2:
							{
								cout<<"----------����ͼ�����ƣ�"<<endl;
								char d1[20];
								cin>>d1[20];
								teadminB.Search(d1);
								break;
							}
						} 
						break;
					}
					case 2:
					{
						teadminB.Input();
						break;	
					}
					case 3:
					{
						teadminB.Update();
						break;	
					}
					case 4:
					{
						teadminB.Delete();
						break;	
					}
					case 5:
					{
						teaccountMA.add_user();
						break;
					}
					case 6:
					{
						teaccountMA.update_user();
						break;
					}
					case 7:
					{
						teaccountMA.delete_user();
						break;
					}
				} 
				cout<<"----------��������������1"<<endl;
				cout<<"----------�˳�����2"<<endl;
				int num19;
				cin>>num19;
				switch(num19)
				{
					case 1: goto here;
					case 2: return 0;	
				} 
			}
			else
			{
				cout<<"-----------------------������󣡵�¼ʧ�ܣ�-----------------------"<<endl;
				return 0;
			}
		}
	}
	return 0;
}
