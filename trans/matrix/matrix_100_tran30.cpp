/* File generated from [Mul_test/Martix_100.c] by PICCO Thu Mar  5 22:22:10 2020
 */

#include <limits.h>

#include <float.h>

//extern void *memcpy(void*,const void*,unsigned int);

//# 1 "ort.onoff.defs"

extern  "C" int   ort_initialize(int*, char***);
 extern "C" void  ort_finalize(int);


/* File generated from [Mul_test/Martix_100.c] by PICCO Thu Mar  5 22:22:10 2020
 */

#include "smc-compute/SMC_Utils.h"

#include <gmp.h>

#include <omp.h>


SMC_Utils *__s;



int  __original_main(int _argc_ignored, char **_argv_ignored)
{
  
  mpz_t _picco_tmp1;
  mpz_init(_picco_tmp1);

  mpz_t* _picco_ftmp1 = (mpz_t*)malloc(sizeof(mpz_t) * 4);
  for(int _picco_j = 0; _picco_j < 4; _picco_j++)
    mpz_init(_picco_ftmp1[_picco_j]);
  void* _picco_temp_;
 int S = 100;

  mpz_t** A; 
  A = (mpz_t**)malloc(sizeof(mpz_t*) * (S));
  for (int _picco_i = 0; _picco_i < S; _picco_i++)
    {
      A[_picco_i] = (mpz_t*)malloc(sizeof(mpz_t) * (S));
      for (int _picco_j = 0; _picco_j < S; _picco_j++)
            mpz_init(A[_picco_i][_picco_j]);
    }

  mpz_t** B; 
  B = (mpz_t**)malloc(sizeof(mpz_t*) * (S));
  for (int _picco_i = 0; _picco_i < S; _picco_i++)
    {
      B[_picco_i] = (mpz_t*)malloc(sizeof(mpz_t) * (S));
      for (int _picco_j = 0; _picco_j < S; _picco_j++)
            mpz_init(B[_picco_i][_picco_j]);
    }

  mpz_t** C; 
  C = (mpz_t**)malloc(sizeof(mpz_t*) * (S));
  for (int _picco_i = 0; _picco_i < S; _picco_i++)
    {
      C[_picco_i] = (mpz_t*)malloc(sizeof(mpz_t) * (S));
      for (int _picco_j = 0; _picco_j < S; _picco_j++)
            mpz_init(C[_picco_i][_picco_j]);
    }

  int i, j, k;

  for(int _picco_i = 0; _picco_i < S; _picco_i++)
    __s->smc_input(1, A[_picco_i], S, "int", -1);

  for(int _picco_i = 0; _picco_i < S; _picco_i++)
    __s->smc_input(1, B[_picco_i], S, "int", -1);

  k = 0;
  for ( ;k < 100; )
  {
    {
      {
        int _picco_batch_counter1 = 0;
        int _picco_batch_counter2 = 0;
        int _picco_ind1 = 0;
        int _picco_ind2 = 0;
                for (i = 0; i < S; i++)
          {
            ++_picco_batch_counter1;
            for (j = 0; j < S; j++)
              {
                ++_picco_batch_counter2;
              }
          }
        int* _picco_batch_index_array1 = (int*)malloc(sizeof(int) * 3 * _picco_batch_counter2);
        for (i = 0; i < S; i++)
          {
            for (j = 0; j < S; j++)
              {
                _picco_batch_index_array1[3*_picco_ind2] = i;
                _picco_batch_index_array1[3*_picco_ind2+1] = j;
                _picco_batch_index_array1[3*_picco_ind2+2] = (S) * (i) + j;
                _picco_ind2++;
              }
            _picco_ind1++;
          }
        __s->smc_batch(A, B, C, 32, 32, 32, S, S, S, NULL, NULL, -1, _picco_batch_index_array1, _picco_batch_counter2, "@", "int", -1);

        free(_picco_batch_index_array1);
      }
    }
    k++;
  }

  for(int _picco_i = 0; _picco_i < S; _picco_i++)
    __s->smc_output(1, C[_picco_i], S, "int", -1);

    for (int _picco_i = 0; _picco_i < S; _picco_i++)
    {
            for (int _picco_j = 0; _picco_j < S; _picco_j++)
              mpz_clear(C[_picco_i][_picco_j]);
            free(C[_picco_i]);
      }
  free(C);
  for (int _picco_i = 0; _picco_i < S; _picco_i++)
    {
            for (int _picco_j = 0; _picco_j < S; _picco_j++)
              mpz_clear(B[_picco_i][_picco_j]);
            free(B[_picco_i]);
      }
  free(B);
  for (int _picco_i = 0; _picco_i < S; _picco_i++)
    {
            for (int _picco_j = 0; _picco_j < S; _picco_j++)
              mpz_clear(A[_picco_i][_picco_j]);
            free(A[_picco_i]);
      }
  free(A);
  mpz_clear(_picco_tmp1);
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

__s = new SMC_Utils(atoi(argv[1]), argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), IO_files, 3, 1, 33, "4294967311", 1);

struct timeval tv1;
struct timeval tv2;  int _xval = 0;

  gettimeofday(&tv1,NULL);
  _xval = (int) __original_main(argc, argv);
  gettimeofday(&tv2, NULL);
  std::cout << "Time: " << __s->time_diff(&tv1,&tv2) << std::endl;
  return (_xval);
}

