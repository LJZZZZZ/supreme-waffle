#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int bookTotal = 0;                         //书的总数 
int thesisTotal = 0;                      //论文总数 
int total = 0;                           // 用户总数 

//一共分了五个类

//**********************************图书类********************************////////////////////////////////////////////////////////////////////////////////////////////////



class Book{
	public:
		int get_ID()             //get 图书的各项属性 
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
		void set_ID(int n_id)                 //set 图书的各项属性 
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
		int ID;                      //编号 
		char ISBN[20];               //ISBN 
		char Name[20];               //书名 
		char Pubh[20];               //出版社 
		char Author[20];             //作者 
		char Spot[20];               //存放位置 
		char Preserver[20];          //保存者 
		int State;                   //状态 ：1：在库； 0：在借； 2：已删除（删除标记） 
};
Book book[10000];



//************************论文类*******************************************/////////////////////////////////////////////////////



class Thesis
{
	public:
		int get_id()           // get论文的各项属性 
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
		void set_id(int t_id)            //set论文的各项属性 
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
		int id;                          //编号 
		char title[20];                  //标题 
		char author[20];                 //作者 
		char perio[20];                  //刊物 
		char time[20];                   //时间 
		char spot[20];                   //存放位置 
		char otherdec[20];               //备注 
};
Thesis thesis[10000];



//******************************图书管理类***************************（论文同,不过具体的功能实现函数还没写完）//////////////////////////////////////////////////////////// 



class adminB:public Book, Thesis
{
	public:
		adminB()                                  //构造函数，加载文件初始化 
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
		~adminB()                          //析构函数，并在结束时将所做的改动写入文件中 
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


void adminB::Search(int d){                        //按编号查找图书 
	int i;
	for(i = 1; i <= bookTotal; i++){
		if(book[i].get_ID() == d){
			if(book[i].get_State() == 1){
				cout<<book[i].get_ID()<<" "<<book[i].get_ISBN()<<" "<<book[i].get_Name()<<" "<<book[i].get_Pubh()<<" "<<book[i].get_Author()<<" "<<book[i].get_Spot()<<" "<<book[i].get_Preserver()<<" "<<book[i].get_State()<<endl;
				return;
			}
			else if(book[i].get_State() == 0){
				cout<<"图书在借"<<endl; 
				return;
			}
			else if(book[i].get_State() == 2){
				cout<<"图书已删除"<<endl;
				return;
			}
			break;
		}
	}
	if(i == bookTotal+1){
		cout<<"未找到该书！"<<endl; 
		return;
	}
}

                                                                
void adminB::Search(char d[]){                   //按名称查找图书 
	int i;
	for(i = 1; i <= bookTotal; i++){
		if(strcmp(book[i].get_Name(),d) == 0){
			if(book[i].get_State() == 1){
				cout<<book[i].get_ID()<<" "<<book[i].get_ISBN()<<" "<<book[i].get_Name()<<" "<<book[i].get_Pubh()<<" "<<book[i].get_Author()<<" "<<book[i].get_Spot()<<" "<<book[i].get_Preserver()<<" "<<book[i].get_State()<<endl;
			}
			else if(book[i].get_State() == 0){
				cout<<"图书在借"<<endl;
			}
			else if(book[i].get_State() == 2){
				cout<<"图书已删除"<<endl;
			}
			break;
		}
	}
	if(i == bookTotal+1){
		cout<<"未找到该书！"<<endl; 
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////


void adminB::Input(){                              //录入新图书或论文 
	cout<<"录入图书信息输入1"<<endl;
	cout<<"录入论文信息输入2"<<endl;
	int num6;
	cin>>num6;
	if(num6 == 1){
		bookTotal++; 
		cout<<"请输入编号"<<endl;
		int n_id;
		cin>>n_id;
		book[bookTotal].set_ID(n_id);
		cout<<"请输入ISBN"<<endl;
		char n_isbn[20];
		cin>>n_isbn;
		book[bookTotal].set_ISBN(n_isbn);
		cout<<"请输入名称"<<endl;
		char n_name[20];
		cin>>n_name;
		book[bookTotal].set_Name(n_name);
		cout<<"请输入出版社"<<endl;
		char n_pubh[20];
		cin>>n_pubh;
		book[bookTotal].set_Pubh(n_pubh);
		cout<<"请输入作者"<<endl;
		char n_author[20];
		cin>>n_author;
		book[bookTotal].set_Author(n_author);
		cout<<"请输入存放位置"<<endl;
		char n_spot[20];
		cin>>n_spot;
		book[bookTotal].set_Spot(n_spot);
		cout<<"请输入保存者"<<endl;
		char n_preserver[20];
		cin>>n_preserver;
		book[bookTotal].set_Preserver(n_preserver);
		int n_state = 1;
		book[bookTotal].set_State(n_state); 
	}
	//else if(num6 == 2)                  

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void adminB::Update(){                                            //更新图书信息 
	cout<<"请输入要更改的图书名称："<<endl;
	char b_name[20];
	cin>>b_name;
	int k;
	for(int i = 1; i <= bookTotal; i++){
		if(strcmp(book[i].get_Name(),b_name) == 0){
			k = i;	
		}
	}
	cout<<"请输入修改后的图书名称："<<endl;
	char u_name[20];
	cin>>u_name;
	book[k].set_Name(u_name);
	cout<<"请输入修改后的图书ISBN："<<endl;
	char u_isbn[20];
	cin>>u_isbn;
	book[k].set_ISBN(u_isbn);
	cout<<"请输入修改后的图书出版社："<<endl;
	char u_pubh[20];
	cin>>u_pubh;
	book[k].set_Pubh(u_pubh);
	cout<<"请输入修改后的作者："<<endl;
	char u_author[20];
	cin>>u_author;
	book[k].set_Author(u_author);
	cout<<"请输入修改后的存放位置："<<endl;
	char u_spot[20];
	cin>>u_spot;
	book[k].set_Spot(u_spot);
	cout<<"请输入修改后的保存者："<<endl;
	char u_preserver[20];
	cin>>u_preserver;
	book[k].set_Preserver(u_preserver);
	cout<<"请输入修改后的在库状态：在库输入1，出库输入0"<<endl; 
	int u_state;
	cin>>u_state;
	book[k].set_State(u_state); 
}


///////////////////////////////////////////////////////////////////////////////////////


void adminB::Delete(){                       //删除图书信息 
	cout<<"请输入要删除的图书名称："<<endl;
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


void adminB::View()                                  //在线预览图书，具体函数实现不完善 
{
	cout<<"请输入您想在线预览的图书名称："<<endl;
	char Ronline[20];
	cin>>Ronline;
	ifstream in("D:\\图书名称.txt");
	for(string str; getline(in,str);)
	{
		cout<<str<<endl;
	}
	return;
} 


//***************************用户类***********************************************//////////////////////////////////////////////////////


class User{
	public:
		char *get_uname()                            //get用户的各项属性 
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
		void set_uname(char n_uname[])               //set用户的各项属性 
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
		char uname[20];                  //姓名 
		int username;                    //用户名 
		char password[20];               //密码 
		int tag;                         //删除标记 
};
User user[10000];



////////////////////////////////////////////////////////////////////



void User::Bbook()                                  //借书 
{
	cout<<"请输入您要借的图书名称："<<endl;
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
				cout<<"借阅成功！"<<endl;
				bookTotal -= 1;
				break;
			}
			else
			{
				cout<<"该书在借"<<endl;
				break; 
			}
		}
	}
	if(k == bookTotal+1)
	{
		cout<<"未找到该书！"<<endl; 
	}
}

/////////////////////////////////////////////////////////////////

void User::Rbook()                                   //还书 
{
	cout<<"请输入您要归还的图书名称："<<endl;
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
				cout<<"还书成功！"<<endl;
				bookTotal += 1;
				break;
			}
		}
	}
	if(k1 == bookTotal+1)
	{
		cout<<"未找到该书！"<<endl; 
	}
}


//******************************用户管理类*********************************/////////////////////////////////////////////////////////


class accountMA : public User
{
	public:
		accountMA()                          //构造函数，加载用户信息初始化 
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
		~accountMA()                            //析构函数，将改动的信息写入文件 
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


void accountMA::add_user()                 //添加用户 
{
	total += 1;
	int s5 = 1;
	user[total].set_tag(s5); 
	cout<<"请设置姓名："<<endl;
	char n_uname[20];
	cin>>n_uname;
	user[total].set_uname(n_uname);
	cout<<"请设置用户名："<<endl;
	int n_username;
	cin>>n_username;
	user[total].set_username(n_username);
	cout<<"请设置密码："<<endl;
	char n_password[20];
	cin>>n_password;
	user[total].set_password(n_password);
	cout<<endl;
}


/////////////////////////////////////////////////////////////////////////////////////////


void accountMA::update_user()                //更新用户信息 
{
	cout<<"请输入要更改的用户姓名："<<endl;
	char b_uname[20];
	cin>>b_uname;
	int k5;
	for(int i = 1; i <= total; i++){
		if(strcmp(user[i].get_uname(),b_uname) == 0){
			k5 = i;	
		}
	}
	cout<<"请输入修改后的用户名："<<endl;
	int u_username;
	cin>>u_username;
	user[k5].set_username(u_username);
	cout<<"请输入修改后的密码："<<endl;
	char u_password[20];
	cin>>u_password;
	user[k5].set_password(u_password);
	
}


///////////////////////////////////////////////////////////////////////////////////////////


void accountMA::delete_user()                               //注销用户 
{
	cout<<"请输入要删除的用户姓名："<<endl;
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
	cout<<"--------------------欢迎使用图书管理系统！---------------------"<<endl; 
	cout<<endl;
	cout<<"-----------------------读者登陆输入1---------------------------"<<endl;
	cout<<endl;
	cout<<"-----------------------管理员登陆输入2-------------------------"<<endl; 
	cout<<endl;
	cout<<"-----------------------退出输入0-------------------------------"<<endl; 
	Book *tebook;
	adminB teadminB;
	User *teuser;
	accountMA teaccountMA;
	int num1;
	cin>>num1;
	switch(num1){
		case 1:
		{
			cout<<"----------输入用户名(学号)："<<endl;
			long sid;
			char mima[20];
			cin>>sid;		
			if((sid >= 1000000000)&&(sid <= 9999999999))
			{
				cout<<"----------输入密码："<<endl;
				cin>>mima;
				for(int i = 1; i <= total; i++)
				{
					if(sid == user[i].get_username())
					{
						if(strcmp(mima,user[i].get_password()) == 0)
						{
							cout<<"-----------------------登陆成功！-----------------------"<<endl;
							cout<<"----------图书查找输入1"<<endl; 
							cout<<"----------图书借阅输入2"<<endl;
							cout<<"----------图书归还输入3"<<endl;
							cout<<"----------在线浏览输入4"<<endl;
							int num2;
							cin>>num2;
							switch(num2)
							{
								case 1:
								{
									cout<<"----------编号查找输入1："<<endl;
									cout<<"----------书名查找输入2："<<endl;
									int num3;
									cin>>num3;
									switch(num3)
									{
										case 1:
										{
											cout<<"----------输入图书编号："<<endl;
											int d;
											cin>>d;
											teadminB.Search(d);
											break;
										}	
										case 2:
										{
											cout<<"----------输入图书名称："<<endl;
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
							cout<<"----------返回主界面输入1"<<endl;
							cout<<"----------退出输入2"<<endl;
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
							cout<<"-----------------------密码错误，登录失败！-----------------------"<<endl;
							return 0;
						}
					}
				}
			} 
			else
			{
				cout<<"-----------------------该账号不存在！-----------------------"<<endl;
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
			cout<<"----------请输入管理员密码："<<endl;
			long mimaM;
			cin>>mimaM;
			if(mimaM == 2017202057)
			{
				cout<<"-----------------------登陆成功！-----------------------"<<endl;
				cout<<"----------图书查找输入1"<<endl;
				cout<<"----------图书录入输入2"<<endl;
				cout<<"----------图书更新输入3"<<endl;
				cout<<"----------图书删除输入4"<<endl;
				cout<<"----------添加读者输入5"<<endl;
				cout<<"----------更新读者输入6"<<endl;
				cout<<"----------删除读者输入7"<<endl;
				int num4;
				cin>>num4;
				switch(num4)
				{
					case 1:
					{
						cout<<"----------编号查找输入1："<<endl;
						cout<<"----------书名查找输入2："<<endl;
						int num5;
						cin>>num5;
						switch(num5)
						{
							case 1:
							{
								cout<<"----------输入图书编号："<<endl;
								int d1;
								cin>>d1;
								teadminB.Search(d1);
								break;
							}
							case 2:
							{
								cout<<"----------输入图书名称："<<endl;
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
				cout<<"----------返回主界面输入1"<<endl;
				cout<<"----------退出输入2"<<endl;
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
				cout<<"-----------------------密码错误！登录失败！-----------------------"<<endl;
				return 0;
			}
		}
	}
	return 0;
}
