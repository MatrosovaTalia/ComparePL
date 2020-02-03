#include <stdio.h>
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
#include <string.h>

#define N_LANG 4
#define N_ALGO 1

int main (){
  int error_num;
  int lang_n = 4;
  char algorithm[N_ALGO][10] = {"sort"};
  char lang[N_LANG][10] = {"c", "cpp", "java", "kt"};
  char cmp_com[N_ALGO * N_LANG][50];  // compile commands
  char run_com[N_ALGO * N_LANG][50];  // run commands

  int cmp_n = 0;   // number of compile commands
  int run_n = 0; // number of run commands
  for (int i = 0; i < N_LANG; i++){
    for (int j = 0; j < N_ALGO; j++){
      if (strcmp(lang[i], "c") == 0){
        sprintf(cmp_com[cmp_n], "gcc %s.%s -o %s%s", 
                                            algorithm[j], lang[i],
                                            algorithm[j], lang[i]);
        cmp_n++;
        sprintf(run_com[run_n], "./%s%s", algorithm[j], lang[i]);
      }
      else if(strcmp(lang[i], "cpp") == 0){
        sprintf(cmp_com[cmp_n], "g++ -o %s%s %s.%s", 
                                    algorithm[j], lang[i],
                                    algorithm[j], lang[i]);
        cmp_n++;
        sprintf(run_com[run_n], "./%s%s", algorithm[j], lang[i]);
      }
      else if(strcmp(lang[i], "kt") == 0){
        sprintf(cmp_com[cmp_n], "kotlinc %s.%s -include-runtime -d %s%s.jar", 
                                    algorithm[j], lang[i],
                                    algorithm[j], lang[i]);
        cmp_n++;
        sprintf(run_com[run_n], "java -jar %s%s.jar", algorithm[j], lang[i]);
      }
      else if (strcmp(lang[i], "java") == 0){
        sprintf(run_com[run_n], "java %s.%s", algorithm[j], lang[i]);

      }
      run_n++;
    }
  }






  for (int i = 0; i < cmp_n; i++){
    error_num = system(cmp_com[i]);
    printf("%s", cmp_com[i]);
    if (!error_num){
      printf(" OK\n");
    }
    else{
      printf(" Error number: %d\n", error_num);
    }
    
  }

  for (int i = 0; i <= run_n; i++){
    system(run_com[i]);
    // printf("%s\n", run_com[i]);
  }
  return 0;
}