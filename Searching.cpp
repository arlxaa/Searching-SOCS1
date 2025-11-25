#include <stdio.h>
#include <string.h>

struct wlele{
	char nim[105];
	char name[105];
};

int main(){
	int t, T;
	char NIM[105];
	FILE *bukak;
	bukak = fopen("testdata.in","r");
	
	fscanf(bukak, "%d", &t);
	fgetc(bukak);
	struct wlele ke[t];
	
	for (int i = 0; i < t; i++){
		fscanf(bukak, "%s %[^\n]", ke[i].nim, ke[i].name);
		fgetc(bukak);	
	}
	
	fscanf(bukak, "%d", &T);
	fgetc(bukak);
	for (int i = 0 ; i < T ; i++){
		fscanf(bukak, "%s", NIM);
		fgetc(bukak);
		
		for (int j = 0; j < t; j++){
			if (strcmp(NIM, ke[j].nim)==0){
				printf("Case #%d: %s\n", i+1, ke[j].name);
				break;
			} else if (j == t-1){
				printf("Case #%d: N/A\n", i+1);
			}
		}
	}
	fclose(bukak);
}
