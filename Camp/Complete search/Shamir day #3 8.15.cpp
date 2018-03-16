finding tree diameter using two dfs
first one finds the most far leaf that it's gauranties that it's one side of the longest path
with the second dfs from the known leaf we find the other side of the longest path


PII DFS(u,Par){ // first of return is the most fat leaf itself and second is the distance of it
	PII maxi;
	for(v -> adj(u)){
		if(v != Par){

			maxi = max(maxi,DFS(v,u)); // it dosen't work, a good max using dis and updating the vertex is needed here
		}
	}
}

we call DFS(0,-1) to find the

 