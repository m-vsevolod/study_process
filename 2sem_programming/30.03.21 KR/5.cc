bool rewrite_memories(int* begin, int* end, int* fake, unsigned int n){
	if( 1 + end - begin != n ){
		if ( 1 + end - begin < n ){
			for ( int i = 0; i < 1 + end - begin; i++){
				begin[i] = fake[i];
			}
			return false;
		}
		else {
			for ( int i = 0; i < n; i++){
				begin[i] = fake[i];
			}
		return false;
		}
	}
	else {
		for ( int i = 0; i < 1 + end - begin; i++){
			begin[i] = fake[i];
		}
		return true;
	}
}