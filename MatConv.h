// Make sure that this module is compiled only once
#ifndef __MATCONV_H__   
#define __MATCONV_H__

#define KER_ROWS 5
#define KER_COLS 5
#define INP_ROWS 15
#define INP_COLS 15
#define OUTP_ROWS (INP_ROWS - KER_ROWS + 1)
#define OUTP_COLS (INP_COLS - KER_COLS + 1)

// This allow debugging between c and rtl
#define HW_COSIM

typedef char mat_ker;
typedef char mat_inp;
typedef short mat_outp;

#define HW_COSIM

void MatConv(
    mat_ker ker[KER_ROWS][KER_COLS],
    mat_inp inp[INP_ROWS][INP_COLS],
    mat_outp outp[OUTP_ROWS][OUTP_COLS]
);

#endif // __MATCONV_H__

