#include <stdio.h>
#include <stdlib.h>
#include "store.h"

int compare(const void *a, const void *b) {
	 struct store *storeA = (struct store *)a;
 	 struct store *storeB = (struct store *)b;
	 return storeB->id - storeA->id;
}

int main() {
	 FILE *fp;
	 struct store rec[100];
	 int count = 0;
	 fp = fopen("db.dat", "r");
	 if(fp == NULL) {
		 fprintf(stderr, "Error Opening File\n");
		 exit(1);
	 }
	 while(sscanf(fp, "%d %s %s %d %d \n", &rec[count].id, rec[count].name, rec[count].category, &rec[count].expiredDate,&rec[count].stock) == 5)
 		count++;
 		fclose(fp);
 		qsort(rec, count, sizeof(struct store), compare);
 		for(int i = 0; i < count; i++) {
 			printf("%d %s %s %d %d \n", rec[i].id, rec[i].name,rec[i].category, &rec[i].expiredDate, &rec[i].stock);
		}	
		return 0;
}
