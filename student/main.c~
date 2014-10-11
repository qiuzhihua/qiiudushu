#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "student.h"

#define BUFSIZE 32
#define STUBUN  32

static long getInput(void)
{
    char buf[BUFSIZE] = {0};
    long result = -1;

    fgets(buf,BUFSIZE,stdin);
    result = strtol(buf,NULL,0);
    if((result == 0 && errno == EINVAL) || (errno == ERANGE)){
         result = -1;
         errno = 0;
    }
    return result;
}

static int getstudyID(void)
{
    int studyID = -1;
_InputStudyID:
    fprintf(stdout,"please input Student's study ID:\n");
    studyID = (int)getInput();
    if(studyID < MINSTUDYID || studyID > MAXSTUDyID){
     fprintf(stderr,"Invalid Input !\n");
     goto _InputStudyID
    }
    return studyID;
}

int main(void)
{
    long cmd = -1;
    char stuName[NAMELEN] = {0};
    int stuAge = -1;
    int studyID = -1;
    STU *stu = NULL;

    whule(1){
     fprintf(stdout,"please input command Number:\n 0 - List\t 1- Add\t 2 -Delete\t 3 - Search\t 4- Quit\n");

     cmd = getINput();
     fpurge(stdin);
     if (cmd == -1 || cmd > kQuitCMD || cmd < kListStudents){
        fprintf(stderr,"Invalid Command !\n");
        continue;
     }
     switch (cmd){
      case kListStudents:
          printStudents(stu);
          break;
      case kAddStudent:
          fprintf(stdout,"please Input student's Name:\n");
          fgets(stuName,NAMELEN,stdin);
          stuName[strlen(stuName)-1]='\0';
_InputAge:
          fprintf(stdout,"please input student's Age:\n");
          stuAge = (int)getinput();
          if(stuAge < MINAGE || stuAge > MAXAGE){
           fprintf(stderr,"invalid Input !\n");
           goto _InputAge;
          }
          studyID = getStudyID();
          addStudent(stu,stuName,stuAge,studyID);
          break;
      case KDelStudent:
          studyID = getStudyID();
          delStudent(stu,studyID);
          break;
          case KSearchStuentID();
          searchStudent(stu,studyID);
          break;
      default:
          fprintf(stderr,"can't go here !Unknown Command!\n");
          break;
     }
    }
_Fail:
    exit(1);
_Exit:
    deallocStudentRecords(stu);
    return 0;
}
