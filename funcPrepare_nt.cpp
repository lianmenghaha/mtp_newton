#ifndef FUNCPREPARE_NEWTON_CPP
#define FUNCPREPARE_NEWTON_CPP

void funcPrepare_nt()
{
    //from the elements in path, we want to find out for every object
    //oxmin,oxmax,oymin,oymax
    //we assume every pattern [oxmin,oxmax]*[oymin,oymax]
    for(auto o:seto)
    {
	vector<double> vx,vy;
	for(auto xy:o->path)
	{
	    vx.push_back(xy.first);
	    vy.push_back(xy.second);
	}
	o->oxmin=*min_element(vx.begin(),vx.end());
	o->oxmax=*max_element(vx.begin(),vx.end());
	o->oymin=*min_element(vy.begin(),vy.end());
	o->oymax=*max_element(vy.begin(),vy.end());
	o->cpx=(o->oxmin+o->oxmax)/2;
	o->cpy=(o->oymin+o->oymax)/2;
    

	//检测
	/*cout<<o->oxmin<<endl;
	cout<<o->oxmax<<endl;
	cout<<o->oymin<<endl;
	cout<<o->oymax<<endl;
	cout<<o->cpx<<" ? "<<o->cpy<<endl;*/

    }
}

#endif

