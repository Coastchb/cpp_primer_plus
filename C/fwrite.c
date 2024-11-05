/**
 * Created by coast on 2019/2/19
 */
//格式化写文件

#include<stdio.h>

#include<string.h>

#include<stdlib.h>

typedef struct{
    int sno;
    char name[10];
}student;

int main ()
{
  FILE * fin;
  fin = fopen("tmp.txt","w");
  fprintf(fin,"%f %f %f", 0.1, 0.2, 0.3);
  fclose(fin);


  FILE* fout = fopen("tmp.txt", "r");
  const int BUF_SIZE = 128;
  char line[BUF_SIZE];
  memset(line,0,BUF_SIZE);

  int j = 0;

  float in_features[3];

  while(!feof(fout)) {
    printf("line %d:\n", j++);
    fgets(line,BUF_SIZE,fout);
    printf("%s\n", line);
    char * b;
    b = line;
    char * tp = strsep(&b, " ");
    int p = 0;
    while(tp != NULL) {
      double d = atof(tp);
      printf("%f\t", d);
      in_features[p++] = d;
      tp = strsep(&b, " ");
    }
    printf("\n");
    printf("%f\t%f\t%f\n", in_features[0],in_features[1],in_features[2]);


  }
  fclose(fout);

  return 0;

}
