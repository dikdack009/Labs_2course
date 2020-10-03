namespace PROG_1 {

    struct Int {
        int key;
        int col; 
        int str;
        int n;
    };

    int getNum(int&);
    Int** create(Int**, int*, int*);
    void errase(Int**, int);
    void output(Int**, int, int, int);
    void output(Int*);
    Int* createMas(Int**, int);
    Int** realloc(Int**, int);
}