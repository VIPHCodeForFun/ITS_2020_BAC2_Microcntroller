/*
 * Created: 19.07.2023
 * Author: Philipp Vidmar
 *      gcc -o count-sloc.exe count-sloc.c
 *      ./count-sloc.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sloc(char *FileName);
void removeSpaces(char *str);

int main()
{
  int countSLOC[] = {sloc("pin-hal.c"), sloc("timer-hal.c")};
  printf("SLOC of pin-hal.c        %d\n", countSLOC[0]);
  printf("SLOC of von timer-hal.c  %d\n", countSLOC[1]);
  printf("                  SUM()= %d\n", (countSLOC[0] + countSLOC[1]));
  return 0;
}

void removeSpaces(char *str)
{
  int i, j = 0;

  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] == ' ' || str[i] == '\t')
    {
      continue;
    }
    str[j] = str[i];
    j++;
  }
  str[j] = '\0';
}

int sloc(char *FileName)
{
  FILE *file = fopen(FileName, "r");
  if (file == NULL)
  {
    printf("Error when opening the file\n");
    return 1;
  }

  char line[1024];
  char string[1024];
  int lineCount = 0;

  while (fgets(line, sizeof(line), file))
  {
    /* Check for Error */
    if (line == NULL)
    {
      continue;
    }
    strcpy(string, line);
    removeSpaces(string);

    /* Blank line, skip */
    if (string[0] == '\n')
    {
      continue;
    }
    /* Single line comment, skip like // some text */
    else if (string[0] == '/' && string[1] == '/')
    {
      continue;
    }
    /* Single line comment, skip like this one */
    else if (strstr(string, "/*") != NULL && strstr(string, "*/") != NULL)
    {
      continue;
    }
    /* Multiline comment,skip like: */
    /*
     * timer_hal.c
     */
    else if (strstr(string, "/*") != NULL && strstr(string, "*/") == NULL)
    {
      while (fgets(line, sizeof(line), file))
      {
        if (strstr(line, "*/") != NULL)
        {
          break;
        }
      }
      continue;
    }
    lineCount++;
  }
  fclose(file);
  printf("\n");
  return lineCount;
}
