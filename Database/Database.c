# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
 
# include <sys/types.h>
 
 
 
void mkdtbase(DIR* rep, char* file_name)
{
  struct dirent* file = NULL;
  FILE* dtbase = fopen(file_name, "w+");
  if  (rep != NULL)
  {
    for (int i = 0; i < 2429; i++) //2429 files in faces
    {
      file = readdir(rep);
      fprintf(dtbase, "%s \n", file->d_name);
    }
    fclose(dtbase);
  }
}
int main()
{
  DIR* rep1 = opendir ("/home/epita/Daproject/Database/face");
  mkdtbase(rep1,"dtfaces");
}
