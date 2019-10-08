#ifndef FUNCNEWTON_CONS_CPP
#define FUNCNEWTON_CONS_CPP
void funcNewton_Cons()
{
    nCons=-1;
	for(auto o:seto)
    {
	//g_{Pi}<=Ng
	//o->vl-maxL<=0
	nCons++;
	mapcv[nCons].insert(o->vl);
	o->vl->cons_i.insert(nCons);
	o->vl->coef_cons[nCons]=1;
	mapcv[nCons].insert(maxL);
	maxL->cons_i.insert(nCons);
	maxL->coef_cons[nCons]=-1;
	mapcs[nCons]=-1;
	mapcc[nCons]=0;
    }
    //N_G=sum_l sum_m q_{l,m},l=1,...,N_l, m=1,...,N_P
    /*nCons++;
    for(auto c:setcmb)
    {
	for(int i=1;i!=seto.size()+1;++i)
	{
	    mapcv[nCons].insert(c->cpg[i]);
	    c->cpg[i]->cons_i.insert(nCons);
	    c->cpg[i]->coef_cons[nCons]=1;
	}
    }
    mapcv[nCons].insert(maxL);
    maxL->cons_i.insert(nCons);
    maxL->coef_cons[nCons]=-1;
    mapcs[nCons]=0;
    mapcc[nCons]=0;*/

    //for i=1,...,N_P
    //(1)sum_l sum_m a_{l,i}*q_{l,m}=1
    //(2)g_{Pi}=sum_l sum_m m*a_{l,i}*q_{l,m}
    for(auto o:seto)
    {
	//(1)
	nCons++;
	for(auto c:setcmb)
	{
	    for(int i=1;i!=seto.size()+1;++i)
	    {
		mapcv[nCons].insert(c->cpg[i]);
		c->cpg[i]->cons_i.insert(nCons);
		c->cpg[i]->coef_cons[nCons]=c->A[o];
	    }
	}
	mapcs[nCons]=0;
	mapcc[nCons]=1;
	//(2)
	nCons++;
	for(auto c:setcmb)
	{
	    for(int i=1;i!=seto.size()+1;++i)
	    {
		mapcv[nCons].insert(c->cpg[i]);
		c->cpg[i]->cons_i.insert(nCons);
		c->cpg[i]->coef_cons[nCons]=i*c->A[o];
		mapcv[nCons].insert(o->vl);
		o->vl->cons_i.insert(nCons);
		o->vl->coef_cons[nCons]=-1;
	    }
	}
	mapcs[nCons]=0;
	mapcc[nCons]=0;
    }

    //(3)Modelling of Laplace Pressure Conflict
    for(auto o:seto)
    {
	//g_{Pi}+1<=g_{Pj}
	for(auto on:o->setbo)
	{
	    //o->vl+1<=on->vl
		//o->vl-on->vl<=1
	    nCons++;
	    mapcv[nCons].insert(o->vl);
	    o->vl->cons_i.insert(nCons);
	    o->vl->coef_cons[nCons]=1;
	    mapcv[nCons].insert(on->vl);
	    on->vl->cons_i.insert(nCons);
	    on->vl->coef_cons[nCons]=-1;
	    mapcs[nCons]=-1;
	    mapcc[nCons]=-1;
	}
    }
	//(4)each printing group can only contains one combi
	//m=1,...,N_G
	//sum_l q_{l,m}<=1
	for(int i=1;i!=seto.size()+1;++i)
	{
		nCons++;
		for(auto c:setcmb)
		{
			mapcv[nCons].insert(c->cpg[i]);
			c->cpg[i]->cons_i.insert(nCons);
			c->cpg[i]->coef_cons[nCons]=1;
		}
		mapcs[nCons]=-1;
		mapcc[nCons]=1;
	}


    //(5)Minimize N_G+sum_l sum_m d_l*q_{l,m}
    nCons++;
    objcons=nCons;
    mapcv[objcons].insert(maxL);
    maxL->cons_i.insert(objcons);
    maxL->coef_cons[objcons]=1;
    for(auto c:setcmb)
    {
	for(int i=1;i!=seto.size()+1;++i)
	{
	    mapcv[objcons].insert(c->cpg[i]);
	    c->cpg[i]->cons_i.insert(objcons);
	    c->cpg[i]->coef_cons[objcons]=c->vmaxdt;
	}
    }
    
    //jiance
    //cout<<objcons<<endl;


}


#endif

