
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
//1.�����ϵ��
void addPerson(Addressbooks * abs)
{
	if (abs->m_SIZE == MAX)
	{
		cout << "ͨѶ¼�������޷����!" << endl;
		return;
	}
	else
	{

		string name;
		cout << "����������: " << endl;
		cin >> name;
		abs->personArray[abs->m_SIZE].m_Name = name;

		cout << "�������Ա�: " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
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
			cout << "������������������" << endl;
		}


		cout << "����������: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_SIZE].m_Age = age;

		cout << "��������ϵ�绰: " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_SIZE].m_Phone = phone;

		cout << "�������ͥסַ: " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_SIZE].m_Address = address;

		abs->m_SIZE++;
		int ret=contrast(abs,name,sex,age,phone,address);
		if(ret==-1)
			cout << "��ӳɹ�" << endl;
		else
		{
			abs->m_SIZE--;
			cout <<"���ʧ�ܣ�����ϵ���Ѵ��ڣ���������ӣ�"<<endl; 
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
			cout << "\t����: " << abs->personArray[i].m_Name;
			cout << "\t\t�Ա�: " << abs->personArray[i].m_Sex;
			cout << "\t\t����: " << abs->personArray[i].m_Age;
			cout << "\t\t�绰: " << abs->personArray[i].m_Phone;
			cout << "\t\t��ͥסַ: " << abs->personArray[i].m_Address << endl;
			flag = i;
		}
	}
	return flag; 
}

//2.ɾ��ָ����ϵ��
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ��: " << endl;

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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
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
//3. ����ָ����ϵ����Ϣ
void findPerson(Addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ��: " << endl;
	string name;
	cin >> name;

	int ret = seek(abs, name);

	if (ret != -1)  
	{
		cout << "����: " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�: " << abs->personArray[ret].m_Sex << "\t";
		cout << "����: " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
		cout << "��ͥסַ: " << abs->personArray[ret].m_Address << endl;
		ret++;
	}
	else      
	{
		cout << "���޴���" << endl;
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
//4.ɸѡ��ϵ��
void screenPerson(Addressbooks * abs)
{
	cout << "��������Ҫɸѡ�ĵ���" << endl;
	string address;
	cin >> address;

	int ret = isLocal(abs, address);
	if(ret!=-1)
		for(;ret<abs->m_SIZE;ret++)
		{
			if (abs->personArray[ret].m_Address == address) 
			{
				cout << "����: " << abs->personArray[ret].m_Name << "\t";
				cout << "�Ա�: " << abs->personArray[ret].m_Sex << "\t";
				cout << "����: " << abs->personArray[ret].m_Age << "\t";
				cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
				cout << "��ͥסַ: " << abs->personArray[ret].m_Address << endl;
			}
		}
	else   
	{
		cout << "û���ҵ��õ�������ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

//5.�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks * abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��: " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) 
	{
		cout << "����������: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;


		cout << "�������ͥ��ַ: " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;

		cout << "�޸ĳɹ�! " << endl;


	}
	else  
	{
		cout << "���޴���" << endl;

	}
	system("pause");
	system("cls");
}




//6.�����ϵ��
void cleanPerson(Addressbooks * abs)
{
	abs->m_SIZE = 0; 
	cout << "ͨѶ¼�����" << endl;

	system("pause");
	system("cls");


}


//�˵�����
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.ɾ����ϵ�� *****" << endl;
	cout << "***** 3.������ϵ�� *****" << endl;
	cout << "***** 4.ɸѡ��ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
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
		case 1: //1.�����ϵ��
			addPerson(&abs); //���õ�ַ���ݿ��������β�
			break;
		case 2: //2.ɾ����ϵ��
			//{
			// cout << "������ɾ����ϵ�˵�����: " << endl;
			// string name;
			// cin >> name;

			// if (isExist(&abs, name) == -1)
			//{
			//	cout << "���޴���" << endl;
			// }
			// else
			// {
			//	cout << "�ҵ�����" << endl;
			// }
			// }
			deletePerson(&abs);
			break;
		case 3: //3.������ϵ��
			findPerson(&abs);
			break;
		case 4: //4.ɸѡ��ϵ��
		//{
			// cout << "��������Ҫɸѡ�ĵ����� " << endl;
			// string address;
			// cin >> address;

			// if (isExist(&abs, name) == -1
			//{
			// cout << "û�в鵽�õ�������ϵ��" << endl;
			// }
			//else
			// {
			// cout << "�ҵ��õ�����ϵ��" << endl;
			// }
			// }
			screenPerson(&abs);
			break;
		case 5: //5.�޸���ϵ��
		    modifyPerson(&abs);
			break;
		case 6: //6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0: //0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		}
	}
}
