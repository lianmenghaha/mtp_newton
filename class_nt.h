using namespace std;
class var;
class object
{
	public:
		// input
	    object();
	    string name;
	    vector<pair<double,double>> path;
	    double area;
	    set<object*> setco, setbo; // conflict: no merge, no absorption

	    //assume every pattern is [oxmin,oxmax]*[oymin,oymax]
	    double oxmin,oxmax,oymin,oymax;
		//store the coordinate of the  central point of the object
		double cpx,cpy;

		//information about priting group and drying time
		//vl:the printing group which object will be assigned to
		//bvl:binary variable,indicated if this object assigned to this printing group
		var *vl; // layer assignment
		//var **bvl;
};
object::object()
{
	vl=0;
	//bvl=0;
}
class combi
{
        public:
		combi();
		//the set of patterns
		set<object*> setp;
		//A_l=(a_{l,1},...,a_{l,N_P})\in {0,1}^N_P
		map<object*,int> A;


		//paramters for Newton
		//the vector of cpx,cpy
		vector<double> scpx,scpy;
		//the vector of xmin,xmax and ymin,ymax of patterns
		vector<pair<double,double>> x_minmax,y_minmax;
		//indicate if the central points of the patterns have the same x-coord. or y-coord.
		//1:x,2:y, 0:only one pattern or both x y not the same
		int m;
		//if m=1 or 2,xypc=the coord. of the same coord.
		double xypc;	



		//store the result from newton
		vector<pair<double,double>> xy;
		//store the drying time for each pattern
		set<double> dt;

		//maximal drying time for this combination
		double vmaxdt;

		//layer assignment
		//cpg[i]=1,when this combi is the i-th printing group
		var **cpg;
};
combi::combi()
{
	vmaxdt=0;
	m=0;
	xypc=0;
	cpg=0;
}
class var
{
        public:
                var();
                int typ; // 0: binary, 1: integer, 2: continuous
				int index;
                double lb, ub;
                set<int> cons_i;
                map<int,double> coef_cons; // cons_i, coef

		//store the result after Gurobi
                int intrval;//int val
                double dourval; // double val

		//store the sub-optimal solution after Gurobi
		//int intrval2;
		//double dourval2;
		vector<int> intrval2;
		vector<double> dourval2;

		// quadratic
		map<int, set<var*>> coef_setvar;
		map<pair<int, var*>, double> coef_varcons;
};
var::var()
{
        typ=-1;
        intrval=-1;
        dourval=-1;
}

