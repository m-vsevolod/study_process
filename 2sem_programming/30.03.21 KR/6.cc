void rip_samurai(const Track *all_songs, unsigned int all_n, Track **in_memoriam_johnny, unsigned int* johnny_n) {
	
	for (unsigned int i = 0; i < all_n; ++i) {
		if (all_songs[i].author == 0) {
			++(*johnny_n);
		}
	}
	
	(*in_memoriam_johnny) = new Track[(*johnny_n)];
	unsigned int idx = 0;
	
	for (unsigned int i = 0; i < all_n; ++i) {
		if (all_songs[i].author == 0) {
			(*in_memoriam_johnny)[idx++] = all_songs[i];
		}
	}
}