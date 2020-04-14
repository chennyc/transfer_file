/* File generated from [rand_bit/integer-shift.c] by PICCO Wed Apr  8 17:02:08 2020
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [rand_bit/integer-shift.c] by PICCO Wed Apr  8 17:02:08 2020
 */

#include "smc-compute/SMC_Utils.h"

#include <gmp.h>

#include <omp.h>


SMC_Utils *__s;


int K = 100000;
int Ka = 1;

int  __original_main(int _argc_ignored, char **_argv_ignored)
{
  
  mpz_t _picco_tmp1, _picco_tmp2;
  mpz_init(_picco_tmp1);
  mpz_init(_picco_tmp2);

  mpz_t* _picco_ftmp1 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_init(_picco_ftmp1[_picco_j]);
  void* _picco_temp_;
 int i;

  mpz_t* A; 
  A = (mpz_t*)malloc(sizeof(mpz_t) * (Ka));
  for (int _picco_i = 0; _picco_i < Ka; _picco_i++)
        mpz_init(A[_picco_i]);
  mpz_t* C; 
  C = (mpz_t*)malloc(sizeof(mpz_t) * (K));
  for (int _picco_i = 0; _picco_i < K; _picco_i++)
        mpz_init(C[_picco_i]);


  __s->smc_input(1, A, Ka, "int", -1);

  printf("INDIVIDUAL SHIFTS\n");

  printf("PUBLIC RIGHT SHFIT\n");

  i = 0;
  for ( ;i < 100; )
  {
    {
      __s->smc_randbit(C,K);
//      __s->smc_shr(A[i], (i + 1), _picco_tmp1, 32, -1, 32, "int", -1);
//      __s->smc_set(_picco_tmp1, C[i], 32, 32, "int", -1);
    }
    i++;
  }

  __s->smc_output(1, C, K, "int", -1);

  printf("\n\n\n");

    for (int _picco_i = 0; _picco_i < K; _picco_i++)
        mpz_clear(C[_picco_i]);
  free(C);
  for (int _picco_i = 0; _picco_i < Ka; _picco_i++)
        mpz_clear(A[_picco_i]);
  free(A);
  mpz_clear(_picco_tmp1);
  mpz_clear(_picco_tmp2);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_clear(_picco_ftmp1[_picco_j]);
  free(_picco_ftmp1);
  return (0);
}


/* smc-compiler generated main() */
int main(int argc, char **argv)
{

 if(argc < 8){
fprintf(stderr,"Incorrect input parameters\n");
fprintf(stderr,"Usage: <id> <runtime-config> <privatekey-filename> <number-of-input-parties> <number-of-output-parties> <input-share> <output>\n");
exit(1);
}

 std::string IO_files[atoi(argv[4]) + atoi(argv[5])];
for(int i = 0; i < argc-6; i++)
   IO_files[i] = argv[6+i];

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 61, "1152921504606847067", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

