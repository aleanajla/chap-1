#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Course{
    char id[10]; // 10 bytes
    int score; // 4 bytes
};

struct Student{
    char name[255]; // 255 bytes
    double gpa; // 8 bytes
    Course c; // object course
};

// createStudent akan mereturn pointer yang mengarah Student
// const char *name sama aja seperti char name[]
// Student *createStudent(Student s)
Student *createStudent(const char *name, double gpa, const char *ID, int score){
    // alokasi memory 
    Student *newStudent = (Student*)malloc(sizeof(Student));

    strcpy(newStudent->name,name); // strcpy((*newStudent).name,name);

    //hasil = hasil + 3 sama aja dengan hasi;+=3
    //(*newStudent).atributnya sama aja dengan newStudent->atributnya

    newStudent->gpa=gpa;
    strcpy(newStudent->c.id,ID);
    newStudent->c.score = score;


    return newStudent;
}

// tipe data yang direturn : Student*
// nama function createStudent
// parameter : name, gpa, course (id dan score)

void removeStudent(Student *s){
    free(s); // buang memory yang sudah dialokasikan
    s=NULL; // kosongkan nilainya,menghindari dangling pointer
}

void printStudent(Student *s){
    printf("Name %s\n",s->name);
    printf("GPA: %lf\n",s->gpa);
    printf("Course ID: %s\n",s->c.id);
    printf("Score: %d\n",s->c.score);
}

int main(){
    // Student students[10] // static memory allocation
    // float angka = 5.5959;
    // int angkaInterger = (int)angka; // 5
    // printf("%lu", sizeof(Student));

    // Student dummy;
    // isi dummy.na,e, dummy.gpa,....
    // createStudent(dummy);

    // s1 mengarah ke student yang direturn oleh 
    Student *s1 = createStudent("Budi",3.90,"COMP6048",100);
    Student *s2 = createStudent("Abdu;",4.00,"COMP6049",85);

    printf("Before Remove\n");
    printStudent(s1);
    removeStudent(s1);
    printf("After Remove\n");
    Student *s3 = createStudent("Bryan",3.90,"COMP3030",95);
    // buat beberapa varibale
    // hapus2 nilai
    // buat2 struct baru

    //kalo dah di remove ga bisa di akses kembali
    // mengakses undifine illegal behaviour

    return 0;
}