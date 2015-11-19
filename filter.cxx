/* Homework 4 Part 2
 * Programm reads data from a file,
 * filters it and saves it to a new datafile
 * 
 * Written by: Michael Stumpf
 */

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

double* read(const int, const string);
void filtering(const int, double* const);
void saving(const int, double* const, string);

int main(){
  const int N = 237;	// number of data points
  const int M = 15;	// number of filter iterations
  const string fname = "noisy.txt"; // name of data-input
  double* p;
  p = read(N, fname);
  stringstream sname;
  
  for(int i=0; i<M; i++){	//for-loop to do filtering and saving serveral timesl
    sname.str("");
    sname << "fdata_" << i+1 << ".txt";
    filtering(N, p);
    saving(N, p, sname.str());
  }
  
  delete[] p;  
  return 0;
}

double* read(const int N, const string fname){
  ifstream in(fname.c_str());
  double* p = new double[N]; //creates array for input-reading
  for(int i=0; i<N; i++){	//reading for-loop
    in >> p[i];  
  }
  in.close();
  return p;
}

void filtering(const int N, double* const p){
  double temp0 = p[0];		//store some values temporarily
  double temp1 = p[0];		//store some values temporarily
  
  p[0] = (p[N-1]+p[0]+p[1])/3;	//filtering p1
  
  for(int i=1; i<(N-1); i++){
    double temp2 = p[i];
    p[i]=(temp1+p[i]+p[i+1])/3;	//filtering p
    temp1 = temp2;
  }
  p[N-1] = (temp1+p[N-1]+temp0)/3;	//filtering pN
}

void saving(const int N, double* const p, string sname){
  ofstream out(sname.c_str());
  for(int i=0; i<N; i++){	//for-loop for saving p
    out << p[i] << endl;  
  }
  out.close();
  
}