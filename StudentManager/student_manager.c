//
//  student_manager.c
//  StudentManager
//
//  Created by zhangsf on 15/1/2.
//  Copyright (c) 2015年 zhangsf. All rights reserved.
//

#include "student_manager.h"
#include <string.h>

STU g_student_list[30] = {0};
static unsigned int nCountStudent = 0;
static unsigned int deleteIndex = -1;

int registerNewStudent(STU *newStudent)
{
    if (nCountStudent > 29) {
        printf("The student manager system has no space\n");
        return kStudentMgrOperError;
    }
    
    STU tempStudent = {0};
    strcpy(tempStudent.name, newStudent->name);
    strcpy(tempStudent.stuNumber, newStudent->stuNumber);
    tempStudent.age = newStudent->age;
    tempStudent.academic_record = newStudent->academic_record;
    
    /*
    for (int i = 0; i <= nCountStudent; i++) {
        if (nCountStudent > 1 && g_student_list[i].isUnregister == true) {
            g_student_list[i] = tempStudent;
            nCountStudent++;
            break;
        } else if (nCountStudent == 0)
        {
            g_student_list[i] = tempStudent;
            nCountStudent++;
        }
    }
    */
    g_student_list[nCountStudent] = tempStudent;
    nCountStudent++;
    return kStudentMgrOperOK;
}

int unregisterStudentWithStuNumber(const char *studentNum)
{
    if (nCountStudent < 1) {
        printf("The student manager system has no record\n");
        return kStudentMgrOperError;
    }
    STU *temStudent = findStudentInfoWithStuNumber(studentNum);
    /*
    if (temStudent != NULL) {
        //memset(temStudent, 0x00, sizeof(STU));
        temStudent->isUnregister = true;
        nCountStudent--;
    }
    */
    
    if (temStudent != NULL) {
        //数组前移
        for (int i = deleteIndex; i < nCountStudent-1; i++) {
            g_student_list[i] = g_student_list[i+1];
        }
        nCountStudent--;
    }
    return 0;
}


STU *findStudentInfoWithName(const char *name)
{
    for (int i = 0; i < nCountStudent; i++) {
        STU tempStudent = g_student_list[i];
        if (strcmp(tempStudent.name, name) == 0) {
            deleteIndex = i;
            return &g_student_list[i];
        }
    }
    return NULL;
}

STU *findStudentInfoWithStuNumber(const char *studentNum)
{
    for (int i = 0; i < nCountStudent; i++) {
        STU tempStudent = g_student_list[i];
        if (strcmp(tempStudent.stuNumber, studentNum) == 0) {
            return &g_student_list[i];
        }
    }
    return NULL;
}

void showStudentInfo(STU *student)
{
    printf("The student's infomation:\n name:%s\n studentID:%s\n Age:%d\n,academic_record:%f\n",student->name,student->stuNumber,
           student->age,student->academic_record);
    
}

void showAllStudent()
{
    for (int i = 0 ; i < nCountStudent; i++ )
    {
        showStudentInfo(&g_student_list[i]);
    }
}

void startStudentManagerSystem()
{
    char cmdInput[30] = {0};
    printf("********************************\n河南青云学生管理系统\n *********************************\n");
    
    do {
        showStuManagerMenuList();
        scanf("%s",cmdInput);
        if (strcmp(cmdInput, "R") == 0) {
            printf("Please input the student's name ,studentNumber\n");
            STU student = {0};
            scanf("%s%s",student.name,student.stuNumber);
            registerNewStudent(&student);
        }else if (strcmp(cmdInput, "D") == 0)
        {
            printf("Please input the student's studentNumber\n");
            char strID[20] = {0};
            scanf("%s",strID);
            unregisterStudentWithStuNumber(strID);
        }else
        {
            showAllStudent(); 
        }
    } while ( strcmp(cmdInput, "Q") != 0);

}