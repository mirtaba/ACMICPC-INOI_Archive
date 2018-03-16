// C is the coins , we start from the amount we want to make to the 0 to make sure that we don't use a same coins multiple times
// d[i] is egual to 0 if we can't make it , and if we can make it, the last coin we made is the d[i]
d[0]=1;
FOR(i,0,N)
    for (LL i = goal;i >=0;i++)
    {
        if (d[i])
            d[i+C[i]]=C[i];
    }
d[0]=0;
