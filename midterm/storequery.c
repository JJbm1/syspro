#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"

int main() {
 	FILE *fp;
 	struct store rec[1000]; 
 	int c;
 	fp = fopen("db.dat", "r");
 	if(fp == NULL) {
 		fprintf(stderr, "File Open Error\n");
 		exit(1);
 	}

       	printf("0: list of all goods, 1: list of available goods ) ");
 		scanf("%d", &c);
 		//getchar(); 
 		printf("%-9s %-9s %-9s %-9s %-9s\n", "ID", "Name", "Category", "Expired Date", "Stock");
 		if(c == 0) {
 			for(int i = 0; i < 7; i++) {
 				fprintf("%ls %s %s %ls %ls\n", &rec[i].id, rec[i].name, rec[i].category, &rec[i].expiredDate, &rec[i].stock);
			}
 		} 
		else if(c == 1) {
			 for(int i = 0; i < 7; i++) {
				 if(&rec[i].expiredDate >= "2023"){ 
					 continue;
				 	 fprintf("%ls %s %s %ls %ls\n", &rec[i].id, rec[i].name, rec[i].category, &rec[i].expiredDate, &rec[i].stock);
				}
			 }
		}
		else {
			 fprintf(stderr, "Invalid Input\n");
		} 
		return 0;
	}
	
