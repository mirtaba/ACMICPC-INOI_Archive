swipline n^2log^2n for 2D / should search for nlog^2n or nlogn algorithm
bitcount __builtin_popcont()
all hardware supported methods are started with __builtin_

fenwick(binary indexed tree)

define LSB(a) ((a)&(-a))

void ft-update(int index, int val){

	for(index;index < 100; index += LSB(index))
		A[index] += val;
}

int ft-query(int index){

	int val = 0;
	for(;index>0; index -= LSB(index))
		val += A[index];
	return val;
}


go learn KMP