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
	}

	//检测
	//cout<<o->oxmin<<endl;
	//cout<<o->oxmax<<endl;
	//cout<<o->oymin<<endl;
	//cout<<o->oymax<<endl;

	//with the consideration of conflicts,we figure out every possible combination of patterns
	vector<object*> vo;
	for(auto o:seto)
	  vo.push_back(o);
	set<set<object*>> sn;
	set<set<object*>> st;
	for(auto o:seto)
	{
		if(o->setco.size()!=0)
		{
			for(auto on:o->setco)
				sn.insert({o,on});
		}
		if(o->setbo.size()!=0)
		{
			for(auto on:o->setbo)
			  sn.insert({o,on});
		}
	}

	unsigned int pow_set_size=pow(2,vo.size());
	int cnt,k;
	for(cnt=0;cnt!=pow_set_size;++cnt)
	{
		set<object*> stmp;
		for(k=0;k!=vo.size();++k)
		{
			if(cnt&(1<<k))
			  stmp.insert(vo[k]);
		}
		st.insert(stmp);
	}
	//jiance
	cout<<st.size()<<endl;
	//copy st
	set<set<object*>> stcpy=st;
	//erase the impossible combination
	for(auto s:stcpy)
	{
		if(s.size()==0)
		  st.erase(s);
		else{
			vector<int> vtmp;
			for(auto en:sn)
			{
				int itmp=0;
				for(auto esn:en)
				{
					if(s.find(esn)!=s.end())
					  ++itmp;
				}
				vtmp.push_back(itmp);
			}
			for(auto ve:vtmp)
			{
				if(ve==2)
				{
					st.erase(s);
					break;
				}
			}
		}
	}
	//jiance
	cout<<st.size()<<endl;
	
}







































#endif
