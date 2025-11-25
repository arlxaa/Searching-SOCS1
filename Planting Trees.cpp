#include <stdio.h>
#include <string.h>

struct pohon{
	char depan[50];
	char belakang[50];
};

int main(){
	int n, a;
	char cari[50];
	FILE *bukak;
	bukak = fopen("testdata.in", "r");
	
	fscanf(bukak, "%d\n", &n);
	struct pohon wle[n];
	
	for (int i = 0 ; i < n ; i++){
		fscanf(bukak, "%[^#]#%[^\n]\n", wle[i].depan, wle[i].belakang);
	}
	
	fscanf(bukak, "%d\n", &a);
	for (int i = 0 ; i < a ; i ++){
		fscanf(bukak, "%[^\n]\n", cari);
		for (int j = 0 ; j < n ; j++){
			if (strcmp(wle[j].depan, cari)==0){
				printf("Case #%d: %s\n", i+1, wle[j].belakang);
				break;
			} else if (j == n-1){
				printf("Case #%d: N/A\n", i+1);
			}
		}
	}
	fclose(bukak);
	return 0;
}



