#include <iostream>
#include "MatConv.h"

using namespace std;

int main(){

   mat_ker kernel[3][3] = {
       {1, 0, 1},
       {0, 1, 0},
       {1, 0, 1}
   };

   mat_inp input[5][5] = {
       {1, 1, 1, 0, 0},
       {0, 1, 1, 1, 0},
       {0, 0, 1, 1, 1},
       {0, 0, 1, 1, 0},
       {0, 1, 1, 0, 0}
   };

   mat_outp hw_res[3][3], sw_res[3][3];
   int err_cnt = 0;

   for (int i = 0; i < OUTP_ROWS; i++) {
       for (int j = 0; j < OUTP_COLS; j++) {
           sw_res[i][j] = 0;
           for (int y = 0; y < KER_ROWS; y++) {
               for (int x = 0; x < KER_COLS; x++) {
                   sw_res[i][j] += kernel[y][x] * input[i + y][j + x];
               }
           }
       }
   }

   // Run the Matrix Convolution block
   #ifdef HW_COSIM
       MatConv(kernel,input,hw_res);
   #endif

   //Print the output
   for (int i = 0 ; i < OUTP_ROWS ; i++){
       for (int j = 0 ; j < OUTP_COLS ; j++){
           #ifdef HW_COSIM
               cout << hw_res[i][j];
               if (hw_res[i][j] != sw_res[i][j]){
                   cout << "*";
                   err_cnt++;
               }
           #else
               cout << sw_res[i][j];
           #endif
           cout << " ";
       }
       cout << endl;
   }

   #ifdef HW_COSIM
       if (err_cnt)
           cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
       else
           cout << "Test passed." << endl;
   #endif
   return err_cnt;

}
