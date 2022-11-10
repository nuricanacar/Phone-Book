#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char *name;
	char *surname;
	char *number;
	char *email;
	struct node *adress;
}llist_t;

llist_t *node1 = NULL;

void print_list();
llist_t *create_node();
void add_end();
void delete_end();
void delete_n();
void find_n();

int main(){
	int a = 0, b = 0;
	char dizi[30][4][30];
	int c2, opr;
	node1 = create_node("NuriCan","Acar","05462284660","kanarya_nurican@hotmail.com");
	llist_t *node2 = create_node("Necati","Akar","05922284660","n_akar@gmail.com");
	llist_t *node3 = create_node("Ayse","Yilmaz","05992284660","ayseyilmaz34@outlook.com");
	llist_t *node4 = create_node("Muzaffer","Korkmaz","05894835436","m_krkmz@gmail.com");
	node1 -> adress = node2;
	node2 -> adress = node3;
	node3 -> adress = node4;
	printf("Rehbere hosgeldiniz.\n");
	
	loop:
	 printf("\n--|1|Listele| |2|Kisi sil| |3|Arama yap| |4|Kisi ekle| |0|Cikis yap|--\n\n ===>>> ");
	 scanf("%d",&opr);
	
	switch (opr) {
	case 0:
		printf("Rehber Kapatiliyor...\n");
		break;
	case 1:
		print_list();
		goto loop;
		break;
	case 2:
		printf("Silmek istediginiz kisinin listedeki sirasini giriniz\n");
		scanf("%d",&c2);
		delete_n(c2);
		goto loop;
		break;
	case 3:
		printf("Aramak istediginiz kisinin isim veya soyisimini giriniz : ");
		char src[20];
		scanf("%s",&src);
		find_n(src);
		opr = 12;
		goto loop;
		break;
	case 4:
		printf("Eklenecek kisinin;\nAdi: ");
		scanf("%s",&dizi[a][0]);
		printf("Soyadi: ");		
		scanf("%s",&dizi[a][1]);
		printf("TelefonNumarasi: ");		
		scanf("%s",&dizi[a][2]);
		printf("E-mail adresi: ");		
		scanf("%s",&dizi[a][3]);
		add_end(dizi[a][0],dizi[a][1],dizi[a][2],dizi[a][3]);
		a++;
		opr = 12;
		goto loop;
		break;
	default:
		printf("Hatali giris yaptiniz\n");
		printf("Rehber Kapatiliyor...\n");
		break;
		}
}

llist_t *create_node(char *pname,char *psurname,char *pnum,char *pemail){
	llist_t *nnode = (llist_t *)malloc(sizeof(llist_t));
	nnode -> name = pname;
	nnode -> surname = psurname;
	nnode -> number = pnum;
	nnode -> email = pemail;
	nnode -> adress = NULL;
	return nnode;
}

void print_list(){
	int i = 0;
	llist_t *temp = node1;
	while (temp != NULL){
	printf("%d. ",++i);
	printf("%s ",temp -> name);
	printf("%s ",temp -> surname);
	printf("%s ",temp -> number);
	printf("%s ",temp -> email);
	printf("\n");
	temp = temp -> adress;
	}
	printf("\n");
}

void add_end(char *pname,char *psurname,char *pnum,char *pemail){
	llist_t *anode = create_node(pname,psurname,pnum,pemail);
	llist_t *temp = node1;
	while (temp -> adress != NULL)
	{
	temp = temp -> adress;
	}
	temp -> adress = anode;
}

void delete_n(int q){
	
	llist_t *dnode = node1;
	for(int i = 0;i < q-1;i++)
	{
	dnode = dnode -> adress;
	}
	llist_t *temp = dnode -> adress;
	if(temp == NULL)
	 delete_end();
	else
	{
	dnode -> name = temp -> name;
	dnode -> surname = temp -> surname;
	dnode -> number = temp -> number;
	dnode -> email = temp -> email;
	dnode -> adress = temp -> adress;
	free(temp);
	}
}

void delete_end(){
	llist_t *temp = node1;
	while(temp -> adress -> adress != NULL){
	temp = temp -> adress;
	}
	free(temp -> adress);
	temp -> adress = NULL;
}

void find_n(char *srcname){
	llist_t *temp = node1;
	while(temp -> adress != NULL){
		if (!strcmp((temp -> name),srcname)){
		printf("Ismi %s olan kisi bulundu.\n%s %s %s %s\n\n",srcname,temp -> name,temp -> surname,temp -> number,temp -> email);
		return;
		}
		else if(!strcmp((temp -> surname),srcname)){
		printf("Soyismi %s olan kisi bulundu.\n%s %s %s %s\n\n",srcname,temp -> name,temp -> surname,temp -> number,temp -> email);
		return;
		}
		else{
		temp = temp -> adress;
		}
	}
	printf("Aradiginiz eleman '%s' listede mevcut degil\n",srcname);
	return;
}