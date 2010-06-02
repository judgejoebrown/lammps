/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under 
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(dpd/omp,PairDPDOMP)

#else

#ifndef LMP_PAIR_DPD_OMP_H
#define LMP_PAIR_DPD_OMP_H

#include "pair_omp.h"

namespace LAMMPS_NS {

class PairDPDOMP : public PairOMP {
 public:
  PairDPDOMP(class LAMMPS *);
  virtual ~PairDPDOMP();
  virtual void compute(int, int);
  virtual void settings(int, char **);
  virtual void coeff(int, char **);
  void init_style();
  double init_one(int, int);
  void write_restart(FILE *);
  void read_restart(FILE *);
  virtual void write_restart_settings(FILE *);
  virtual void read_restart_settings(FILE *);
  double single(int, int, int, int, double, double, double, double &);

 protected:
  double cut_global,temperature;
  int seed;
  double **cut;
  double **a0,**gamma;
  double **sigma;
  class RanMars **random;

  template <int, int, int> void eval();
  void allocate();
};

}

#endif
#endif
