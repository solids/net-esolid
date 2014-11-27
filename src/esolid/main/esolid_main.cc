//  file:  esolid_main.cc
//  update:  09/25/02

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

#ifdef _EXPERIMENT
unsigned long num_kratpoly_sgn_at       = 0;
unsigned long num_kratpoly_exact_sgn_at = 0;
unsigned long num_root1_isolate         = 0;
unsigned long num_root1_exact_isolate   = 0;
unsigned long num_kpoint1d_get_pts      = 0;
unsigned long num_kpoint2d_get_pts      = 0;
unsigned long num_ksolid_boolean        = 0;
#endif

int main(int argc, char* argv[])
{

  //assert(argc >= 4);

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
  static const bigrational perturb_factor_proto = 0;
//  static const bigrational perturb_factor_proto = bigrational(1, 512);
//  static const bigrational perturb_factor_proto = bigrational(1, 1024);

  op = argv[1][1];
  assert(op == 'D' || op == 'I' || op == 'U' || op == 'O' || op == 'M');

  CLOCK_START();

  if (op == 'D' || op == 'I' || op == 'U')
  {
    assert(argc == 5);

    if (op == 'D')
    {
      perturb_factor1 = perturb_factor_proto;
      perturb_factor2 = - perturb_factor_proto;
    }
    else if (op == 'I')
    {
      perturb_factor1 = - perturb_factor_proto;
      perturb_factor2 = - perturb_factor_proto;
    }
    else  //  if (op == 'U')
    {
      perturb_factor1 = perturb_factor_proto;
      perturb_factor2 = perturb_factor_proto;
    }

    in_file.open(argv[2]);
    s1 = read_solid(in_file, perturb_factor1);
    in_file.close();

    in_file.open(argv[3]);
    s2 = read_solid(in_file, perturb_factor2);
    in_file.close();

    s3 = s1.boolean(s2, op);

    out_file.open(argv[4]);
    s3.Bezier_output(out_file);
    out_file.close();
  }
  else if (op == 'O')
  {
    assert(argc == 4);

    perturb_factor = perturb_factor_proto;

    in_file.open(argv[2]);
    s3 = read_solid(in_file, perturb_factor);
    in_file.close();

    out_file.open(argv[3]);
    s3.Bezier_output(out_file);
    out_file.close();
  }
  else if (op == 'M')
  {
    assert(argc == 4);

    perturb_factor = perturb_factor_proto;

    s3 = read_CSG(argv[2], argv[3], perturb_factor);

    out_file.open(argv[3]);
    s3.Bezier_output(out_file);
    out_file.close();
  }

  CLOCK_STOP(&lap);
  cerr << " esolid_main: main: lap = " << lap << " micro-seconds. " << endl << flush;
#ifdef _EXPERIMENT
  cerr << " esolid_main: main: num_kratpoly_sgn_at       = " << num_kratpoly_sgn_at << endl << "                    num_kratpoly_exact_sgn_at = " << num_kratpoly_exact_sgn_at << endl << flush;
  cerr << " esolid_main: main: num_root1_isolate         = " << num_root1_isolate << endl << "                    num_root1_exact_isolate   = " << num_root1_exact_isolate << endl << flush;
  cerr << " esolid_main: main: num_kpoint1d_get_pts      = " << num_kpoint1d_get_pts << endl << flush;
  cerr << " esolid_main: main: num_kpoint2d_get_pts      = " << num_kpoint2d_get_pts << endl << flush;
  cerr << " esolid_main: main: num_ksolid_boolean        = " << num_ksolid_boolean << endl << flush;
#endif

  return 0;
}

