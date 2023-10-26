#include <stdio.h>
#include "store.h"

int main(int argc, char *argv[]){
        struct store rec;
        FILE *fp;
        if(argc != 2){
                fprintf(stderr, "How to use : %s FileName\n", argv[0]);
                 return 1;
         }
         fp = fopen(argv[1], "w");
         printf("%-9s %-9s %-9s %-9s %-9s \n", "ID", "Name", "Category", "Expired Date", "Stock");
         while(scanf("%d %s %s %d %d",&rec.id, rec.name, rec.category, &rec.expiredDate, &rec.stock ) ==5)
                 fwrite(&rec, sizeof(rec), 1,fp);
         fclose(fp);
         return 0;
}
