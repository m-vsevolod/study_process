struct vect sum(struct vect a, struct vect b){
	struct vect result = {a.x + b.x, a.y + b.y, a.z + b.z};
	return result;
}