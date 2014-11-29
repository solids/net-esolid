#!/bin/bash

./esolid -D desolid/boxinp2 desolid/boxinp5 output/D_boxinp2_boxinp5.bez
./esolid -D desolid/boxinp5 desolid/boxinp2 output/D_boxinp5_boxinp2.bez
./esolid -D desolid/boxinp3 desolid/boxinp5 output/D_boxinp3_boxinp5.bez
./esolid -D desolid/boxinp6 desolid/boxinp5 output/D_boxinp6_boxinp5.bez
./esolid -D desolid/cylinp3 desolid/cylinp5 output/D_cylinp3_cylinp5.bez
./esolid -D desolid/cylinp10 desolid/cylinp5 output/D_cylinp10_cylinp5.bez
./esolid -D desolid/cylinp10 desolid/boxinp5 output/D_cylinp10_boxinp5.bez
./esolid -D desolid/boxinp4 desolid/boxinp5 output/D_boxinp4_boxinp5.bez

./esolid -I desolid/boxinp2 desolid/boxinp5 output/I_boxinp2_boxinp5.bez
./esolid -I desolid/boxinp5 desolid/boxinp2 output/I_boxinp5_boxinp2.bez
./esolid -I desolid/boxinp3 desolid/boxinp5 output/I_boxinp3_boxinp5.bez
./esolid -I desolid/boxinp6 desolid/boxinp5 output/I_boxinp6_boxinp5.bez
./esolid -I desolid/cylinp3 desolid/cylinp5 output/I_cylinp3_cylinp5.bez
./esolid -I desolid/cylinp10 desolid/cylinp5 output/I_cylinp10_cylinp5.bez
./esolid -I desolid/cylinp10 desolid/boxinp5 output/I_cylinp10_boxinp5.bez
./esolid -I desolid/boxinp4 desolid/boxinp5 output/I_boxinp4_boxinp5.bez

./esolid -U desolid/boxinp2 desolid/boxinp5 output/U_boxinp2_boxinp5.bez
./esolid -U desolid/boxinp5 desolid/boxinp2 output/U_boxinp5_boxinp2.bez
./esolid -U desolid/boxinp3 desolid/boxinp5 output/U_boxinp3_boxinp5.bez
./esolid -U desolid/boxinp6 desolid/boxinp5 output/U_boxinp6_boxinp5.bez
./esolid -U desolid/cylinp3 desolid/cylinp5 output/U_cylinp3_cylinp5.bez
./esolid -U desolid/cylinp10 desolid/cylinp5 output/U_cylinp10_cylinp5.bez
./esolid -U desolid/cylinp10 desolid/boxinp5 output/U_cylinp10_boxinp5.bez
./esolid -U desolid/boxinp4 desolid/boxinp5 output/U_boxinp4_boxinp5.bez