#ifndef FUNCNEWTON_VAR_CPP
#define FUNCNEWTON_VAR_CPP
void funcNewton_Var()
{
    //max printing group, N_G
    maxL=new var;
    maxL->index=vvar.size();//begin at 0
    maxL->lb=1;
    maxL->ub=seto.size();//N_G<=N_P
	//maxL->ub=5;
    maxL->typ=1;
    vvar.push_back(maxL);
    //jiance
    //cout<<"maxL"<<endl;

    //Pi will be assigned into printing group g_{Pi}
    //o->vl
    for(auto o:seto)
    {
	o->vl=new var;
	o->vl->index=vvar.size();
	o->vl->lb=1;
	o->vl->ub=seto.size();
	o->vl->typ=1;
	vvar.push_back(o->vl);
    }
    //jiance
    //cout<<"o->vl"<<endl;

    //q_{l,m} binary,
    //q_{l,m}=1 when l-th combi be the m-th printing group
    for(auto c:setcmb)
    {
	c->cpg=new var*[seto.size()+1];//index: 0,...,seto.size()
	for(int i=1;i!=seto.size()+1;++i)//begin at 1
	{
	    c->cpg[i]=new var;
	    c->cpg[i]->index=vvar.size();
	    c->cpg[i]->lb=0;
	    c->cpg[i]->ub=1;
	    c->cpg[i]->typ=0;
	    vvar.push_back(c->cpg[i]);
	}
    }
    //jiance
    //cout<<"cpg"<<endl;

}



#endif

