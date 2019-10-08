void funcReadFile_nt(const char*, const char*);
void funcPrepare_nt();
void funcNewton();
void funcNewton_Var();
void funcNewton_Cons();
void funcWriteFile_nt(const char*,int,const char*);
void funcGurobi(int, double, double, double, double, int, int,int,int,int);
void funcConsClear();//
void funcSM_nt();

// ReadFile
	// ReadFile_obj
	set<object*> seto;
	map<string, object*> mapnameo;
	// ReadFile_conf
	set<vector<object*>> sm;//for the obj. inseperable
	// ReadFile_dtime
// funcPrepare
// funcCombination_nt
	set<combi*> setcmb;
// funcModel_Var
var *maxL;
vector<combi*> vecc;

// Model
int nCons, objcons;
map<int,int> mapcs; // use cons index to map sense: 1=g, 0=e, -1=l
map<int,double> mapcc; // use cons index to map right side constant
map<int,set<var*>> mapcv; // use cons index to map corresponding vars
vector<var*> vvar;
set<int> qcons;

