#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
	int data;
	Node* next;

};
typedef	Node* List;

 //-----Ten Ham Con ------//
 void Init ();
 void Del ();
 void AddHead ();
 void Menu ();
 void Nhap ();
 void Xuat ();
 void Lap ();
 void ThucHienChuongTrinh ();
 void ThongTin ();
 void Chon ();
 void RamDom();
 
 // ---- DINH NGHIA HAM ---- //
 
 Node* CreateNode(int x) // Ham tao 1 Node
{
	Node* p = new Node;
	p->next = NULL;
	p->data = x;
	return p;

}
void Init(List& head)
{
	head = NULL;

}
//---------------------
void Del(List& head, Node* p) // Ham xoa 1 Node
{
	Node* q = head;
	head = head->next;
	p->next = head;
	delete q;
}
//---------------------
void AddHead(List& head, Node* p) 
{
	p->next = head;
	head = p;
}
//---------------------
void Menu() // Danh sach chon
{
	cout << "DO AN GIAI THUAT VA LAP TRINH" << endl;
    cout << "CHUONG TRINH BAI TOAN JOSEPHUS" << endl;
    cout << "------------*******------------" << endl;
    cout << "=============MENU==============" << endl;
    cout << "1. Thuc Hien Chuong Trinh" << endl;
    cout << "2. Thong Tin Sinh Vien Va Giao Vien" << endl;
	cout << "3. Thoat " << endl;
}
//---------------------
void Nhap(List& head, int n) // Ham tao 1 List Node co gia tri tu 1 den n
{
	Node* q = new Node;
	for (int i = n; i >= 1; i--)
	{
		Node* p = CreateNode(i);
		if (i == n)
			q = p;
		AddHead(head, p);

	}
	q->next = head;
	

}
//---------------------
void Xuat(List head) // Ham xuat gia tri cua chuong trinh
{
	cout << "Nguoi cuoi cung con song la : "<< head->data << endl;
	cout << endl;

}
//---------------------
void RamDom(List& head, int k){

	while (head-> data != k)
	{
		Node* p = head;
		head = head->next;
	}
}
void Lap(List& head, int n) // Ham lap de xoa nguoi choi thu k
{
	int count = 1;
	
	while (head-> next != head)
	{
		count++;
		Node* p = head;
		head = head->next;
		if (count == n)
		{
			count = 1;
			Del(head, p);
		}
	}
}


//---------------------
void ThucHienChuongTrinh () // Ham thuc hien chuong trinh
{
	List head;
	Init(head);
	int n ;
	do{
	cout << "Nhap n (n > 1), so nguoi trong vong tron: " << endl;
	cin >> n;
	} while (n <= 1);
	srand(time(NULL));
	int k = rand() % (n - 2 + 1) + 2;
	cout << "so thu tu nguoi chon ngau nhien: " << k << endl;
	Nhap(head, n);
	RamDom(head, k);
	Lap(head, n);
	Xuat(head);
	cout << " ---------- "  << endl;
	cout << "Nhap 1 de quay lai ! \n Nhan bat ky de thoat \n" << endl;
	int b;
	cin >> b;

	if (b == 1)
	{
	Menu();
	Chon();
	}
}
//---------------------
void Chon () // Ham chon
{
	int kt;
	do
    {  cout << "Ban Chon: ";
	   cin >> kt;
	   cout << endl;
	}
	while( kt <= 0 || kt >=4);
	
	switch (kt)
	{
		case 1 :
			{
				ThucHienChuongTrinh();
				break;
			}
		case 2 :
			{
				ThongTin();
				break;
			}
		case 3 :
			{
				break;
			}
	}
}
//-------------------
void ThongTin() // Ham in thong tin
{
	cout << " Giang Vien Huong Dan : Nguyen Thi Minh Hy " << endl;
	cout << " Lop : 18.77C \n Nhom : 09 " << endl;
	cout << " Sinh Vien Thuc Hien : \n Tran Thanh Lo & Vo Van Nhat Khoa 18THXD " << endl;
	cout << " ------------- \n Cam On Thay Co Da Xem Chuong Trinh \n\n " << endl;
	cout << "Nhap 1 de quay lai ! \n Nhan bat ky de thoat \n" << endl;
	int a;
	cin >> a;
	if (a == 1)
	{
	Menu();
	Chon();
	}
}
//------------MAIN------------//
int main()
{
	Menu();
	Chon();
	system("pause");
	return 0;
}


