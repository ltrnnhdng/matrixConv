############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_array_partition -type complete -dim 0 "MatConv" ker
set_directive_array_partition -type complete -dim 0 "MatConv" inp
set_directive_array_partition -type complete -dim 0 "MatConv" outp
set_directive_unroll "MatConv/Ker_Cols"
set_directive_unroll "MatConv/Ker_Rows"
set_directive_pipeline "MatConv/Output_Cols"
set_directive_pipeline "MatConv/Output_Rows"
