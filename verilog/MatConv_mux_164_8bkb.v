// ==============================================================
// File generated on Wed Jun 04 12:39:00 +0700 2025
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================

`timescale 1ns/1ps

module MatConv_mux_164_8bkb #(
parameter
    ID                = 0,
    NUM_STAGE         = 1,
    din0_WIDTH       = 32,
    din1_WIDTH       = 32,
    din2_WIDTH       = 32,
    din3_WIDTH       = 32,
    din4_WIDTH       = 32,
    din5_WIDTH       = 32,
    din6_WIDTH       = 32,
    din7_WIDTH       = 32,
    din8_WIDTH       = 32,
    din9_WIDTH       = 32,
    din10_WIDTH       = 32,
    din11_WIDTH       = 32,
    din12_WIDTH       = 32,
    din13_WIDTH       = 32,
    din14_WIDTH       = 32,
    din15_WIDTH       = 32,
    din16_WIDTH         = 32,
    dout_WIDTH            = 32
)(
    input  [7 : 0]     din0,
    input  [7 : 0]     din1,
    input  [7 : 0]     din2,
    input  [7 : 0]     din3,
    input  [7 : 0]     din4,
    input  [7 : 0]     din5,
    input  [7 : 0]     din6,
    input  [7 : 0]     din7,
    input  [7 : 0]     din8,
    input  [7 : 0]     din9,
    input  [7 : 0]     din10,
    input  [7 : 0]     din11,
    input  [7 : 0]     din12,
    input  [7 : 0]     din13,
    input  [7 : 0]     din14,
    input  [7 : 0]     din15,
    input  [3 : 0]    din16,
    output [7 : 0]   dout);

// puts internal signals
wire [3 : 0]     sel;
// level 1 signals
wire [7 : 0]         mux_1_0;
wire [7 : 0]         mux_1_1;
wire [7 : 0]         mux_1_2;
wire [7 : 0]         mux_1_3;
wire [7 : 0]         mux_1_4;
wire [7 : 0]         mux_1_5;
wire [7 : 0]         mux_1_6;
wire [7 : 0]         mux_1_7;
// level 2 signals
wire [7 : 0]         mux_2_0;
wire [7 : 0]         mux_2_1;
wire [7 : 0]         mux_2_2;
wire [7 : 0]         mux_2_3;
// level 3 signals
wire [7 : 0]         mux_3_0;
wire [7 : 0]         mux_3_1;
// level 4 signals
wire [7 : 0]         mux_4_0;

assign sel = din16;

// Generate level 1 logic
assign mux_1_0 = (sel[0] == 0)? din0 : din1;
assign mux_1_1 = (sel[0] == 0)? din2 : din3;
assign mux_1_2 = (sel[0] == 0)? din4 : din5;
assign mux_1_3 = (sel[0] == 0)? din6 : din7;
assign mux_1_4 = (sel[0] == 0)? din8 : din9;
assign mux_1_5 = (sel[0] == 0)? din10 : din11;
assign mux_1_6 = (sel[0] == 0)? din12 : din13;
assign mux_1_7 = (sel[0] == 0)? din14 : din15;

// Generate level 2 logic
assign mux_2_0 = (sel[1] == 0)? mux_1_0 : mux_1_1;
assign mux_2_1 = (sel[1] == 0)? mux_1_2 : mux_1_3;
assign mux_2_2 = (sel[1] == 0)? mux_1_4 : mux_1_5;
assign mux_2_3 = (sel[1] == 0)? mux_1_6 : mux_1_7;

// Generate level 3 logic
assign mux_3_0 = (sel[2] == 0)? mux_2_0 : mux_2_1;
assign mux_3_1 = (sel[2] == 0)? mux_2_2 : mux_2_3;

// Generate level 4 logic
assign mux_4_0 = (sel[3] == 0)? mux_3_0 : mux_3_1;

// output logic
assign dout = mux_4_0;

endmodule
