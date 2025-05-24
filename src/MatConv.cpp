#include "MatConv.h"

void MatConv(
	mat_ker ker[KER_ROWS][KER_COLS],
	mat_inp inp[INP_ROWS][INP_COLS],
	mat_outp outp[OUTP_ROWS][OUTP_COLS]
){
    Output_Rows: for(int i = 0; i < OUTP_ROWS; i++){
        Output_Cols: for(int j = 0; j < OUTP_COLS; j++){
            outp[i][j] = 0;
            Ker_Rows: for (int y = 0; y < KER_ROWS; y++){
                Ker_Cols: for (int x = 0; x < KER_COLS; x++){
                    outp[i][j] += ker[y][x] * inp[i + y][j + x];
                }
            }
        }
    }
}
