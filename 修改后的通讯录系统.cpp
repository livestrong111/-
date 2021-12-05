
#include <iostream> 

#include <string>
using namespace std;
#define MAX 1500


struct Person
{
	string m_Name;
	
	string m_Sex;
	
	int m_Age;
	
	string m_Phone;
	
	string m_Address;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_SIZE; 
};
int contrast(Addressbooks * abs,string name,string sex,int age,string phone,string address)
{
	int flag = -1;
	 for (int i = 0; i < abs->m_SIZE-1; i++)
	 {
	  
	  if (abs->personArray[i].m_Name == name)
	  {
	  	if(abs->personArray[i].m_Sex == sex)
	  	{
		  	if(abs->personArray[i].m_Age == age)
		  	{
			  	if(abs->personArray[i].m_Phone==phone)
			  	{
				  	if(abs->personArray[i].m_Address == address)
				  		   return i; 
				}
			  }
		  }

	  }
	 }
	 return flag; 
}
//1.添加联系人
void addPerson(Addressbooks * abs)
{
	if (abs->m_SIZE == MAX)
	{
		cout << "通讯录已满，无法添加!" << endl;
		return;
	}
	else
	{

		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_SIZE].m_Name = name;

		cout << "请输入性别: " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int s = 0;
		string sex;
		while (true)
		{
			cin >> s;
			if (s == 1 )
			{
				abs->personArray[abs->m_SIZE].m_Sex = "Man";
				sex = "Man";
				break;
			}
			if (s == 2 )
			{
				abs->personArray[abs->m_SIZE].m_Sex="Woman";
				sex = "Women";
				break; 
			}
			cout << "输入有误，请重新输入" << endl;
		}


		cout << "请输入年龄: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_SIZE].m_Age = age;

		cout << "请输入联系电话: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_SIZE].m_Phone = phone;

		cout << "请输入家庭住址: " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_SIZE].m_Address = address;

		abs->m_SIZE++;
		int ret=contrast(abs,name,sex,age,phone,address);
		if(ret==-1)
			cout << "添加成功" << endl;
		else
		{
			abs->m_SIZE--;
			cout <<"添加失败，该联系人已存在，请重新添加！"<<endl; 
		}

		system("pause"); 
		system("cls");  

	}
}
int isExist(Addressbooks * abs, string name)
{
	int flag = -1;
	for (int i = 0; i < abs->m_SIZE; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			cout << "\t姓名: " << abs->personArray[i].m_Name;
			cout << "\t\t性别: " << abs->personArray[i].m_Sex;
			cout << "\t\t年龄: " << abs->personArray[i].m_Age;
			cout << "\t\t电话: " << abs->personArray[i].m_Phone;
			cout << "\t\t家庭住址: " << abs->personArray[i].m_Address << endl;
			flag = i;
		}
	}
	return flag; 
}

//2.删除指定联系人
void deletePerson(Addressbooks * abs)
{
	cout << "请输入您要删除的联系人: " << endl;

	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->m_SIZE; i++)
		{
	
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_SIZE--; 
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	system("pause");
	system("cls");
}
int seek(Addressbooks * abs, string name)
{
 int flag = -1;
 for (int i = 0; i < abs->m_SIZE; i++)
 {
  
  if (abs->personArray[i].m_Name == name)
  {
   return i; 
  }
 }
 return flag; 
}
//3. 查找指定联系人信息
void findPerson(Addressbooks *abs)
{
	cout << "请输入你要查找的联系人: " << endl;
	string name;
	cin >> name;

	int ret = seek(abs, name);

	if (ret != -1)  
	{
		cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
		cout << "性别: " << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
		cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
		cout << "家庭住址: " << abs->personArray[ret].m_Address << endl;
		ret++;
	}
	else      
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

int isLocal(Addressbooks * abs, string address)
{
 int flag = -1;
 for (int i = 0; i < abs->m_SIZE; i++)
 {
  
  if (abs->personArray[i].m_Address == address)
  {
   return i; 
  }
 }
 return flag; 
}
//4.筛选联系人
void screenPerson(Addressbooks * abs)
{
	cout << "请输入你要筛选的地区" << endl;
	string address;
	cin >> address;

	int ret = isLocal(abs, address);
	if(ret!=-1)
		for(;ret<abs->m_SIZE;ret++)
		{
			if (abs->personArray[ret].m_Address == address) 
			{
				cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
				cout << "性别: " << abs->personArray[ret].m_Sex << "\t";
				cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
				cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
				cout << "家庭住址: " << abs->personArray[ret].m_Address << endl;
			}
		}
	else   
	{
		cout << "没有找到该地区的联系人" << endl;
	}
	system("pause");
	system("cls");
}

//5.修改指定联系人信息
void modifyPerson(Addressbooks * abs)
{
	cout << "请输入你要修改的联系人: " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) 
	{
		cout << "请输入年龄: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;


		cout << "请输入家庭地址: " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;

		cout << "修改成功! " << endl;


	}
	else  
	{
		cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");
}




//6.清空联系人
void cleanPerson(Addressbooks * abs)
{
	abs->m_SIZE = 0; 
	cout << "通讯录已清空" << endl;

	system("pause");
	system("cls");


}


//菜单界面
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.删除联系人 *****" << endl;
	cout << "***** 3.查找联系人 *****" << endl;
	cout << "***** 4.筛选联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
	
}

int main()
{
	Addressbooks abs;
	abs.m_SIZE = 0;

	int select = 0; 

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: //1.添加联系人
			addPerson(&abs); //利用地址传递可以修饰形参
			break;
		case 2: //2.删除联系人
			//{
			// cout << "请输入删除联系人的姓名: " << endl;
			// string name;
			// cin >> name;

			// if (isExist(&abs, name) == -1)
			//{
			//	cout << "查无此人" << endl;
			// }
			// else
			// {
			//	cout << "找到此人" << endl;
			// }
			// }
			deletePerson(&abs);
			break;
		case 3: //3.查找联系人
			findPerson(&abs);
			break;
		case 4: //4.筛选联系人
		//{
			// cout << "请输入你要筛选的地区： " << endl;
			// string address;
			// cin >> address;

			// if (isExist(&abs, name) == -1
			//{
			// cout << "没有查到该地区的联系人" << endl;
			// }
			//else
			// {
			// cout << "找到该地区联系人" << endl;
			// }
			// }
			screenPerson(&abs);
			break;
		case 5: //5.修改联系人
		    modifyPerson(&abs);
			break;
		case 6: //6.清空联系人
			cleanPerson(&abs);
			break;
		case 0: //0.退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
		}
	}
}
