#ifndef FUNCCOMBINATION_NT_CPP
#define FUNCCOMBINATION_NT_CPP
void funcCombination_nt(int combin)
{
    vector<object*> vo(seto.begin(),seto.end());
    /*for(auto o:vo)
	cout<<o->name<<endl;*/
    set<vector<object*>> sn;
    for(auto o:seto)
    {
	for(auto on:o->setco)
	    sn.insert({o,on});
	for(auto on:o->setbo)
	{
	    sn.insert({o,on});
	    sn.insert({on,o});
	}
    }
    //jiance
    /*for(auto sne:sn)
	cout<<sne[0]->name<<","<<sne[1]->name<<endl;*/

    //update sm
    /*set<vector<object*>> smcpy(sm);
    for(auto sme:smcpy)
    {i
	for_each_permutation(sme.begin(),next(sme.begin(),sme.size()),sme.end(),[&](vector<object*>::iterator vbeg,vector<object*>::iterator vend)
	{
	if(vbeg!=vend)
	{
	vector<object*> vtmp(vbeg,vend);
	sm.insert(vtmp);
	}
	return false;
	});
    }*/
    //jiance
    /*for(auto sme:sm)
    {
	for(auto v:sme)
	    cout<<v->name<<" ? ";
	cout<<endl;
    }*/
	
    
    
    
    
    
    
    //jiance
    /*for(auto sme:sm)
	cout<<sme[0]->name<<","<<sme[1]->name<<","<<sme[2]->name<<endl;*/
    size_t num_visits=0;
    //this 7 we get from the last result
    for(size_t k=1;k<=combin;++k)
	for_each_combination(vo.begin(),next(vo.begin(),k),vo.end(),
		[&](vector<object*>::iterator vbeg,vector<object*>::iterator vend)
		{
		int itmp=0;//indicate for sn
		int itmp2=0;//indicate for sm
		if(vbeg!=vend)
		{
		//must not contain the set in sn
		for(auto sne:sn)
		{
		if(includes(vbeg,vend,sne.begin(),sne.end()))
		{
		++itmp;
		break;
		}
		}
		//if contains one element in sm, then must the rest set
		for(auto sme:sm)
		{
		if(itmp2==0)
		{
		for(auto smee:sme)
		{
		if((find(vbeg,vend,smee)!=vend)&&(!(includes(vbeg,vend,sme.begin(),sme.end()))))
		{
		    ++itmp2;
		    break;
		}
		}
		}
		else
		    break;
		}
		if((itmp==0)&&(itmp2==0))
		{
		    ++num_visits;
		    //we bild new combination
		    combi *c=new combi;
		    setcmb.insert(c);
		    for(;vbeg!=vend;++vbeg)
		    {
			c->setp.insert(*vbeg);
			c->scpx.push_back((*vbeg)->cpx);
			c->scpy.push_back((*vbeg)->cpy);
			c->x_minmax.push_back(make_pair((*vbeg)->oxmin,(*vbeg)->oxmax));
			c->y_minmax.push_back(make_pair((*vbeg)->oymin,(*vbeg)->oymax));
			//jiance
			//cout<<(*vbeg)->name<<",";
			double cxmin=*min_element(c->scpx.begin(),c->scpx.end());
			double cxmax=*max_element(c->scpx.begin(),c->scpx.end());
			double cymin=*min_element(c->scpy.begin(),c->scpy.end());
			double cymax=*max_element(c->scpy.begin(),c->scpy.end());
			if((cxmin==cxmax)&&(cymin!=cymax))
			{
			    c->m=1;
			    c->xypc=cxmin;
			}
			if((cymin==cymax)&&(cxmin!=cxmax))
			{
			    c->m=2;
			    c->xypc=cymin;
			}
			else
			    c->m=0;

		    }
		    for(auto o:seto)
		    {
			if(c->setp.find(o)==c->setp.end())//o is not in this combi
			    c->A[o]=0;
			else
			    c->A[o]=1;
		    }

		    //cout<<endl;
		}
		}
		return false;
		});
		
		
    //jiance
    /*for(auto elem:setcmb)
    {
	cout<<"!";
	for(auto e:elem->setp)
	    cout<<e->name<<" ? ";
	cout<<endl;
	for(auto e:elem->scpx)
	    cout<<e<<" : ";
	cout<<endl;
	for(auto e:elem->x_minmax)
	    cout<<e.first<<" ..."<<e.second<<" ";
	for(auto e:elem->y_minmax)
	    cout<<e.first<<" iii "<<e.second<<" ";
	cout<<endl;
	cout<<"lala "<<elem->m<<endl;
	cout<<"jiance A"<<endl;
	for(auto o:seto)
	    cout<<o->name<<": "<<elem->A[o]<<" en ";
	cout<<endl;
    }*/
    

		
	    
	    
	    
	   












}
#endif

