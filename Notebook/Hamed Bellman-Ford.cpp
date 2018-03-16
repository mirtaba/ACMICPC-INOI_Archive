// This is Bellman-Ford Algorithm use to find the shortest path between each two vertex in a DIRECTED graph
// Notice that if you have a circuit that the sum is negative , you should use something
// that described below to find this circuit

FOR(i,0,N)
{
    FOR(j,0,E)// V -> U
    {
        if (d[u] > (d[v]+w[j])) // w[j] is the weight of the j-th edge
        {
            d[u]=(d[v]+w[j]);
        }
    }
}
// this circuit will be found by running this algorithm again right afther you finished with a bellman.if the
// d for a vertex changed , then we have a negative circuit.
