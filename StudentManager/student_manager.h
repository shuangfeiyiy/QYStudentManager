//
//  student_manager.h
//  StudentManager
//
//  Created by zhangsf on 15/1/2.
//  Copyright (c) 2015年 zhangsf. All rights reserved.
//

#ifndef __StudentManager__student_manager__
#define __StudentManager__student_manager__

#include <stdio.h>
#include "common.h"

void startStudentManagerSystem();
//根据输入的学生信息， 完成学生管理系统的注册功能，向系统里添加一个新的学生
int registerNewStudent(STU *newStudent);

//根据学生的学号， 从学生管理系统里删除一个学生的信息
int unregisterStudentWithStuNumber(const char *studentNum);

//根据学生的姓名， 从学生系统里查找对应的学生，并返回查找到的学生信息
STU *findStudentInfoWithName(const char *name);

//根据学生的学号， 从学生系统里查找对应的学生， 并返回查找到学生的信息
STU *findStudentInfoWithStuNumber(const char *studentNum);

//根据传入的学生信息， 输出学生信息
void showStudentInfo(STU *student);

void showAllStudent();
#endif /* defined(__StudentManager__student_manager__) */
