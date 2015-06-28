//
//  common.h
//  StudentManager
//
//  Created by zhangsf on 15/1/2.
//  Copyright (c) 2015年 zhangsf. All rights reserved.
//

#ifndef __StudentManager__common__
#define __StudentManager__common__

#include <stdio.h>
#include <stdbool.h>
//用于表示一个学生信息的类型
typedef struct STUDENT_ITEM
{
    char name[20];
    char stuNumber[20];
    int age;
    float academic_record;
    bool isUnregister;
} STU;

//学生管理系统里关于业务处理的命令字
typedef enum StuSysMgr
{
    kCmdRegister,
    kCmdFindStudent,
    kCmdUnregister,
    kCmdModifyStuInfo,
    kCmdQuit
} QYStuCommandType;

//学生管理系统处理结果
enum {
    kStudentMgrOperError = -1,
    kStudentMgrOperOK
};

void showStuManagerMenuList();
#endif /* defined(__StudentManager__common__) */
