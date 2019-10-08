#ifndef FUNCRWFILE_NT_CPP
#define FUNCRWFILE_NT_CPP
void funcReadFile_nt(const char* filename_obj,const char *filename_conf)
{
    //read path info of objects,object.txt
    fstream ReadFile_obj(filename_obj,fstream::in);
    string rname,line;
    ReadFile_obj>>rname;
    while(!ReadFile_obj.eof())
    {
	object *o=new object;
	o->name=rname;
	mapnameo[rname]=o;
	seto.insert(o);
	ReadFile_obj>>o->area;
	//read details of path
	while(ReadFile_obj>>rname)
	{
	    if(ReadFile_obj.eof()||rname[rname.size()-1]!=':')
		break;
	    getline(ReadFile_obj,line);
	    auto strpos1=1;
	    auto strpos2=line.find_first_of("+");
	    auto strpos3=line.find_first_of("i");
	    auto strpos4=line.find_last_of("+");
	    double x1,x2,y1,y2;
	    x1=atof(line.substr(strpos1,strpos2-strpos1).c_str());
	    y1=atof(line.substr(strpos2+1,strpos3-strpos2-1).c_str());
	    x2=atof(line.substr(strpos3+2,strpos4-strpos3-2).c_str());
	    y2=atof(line.substr(strpos4+1,line.size()-strpos4-2).c_str());
	    o->path.push_back({x1,y1});
	    o->path.push_back({x2,y2});
	}
    }
    ReadFile_obj.close();
    //read conflict info of objects
    fstream ReadFile_conf(filename_conf,fstream::in);
    while(getline(ReadFile_conf,line))
    {
	//jiance
	//cout<<"conf"<<endl;
	if(ReadFile_conf.eof())
	    break;
	if(line.compare("no merge conflict:")==0)
	{
	    //jiance
	    //cout<<"yidu"<<endl;
	    while(ReadFile_conf>>rname)
	    {
		if(rname.compare("FIN")==0)
		    break;
		object *o=mapnameo[rname];
		//cout<<rname<<" ";
		int nobj;
		ReadFile_conf>>nobj;
		//cout<<nobj<<" ";
		for(int i=0;i!=nobj;++i)
		{
		    ReadFile_conf>>rname;
		    o->setco.insert(mapnameo[rname]);
		    //jiance
		    //cout<<rname<<endl;
		}
	    }
	}
	if(line.compare("no absorption conflict:")==0)
	{
	    //jiance
	    //cout<<"yidu2"<<endl;
	    while(ReadFile_conf>>rname)
	    {
		if(rname.compare("FIN")==0)
		    break;
		object *o=mapnameo[rname];
		int nobj;
		ReadFile_conf>>nobj;
		for(int i=0;i!=nobj;++i)
		{
		    ReadFile_conf>>rname;
		    o->setbo.insert(mapnameo[rname]);
		    //jiance
		   // cout<<"no"<<endl;
		}
	    }
	}
	if(line.compare("inseparable:")==0)
	{
	    while(ReadFile_conf>>rname)
	    {
		if(rname.compare("FIN")==0)
		    break;
		int nobj;
		vector<object*> vobj;
		ReadFile_conf>>nobj;
		for(int i=0;i!=nobj;++i)
		{
		    ReadFile_conf>>rname;
		    vobj.push_back(mapnameo[rname]);
		    //jiance
		    //cout<<"aiza "<<rname<<endl;
		}
		sm.insert(vobj);
	    }
	}

    }
    ReadFile_conf.close();
}

void funcWriteFile_nt(const char* filename,int psol,const char* filenamesub)
{
    for(int i=1;i!=maxL->intrval+1;++i)
    {
	ostringstream convi;
	convi<<i;
	string strtmp=filename;
	strtmp+="_objassign"+convi.str()+".txt";
	fstream WriteFile_oa(strtmp.c_str(),fstream::out);
	WriteFile_oa<<"Printing Group: "<<i<<endl;
	for(auto c:setcmb)
	{
	    if(c->cpg[i]->intrval==1)
	    {
		WriteFile_oa<<"The total number of objects: "<<c->setp.size()<<endl;
		for(auto o:c->setp)
		    WriteFile_oa<<o->name<<endl;

		WriteFile_oa.setf(ios_base::fixed,ios_base::floatfield);
		WriteFile_oa.precision(10);
		WriteFile_oa<<"The total drying time for this layer is: "<<c->vmaxdt<<endl;
	    }
	}
	WriteFile_oa.close();
    }

    //write the information about sub-optimal solution
    for(int i=0;i!=psol;++i)
    {
	ostringstream convi;
	convi<<i;
	string strtmp=filenamesub;
	strtmp+="_subop"+convi.str()+".txt";
	fstream WriteFile_sub(strtmp.c_str(),fstream::out);
	WriteFile_sub<<"The "<<i<<"-th sub-optimal Solution"<<endl;
	double dtmp=0;
	for(int k=1;k!=maxL->intrval2[i]+1;++k)
	{
	    WriteFile_sub<<"Pringting Group "<<k<<" : "<<endl;
	    for(auto c:setcmb)
	    {
		if(c->cpg[k]->intrval2[i]==1)
		{
			dtmp+=c->vmaxdt;
		    for(auto o:c->setp)
			WriteFile_sub<<o->name<<" ";
		    WriteFile_sub<<endl;
		    WriteFile_sub.setf(ios_base::fixed,ios_base::floatfield);
		    WriteFile_sub.precision(10);
		    WriteFile_sub<<"The total drying time for this layer is: "<<c->vmaxdt<<endl;
		}
	    }
	
	}
	WriteFile_sub<<endl;
	WriteFile_sub<<"Total Printing Group: "<<maxL->intrval2[i]<<endl;
	WriteFile_sub<<"Sum of Optimization Solution: "<<dtmp+maxL->intrval2[i]<<endl;
	WriteFile_sub.close();
    }
}


#endif

