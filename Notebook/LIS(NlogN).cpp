void LIS(vector <int> in, vector <int> &out){

    if(in.size() == 0) return;

    vector <int> par(in.size(),(int)-1) ;
	vector <int> lisNumb , lisIndex;

	for(int i = 0; i < in.size(); i++){

        auto it = upper_bound(lisNumb.begin(),lisNumb.end(),in[i]); //upper_bound -> increasing
                                                                    //lower_bound -> strictly increasing

        int index = it-lisNumb.begin();
        if(it == lisNumb.end()) {

                lisNumb.push_back(in[i]);
                lisIndex.push_back(i);
        }
        else{
           lisNumb[index] = in[i];
           lisIndex[index] = i;
        }

        if(index != 0)
            par[i] = lisIndex[index-1];

	}

	out.push_back(in[lisIndex[lisIndex.size()-1]]);
	int tp = par[lisIndex[lisIndex.size()-1]];
	while(tp != -1){

        out.push_back(in[tp]);
        tp = par[tp];

	}

}
