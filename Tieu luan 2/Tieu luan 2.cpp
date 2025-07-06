// Tieu luan 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
// QUY TRINH TAO DANH SACH LIEN KET DON QUAN LY SINH VIEN
// Buoc 1: Khai bao phan tu node
typedef struct birth
{
	int day,month,year;
} birth ;
typedef struct sinhvien
{
	char mssv[10];
	char hoten[50];
	char sdt[20];
	char gioitinh[5];
	birth ngaysinh;
	char malop[15];
	float dtb;
	
} sinhvien;
typedef struct node
{
	sinhvien data;
	node* next;
} node ;

// Buoc 2: Tao node Head va Tail

typedef struct list
{
	node *pHead, *pTail;
}L;
// Buoc 3: Ham tao 1 node
node* getNode(sinhvien a)  
{  
    node* p;  
    p = (node*)malloc(sizeof(node));  
	if (p == NULL)
	{
		printf("Khong de bo nho!\n");
		return NULL;    // phải return NULL nếu malloc thất bại
	}
    p->data = a;  
    p->next = NULL;  
    return p;  
}
// Buoc 4: Ham tao danh sach rong
void Init(list &L)
{
	L.pHead = L.pTail = NULL;
}

// Buoc 5: Ham them node vao dau danh sach
void addHead(list &L, node *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		p->next = L.pHead;
		L.pHead = p;
	}
}
// Buoc 6: Ham them node vao cuoi danh sach
void addBack(list& L, node *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		L.pTail->next = p;
		L.pTail = p;
	}
}
// Ham nhap chuoi
void nhapChuoi(char* str, int sizeofstr)
{
	fgets(str, sizeofstr, stdin);
	str[strcspn(str, "\n")] = '\0';
}
// HAM NHAP THONG TIN DATA SINHVIEN
void Nhapsinhvien(sinhvien *sv) // Pass sinhvien by reference to initialize it properly
{
    printf("Nhap thong tin sinh vien \n");
	while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại
    printf("Nhap MSSV: ");
    nhapChuoi(sv->mssv,sizeof(sv->mssv));

	printf("DEBUG: MSSV: %s\n", sv->mssv);

    printf("Nhap Ho va Ten: ");
    nhapChuoi(sv->hoten, sizeof(sv->hoten));
	printf("DEBUG: Hoten: %s\n", sv->hoten);

    printf("Nhap So dien thoai: ");
    nhapChuoi(sv->sdt, sizeof(sv->sdt));
	printf("DEBUG: Sodienthoai: %s\n", sv->sdt);

    printf("Nhap Gioi tinh: ");
    nhapChuoi(sv->gioitinh, sizeof(sv->gioitinh));
	printf("DEBUG: Gioi tinh: %s\n", sv->gioitinh);

    printf("Nhap ngay thang nam sinh\n");
    printf("Nhap ngay sinh: ");
    scanf_s("%d",&sv->ngaysinh.day);

	printf("Nhap thang sinh: ");
	scanf_s("%d",&sv->ngaysinh.month);

    printf("Nhap nam sinh: ");
	scanf_s("%d",&sv->ngaysinh.year);
	while (getchar() != '\n'); // xóa bỏ ký tự '\n' còn sót lại

    printf("Nhap ma lop: ");
    nhapChuoi(sv->malop, sizeof(sv->malop));
	

    printf("Nhap diem trung binh: ");
	while (scanf_s("%f", &sv->dtb) != 1)
	{
		printf("Nhap diem sai . Vui long nhap lai");
		while (getchar() != '\n');
	}// Change %d to %f for float type
	while (getchar() != '\n'); // xóa '\n'
}

// CAC HAM CHUC NANG
// THEM MOT SINH VIEN VAO DAU DANH SACH
void themSinhvienHead(list &L)
{
	printf("\n===Them mot sinh vien moi===\n");
	sinhvien a;
    Nhapsinhvien(&a);
	node* p = getNode(a);
	if (p == NULL)
	{
		printf("Khong du bo nho!\n");
		return;
	}
	addHead(L,p);
	printf("\n===Nhap sinh them sinh vien thanh cong===\n");
}
// THEM MOT SINH VIEN VAO CUOI DANH SACH
void themSinhvienBack(list& L)
{
	printf("\n===Them mot sinh vien moi===\n");
	sinhvien a;
	Nhapsinhvien(&a);
	node* p = getNode(a);
	if (p == NULL)
	{
		printf("Khong du bo nho!\n");
		return;
	}
	addBack(L, p);
	printf("\n===Nhap sinh them sinh vien thanh cong===\n");
}
// HAM IN RA DANH SACH SINH VIEN
void xuat1sinhvien(node* temp)  // xuat 1 sinh vien
{
	sinhvien a = temp->data;
	printf("---------------------------------------------------------------------------------------------------\n");
	printf("----------------------------------THONG TIN SINH VIEN ---------------------------------------------\n");
	printf("| %-10s | %-20s | %-12s | %-10s | %02d/%02d/%04d  | %-8s | %-6.2f |\n",
		a.mssv,
		a.hoten,
		a.sdt,
		a.gioitinh,
		a.ngaysinh.day,
		a.ngaysinh.month,
		a.ngaysinh.year,
		a.malop,
		a.dtb);
}
void xuatdanhsach(list& L)  // xuat ca danh sach
{
	node* temp = L.pHead;
	printf("--------------------------------------------------------------------------------------------------\n");
	printf("| %-10s | %-20s | %-12s | %-10s | %-10s | %-8s | %-6s |\n",
		"MSSV", "Ho ten", "SDT", "Gioi tinh", "Ngay sinh", "Ma lop", "DTB");
	printf("--------------------------------------------------------------------------------------------------\n");

	while (temp != NULL)
	{
		sinhvien a = temp->data;
		printf("| %-10s | %-20s | %-12s | %-10s | %02d/%02d/%04d | %-8s | %-6.2f |\n",
			a.mssv,
			a.hoten,
			a.sdt,
			a.gioitinh,
			a.ngaysinh.day,
			a.ngaysinh.month,
			a.ngaysinh.year,
			a.malop,
			a.dtb);
		temp = temp->next;
	}
	printf("--------------------------------------------------------------------------------------------------\n");
}
// HAM TIM KIEM SINH VIEN
node* Timkiemsinhvien(list &L,char mssvSearch[])
{
	node* temp = L.pHead;
	while (temp != NULL)
	{
		if (strcmp(temp->data.mssv, mssvSearch) == 0)
		{
			return temp;
		}
		temp = temp->next;
	}
	printf("Khong tim duoc sinh vien !");
	return NULL;
}
// HAM HOAN DOI
void swap(sinhvien *a, sinhvien *b)
{
	sinhvien temp = *a;
	*a = *b;
	*b = temp;
}
// HAM XOA MOT SINH VIEN
void Xoasinhvien(list& L,char mssvDelete[])
{
	node* temp = L.pHead;
	// Tim node can xoa
	// 	while (temp != NULL)
	while (temp != NULL) {
		if (strcmp(temp->data.mssv, mssvDelete) == 0)
		{
			printf("Thong tin sinh vien \n");
			xuat1sinhvien(temp);
			break;
		}
		temp = temp->next;
	}
	// Kiem tra danh sach rong 
	if (L.pHead == NULL || temp == NULL) return;
	// Neu chi co 1 node trong danh sach
	if (L.pHead == temp && temp->next == NULL)
	{
		free(temp);
		L.pHead = L.pTail = NULL;
		printf("Xoa sinh vien co MSSV [%s] thanh cong!\n", mssvDelete);
		return;
	}
	/* Neu p la node cuoi cung
	   Duyet danh sach de tim p truoc
	   ptruoc -> next = NULL
	   delete p
	*/
	if (L.pTail == temp)
	{
		node* prev = L.pHead;
		while (prev->next != temp)
		{
			prev = prev->next;
		}
		prev->next = NULL;
		L.pTail = prev;
		free(temp);
		printf("Xoa sinh vien co MSSV [%s] thanh cong!\n", mssvDelete);
		return;
	}
	/* Truong hop thong thuong (p khong phai la cuoi)
	Cach 1
	Duyet danh de tim p truoc
	ptrc -> next = p->next
	p->next = NULL
	free(p)
    {
		prev = L.pHead;
		while (prev->next != temp)
		{
			prev = prev->next;
		}
		prev->next = temp->next;
		temp->next = NULL;
		free(temp);
		return;
	}
	*/

	else 
	{
		/* Cach 2
		 pSau1 = p->pNext;       // node sau p
		 pSau2 = pSau1->pNext;   // node sau pSau1
		// Hoán đổi giá trị giữa p và pSau1
		   hoán vị p->info và pSau1->info;
		 p->pNext = pSau2;
		 delete pSau1;
		 */
		node* temp1next = temp->next;
		node* temp2next = temp1next->next;
		swap(&temp->data, &temp1next->data);
		temp->next = temp2next;
		temp1next->next = NULL;
		free(temp1next);
		printf("Xoa sinh vien co MSSV [%s] thanh cong!\n", mssvDelete);
		return;
	}
}
// Ham kiem tra chuoi ky tu la chu so
int isDigit(char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}
// Cap nhat thong tin cua mot sinh vien 
void Capnhatsinhvien(list& L, char mssvUpdate[]) 
{
	if (!isDigit(mssvUpdate))
	{
		printf("MSSV khong hop le!\n");
		return;
	}
	node* p = Timkiemsinhvien(L, mssvUpdate);
	if (p)
	{
		printf("Tim thay sinh vien co MSSV: %s\n", mssvUpdate);
		xuat1sinhvien(p);
		printf("-----CAP NHAT THONG TIN SINH VIEN (NHAN ENTER DE TIEP TUC)----\n");
		char oldmssv[10];
		strcpy_s(oldmssv, p->data.mssv);
		Nhapsinhvien(&p->data);
		strcpy_s(p->data.mssv, oldmssv);
		printf("----------------CAP NHAT THONG TIN THANH CONG-----------------\n");
	}
	else
	{
		printf("Khong tim thay sinh vien co MSSV: %s\n", mssvUpdate);
	}
}
/* Sap xep danh sach theo tieu chi(VD: tang / giam theo diem, theo ten)
   Thuat toan sap xep Interchange Sort:
   for( i = 0; i < n; i++ )
     for (j = i+1 ; j<n; j++)
	   if s[i] > s[j]
	     swap(s[i],s[j])
*/
void sapxepMSSVtangdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		for (node* psau = p->next; psau != NULL; psau = psau->next)
		{
			if (strcmp(p->data.mssv, psau->data.mssv) > 0)
				swap(&p->data, &psau->data);
		}
	}
	printf("----Sap xep sinh vien theo MSSV tang dan thanh cong!----\n");
}
void sapxepMSSVgiamdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		for (node* psau = p->next; psau != NULL; psau = psau->next)
		{
			if (strcmp(p->data.mssv, psau->data.mssv) < 0)
				swap(&p->data, &psau->data);
		}
	}
	printf("----Sap xep sinh vien theo MSSV giam dan thanh cong!----\n");
	}
	// Sap xep theo Ho ten
	/* Thuat toan Bubble Sort:
	   for i = 0 -> n ; i++ 
		  for j = i -> n ; j++
			 if s[j] > s[j+1]
			  swap(s[j], s[j+1])
	*/
	void sapxepHotentangdan(list& L)
	{
		if (L.pHead == NULL || L.pHead->next == NULL)
			return;  // Danh sách rỗng hoặc chỉ có 1 phần tử

		for (node* i = L.pHead; i->next != NULL; i = i->next)
		{
			for (node* j = L.pHead; j->next != NULL; j = j->next)
			{
				if (strcmp(j->data.hoten, j->next->data.hoten) > 0)
				{
					swap(&j->data, &j->next->data);
				}
			}
		}
		printf("----Sap xep sinh vien theo Ho ten tang dan thanh cong!----\n");
	}

void sapxepHotengiamdan(list& L)
{
	if (L.pHead == NULL || L.pHead->next == NULL)
		return;  // Danh sách rỗng hoặc chỉ có 1 phần tử

	for (node* i = L.pHead; i->next != NULL; i = i->next)
	{
		for (node* j = L.pHead; j->next != NULL; j = j->next)
		{
			if (strcmp(j->data.hoten, j->next->data.hoten) < 0)
			{
				swap(&j->data, &j->next->data);
			}
		}
	}
	printf("----Sap xep sinh vien theo Ho ten giam dan thanh cong!----\n");
}

/* Sap xep theo SDT 
   Thuat toan Insertion Sort:
   for i = 1; i<n ; i++
   j = i
   while( j > 0 && a[j] > a[j-1] )
        swap(a[j], a[j-1])
		j-- 
   -> Phai tim p truoc cua p -> phai duyet lai mang -> Khong hieu qua


Thuat toan Selection Sort:
	for i = 0, i<n , i++{
	  min = i
	  for j=i+1, j<n, j++{
	     if (s[j] < s[min])  
	        min = j;
	  }
	  swap(s[i],s[min]);
	 }
*/
void sapxepSDTtangdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* min = p;
		for (node *q = p->next; q != NULL; q = q->next)
		{
			if (strcmp(q->data.sdt, min->data.sdt) < 0)
				min = q;
		}
		swap(&p->data, &min->data);
	}
	printf("----Sap xep sinh vien theo SDT tang dan thanh cong!----\n");
}
void sapxepSDTgiamdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* max = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (strcmp(q->data.sdt, max->data.sdt) > 0)
				max = q;
		}
		swap(&p->data, &max->data);
	}
	printf("----Sap xep sinh vien theo SDT giam dan thanh cong!----\n");
}
// Sap xep theo diem trung binh
void sapxepDTBtangdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* min = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (q->data.dtb < min->data.dtb)
				min = q;
		}
		if(p != min)
		swap(&p->data, &min->data);
	}
	printf("----Sap xep sinh vien theo DTB tang dan thanh cong!----\n");
}
void sapxepDTBgiamdan(list& L)
{
	for (node* p = L.pHead; p != NULL; p = p->next)
	{
		node* max = p;
		for (node* q = p->next; q != NULL; q = q->next)
		{
			if (q->data.dtb > max->data.dtb)
				max = q;
		}
		if (p != max)
		swap(&p->data, &max->data);
	}
	printf("----Sap xep sinh vien theo DTB giam dan thanh cong!----\n");
}
// Ghi du lieu ra tep va doc du lieu tu tep
// HAM DOC DU LIEU TU TEP
void docFile(list& L, const char* filename)
{
	FILE* f = fopen(filename, "r");  // dùng fopen thay vì fopen_s

	if (f == NULL)
	{
		printf("Khong mo duoc file %s de doc!\n", filename);
		return;
	}

	sinhvien sv;
	int count = 0;

	while (fscanf(f, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d|%[^|]|%f\n",
		sv.mssv,
		sv.hoten,
		sv.sdt,
		sv.gioitinh,
		&sv.ngaysinh.day,
		&sv.ngaysinh.month,
		&sv.ngaysinh.year,
		sv.malop,
		&sv.dtb) == 9)
	{
		node* p = getNode(sv);
		addBack(L, p);
		count++;
	}
	fclose(f);
	printf("Doc file thanh cong! Da them %d sinh vien vao danh sach.\n", count);
}

// HAM GHI DU LIEU VAO TEP
void ghiFile(list& L, const char* filename)
{
	FILE* f = NULL;
	fopen_s(&f, filename, "w");
	if(f == NULL)
	{
		printf("Khong mo duoc file %s de ghi!\n", filename);
		return;
	}
	node* p = L.pHead;
	while (p != NULL)
	{
		sinhvien sv = p->data;
		fprintf(f, "%s|%s|%s|%s|%02d|%02d|%04d|%f\n",
			sv.mssv,
			sv.hoten,
			sv.sdt,
			sv.gioitinh,
			sv.ngaysinh.day,
			sv.ngaysinh.month,
			sv.ngaysinh.year,
			sv.dtb
		);
		p = p->next;
	}
	fclose(f);
	printf("Ghi file thanh cong vao %s:\n", filename);
}
// Ham lua chon sap xep tang dan hoac giam dan
char up_or_down()
{
	char updownchoice;
	printf("Ban muon sap xep theo chieu:\n");
	printf("[A].Tang dan\n");
	printf("[B].Giam dan\n");
	printf("Lua chon cua ban [A-B]:");
	scanf_s(" %c",&updownchoice, (unsigned int)sizeof(updownchoice));
	return updownchoice;
}

// MENU CHUONG TRINH
int main()
{
	list L;
	Init(L);
	char username[20];
	printf("==================== DANH SACH QUAN LY THONG TIN SINH VIEN ====================\n");
	printf("Nhap ten cua ban:");
	nhapChuoi(username, sizeof(username));
	printf("\nCHAO MUNG ! %s\n", username);
	int choice;
	do
	{
		printf("Ban muon:\n");
		printf("[1].Them sinh vien\n");
		printf("[2].Hien thi danh sach\n");
		printf("[3].Tim kiem sinh vien\n");
		printf("[4].Xoa sinh vien\n");
		printf("[5].Chinh sua thong tin sinh vien\n");
		printf("[6].Sap xep danh sach sinh vien\n");
		printf("[7].Ghi du lieu danh sach ra tep\n");
		printf("[8].Doc du lieu danh sach tu tep\n");
		printf("[9].Thoat danh sach\n");
		printf("Nhap lua chon cua ban [1-9]:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			char searchchoice;
			printf("Ban muon them sinh vien:\n");
			printf("[A].Vao dau danh sach\n");
			printf("[B].Vao cuoi danh sach\n");
			while (getchar() != '\n');
			scanf_s("%c", &searchchoice, (unsigned int)sizeof(searchchoice));
			switch (searchchoice)
			{
			case 'A':
				themSinhvienHead(L); break;
			case 'B':
				themSinhvienBack(L); break;
			}
		}break;
		case 2:
		{
			xuatdanhsach(L);
		}break;
		case 3:
		{
			char mssvSearch[10];
			printf("Nhap MSSV cua sinh vien can tim:");
			while (getchar() != '\n');
			nhapChuoi(mssvSearch, sizeof(mssvSearch));
			node* p = Timkiemsinhvien(L,mssvSearch);
			if (p)
			{
				printf("Da tim thay sinh vien co MSSV: %s", p->data.mssv);
				xuat1sinhvien(p);
			}
		}break;
		case 4:
		{
			char mssvDelete[10];
			printf("Nhap MSSV can xoa:");
			while (getchar() != '\n');
			nhapChuoi(mssvDelete, sizeof(mssvDelete));
			Xoasinhvien(L,mssvDelete);
		}break;
		case 5:
		{
			char mssvUpdate[10];
			printf("Nhap MSSV can cap nhat:");
			while (getchar() != '\n');
			nhapChuoi(mssvUpdate, sizeof(mssvUpdate));
			Capnhatsinhvien(L, mssvUpdate);
		}break;
		case 6:
		{
			int sortchoice;
			printf("Ban muon sap xep danh sach theo:\n");
			printf("[1].Ma so sinh vien\n");
			printf("[2].Ho va ten\n");
			printf("[3].So dien thoai\n");
			printf("[4].Diem trung binh\n");
			printf("Nhap lua chon cua ban [1-4]:");
			scanf_s("%d", &sortchoice);
			switch (sortchoice)
			{
			case 1:
			{
				switch (up_or_down())
				{
				case 'A': sapxepMSSVtangdan(L); break;

				case 'B':sapxepMSSVgiamdan(L); break;
				}
			}break;
			case 2:
			{
				switch (up_or_down())
				{
				case 'A':
					sapxepHotentangdan(L); break;

				case 'B':
					sapxepHotengiamdan(L); break;
				}
			}break;
			case 3:
			{
				switch (up_or_down())
				{
				case 'A':
					sapxepSDTtangdan(L); break;

				case 'B':
					sapxepSDTgiamdan(L); break;
				}
			}break;
			case 4:
			{
				switch (up_or_down())
				{
				case 'A':
					sapxepDTBtangdan(L); break;
				case 'B':
					sapxepDTBgiamdan(L); break;
				}
			}break;
			}
		}break;
            case 7: 
            {
                char filename[100];
                printf("Nhap ten file de ghi du lieu: ");
				while (getchar() != '\n');
                nhapChuoi(filename, sizeof(filename)); // Use the existing `nhapChuoi` function to input the filename.
                ghiFile(L, filename); // Pass the list `L` and the filename to the `ghiFile` function.
            } 
            break;
			case 8: 
			{
				char filename[100];
				printf("Nhap ten file de doc du lieu: ");
				while (getchar() != '\n');
				nhapChuoi(filename, sizeof(filename));
				docFile(L, filename);
			}
			case 9: break;
			default: printf("Lenh khong hop le!\n");
		}	
	} while (choice != 9);
	printf("================================= TAM BIET %s =================================\n", username);
	return 0;
}
			
       