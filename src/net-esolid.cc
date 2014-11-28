#include <uv.h>

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <timer.h>

#include <ksolid.h>
#include <genbox.h>
#include <gencyl.h>
#include <genell.h>
#include <gentor.h>

using namespace std;

int main(int argc, char* argv[]) {
  ifstream    in_file;
  ofstream    out_file;
  char        op;
  long        lap;
  bigrational perturb_factor1, perturb_factor2;
  bigrational perturb_factor;
  K_SOLID     s1, s2, s3;

  uint8_t num_pts = 8;

  bigrational_vector *in_pts = new bigrational_vector[num_pts];

  for (uint8_t i=0; i<num_pts; i++) {
    in_pts[i] = bigrational_vector(3);
  }

  in_pts[0][0] = 0; in_pts[0][1] = 2; in_pts[0][2] = 0;
  in_pts[1][0] = 2; in_pts[1][1] = 2; in_pts[1][2] = 0;
  in_pts[2][0] = 2; in_pts[2][1] = 0; in_pts[2][2] = 0;
  in_pts[3][0] = 0; in_pts[3][1] = 0; in_pts[3][2] = 0;
  in_pts[4][0] = 0; in_pts[4][1] = 0; in_pts[4][2] = 4;
  in_pts[5][0] = 2; in_pts[5][1] = 0; in_pts[5][2] = 4;
  in_pts[6][0] = 2; in_pts[6][1] = 2; in_pts[6][2] = 4;
  in_pts[7][0] = 0; in_pts[7][1] = 2; in_pts[7][2] = 4;

  bigrational_vector *pts = new bigrational_vector[num_pts];

  planarize(in_pts, pts, num_pts);

  gen_box(pts, num_pts).Bezier_output(cout);

  return 0;
}
