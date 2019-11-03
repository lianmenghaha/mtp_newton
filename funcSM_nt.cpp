#ifndef FUNCSCREENMESSAGE_CPP
#define FUNCSCREENMESSAGE_CPP
void funcSM_nt()
{
    //object info
    for(auto o:seto)
    {
	cout<<o->name<<": "<<endl;
	if(o->setco.size()!=0)
	{
	    cout<<"MC: ";
	    for(auto on:o->setco)
		cout<<on->name<<" ";
	    cout<<endl;
	}
	if(o->setbo.size()!=0)
	{
	    cout<<"LPC: ";
	    for(auto on:o->setbo)
		cout<<on->name<<" ";
	    cout<<endl;
	}
    }
    cout<<endl;
    //layer info
	double dtmp=0;
    for(int i=1;i!=maxL->intrval+1;++i)
    {
	cout<<"Printing Group "<<i<<":"<<endl;
	for(auto c:setcmb)
	{
	    if(c->cpg[i]->intrval==1)
	    {
		for(auto o:c->setp)
		    cout<<o->name<<" ";
		cout<<endl;
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout.precision(10);
		cout<<"The Drying Time for this Printing Group: "<<c->vmaxdt<<endl;
		dtmp+=c->vmaxdt;
	    }
	}
	//cout<<endl;
    }
	cout<<endl;
	cout<<"Total Printing Group: "<<maxL->intrval<<endl;
	cout<<"Total Sum of Drying Time is: "<<dtmp<<endl;
	/*int lyn=0;
    while(lyn!=maxL->intrval)
    {
	for(auto c:setcmb)
	{
	    for(int i=1;i!=seto.size()+1;++i)
	    {
		if(c->cpg[i]->intrval==1)
		{
		    ++lyn;
			cout<<i<<endl;
		    cout<<"Printing Group "<<lyn<<": "<<endl;
		    for(auto o:c->setp)
			cout<<o->name<<" ";
		    cout<<endl;
		    cout.setf(ios_base::fixed,ios_base::floatfield);
		    cout.precision(10);
		    cout<<c->vmaxdt<<endl;
		}
	    }
	}
    }*/
	//jiance
	/*cout<<maxL->intrval<<endl;
	for(auto c:setcmb)
	{
		for(auto o:c->setp)
		  cout<<o->name<<".";
		cout<<endl;
		cout<<c->vmaxdt<<endl;
		for(int i=1;i!=seto.size()+1;++i)
		  cout<<c->cpg[i]->intrval<<":";
		cout<<endl;
	}
	for(auto o:seto)
	  cout<<o->name<<": "<<o->vl->intrval<<endl;
	cout<<endl;
	cout<<maxL->intrval<<endl;*/
}

#endif

