namespace lab1 {

	struct Line {
		int pos;
		int number;
		Line* next;
	};
	
	struct Col {
		int pos;
		Line* l;
		Col* next;
	};

	Col* matrix_create(int m, int n);
	Col* modify(Col* mx, int n);
	void output(const char* msg, Col* mx, int m, int n);
	void erase(Col* mx);
	int getInt(int &a);
	void pz(int q);
}