#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int numberOfStudents;

typedef struct student {
char name[NAMElEN];
int age;
int studyID;
int useFlag;
}STU;

enum command {
kListStudents,
kAddStudent,
kDeleStudent,
kSearchStudent,
kQuiteCMD,
};

STU *allocStudentRecords(int number)
{
    STU *stu = NULL;
    int size = number *sizeof(STU);
    stu = malloc(size);
    if (stu == NULL){
        perror("malloc");
        return NULL;
    }
    memset (stu,0,size);
    numberOfStudents = number;
    return stu;
}

static void printfStudent(STU *stu,int index)
{
    printf("Student's Name is [%s]\n",stu[index].name);
    printf("Student's Age is [%d]\n",stu[index].age);
    printf("Student's StudyID is [%d]\n",stu[index].studyID);
    printf("============================================\n");
}
void printfStudents(STU *stu)
{
    for (int i = 0;i < numberOfStudents;i++){
       if(stu[i].useFlag){
           printStudent(stu,i);
       }
    }
}

static int checkStudyID(STU *stu,int studyID)
{
    for (int i = 0;i < numberOfStudents;i++)
    {
        if(studyID == stu[i].studyID && stu[i].useFlag == 1){
         return -1;
        }
    }
    return 0;
}

static int getFreePosition(STU *stu)
{
    for (int i = 0;i < numberOfStudents;i++){
     if(stu[i].useFlag == 0){
            return i;
     }
    }
    return -1;
}

int addStudent(STU *stu,char *name,int age,int studyID)
{
    int index = -1;
    if(checkStudyID(stu,stutyID)<0){
    fprintf(stderr,"student <%d> Already Exsist!\n",studyID);
    return -1;
    }
    index = getFreePosition(stu);
    if (index < 0){
        fprintf(stderr,"no free position to add new student!\n");
        return -1;
    }

    strncpy(stu[index].name,name,NAMELEN-1);
    stu[index].age = age;
    stu[index].studyID = studyID;
    stu[index].useFlag = 1;

    printf("Added successfully !\n");
    return 0;
}

int delStudent(STU *stu,int studyID)
{
    for (int i = 0;i < numberOfStudents;i++)
    {
        if (stu[i].studyID == studyID && stu[i].useFlag){
           stu[i].useFlag = 0;
           printf("Deleted Successfully !\n");
           return 0;
        }
    }
    fprintf(stderr,"student <%d> to delete does not exsist !\n");
}

int seachStudent(STU *stu,int studyID)
{
    for(int i = 0;i < numberOfStudents;i++){
      if(stu[i].studyID == studyID && stu[i].useFlag){
       printfStudent(stu,i);
       return 0;
      }
    }
    fprintf(stderr,"student <%d> to search does not exsist ! \n",studyID);
    return -1;
}

void deallocStudentRecords(STU *stu)
{
    free(stu);
}
