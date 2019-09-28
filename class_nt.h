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


		//information about priting group and drying time
		//vl:the printing group which object will be assigned to
		//bvl:binary variable,indicated if this object assigned to this printing group
		var *vl, **bvl; // layer assignment
};
object::object()
{
	vl=0;
	bvl=0;
}
class combi
{
        public:
		combi();
		//the set of patterns
		set<object*> setp;
		//maximal drying time for this combination
		var *vmaxdt;
		//layer assignment
		//vl:the printing group which combination will be assigned to 
		//bvl:binary variable,indicated if this combination assigned to this printing group
		var *vl,**bvl;
};
combi::combi()
{
	vmaxdt=0;
	vl=0;
	bvl=0;
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
