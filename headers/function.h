#pragma once
#ifdef INTEGER
void Rand_Int(int *, int);
void Print_Int(int *, int);
#define Type int
#define Rand Rand_Int
#define Print Print_Int
#endif
#ifdef DOUBLE
void Rand_Double(double *, int);
void Print_Double(double *, int);
#define Type double
#define Rand Rand_Double
#define Print Print_Double
#endif