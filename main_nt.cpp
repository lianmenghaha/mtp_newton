#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<ctime>
#include<algorithm>
#include"alg_combi.cpp"
#include"gurobi_c++.h"

#include"class_nt.h"
#include"gv_nt.h"
#define Mval 1000000

#include<gsl/gsl_errno.h>
#include<gsl/gsl_math.h>
#include<gsl/gsl_sf.h>
#include<gsl/gsl_randist.h>
#include<gsl/gsl_cdf.h>
#include<gsl/gsl_roots.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_multiroots.h>

using namespace std;

#include"funcRWFile_nt.cpp"
#include"funcPrepare_nt.cpp"
#include"funcCombination_nt.cpp"
#include"erf_Z_safe.cpp"
#include"Newton_fn.h"
#include"Newton_multi_fn.h"
#include"Newton_fn.cpp"
#include"Newton_multi_fn.cpp"
#include"funcNewton.cpp"
#include"funcNewton_Var.cpp"
#include"funcNewton_Cons.cpp"
#include"funcSM_nt.cpp"
#include"funcGurobi.cpp"


int main(int argc,char** argv)
{
	cout<<"Start Reading Files: objects.txt conflict.txt"<<endl;
    funcReadFile_nt(argv[1],argv[2]);
    cout<<"Finished Reading Files."<<endl;
	cout<<"Preparing for the Combination"<<endl;
	funcPrepare_nt();
	cout<<"Finished Preparing."<<endl;
	cout<<"Start Building the Combinations."<<endl;
	funcCombination_nt(atoi(argv[3]));//maximal obj.nr.in one combination
	cout<<"Finished Building "<<setcmb.size() <<" Combinations"<<endl;
	cout<<"Start Computing the Drying Time for each possible Combination of the Patterns."<<endl;
	funcNewton();
	cout<<"Finished Computing."<<endl;
	cout<<"Start Building Variables."<<endl;
	funcNewton_Var();
	cout<<"Finished Building Variables: "<<vvar.size()<<" Variables."<<endl;
	cout<<"Start Building Constraints:"<<endl;
	funcNewton_Cons();
	cout<<"Finished Building Constraints: "<<nCons<<" Constraints."<<endl;
	funcGurobi(0,0.05,atoi(argv[4]),0.0,0.0,1,1,atoi(argv[5]),2);
	//min/max,heu,time,absgap,gap,display,focus,psol,psmode
	funcWriteFile_nt(argv[6],atoi(argv[5]),argv[7]);
	funcSM_nt();

    return 0;
}

