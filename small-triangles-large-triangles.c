// https://www.hackerrank.com/challenges/small-triangles-large-triangles

double calc_area(int a, int b, int c) {
    double p = 1.0 * (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    triangle t;
    double area_a, area_b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n-1); j++) {
            area_a = calc_area(tr[j].a, tr[j].b, tr[j].c);
            area_b = calc_area(tr[j+1].a, tr[j+1].b, tr[j+1].c);
            if (area_b < area_a) {
                t = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = t;
            }
        }
    }
}
